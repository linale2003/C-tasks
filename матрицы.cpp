#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	const int size = 4;
	int arr[size][size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {//?????????? ??????? ?? ????? -1 ? 1
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 2;
			if (arr[i][j] == 0) {
				arr[i][j] = -1;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << '\n';
		for (int j = 0; j < size; j++) {
			cout << arr[i][j]<<"\t";
		}
	}
	int summa1 = 0;//????? ???????? ????????????
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0) {
				summa1 += arr[i][j] * arr[size - 1][j] + arr[i][j] * arr[i][size - 1];

			}
			else {
				summa1 += arr[i][j] * arr[i - 1][j] + arr[i][j] * arr[i][j - 1];
				
			}
		}
	}
	cout <<"\n" << summa1;
	return 0;
}
