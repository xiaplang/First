#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "source.cpp"
using namespace std;

int main(){
	char input[30];
    FILE *fpin;
    cout<<"请输入源文件名：\n"<<endl;
    for(;;){
        cin>>input;
        if((fpin = fopen(input,"r")) != NULL)
            break;
        else
            cout<<"路径输入错误"<<endl;
    }
    cout<<"****************词法分析结果********************"<<endl;
    analyze(fpin);
    fclose(fpin);
    cout << tokens << endl;
    ofstream os;     //创建一个文件输出流对象
    os.open("token.txt");//将对象与文件关联      
    os << tokens;   //将输入的内容放入txt文件中
    os.close();
	return 0;
}
