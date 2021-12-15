#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	ifstream indata;
	indata.open("trial.txt");
	ofstream outdata;
	outdata.open("output.txt");
	if(indata.is_open()){
		while(getline(indata ,s)){
			for(int i=0 ; i<s.length() ; i++){
	
		
			if(s[0] == ' '){
				s.erase(0 ,4);
			}
		
				else {
				break;
			}
			}
			outdata << s;

	
		}
	
	indata.close();
	return 0;

	}
}
