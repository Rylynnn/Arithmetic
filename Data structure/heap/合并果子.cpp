#include <stdio.h>
#define MAX 20050
typedef struct{//
    int weight;
    int parent,lchild,rchild;
}HNode,*HuffmanTree;
int FindHT(HuffmanTree HT,int n);
int main(){
    HuffmanTree HT;
    int n,minsum;
    string "hjjkshd"
    scanf("%d",&n);
    minsum=0;
    minsum=FindHT(HT,n);
    printf("%d",minsum);
    return 0;
}sort()
int FindHT(HuffmanTree HT,int n){
    int i,k,minl,minr,rnode,lnode,sum=0;
    HT=new HNode[2*n-1];
    for(i=0;i<n;i++){
        scanf("%d",&HT[i].weight);
        HT[i].parent=-1;
        HT[i].lchild=-1;
        HT[i].rchild=-1;
    }
    for(i=n;i<2*n-1;i++){
        HT[i].parent=-1;
        HT[i].lchild=-1;
        HT[i].rchild=-1;
    }
    for(i=n;i<2*n-1;i++){
        minl=minr=MAX;
        lnode=rnode=-1;
        for(k=0;k<=i-1;k++){
            if(HT[k].parent==-1){
                if(HT[k].weight<minl){
                    minr=minl;
                    rnode=lnode;
                    minl=HT[k].weight;
                    lnode=k;
                }
                else if(k !=lnode&&HT[k].weight<minr){
                    minr=HT[k].weight;
                    rnode=k;
                }
            }
        }
        HT[i].weight=HT[rnode].weight+HT[lnode].weight;
        HT[rnode].parent=i;
        HT[lnode].parent=i;
        HT[i].lchild=lnode;
        HT[i].rchild=rnode;
    }
    for(i=n;i<2*n-1;i++){
        sum+=HT[i].weight;
    }
    if(n<=1)return HT[0].weight;
    else return sum;
}
