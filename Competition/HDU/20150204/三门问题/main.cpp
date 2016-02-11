#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;


int main(){
	//ofstream fout;
    //fout.open("test1.txt");
	//ifstream fin;
    //fin.open("test.txt");
	long long n,i,a;
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> a;
		cout <<  a-1 << "/" << a << endl;
	}
	//fout.close();
	//fin.close();
	return 0;
}
