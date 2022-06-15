#include <iostream>
#include <vector>

using namespace std;

int Determinant(vector < vector <int> > &MTRX);

int Lower(int num, vector < vector <int> > &minor){	
	
	vector < vector <int> > mas(num-1, vector<int> (num-1, 0)); // Новая матрица с пониженным порядком
	
	int sum = 0; 								// Определитель
	for(int i = 0; i < num; i++){ 				// Строка, которая вычеркивается
		int z = 0;								// Координата mas'a по столбцу 
		int x = 0;								// Координата mas'a по строке 
		int k = 1; 								// Старый минор, по умолчанию равен 1, чтобы не получить 0 в слаче, если матрица 4 порядка
		for( int u = 0; u < num; u++){			// Адрес внутри столбца
			for(int y = 1; y < num; y++){ 		// Адрес внутри строки
				if (u != i){						// Понижение
					mas[z][x] = minor[u][y];		// Порядка 
					x++;							// Матрицы
					if (x == num-1){
						x = 0;
						z++;
					} 
				}
			}
		}
		k *= minor[i][0]; // Перемножает предыдущий минор с текущим
	
		// Уже есть матрица с пониженным порядком, нужно минор умножить на D этой матрицы
		
		if(i % 2 == 0){		// Проверка знака минора
			sum += k * Determinant(mas); // Возвращает произведение минора и D матрицы
		}
		else{
			sum += -1 * k * Determinant(mas);
		}
	
	}
	
	
	return sum;
}

int Determinant(vector < vector <int> > &MTRX){ // Проверяет порядок и выводит ответ
int D = 0; 

	if(MTRX.size() == 3){						
	D = 
	 (MTRX[0][0]*MTRX[1][1]*MTRX[2][2])
	+(MTRX[2][0]*MTRX[0][1]*MTRX[1][2])
	+(MTRX[1][0]*MTRX[2][1]*MTRX[0][2])
	-(MTRX[2][0]*MTRX[1][1]*MTRX[0][2])
	-(MTRX[0][0]*MTRX[2][1]*MTRX[1][2])
	-(MTRX[1][0]*MTRX[0][1]*MTRX[2][2]);	
	}
	else{
		D = Lower(MTRX.size(), MTRX);	// Должен получить целое число
	}
	return D;
}

void PrintMatrix(vector < vector <int> > &matrix, int n) // Вывод матрицы
{
	system("cls");
   for (int i = 0; i < n; i++) 
   {
        for (int j = 0; j < n; j++) 
        {
             cout << "\t" << matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
	setlocale(0, ""); 								// Ну не траслитом же писать
	int n = 0; 
	cout << "Размерность матрицы: ";
	cin >> n; 										// Ввод размерности матрицы
	vector < vector <int> > matrix(n, vector<int> (n, 0));
	PrintMatrix(matrix, n);							
	for(int i = 0; i <= n-1; i++){					// Заполнение матрицы числами
		for(int j = 0; j <= n-1; j++){
			cout << "Ввод числа << "<<"["<<i<<"]"<<"["<<j<<"]" <<": "; 
			cin >> matrix[i][j];
			PrintMatrix(matrix, n);
		}
	}
	cout << "Ответ: " << Determinant(matrix);		
}
