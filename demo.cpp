#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include "source.cpp"
using namespace std;

int main(){
	char input[30];
    FILE *fpin;
    cout<<"������Դ�ļ�����\n"<<endl;
    for(;;){
        cin>>input;
        if((fpin = fopen(input,"r")) != NULL)
            break;
        else
            cout<<"·���������"<<endl;
    }
    cout<<"****************�ʷ��������********************"<<endl;
    analyze(fpin);
    fclose(fpin);
    cout << tokens << endl;
    ofstream os;     //����һ���ļ����������
    os.open("token.txt");//���������ļ�����      
    os << tokens;   //����������ݷ���txt�ļ���
    os.close();
	return 0;
}
