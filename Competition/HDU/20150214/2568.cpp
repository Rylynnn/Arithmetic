/*
  记f(n)为杀死所有蝙蝠所要进行B斩击的次数
  当n为1时，使用一次
  当n为偶数时，使用f(n/2)次
  当n为奇数时，使用f(n/2)+1次
*/
#include"iostream"

using namespace std;

int f(long long n ){
    if(n == 1) return 1;
	if(n % 2 == 0) return f(n/2);
	return f(n/2)+1;
}

int main(){

    long long c,num;
    cin >> c;
    for(int i = 0; i < c; i++){
		cin  >> num;
		cout << f(num) << endl;
	}
	return 0;
}