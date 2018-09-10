/*
 * rsa.cpp
 *
 *  Created on: 10-Sep-2018
 *      Author: Aarshiya
 */
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j;
char en[50], m[50];
char msg[100];
int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main(void)
{
   cout << "----------------------------------------------------";
   cout << "\n\tRSA ENCRYPTION\n";
   cout << "----------------------------------------------------\n";
   cout << "\n\tENTER FIRST PRIME NUMBER: ";
   cin >> x;
   
   flag = prime(x);
   while(flag == 0)
   {
      cout <<"\n\t" << x << " IS NOT A PRIME NUMBER!;
      cout << "\n\tRE-ENTER FIRST PRIME NUMBER: ";
      cin >> x;
      flag = prime(x);
   }
   cout << "\n\tENTER SECOND PRIME NUMBER: ";
   cin >> y;

   flag = prime(y);
   while(flag == 0 || x == y)
   {
	   cout <<"\n\t" << y << " IS NOT A PRIME NUMBER OR SAME AS FIRST ONE";
	   cout << "\n\tRE-ENTER SECOND PRIME NUMBER: ";
	   cin >> y;
	   flag = prime(y);
   }

   cout << "\n\tENTER MESSAGE OR STRING TO ENCRYPT: ";
   cin >> msg;

   for(i = 0; msg[i] != '\0'; i++)
      m[i] = msg[i];
   n = x * y;
   t = (x - 1) * (y - 1);

   encryption_key();
   cout << "\n\tPOSSIBLE VALUES OF e AND d ARE\n";

   for(i = 0; i < j - 1; i++)
      cout << "\n\t" << e[i] << "\t" << d[i];

   encrypt();
   decrypt();
   return 0;
}

int prime(long int pr)
{
   int i;
   j = sqrt(pr);
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

void encryption_key()
{
   int k;
   k = 0;
   for(i = 2; i < t; i++)
   {
      if(t % i == 0)
         continue;
      flag = prime(i);
      if(flag == 1 && i != x && i != y)
      {
         e[k] = i;
         flag = cd(e[k]);
         if(flag > 0)
         {
            d[k] = flag;
            k++;
         }
         if(k == 99)
         break;
      }
   }
}

long int cd(long int a)
{
   long int k = 1;
   while(1)
   {
      k = k + t;
      if(k % a == 0)
         return(k/a);
   }
}

void encrypt()
{
   long int pt, ct, key = e[0], k, len;
   i = 0;
   len = strlen(msg);

   while(i != len)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct= k + 96;
      en[i] = ct;
      i++;
   }
   en[i] = -1;
   cout << "\n\n\tTHE ENCRYPTED MESSAGE IS: ";
   for(i=0; en[i] != -1; i++)
      cout << en[i];
}

void decrypt()
{
   long int pt, ct, key = d[0], k;
   i = 0;
   while(en[i] != -1)
   {
      ct = temp[i];
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
   }
   m[i] = -1;
   cout << "\n\n\tTHE DECRYPTED MESSAGE IS: ";
   for(i = 0; m[i] != -1; i++)
      cout << m[i];

  cout << endl;
}
