#include "treasure.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static void run_test() {
	int n;
	cin >> n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];
	vector<int> enc=encode(x,y);
	int MXV=2e9;
	for(int i=0;i<enc.size();i++)
	{
		if(enc[i]<0||enc[i]>MXV)
		{
			cout << "WA: invalid return from encode" << endl;
			exit(0);
		}
	}
	random_shuffle(enc.begin(),enc.end());
	vector<int> res=decode(enc);
	if((int)res.size()!=2*n)
	{
		cout << "WA: invalid return size from decode" << endl;
		exit(0);
	}
	vector<pair<int,int> > ret,inp;
	for(int i=0;i<n;i++)
	{
		inp.push_back({x[i],y[i]});
		ret.push_back({res[i*2],res[i*2+1]});
	}
	sort(inp.begin(),inp.end());
	sort(ret.begin(),ret.end());
	for(int i=0;i<n;i++)
	{
		if(inp[i]!=ret[i])
		{
			cout << "WA: invalid return from decode" << endl;
			exit(0);
		}
	}
	cout << "OK: " << enc.size() << endl;
}

int main() {
	int tests;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		run_test();
	}
	return 0;
}
