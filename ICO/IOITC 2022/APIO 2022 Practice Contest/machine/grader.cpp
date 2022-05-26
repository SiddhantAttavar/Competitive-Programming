#include <bits/stdc++.h>
#include "machine.h"

using namespace std;


static int n,x;
static int qs,mx;
static vector<int> p;
static void WA(string s)
{
	cout << "WA: " << s << endl;
	exit(0);
}


vector<int> use_machine(vector<int> v)
{
	if(v.size()!=n) WA("size of queried array is not n");
	vector<int> ret;
	qs++;
	for(int i=0;i<n;i++)
	{
		ret.push_back(v[p[i]]^x);
		mx=max(mx,v[i]);
	}
	return ret;
}

int main()
{
	int t;
	assert(1 == scanf("%d",&t));
	while(t--)
	{
		assert(2 == scanf("%d %d",&n,&x));
		p=vector<int>(n);
		for(int i=0;i<n;i++)
			assert(1 == scanf("%d",&p[i]));
		vector<int> ret=guess_permutation(n);
		if(ret.size()!=n) WA("size of answer is not n");
		for(int i=0;i<n;i++)
			if(ret[i]!=p[i]) WA("Invalid guess");
		printf("OK: %d %d\n",qs, mx);
		mx=0; qs=0;
	}
}