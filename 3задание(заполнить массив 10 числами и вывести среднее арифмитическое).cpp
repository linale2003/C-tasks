#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
	int arr[10];
	for(int i=0;i<10;i++){
		arr[i]=rand()%20;
		cout<<arr[i]<<endl;
	}
	
	int summ=0;
	
	for(int i=0;i<10;i++){
		summ+=arr[i];
	}
	cout<<summ/10<<endl;
	return 0;
}
