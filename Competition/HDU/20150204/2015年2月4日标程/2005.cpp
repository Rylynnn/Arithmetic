#include <iostream>
#include <algorithm>
#include<fstream>
using namespace std;

const int maxn = 100+10;
int main()
{
    int a[maxn],b[maxn],boy,girl;
    while(cin >> boy){
		for( int i = 0; i < boy; i++){
			cin >> a[i];
		}
		cin >> girl;
		for( int i = 0; i < girl; i++){
			cin >> b[i];
		}
		sort(a,a+boy);
		sort(b,b+girl);
		int i = 0, j = 0, pairNum = 0;
		while(i < boy && j < girl){
			if( abs(a[i] - b[j]) <= 1 ){
				pairNum++;
				i++;
				j++;

			}
			else{
				if( a[i] > b[j]){
					j++;
				}
				else{
					i++;
				}
			}
		}
			cout << pairNum << endl;
    }
    return 0;
}
