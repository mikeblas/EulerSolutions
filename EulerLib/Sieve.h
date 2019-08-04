#pragma once


#include <cassert>

class CSieve
{
public:
	CSieve(int nMaximum)
	{
		nMax = nMaximum;
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

	int nMax;
	bool *pFlags;
};

