#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i;
	int in[26];
	int out[26];
	string input;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	cin>>input;
	for(i=0;i<input.length();i++){
		in[input[i]-'A']++;
	}
	cin>>input;
	for(i=0;i<input.length();i++){
		out[input[i]-'A']++;
	}
	sort(in,in+26);
	sort(out,out+26);
	for(i=0;i<26;i++){
		if(in[i]!=out[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
