ha#include <iostream>
#include<fstream>
using namespace std;

const int MAX = 10000+10;
int main()
{
	//ifstream fin;
	//ofstream fout;
    //fin.open("test.txt");
    //fout.open("out.txt");
    int people[MAX], peopleNumber;
    int sum = 1, t = 1, cut=0;
    for(int i = 0; i<MAX; i++){
		if(i <= sum){
			people[i] = cut;
		}
		else{
			cut++;
			sum+=t;
			t++;
			people[i] = cut;
		}
    }
    while(cin >> peopleNumber){
		cout << people[peopleNumber] << endl;
    }
}
