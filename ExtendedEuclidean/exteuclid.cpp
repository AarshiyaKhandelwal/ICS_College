/*
 * exteuclid.cpp
 *
 *  Created on: 10-Sep-2018
 *      Author: Aarshiya
 */
#include<iostream>
using namespace std;
int main()
{
	int q,n1,n2,r,t1,t2,t;
	t1=0;
	t2=1;
	cout << "\n\t----------------------------\n";
	cout << "\tEXTENDED ECUCLIDEAN THM";
	cout << "\n\t----------------------------\n";
	cout<<"\n\tEnter the first number(n1): ";
	cin>>n1;
	cout<<"\n\tEnter the second number(n2): ";
	cin>>n2;
	int a=n1;
	int b=n2;
    	cout<<"\n\tq n1 n2 r t1 t2 t";
    	cout<<"\n\t_________________"<<endl;
	while(n1!=1 && n2!=0)
	{
		q=n1/n2;
		r=n1%n2;
		t=t1-q*t2;
		cout<<"\t"<<q<<" "<<n1<<" "<<n2<<" "<<r<<" "<<t1<<" "<<t2<<" "<<t<<endl;
		n1=n2;
		n2=r;
		t1=t2;
		t2=t;
	}
	cout<<"\t-----------------"<<endl;
	//cout << t1;
	cout << "\n\tgcd(" << a << ", " << b << ") = ";
	if(t1<0)
	{
		cout<<(t1+a);
	}
	else
	{
		cout<<t1;
	}
	return 0;
}

/*
OUTPUT-
	----------------------------
	EXTENDED ECUCLIDEAN THM
	----------------------------

	Enter the first number(n1): 26

	Enter the second number(n2): 11

	q n1 n2 r t1 t2 t
	_________________
	2 26 11 4 0 1 -2
	2 11 4 3 1 -2 5
	1 4 3 1 -2 5 -7
	3 3 1 0 5 -7 26
	-----------------
	gcd(26, 11) = 19
*/
