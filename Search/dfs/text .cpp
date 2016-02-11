#include <cstdio>
int cantor()//康拓展开求hash值
    int i,j,sum=0;
    for(i=0;i<=8;i++){
        num=0;
        for(j=i+1;j<=8;j++){
            if(eight.s[j]<eight.s[i]){
                ++num;
            }
        }
        sum+=num*cantor[9-i-1];
    }
    return sum+1;   
}
int main()
{
	for(i=1;i<=400000;i++){
		
	}
}