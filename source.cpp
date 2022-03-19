#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
#define MAX 13

char ch = ' ';
string keyWord[MAX] = {"int","main","void","if","else","char","string","for","while","switch", "break", "double", "return"};
string tokens;

int IF_keyWord(string token){
	for(int i = 0; i < MAX; ++ i){
		if(token==keyWord[i]) return true;
	}
	return false;
}

bool IF_letter(char letter){
	if((letter >= 'a' && letter <= 'z')||(letter >= 'A' && letter <= 'Z'))
        return true;
    else
        return false;
}

bool IF_Digit(char digit){
    if(digit >= '0' && digit <= '9')
        return true;
    else
        return false;
}

void analyze(FILE *fpin){
	while((ch = fgetc(fpin)) != EOF){
		
        if(ch == ' '||ch == '\t'||ch == '\n'){
			tokens += ch;
		}
        //关键字&标识符 
        else if(IF_letter(ch)){
        	string token;
        	while(IF_letter(ch)||IF_Digit(ch)){
        		token+=ch;
        		ch = fgetc(fpin);
			}
			//回退一个指针
            fseek(fpin,-1L,SEEK_CUR);
            if(IF_keyWord(token)){
            	if(token == "int") {
            		cout << token << "\t<04>" << "\t关键字" << endl;
            		tokens += "<04>"; 
				}
				else if(token == "main"){
					cout << token << "\t<05>" << "\t关键字" << endl;
					tokens += "<05>";
				}
				else if(token == "void"){
					cout << token << "\t<06>" << "\t关键字" << endl;
					tokens += "<06>";
				}
				else if(token == "if"){
					cout << token << "\t<07>" << "\t关键字" << endl;
					tokens += "<07>";
				}
				else if(token == "else"){
					cout << token << "\t<08>" << "\t关键字" << endl;
					tokens += "<08>";
				}
				else if(token == "char"){
					cout << token << "\t<09>" << "\t关键字" << endl;
					tokens += "<09>";
				}
				else if(token == "string"){
					cout << token << "\t<10>" << "\t关键字" << endl;
					tokens += "<10>";
				}
				else if(token == "for"){
					cout << token << "\t<11>" << "\t关键字" << endl;
					tokens += "<11>";
				}
				else if(token == "while"){
					cout << token << "\t<12>" << "\t关键字" << endl;
					tokens += "<12>";
				}
				else if(token == "switch"){
					cout << token << "\t<13>" << "\t关键字" << endl;
					tokens += "<13>";
				}
				else if(token == "break"){
					cout << token << "\t<14>" << "\t关键字" << endl;
					tokens += "<14>";
				}
				else if(token == "double"){
					cout << token << "\t<15>" << "\t关键字" << endl;
					tokens += "<15>";
				}
				else if(token == "return"){
					cout << token << "\t<16>" << "\t关键字" << endl;
					tokens += "<16>";
				}
			}
			else {
				cout << token << "\t<00>" << "\t标识符" << endl;
				tokens += "<00>";
			}
		}
		//数字 
		else if(IF_Digit(ch)){
            string token;
            while(IF_Digit(ch)||(ch == '.'&&IF_Digit(fgetc(fpin)))){
                if(ch == '.')fseek(fpin,-1L,SEEK_CUR);
                token += ch;
                ch = fgetc(fpin);
            }
            fseek(fpin,-1L,SEEK_CUR);
            //属于无符号常数
            cout << token << "\t<03>" << "\t数字" << endl;
            tokens += "<03>";
		}
		//字符串 
		else if(ch == '"'){	
			string token;
			token += ch;
			ch = fgetc(fpin);
			while(IF_letter(ch) || IF_Digit(ch)){
			 	token += ch;
			 	ch = fgetc(fpin);
			}
			token += ch;
			cout << token << "\t<02>" << "\t字符串" << endl; 
			tokens += "<02>";
		}
		//字符 
		else if(ch == '\''){
			string token;
			token += ch;
			ch = fgetc(fpin);
			token += ch;
			ch = fgetc(fpin);
			if(ch != '\'') {
			 	cout << "请输入正确的字符形式！";
			}
			else {
			 	token += ch; 
			 	cout << token << "\t<01>" << "\t字符" << endl;
			 	tokens += "<01>";
			} 
		}
		//运算符 &界符 
		else switch(ch){
			case '>':{
				ch = fgetc(fpin);
				if(ch == '=') {
					cout << ">=" << "\t<21>" << "\t运算符" << endl;
					tokens += "<21>";
				}
				
				else {
					cout << ">" << "\t<20>" << "\t运算符"  << endl; 
					tokens += "<20>";
					fseek(fpin,-1L,SEEK_CUR);
				} 
				break;
			}
			case '<':{
				ch = fgetc(fpin);
				if(ch == '=') {
					cout << "<=" << "\t<23>" << "\t运算符" << endl;
					tokens += "<23>";
				}
				else {
					cout << "<" << "\t<22>" << "\t运算符"  << endl; 
					tokens += "<22>";
					fseek(fpin,-1L,SEEK_CUR);
				} 
				break;
			}
			case '+':{
				ch = fgetc(fpin);
				if(ch == '+'){
					cout << "++" << "\t<25>" << "\t运算符" << endl;
					tokens += "<25>";
				} 
				else if(ch == '=') {
					cout << "+=" << "\t<26>" << "\t运算符" << endl; 
					tokens += "<26>";
				}
				else {
					cout << "+" << "\t<24>" << "\t运算符"  << endl; 
					tokens += "<24>";
					fseek(fpin,-1L,SEEK_CUR);
				} 
				break;
			}
			case '-':{
				ch = fgetc(fpin);
				if(ch == '-') {
					cout << "--" << "\t<28>" << "\t运算符" << endl;
					tokens += "<28>";
				}
				else if(ch == '=') {
					cout << "-=" << "\t<29>" << "\t运算符" << endl; 
					tokens += "<29>";
				}
				else {
					cout << "-" << "\t<27>" << "\t运算符"  << endl; 
					tokens += "<27>";
					fseek(fpin,-1L,SEEK_CUR);
				} 
				break;
			}
			case '*':{
				ch = fgetc(fpin);
				if(ch == '=') {
					cout << "*=" << "\t<31>" << "\t运算符" << endl;
					tokens += "<31>";
				}
				else {
					cout << "*" << "\t<30>" << "\t运算符"  << endl; 
					tokens += "<30>";
					fseek(fpin,-1L,SEEK_CUR);
				} 
				break;
			}
            case '/':{
				ch = fgetc(fpin);
				if(ch == '=') {
					cout << "/=" << "\t<33>" << "\t运算符" << endl;
					tokens += "<33>";
				}
				else {
					cout << "/" << "\t<32>" << "PT界符"  << endl; 
					tokens += "<32>";
					fseek(fpin,-1L,SEEK_CUR);
				} 
				break;
			}
			case '{' :{
				cout << ch << "\t<34>" << "\t界符" << endl;
				tokens += "<34>";
				break;
			}
			case '}':{
				cout << ch << "\t<35>" << "\t界符" << endl;
				tokens += "<35>";
				break;
			}
			case '(':{
				cout << ch << "\t<36>" << "\t界符" << endl;
				tokens += "<36>";
				break;
			}
			case ')':{
				cout << ch << "\t<37>" << "\t界符" << endl;
				tokens += "<37>";
				break;
			}
			case '[':{
				cout << ch << "\t<38>" << "\t界符" << endl;
				tokens += "<38>";
				break;
			}
			case ']':{
				cout << ch << "\t<39>" << "\t界符" << endl;
				tokens += "<39>";
				break;
			}
			case ':':{
				cout << ch << "\t<40>" << "\t界符" << endl;
				tokens += "<40>";
				break;
			}
			case ';':{
				cout << ch << "\t<41>" << "\t界符" << endl;
				tokens += "<41>";
				break;
			}
		}
	}
}
