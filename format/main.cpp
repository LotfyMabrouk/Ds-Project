#include"format.h"
using namespace std;


int main() {
	string line;
	string filenameIn = "sample.txt";
	string filenameOut = "output.txt";
	writeToOutput(filenameIn, filenameOut);
	format(filenameIn, filenameOut);
	system("pause");
	return 0;
}