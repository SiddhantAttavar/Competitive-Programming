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
	
	int dp[n];
	range(i, 0, n) {
		dp[i] = 1;
		range(j, 0, i) {
			if (a[i] % a[j] == 0) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	print(*max_element(dp, dp + n));
}