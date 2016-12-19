#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=130007;
const int INF=0x3f3f3f3f;

int cnt_stack,cnt_pool;
struct Node *nodeStack[MAXN],*root,*NIL;

struct Node {
    Node *par,*son[2];//0表示左儿子，1表示右儿子
    int key;//当前结点保存的值，可根据需要修改 类型
    int size;
    int lazy;

    #define lson son[0]
    #define rson son[1]

    void reset(int val) {//初始化当前结点
        lson=rson=par=NIL;
        key=val;
        lazy=0;
    }

    void reverse() {//将当前区间翻转
        lazy^=1;
        swap(lson,rson);
    }

    void pushUp() {//将子结点的值跟新到当前结点
        size=lson->size + 1 + rson->size;
        lazy=0;
    }

    void pushDown() {
        if((lazy&1)==1) {
            lson->reverse();
            rson->reverse();
        }
        lazy=0;
    }

    int sgn() {//通过判断当前结点是否在其父亲结点的右儿子处，返回当前结点在其父亲结点的哪个结点
        return par->rson==this?1:0;
    }

    void set(Node *x,int d) {//d=0表示左儿子，d=1表示右儿子；将x结点挂在当前结点的(d == 0:左 || 1:右)儿子
        son[d]=x;
        x->par=this;
    }

    void setLson(Node *x) {//将x结点挂在当前结点的左儿子
        set(x,0);
    }

    void setRson(Node *x) {//将x结点挂在当前结点的右儿子
        set(x,1);
    }

    void rotate(int d) {//d=0表示 左旋，d=1表示右旋
        Node *y=par,*z=y->par;//y指向当前结点的父亲结点，z指向当前结点的祖父结点
        z->set(this,y->sgn());//将当前结点挂在y结点的原位置
        y->set(son[d^1],d);//将当前结点的(d == 0:右 || 1:左)儿子挂在其父亲结点y的(d == 0:左 || 1:右)儿子处
        set(y,d^1);//将y结点挂在当前结点的(d == 0:右 || 1:左)儿子处
        y->pushUp();//更新y结点的旋转后的值
        ///【旋转操作中不需要更新当前结点旋转后的值，因为当前结点可能还需要旋转，所以最后在splay操作中pushUp即可】
    }

    void rotate() {//通过判断当前结点在其父亲结点的位置，进行 左旋 或 右旋，实现上升
        rotate(sgn());
    }

/*
    Node *splay(Node *goal) {//通过单旋上升到指定位置，效率低，可用于调试
        while(par!=goal) {
            rotate();
        }
        pushUp();
        if(goal==NIL) {//如果当前结点已旋转至根结点，则更新其为根结点
            root=this;
        }
        return this;
    }
*/

    Node *splay(Node *goal) {//不断将当前结点旋转，直至其成为goal的子结点
        int a,b;
        while(par!=goal) {//若当前结点不是goal结点的子结点，则继续旋转
            if(par->par==goal) {//若goal结点是当前结点的祖父结点，则只需旋转一次即可到达目标位置
                rotate();
            }
            else {
                a=sgn();//当前结点在其父亲结点的位置
                b=par->sgn();//当前结点的父亲结点在其父亲结点的位置
                ((a^b)==0?par:this)->rotate(a);//如果当前结点和其父亲结点所在位置相同
                rotate(b);
            }
        }
        pushUp();//当前结点已旋转至指定位置，更新旋转后的值
        if(goal==NIL) {//如果当前结点已旋转至根结点，则更新其为根结点
            root=this;
        }
        return this;
    }

    void recycle() {//释放当前结点及其整棵树
        if(this==NIL) {
            return ;
        }
        lson->recycle();
        rson->recycle();
        nodeStack[++cnt_stack]=this;//回收当前结点
    }

    void inorder() {//中序遍历输出当前序列，方便调试
        if(this==NIL) {
            return ;
        }
        pushDown();
        lson->inorder();
        if(key!=-INF) {
            printf("%d ",key);
        }
        rson->inorder();
    }

}nodePool[MAXN];

inline Node *newNode(int val) {//分配一个值为val的新结点
    Node *x=(cnt_stack==0? &nodePool[++cnt_pool] : nodeStack[cnt_stack--] );
    x->reset(val);//初始化当前结点
    return x;
}

Node *findNo(int k,Node *p=NIL) {//从p开始查找第k个结点，并返回这个结点的指针
    Node *x=root;
    while(x->pushDown(),x->lson->size!=k) {
        if(k < x->lson->size) {//如果第k的结点在左子树中
            x=x->lson;
        }
        else {
            k-=x->lson->size+1;//减去左子树和当前结点的个数
            x=x->rson;
        }
    }
    return x->splay(p);//将第k个结点旋转至p结点下
}

int num[MAXN];//需要维护的序列

void splayInit() {//splay树运行前初始化
    NIL=&nodePool[0];
    num[0]=-INF;
}

Node *build(int l,int r) {//根据序列num建立splay树
    if(l>r) {
        return NIL;
    }
    int mid=(l+r)>>1;
    Node *x=newNode(num[mid]);
    x->setLson(build(l,mid-1));
    x->setRson(build(mid+1,r));
    x->pushUp();
    return x;
}

void revers(int l,int r) {//翻转区间[l,r]
    Node *x,*y,*z;
    y=findNo( l-1, z=findNo(r+1) );//将r的后一个结点z旋转至根结点，将l的前一个结点y旋转至此时的根节点下（必在其左儿子），则区间[l,r]在y结点的右子树中
    x=y->rson;//x结点子树为区间[l,r]
    x->reverse();//翻转区间[l,r];
    y->pushUp();//由于y结点是z结点的儿子，所以需要先更新y结点
    z->pushUp();
}

int n,q,l,r;

int main() {
    splayInit();
    while(2==scanf("%d%d",&n,&q)) {
        cnt_pool=cnt_stack=0;//初始化内存池和内存回收栈
        for(int i=1;i<=n;++i) {
            num[i]=i;
        }
        num[n+1]=-INF;
        root=build(0,n+1);
        while(q-->0) {
            scanf("%d%d",&l,&r);
            revers(l,r);
        }
        root->inorder();
        printf("\n");
    }
    return 0;
}
