#include<iostream>
using namespace std;
int linear(int array[], int s, int t){
	for(int i=0;i<s-1; i++){
		if(array[i] == t){
			return i;
		}
		return -1;
	}
}

int binary(int array[], int s, int t){
	int l = 0;
	int h = s-1;
	
	while(l<=h){
		int m = (l+h)/2;
		if(array[m] == t){
			return m;
		}
		else if(array[m] < t)
			l = m+1;
			
		else{
			h = m-1;
		}
	}
	return -1;
	
}

void display(int array[],int n, int t){
	cout<<"Array is:\n";
	for(int i = 0; i<n; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
}

int main(){
	int array[] = {2,6,7,9,11};
	int n = sizeof(array)/sizeof(array[0]);
	int t = 11;
	display(array,n,t);
	int f = linear(array,n,t);
	int g = binary(array,n,t);
	if(f != -1 and g != -1){
		cout<<"found the element: "<<f<<endl;
	}
	else{
		cout<<"Not found";
	}
	
}
