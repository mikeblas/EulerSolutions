// Euler038.cpp : Solution for Project Euler problem #38
//

#include "pch.h"

int main()
{
	static const std::string strStarts{ "1234567890" };
	static const std::string strEnds{ "999999999" };

	int best = 0;

	for (int nStartLen = 1; nStartLen < 9; nStartLen++)
	{
		int nStart = atoi(strStarts.substr(0, nStartLen).c_str());
		int nEnd = atoi(strEnds.substr(0, nStartLen).c_str());
		printf("%d to %d\n", nStart, nEnd);


		for (int n = nEnd; n >= nStart; n--)
		{
			char sz[15] = "";
			bool bFlags[10] = { false };

			char* dest = sz;

			int nBy = 1;
			bool bFailed = false;
			while (strlen(sz) < 9 && !bFailed)
			{
				int nSet = nBy * n;
				char szPart[10];
				int nPartLen = sprintf_s(szPart, "%d", nSet);

				for (int m = 0; m < nPartLen; m++)
				{
					int nDigit = szPart[m] - '0';
					if (nDigit == 0)
					{
						bFailed = true;
						break;
					}

					if (bFlags[nDigit])
					{
						bFailed = true;
						break;
					}

					*dest = szPart[m];
					dest++;
					*dest = 0;
					bFlags[nDigit] = true;
				}

				nBy++;
			}

			if (strlen(sz) > 9)
				bFailed = true;

			for (int m = 1; m <= 9; m++)
			{
				if (!bFlags[m])
				{
					bFailed = true;
					break;
				}
			}

			if (!bFailed)
			{
				printf("%s\n", sz);
				int result = atoi(sz);
				best = std::max(result, best);
				break;
			}
		}
	}

	printf("Best found is %d\n", best);

	return 0;
}


