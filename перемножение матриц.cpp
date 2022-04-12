#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	const int N = 3;
	int i, j, k;
	double A[N][N];
	double B[N][N];
	double C[N][N];
	srand(time(NULL));
	cout << "Matrix A:\n";
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = rand() % 20;
	cout << "Matrix B:\n";
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			B[i][j] = rand() % 20;
	cout << "Matrix C=AB:\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[i][j] = 0;
			for (k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
