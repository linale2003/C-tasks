#include <iostream>
#include<math.h>

using namespace std;

float func(float x);

int factor(int s);

int main() {
	setlocale(LC_ALL, "rus");
	for (float i = -2; i <= 3; i += 0.5) {
		cout << func(i) << endl;
	}
}

float func(float x) {
	float sum = 0;
	for (float k = 1; k < 6; k++) {
		int c = k + 1;
		sum += (pow(-2, c) * factor(c)) / (pow((x + 2.5), c));
	}
	return sum;
}
int factor(int s) {
	if (s == 0 || s == 1) {
		return 1;
	}
	else {
		return s * factor(s - 1);
	}
}
