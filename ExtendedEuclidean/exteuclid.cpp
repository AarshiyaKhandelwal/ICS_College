/*
 * exteuclid.cpp
 *
 *  Created on: 10-Sep-2018
 *      Author: Aarshiya
 */
#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int x, int y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1=1, y1=1;
    int gcd = gcdExtended(b%a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

int main(void)
{

    int x=1, y=1;
    int a = 0, b = 0;
    int g = 0;

    cout << "\n-------------------------------------------------";
    cout << "\n\tEXTENDED EUCLIDEAN THEOREM\n";
    cout << "-------------------------------------------------\n";
    cout << "\n\tEnter two numbers to find their GCD:\n\t";
    cin >> a >> b;
    g = gcdExtended(a, b, x, y);
    cout << "\n\tgcd("<< a << ", " << b << ") = " << g;
    return 0;
}

/*
OUTPUT-
-------------------------------------------------
	EXTENDED EUCLIDEAN THEOREM
-------------------------------------------------

	Enter two numbers to find their GCD:
	100 101

	gcd(100, 101) = 1
*/
