#include <iostream>
#include <vector>

using namespace std;

int Determinant(vector < vector <int> > &MTRX);

int Lower(int num, vector < vector <int> > &minor){	
	
	vector < vector <int> > mas(num-1, vector<int> (num-1, 0)); // ����� ������� � ���������� ��������
	
	int sum = 0; 								// ������������
	for(int i = 0; i < num; i++){ 				// ������, ������� �������������
		int z = 0;								// ���������� mas'a �� ������� 
		int x = 0;								// ���������� mas'a �� ������ 
		int k = 1; 								// ������ �����, �� ��������� ����� 1, ����� �� �������� 0 � �����, ���� ������� 4 �������
		for( int u = 0; u < num; u++){			// ����� ������ �������
			for(int y = 1; y < num; y++){ 		// ����� ������ ������
				if (u != i){						// ���������
					mas[z][x] = minor[u][y];		// ������� 
					x++;							// �������
					if (x == num-1){
						x = 0;
						z++;
					} 
				}
			}
		}
		k *= minor[i][0]; // ����������� ���������� ����� � �������
	
		// ��� ���� ������� � ���������� ��������, ����� ����� �������� �� D ���� �������
		
		if(i % 2 == 0){		// �������� ����� ������
			sum += k * Determinant(mas); // ���������� ������������ ������ � D �������
		}
		else{
			sum += -1 * k * Determinant(mas);
		}
	
	}
	
	
	return sum;
}

int Determinant(vector < vector <int> > &MTRX){ // ��������� ������� � ������� �����
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
		D = Lower(MTRX.size(), MTRX);	// ������ �������� ����� �����
	}
	return D;
}

void PrintMatrix(vector < vector <int> > &matrix, int n) // ����� �������
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
	setlocale(0, ""); 								// �� �� ��������� �� ������
	int n = 0; 
	cout << "����������� �������: ";
	cin >> n; 										// ���� ����������� �������
	vector < vector <int> > matrix(n, vector<int> (n, 0));
	PrintMatrix(matrix, n);							
	for(int i = 0; i <= n-1; i++){					// ���������� ������� �������
		for(int j = 0; j <= n-1; j++){
			cout << "���� ����� << "<<"["<<i<<"]"<<"["<<j<<"]" <<": "; 
			cin >> matrix[i][j];
			PrintMatrix(matrix, n);
		}
	}
	cout << "�����: " << Determinant(matrix);		
}
