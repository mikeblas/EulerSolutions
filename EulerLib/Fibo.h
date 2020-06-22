
#include <cassert>


template <int C>
class CFibo
{
public:
	int nLength;
	int nMaxLength;

	typedef unsigned char byte;

	byte* bDigits;


	CFibo()
	{
		nMaxLength = C;
		bDigits = new byte[C];
	}

	~CFibo()
	{
		delete[] bDigits;
	}

	void set(int n)
	{
		nLength = 0;
		bDigits[0] = 0;

		while (n > 0)
		{
			bDigits[nLength++] = n % 10;
			n = n / 10;
		}
	}

	static void add(CFibo &sum, CFibo &a, CFibo &b)
	{
		int nMax = (a.nLength > b.nLength) ? a.nLength : b.nLength;
		byte carry = 0;
		for (int n = 0; n < nMax; n++)
		{
			byte tsum = 0;
			if (n < a.nLength) tsum += a.bDigits[n];
			if (n < b.nLength) tsum += b.bDigits[n];
			tsum += carry;
			if (tsum >= 10) { tsum -= 10; carry = 1; }
			else carry = 0;

			sum.bDigits[n] = tsum;
		}

		if (carry == 0)
			sum.nLength = nMax;
		else
		{
			sum.nLength = nMax + 1;
			sum.bDigits[nMax] = carry;
		}

		if (sum.nMaxLength <= sum.nLength) {
			printf("Max length exceeded %d\n", sum.nMaxLength);
			exit(1);
		}
	}

	static void multiply(CFibo &product, CFibo &factor, byte b)
	{
		byte carry = 0;
		for (int n = 0; n < factor.nLength; n++)
		{
			byte tprod = factor.bDigits[n] * b;
			tprod += carry;
			if (tprod >= 10) { carry = tprod / 10; tprod = tprod % 10; }
			else carry = 0;

			product.bDigits[n] = tprod;
		}

		if (carry == 0)
			product.nLength = factor.nLength;
		else
		{
			product.nLength = factor.nLength + 1;
			product.bDigits[factor.nLength] = carry;
		}
	}

	static void shift(CFibo &target, int nPositions)
	{
		if (nPositions == 0)
			return;
		if (target.isZero())
			return;

		for (int n = target.nLength - 1; n >= 0; n--)
		{
			target.bDigits[n + nPositions] = target.bDigits[n];
		}
		for (int n = 0; n < nPositions; n++)
		{
			target.bDigits[n] = 0;
		}
		target.nLength = target.nLength + nPositions;

		assert(target.nMaxLength <= target.nLength);

		return;
	}

	bool isZero()
	{
		if (nLength == 0)
			return true;
		if (nLength == 1 && bDigits[0] == 0)
			return true;
		return false;
	}

	static void multiply(CFibo &product, CFibo &a, CFibo &b)
	{
		product.set(0);
		CFibo temp;
		for (int nb = 0; nb < b.nLength; nb++)
		{
			multiply(temp, a, b.bDigits[nb]);
			shift(temp, nb);
			add(product, product, temp);
		}
	}
};

typedef CFibo<2000> CFibo2K;
typedef CFibo<1000000> CFibo1M;
