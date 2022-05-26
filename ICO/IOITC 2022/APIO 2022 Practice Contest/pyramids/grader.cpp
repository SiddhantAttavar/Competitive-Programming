#include "pyramids.h"
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main() {
	int n,q;
	assert(2 == scanf("%d %d",&n,&q));
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
		assert(1 == scanf("%d",&a[i]));
	for(int i=0;i<n;i++)
		assert(1 == scanf("%d",&b[i]));
	init(a,b);
	while(q--)
	{
		int l1,r1,l2,r2;
		assert(4 == scanf("%d %d %d %d",&l1,&r1,&l2,&r2));
		printf("%d\n",can_convert(l1,r1,l2,r2));
	}
	return 0;
}
