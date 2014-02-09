// Euler234.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long> vPrimes;
long lasti = 0;

void sieve(long max);
long lps(long long n);
long ups(long long n);

int main()
{
    sieve(2000000);
    long long sum = 0;
       
    for (long long n = 4; n <= 999966663333LL; n++)
    {
        int modl = n % lps(n);
        int modu = n % ups(n);
        if (modl == 0 && modu != 0 || modl != 0 && modu == 0)
           sum += n;
    }
    
    cout << sum << endl;
    system("pause");
}

long lps(long long n)
{
     double nDbl = sqrt(double(n));
     
     for (long i = lasti; i < vPrimes.size(); i++)
         if (vPrimes[i] == nDbl)
         {
            lasti = i;
            return vPrimes[i];
         }
         else if (i > 0 && nDbl > vPrimes[i - 1] && nDbl < vPrimes[i])
         {
              lasti = i;
              return vPrimes[i - 1];
         }
         else if (i > 0 && nDbl > vPrimes[i] && nDbl < vPrimes[i + 1])
         {
              lasti = i;
              return vPrimes[i];
         }
}

long ups(long long n)
{
     double nDbl = sqrt(double(n));
     
     if (vPrimes[lasti] == nDbl)
        return vPrimes[lasti];
     else if (lasti > 0 && nDbl > vPrimes[lasti - 1] && nDbl < vPrimes[lasti])
          return vPrimes[lasti];
     else if (lasti > 0 && nDbl > vPrimes[lasti] && nDbl < vPrimes[lasti + 1])
          return vPrimes[lasti + 1];
}

void sieve(long max)
{
     vector<bool> vNotPrime;
     vNotPrime.resize(max);
     
     for (long i = 2; i < max; i++)
         if (!vNotPrime[i])
         {
            vPrimes.push_back(i);
            for (long a = i + i; a < max; a += i)
                vNotPrime[a] = true;
         }
}
