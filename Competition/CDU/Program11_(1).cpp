//C++面向对象程序设计    第十一章    第二大题    第1小题
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

/*
注意：命令行输入本可执行文件名时必须用双引号括起来或者更换可执行程序的文件名
*/

void DelPreChar(string& iss,int staIndex) {
	string temp;
	for(int i=0;staIndex<iss.size();++staIndex,++i)
		temp+=iss[staIndex];
	iss=temp;
}

void OutPreChar(ofstream& ofs,string& iss,int endText) {
	int p1=0,p=0;
	for(int i=0;i<endText;++i){    //kashdk
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
	if (-1==endText||(0!=endText&&iss[endText-1]=='\\')) {//文本未结束
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
		cout<<"参数个数错误！\n";
		exit(0);
	}
	ifstream ifs(argv[1]);
	if(!ifs.is_open()) {
		cout<<"文件不存在！\n";
		exit(0);
	}
	bool blockNote=false,text=false;
	string iss;
	int i,rowIndex,blockIndex,endIndex,staText;
	ofstream ofs("temp.tmp");//此处未检查文件是否存在是因为本题重点不在此处
	while (getline(ifs,iss)) {
		if(text) {//判断是否在文本（即""）内
			TextEdit(text,ofs,iss);
			if(text)//处理完后，文本仍未结束
				continue;
		}
		if(blockNote) {//判断是否存在块注释
			blockIndex=iss.find("*/");
			if(blockIndex==-1)//没有块注释结束的标志
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
		rowIndex=iss.find("//");
		blockIndex=iss.find("/*");
		if(!(-1==staText||(-1!=rowIndex&&rowIndex<staText)||(-1!=blockIndex&&blockIndex<staText)))//判断双引号是否在注释内
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
		rowIndex=iss.find("//");
		blockIndex=iss.find("/*");
		if (-1==rowIndex&&-1==blockIndex) {//既无行注释，也无块注释
			ofs<<iss<<'\n';
			continue;
		}
		if(-1!=rowIndex&&-1!=blockIndex)//行注释与块注释的开始的标志都存在
			if (rowIndex<blockIndex)//行注释生效
				blockIndex=-1;
			else//块注释生效
				rowIndex=-1;
		if(-1==rowIndex) {//只存在块注释
			endIndex=iss.find("*/");
			for (i=0;i<blockIndex;++i)
				ofs<<iss[i];
			if(-1==endIndex)//块注释未在本行结束
				blockNote=true;
			else
				for(i=blockIndex+2;i<iss.size();++i)
					ofs<<iss[i];
			ofs<<'\n';
			continue;
		}
		if(-1==blockIndex) {//只存在行注释
			for (i=0;i<rowIndex;++i)
				ofs<<iss[i];
			ofs<<'\n';
			continue;
		}
	}

	/*
	ifstream 是有状态的对象，一个 ifstream 操作完后一般处于非正常状态，内部的 eofbit 标记 failbit 标记等可能已被设定。
	重新打开文件并不会清除这些标记，因此需要添加一步：
	ifs.clear();  // 去除 ifs 中的错误标记(如文件末尾标记或读取失败标记等)
	*/

	ifs.clear();
	ofs.clear();

	ifs.close();
	ofs.close();
	//下面把中间文件temp.tmp全部复制到原文件中
	ifs.open("temp.tmp");
	if(!ifs.is_open()) {
		cout<<"数据文件丢失！请重新运行本程序！\n";
		exit(0);
	}
	ofs.open(argv[1]);
	while (getline(ifs,iss)) {
		ofs<<iss<<'\n';
	}
	ifs.close();
	ofs.close();
	//删除中间文件
	remove("temp.tmp");
	return 0;
}//end of main

