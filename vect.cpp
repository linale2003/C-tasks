#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>


int main () {
	using namespace std;
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	vector < vector <int> > vec(7,vector<int>(7,0));
	vector < vector <int> > vec_cp(7,vector<int>(7,0));
	for ( int i = 0; i < 7; i++){
		for ( int y = 0; y < 7; y++){
			vec[i][y] = rand() % 100;
			vec_cp[i][y] = vec[i][y];
		}
	}
	for ( int i = 0; i < 7; i++){
		for ( int y = 0; y < 7; y++){
			cout << vec[i][y] << '\t';
		}//вывод матрицы
		cout <<"\n";
	}
	// заменяется главная диагональ
		int y = 6;
		int n = 0;
	for (int i = 0; i < 7; i++){
		vec[i][i] = vec_cp [y][n];
		y -= 1;
		n += 1;
	}
	//заменяется побочная диагональ
		y = 0;
		n = 0;
	for (int i = 6; i >=0; i-=1){
		vec[i][n] = vec_cp [y][y];
		y++;
		n++;
	}
	cout<<"\n";
	for ( int i = 0; i < 7; i++){
		for ( int y = 0; y < 7; y++){
			cout << vec[i][y] << '\t';
		}//вывод измененной матрицы
		cout << "\n";
	}
	return 0;
}

