#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL,"rus");
    int n, reverse = 0, rem;
    cout << "Enter a number: ";
    cin >> n;
    while (n > 0) {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }
    cout << "Reversed Number: " << reverse << endl;
    if(reverse==n){
    	cout<<"числа равны"<<endl;
    }
    else{
    	cout<<"числа не равны"<<endl;
    }
    return 0;
}

