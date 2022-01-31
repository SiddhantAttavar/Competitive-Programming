#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int modPow(int a, int b, int m) {
	int res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

int32_t main() {
	setup();
	
	const int m = 998244353;
	int n, k;
	input(n, k);
	vector<int> a(n);
	arrPut(a);

	if (n == k) {
		print(modPow(2, n - 1, m));
		return 0;
	}

	if (count(a.begin(), a.end(), 1) == n) {
		print(modPow(2, n - 1, m));
		return 0;
	}

	vector<vector<bool>> valid(n, vector<bool>(n));
	range(i, 0, n) {
		map<int, int> map;
		int c = 0;
		range(j, i, n) {
			if (!map.count(a[j])) {
				c++;
			}
			else if (map[a[j]] == 1) {
				c--;
			}
			map[a[j]]++;
			if (c <= k) {
				valid[i][j] = true;
			}
		}
	}

	vector<int> dp(n);
	dp[0] = 1;
	range(i, 1, n) {
		if (valid[0][i]) {
			dp[i] = 1;
		}
		range(j, 0, i) {
			if (valid[j + 1][i]) {
				dp[i] += dp[j];
				dp[i] %= m;
			}
		}
	}
	print(dp[n - 1]);
}
