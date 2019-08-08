#pragma once


#include <cassert>
#include <set>

class CSieve
{
public:

	// build a sieve of primes from 0 .. nMaximum, inclusive
	CSieve(int nMaximum)
	{
		nMax = nMaximum+1;
		pFlags = new bool[nMax];

		for (int n = 0; n < nMax; n++)
		{
			pFlags[n] = true;
		}

		pFlags[0] = false;
		pFlags[1] = false;
		pFlags[2] = true;
		pFlags[3] = true;

		walkInterval(2);

		for (int nInterval = 3; nInterval <= nMax / 2; nInterval += 2)
		{
			walkInterval(nInterval);
		}
	}

	~CSieve()
	{
		delete[] pFlags;
	}

	void walkInterval(int nInterval)
	{
		for (int n = nInterval * 2; n < nMax; n += nInterval)
		{
			pFlags[n] = false;
		}
	}

	bool isPrime(int n)
	{
		assert(n < nMax);
		assert(n >= 0);

		return pFlags[n];
	}

	// get the first prime greater than n
	// returns -1 if we don't know it
	int getNextPrime(int n)
	{
		for (int m = n + 1; m < nMax; m++)
		{
			if (isPrime(m))
				return m;
		}

		return -1;
	}

	// return a set of all primes between low and high, inclusive
	std::set<int> getPrimesInRange(int low, int high)
	{
		assert(low >= 0);
		assert(low <= high);
		assert(high < nMax);

		std::set<int> sp;

		for (int n = low; n <= high; n++)
		{
			if (isPrime(n))
				sp.insert(n);
		}

		return sp;
	}

private:
	int nMax;
	bool *pFlags;
};

