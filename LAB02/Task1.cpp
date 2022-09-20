#include <iostream>
#include <string>
using namespace std;

int main()
{

int a, *p, *q;
	int arr[4]= {0};

	p=arr;
	q=p;

	*p=4;

	for(int i=0; i<3; i++){
			a=*p;
			p++;
			*p=(a+i);
	}
	for (int j=0; j<4; j++){
			cout<<*q<<" ";
			q++;
	}


    return 0;
}