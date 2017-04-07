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

class UnexpectedException {
public:
	UnexpectedException(const char *pstr, long long val) {
		printf("%s: (%I64d)\n", pstr, val);
		exit(1);
	}
};


int main()
{
    sieve(2000000);
	printf("Sieve done\n");
	long long sum = 0;
       
	// long long limit = 999966663333LL;
	long long limit = 100;

    for (long long n = 4; n <= limit; n++)
    {
		int thisLps = lps(n);
		int thisUps = ups(n);
		printf("%I64d: %d, %d", n, thisLps, thisUps);

        int modl = n % lps(n);
        int modu = n % ups(n);
		if (modl == 0 && modu != 0 || modl != 0 && modu == 0) {
			printf(" yes");
			sum += n;
		}
		printf("\n");
    }
    
    cout << sum << endl;
    system("pause");
}

long lps(long long n)
{
     double nDbl = sqrt(double(n));
     
	 for (size_t i = lasti; i < vPrimes.size(); i++)
	 {
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

	 throw new UnexpectedException("lps exited without a decision", n);
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

	 throw new UnexpectedException("ups exited without a decision", n);
}

void sieve(long max)
{
     vector<bool> vNotPrime;
     vNotPrime.resize(max);
     
	 for (long i = 2; i < max; i++) {
         if (!vNotPrime[i])
         {
            vPrimes.push_back(i);
            for (long a = i + i; a < max; a += i)
                vNotPrime[a] = true;
         }

	 }
}
