
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;


void DelPreChar(string& iss,int staIndex) {
	string temp;
	for(int i=0;staIndex<iss.size();++staIndex,++i)
		temp+=iss[staIndex];
	iss=temp;
}
void OutPreChar(ofstream& ofs,string& iss,int endText) {
	int p1=0,p=0;
	for(int i=0;i<endText;++i){    
        if(p1==0&&iss[i]==' '){
            p1=i;
        }
        else if(iss[i]!=' '){
            p1=0;
            p=1;
        }
	}
	if(p==0){
        return;
	}
	else if(p==1&&p1!=0){
        for(int i=0;i<p1;i++){
            ofs<<iss[i];
        }
        ofs<<endl;
	}
}
void TextEdit(bool& text,ofstream& ofs,string& iss) {
	int endText=iss.find('\"');
	if (-1==endText||(0!=endText&&iss[endText-1]=='\\')) {
		ofs<<iss<<'\n';
		return;
	}
	for(int i=0;i<=endText;++i)
		ofs<<iss[i];
	text=false;
	DelPreChar(iss,endText+1);
}
int main(int argc,char* argv[]) {
	if(argc!=2) {
参数个数错误！\n";
		exit(0);
	}
	ifstream ifs(argv[1]);
	if(!ifs.is_open()) {
文件不存在！\n";
		exit(0);
	}
	bool blockNote=false,text=false;
	string iss;
	int i,rowIndex,blockIndex,endIndex,staText;
temp.tmp");
	while (getline(ifs,iss)) {
		if(text) {
			TextEdit(text,ofs,iss);
			if(text)
				continue;
		}
		if(blockNote) {
*/");
			if(blockIndex==-1)
				continue;
			blockNote=false;
			i=blockIndex+2;
			while (i<iss.size()) {
				ofs<<iss[i];
				++i;
			}
			DelPreChar(iss,blockIndex+2);
			ofs<<'\n';
		}
		staText=iss.find('\"');
//");
/*");
		if(!(-1==staText||(-1!=rowIndex&&rowIndex<staText)||(-1!=blockIndex&&blockIndex<staText)))
			while(-1!=staText&&!iss.empty()) {
				if(0!=staText&&iss[staText-1]=='\\')
					break;
				OutPreChar(ofs,iss,staText);
				DelPreChar(iss,staText+1);
				text=true;
				TextEdit(text,ofs,iss);
				staText=iss.find('\"');
			}
		if(iss.empty())
			continue;
//");
/*");
		if (-1==rowIndex&&-1==blockIndex) {
			ofs<<iss<<'\n';
			continue;
		}
		if(-1!=rowIndex&&-1!=blockIndex)
			if (rowIndex<blockIndex)
				blockIndex=-1;
			else
				rowIndex=-1;
		if(-1==rowIndex) {
*/");
			for (i=0;i<blockIndex;++i)
				ofs<<iss[i];
			if(-1==endIndex)
				blockNote=true;
			else
				for(i=blockIndex+2;i<iss.size();++i)
					ofs<<iss[i];
			ofs<<'\n';
			continue;
		}
		if(-1==blockIndex) {
			for (i=0;i<rowIndex;++i)
				ofs<<iss[i];
			ofs<<'\n';
			continue;
		}
	}
	

	ifs.clear();
	ofs.clear();
	ifs.close();
	ofs.close();
	
temp.tmp");
	if(!ifs.is_open()) {
数据文件丢失！请重新运行本程序！\n";
		exit(0);
	}
	ofs.open(argv[1]);
	while (getline(ifs,iss)) {
		ofs<<iss<<'\n';
	}
	ifs.close();
	ofs.close();
	
temp.tmp");
	return 0;
}
