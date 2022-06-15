#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int Fac(int i) {
	if (i > 1) {
		return i * Fac(i-1);
	}
	else {
		return 1;
	}
}
int main () {
	ofstream myfile;
	ofstream myfile1;
	ofstream myfile2;
	ofstream myfile3;
	myfile.open("cos_f.txt");
	myfile1.open("sin_f.txt");
	myfile2.open("cos.txt");
	myfile3.open("sin.txt");
	float sins[361];
	for (int i = 0; i < 360;i++){
		float k = 0;
		k = i;
		k *= (3.1415926535/180);
		myfile1 << sin(k)<< endl;
		myfile << cos(k)<< endl;
	}
	for (int y = 0; y < 2; y++){
		for(int i = 0; i < 180; i++){
			float k = 0;
			k = i;
			k *= (3.1415926535/180);
			if ( y < 1){
				myfile3 << (k - (pow(k,3)/Fac(3)) + (pow(k,5)/Fac(5)) - (pow(k,7)/Fac(7)) + (pow(k,9)/Fac(9))) << endl; //sin < 180
				myfile2 << 1 - pow(k,2)/Fac(2) + pow(k,4)/Fac(4)  - pow(k,6)/Fac(6)  + pow(k,8)/Fac(8) << endl; //cos < 180
			}
			else{
				myfile3 << -1*((k - (pow(k,3)/Fac(3)) + (pow(k,5)/Fac(5)) - (pow(k,7)/Fac(7)) + (pow(k,9)/Fac(9)))) << endl; //sin > 180
				myfile2 << -1*(1 - pow(k,2)/Fac(2) + pow(k,4)/Fac(4)  - pow(k,6)/Fac(6)  + pow(k,8)/Fac(8)) << endl; //cos > 180
			}
		}
	}

	myfile.close();
	myfile1.close();
	myfile2.close();
	myfile3.close();
	return 0;
}
