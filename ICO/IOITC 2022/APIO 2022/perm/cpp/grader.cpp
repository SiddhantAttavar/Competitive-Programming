#include "perm.h"
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stdlib.h>

using namespace std;

static long long MX=1e18;

static bool check_permutation(vector<int> v)
{
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		if(v[i]!=i) return 0;
	return 1;
}

long long count_increasing(const vector<int>& v) {
  vector<long long> dp(v.size() + 1, 0);
  dp[0] = 1;
  for (int x : v)
  {
  	for (int i = 0; i <= x; i++)
  	{
  		dp[x+1] += dp[i];
  		dp[x+1] = min(dp[x+1],MX+1);
  	}
  }
  long long result = 0;
  for (int i = 0; i <= (int)v.size(); i++){
  	result += dp[i];
  	result = min(result,MX+1);
  }
  return result;
}

int main() {
	int t;
	assert(1 == scanf("%d", &t));
	while(t--)
	{
		long long k;
		assert(1 == scanf("%lld",&k));
		vector<int> ret=construct_permutation(k);
		if(!check_permutation(ret))
		{
			printf("WA: Returned array is not a permutation\n");
			exit(0);
		}
		long long inc=count_increasing(ret);
		if(inc!=k)
		{
			if(inc==MX+1)
				printf("WA: Expected %lld increasing subsequences, found more than %lld\n",k, MX);
			else
				printf("WA: Expected %lld increasing subsequences, found %lld\n",k,inc);
			exit(0);
		}
		printf("%d\n",(int)ret.size());
		for(int i=0;i<ret.size();i++)
		{
			printf("%d",ret[i]);
			if(i+1==ret.size())
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
