#include<iostream>
using namespace std;

class classname{
	public:
		void Func(){
		int array1[100];
		int input,i;
		cout<<"Enter the size of array: ";
		cin>>input;
		array1[input];
		cout<<"Enter the Elements in array:\n";
		for(int i=0; i< input; i++){
			cin>>array1[i];
		}
		int n = sizeof(array1)/sizeof(array1[0]);
		display(array1,input);
		cout<<"\n\n";
		Bubble(array1,input);
		cout<<"\n\n";
		selection(array1,input);
		cout<<"\n\n";
		insertion(array1,input);
		cout<<"\n\n";
	//	quickSort(array1, 0, n-1);
	}
	void display(int array1[],int n){
		cout<<"Your Array is:\n";
		for(int i = 0; i<n; i++){
			cout<<array1[i]<<" ";
		}
		
	}
	void Bubble(int array1[],int n){
		cout<<"Bubble sorted array:\n";
		for(int i=0;i<n;i++){
			for(int j=0; j<n-i-1; j++){
				if(array1[j] > array1[j+1]){
					int temp = array1[j];
					array1[j] = array1[j+1];
					array1[j+1] = temp;
				}
			
			}
		}
		display(array1,n);
	}
	void selection(int array1[],int n){
		cout<<"selection sort Array:\n";
		for(int i = 0; i<n; i++){
			int min = i;
			for(int j=i+1; j<n; j++){
				if(array1[j] < array1[min]){
					min = j;
			}
			if(min != 0){
				int temp = array1[i];
				array1[i] = array1[min];
				array1[min] = temp;
			}
		}
	}
	display(array1,n);
}
	
	void insertion(int array1[],int n){
	cout<<"insertion sort Array:\n";
	for(int i=1;i<n;i++){
		int temp = array1[i];
		int j = i-1;
		while(j>=0 && array1[j]>temp){
			array1[j+1] = array1[j];
			j=j-1;
		}
		array1[j+1] = temp;
		
	}
	display(array1,n);
}

int main(){
	classname obj;
	obj.Func();	
	return 0;
}




