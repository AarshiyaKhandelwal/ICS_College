#include <bits/stdc++.h>
using namespace std;

int modfunc(int a, int m);
int arePrimePairs(vector<int> m, int n);

int main(void)
{
	int n=0;//4
	int i=0;
	int sum=0;
	int Mcap=1;
	int value=0;
	vector<int> a;//{2, 3, 0, 0};
	vector<int> m;//{3, 7, 2, 5};
	vector<int> M;
	vector<int> Minv;

	cout << "\n\n------------------------------------------------------\n";
	cout << "\tCHINESE REMAINDER THEOREM\n";
	cout << "------------------------------------------------------\n";
	cout << "\n\n\tEnter the number of congruences: ";
	cin >> n;
	cout << "\n\tEnter remainder and modulus for: " << endl;
	for(i=0; i<n; i++)
	{
		cout <<"\t" << i+1 <<") ";
		cin >> value;
		a.push_back(value);
		cin >> value;
		m.push_back(value);
		Mcap *= m[i];
	}
	if(arePrimePairs(m, n) == 1)
	{
		for(i=0; i<n; i++)
		{
			M.push_back(Mcap/m[i]);
			Minv.push_back( modfunc(M[i], m[i]) );
			sum += a[i]*M[i]*Minv[i];
		}

		sum = sum % Mcap;
		cout << "------------------------------------------------------\n";
		cout << "\t" << sum << " satisfies all the given congruences!\n";
		cout << "------------------------------------------------------\n";

		return 0;
	}
	else
	{
		cout<<"\n\tAll the moduli are not relatively prime pairs.\n\tCannot run CRT!";
	}
}

int modfunc(int a, int m)
{
	int x=0;

	for(x=1; x>=0; x++)
	{
		if((a*x)%m == 1)
			return x;
	}
	return x;
}

int arePrimePairs(vector<int> m, int n)
{
    for (int i = 0; i < n; i++)
    {
    	for(int j=i+1; j<n; j++)
    	{
    		if(i!=j)
    		{
    			if(__gcd(m[i], m[j])!=1)
    				return 0;
    		}
    	}
    }
    return 1;
}

/*
OUTPUT

------------------------------------------------------
	CHINESE REMAINDER THEOREM
------------------------------------------------------


	Enter the number of conguences: 4

	Enter remainder and modulus for: 
	1) 2 3
	2) 3 7
	3) 0 2
	4) 0 5
------------------------------------------------------
	80 satisfies all the given congruences!

------------------------------------------------------
	CHINESE REMAINDER THEOREM
------------------------------------------------------


	Enter the number of conguences: 3

	Enter remainder and modulus for: 
	1) 1 3
	2) 4 5
	3) 6 7
------------------------------------------------------
	34 satisfies all the given congruences!

------------------------------------------------------
	CHINESE REMAINDER THEOREM
------------------------------------------------------


	Enter the number of congruences: 3

	Enter remainder and modulus for: 
	1) 1 3
	2) 4 6
	3) 6 7

	All the moduli are not relatively prime pairs.
	Cannot run CRT!
*/
