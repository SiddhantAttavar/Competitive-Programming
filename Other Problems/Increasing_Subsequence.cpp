#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, n);
	arrput(int, a, n);
	
	vector<int> dp;
	for (int i : a) {
		int j = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (j == dp.size()) {
			dp.push_back(i);
		}
		else {
			dp[j] = i;
		}
	}

	print(dp.size());
}
