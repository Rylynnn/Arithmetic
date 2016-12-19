 #include <bits/stdc++.h>
 using namespace std;
 int main()
 {
     string a;
     int n;
     while(scanf("%d",&n)!=EOF){
        cin>>a;
        int p=0,b[107],num=0,tmp=0;;
        for(int i=0;i<a.size();i++){
            if(a[i]=='B'&&p==0){
                p=1;
                num++;
            }
            else if(a[i]=='B'&&p==1){
                num++;
            }
            else if(a[i]=='W'&&p==1){
                p=0;
                b[tmp++]=num;
                num=0;
            }
        }
        if(tmp==0&&num==0){
            printf("0\n");
            continue;
        }
        else{
            if(a[n-1]=='B'){
                b[tmp++]=num;
            }
            printf("%d\n",tmp);
            printf("%d",b[0]);
            for(int i=1;i<tmp;i++){
                printf(" %d",b[i]);
            }
        }
     }

 }
