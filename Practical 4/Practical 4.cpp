#include<iostream>
using namespace std;

int fact_iterative(int num){
	int fact = 1;
	if(num == 0)
		return 1;
	for(int i=num; i>=1; i--){
		fact = fact*i;
	}
	return fact;
}
int fact_recursive(int num){
	int fact = 1;
	if(num == 0)
		return 1;
	while(num >= 1){
		fact = fact*num;
		num--;
		fact_recursive(num);
	}
	return fact;
}

int main(){
	cout<<"----------------Factorical-----------------------"<<endl;
	int n;
	cout<<"Enter your number: ";
	cin>>n;
	int i = fact_iterative(n);
	
	cout<<"Iterative method:"<<endl;
	cout<<n<<" factorical is "<<i;
	cout<<endl<<endl;
	int r = fact_recursive(n);
	cout<<"Recursive method:"<<endl;
	cout<<n<<" factorical is "<<r;
	
	return 0;
}
