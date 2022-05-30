#include "mars.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>

using namespace std;

static void WA(string msg)
{
	cout << "WA: " << msg << endl;
	exit(0);
}

static long long to_longlong(string s)
{
  long long ans=0;
  for(int i=(int)s.size()-1;i>=0;i--)
    ans=(ans*2)+s[i]-'0';
  return ans;
}

int main()
{
	int t;
	assert(scanf("%d",&t) == 1);
	while(t--)
	{
		int n;
		assert(scanf("%d",&n) == 1);

		vector <vector<char>> s(2*n+1, vector<char>(2*n+1));
		for(int i = 0; i < 2*n+1; i++)
			for(int j = 0; j < 2*n+1; j++)
				assert(scanf(" %c",&s[i][j]) == 1);

		vector <vector<string>> h(2*n+1, vector<string>(2*n+1, string(100 ,'0')));
		for(int i = 0; i < 2*n+1; i++)
			for(int j = 0; j < 2*n+1; j++)
				h[i][j][0] = s[i][j];

		vector <vector<string>> subarr(3, vector<string>(3));
		for(int k = 0; k < n; k++)
		{
			int m = 2*(n-k-1);
			for(int i = 0; i <= m; i++)
			{
				for(int j = 0; j <= m; j++)
				{
					for(int y = 0; y < 3; y++)
					{
						for(int x = 0; x < 3; x++)
						{
							subarr[y][x] = h[i+y][j+x];
						}
					}
					h[i][j] = process(subarr, i, j, k, n);

					if(h[i][j].size() != 100) WA("Invalid return length");
					for(int l = 0; l < 100; l++)
						if(h[i][j][l] != '0' && h[i][j][l] != '1') WA("Invalid return");
				}
			}
		}

		printf("%lld\n",to_longlong(h[0][0]));
	}
}
