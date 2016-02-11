#include<cstdio>
#include<cstring>
int main()
{
    int num,i,m,j,k,p,p2,length,fin[27][27];
    int point[26];
    char c[100],n[100],ans[26];
    scanf("%d",&num);
    memset(fin,0,sizeof(fin));
    for(int i=0;i<num;i++){
        scanf("%s",c);
        n[i]=c[0];//存首字母表
    }
    p=0;
    for(i=0;i<strlen(n)-1;i++){
        if(p==1&&n[i]!=n[i+1]){
            fin[n[i]-97][n[i+1]-97]=1;
            continue;
        }
        if(n[i]>n[i+1]&&p!=1){
            fin[n[i]-97][n[i+1]-97]=1;
            p=1;
        }
    }//从第一个出现不遵守字母表顺序的开始建立邻接矩阵关系
    /*for(i=0;i<26;i++){
        for(j=0;j<26;j++)
        printf("%d",fin[j][15]);
        printf("\n");
    }*/
    k=0;
    memset(point,0,26);//用于标记已经填入新字母表中的字母
    for(m=0;m<26;m++){//每次选择字母的时候，重新历遍26个字母，对于每个字母，先判断该字母的入度是否为1，如果为1，则不填该数，换下一个字母，如果入度为0，则填入。
        for(i=0;i<26;i++){
            p2=0;
            for(j=0;j<26;j++){
                if(fin[j][i]==1){
                    p2=1;
                    //printf("1%c\n",i+97);
                    break;
                }
            }
            if(p2==0&&point[i]!=1){
                point[i]=1;
                ans[m]=i+97;
                k++;
                for(j=0;j<26;j++){
                    fin[i][j]=0;
                }//入度为0则填入该数，并将该数的出度置为0,因为如果存在环，则对于同一个字母，不能一次消掉该字母的所有入度，则之后的数字不能填入，则新字母表的总字母数小于26
                //printf("2%c\n",ans[m]);
                break;
            }
        }
    }//从
    //printf("%d",k);
    if(k==26){
        for(i=0;i<k;i++){
            printf("%c",ans[i]);
        }
    }
    else if(k!=26)printf("Impossible");//根据新字母表的总字母数判断是否可以输出新字母表
    return 0;
}
