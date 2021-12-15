#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;

void writeToOutput(string in,string out){
	ifstream indata(in);
	ofstream outdata(out);
	string line;
	while (getline(indata,line)) {
		outdata<<line<<endl;
	}
	indata.close();
}
void minify(string in,string out){
	ifstream indata(in);
	ofstream outdata(out);
	string line,spaces;
    spaces = "    ";
	stack<string> st;
	while (getline(indata,line)){
        for(int i =0;i<line.size();i++){
        /*if(line.substr(line.size()-3,2)=="\n"){
            line.erase(line.size()-3,2);
        }*/
        if(line[0]==' '){
            line.erase(0,4);
        }
        else{
            break;
        }
        }
        outdata<<line;
	}
	indata.close();
}
int main(){
	string line;
	string filenameIn ="sample.txt";
	string filenameOut ="output.txt";
	minify(filenameIn,filenameOut);
	system("pause");
	return 0;

}