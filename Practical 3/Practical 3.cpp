#include<iostream>
using namespace std;

void max_heapify(int arr[],int n,int i){
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i) +2;
	if(l<n && arr[r] > arr[largest]){
		largest = l;
	}
	if(r <= n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		int t = arr[largest];
			arr[largest] = arr[i];
			arr[i] = t;
		max_heapify(arr,n,largest);
	}
}
void heapify(int arr[],int n){
	for(int i = n/2 ; i>=1; i++ ){
		max_heapify(arr,n,i);
		for(int j=n;j>=1;j++){
			int t = arr[1];
			arr[1] = arr[j];
			arr[j] = t;
		}
	}
}
void display(int arr[], int n)
{
    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){
	int arr[] = {5,6,9,7,6,56};
	int size = sizeof(arr)/sizeof(arr[0]);
	heapify(arr,size);
	display(arr, size);

	return 0;
}
