#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
template<typename T> inline void print(T x) {cout << x << endl;}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << endl;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	const int MOD = 1e9 + 7;

	int n;
	input(n);
	vector<int> a(n);
	arrPut(a);

	vector<int> l(n), r(n);
	stack<int> s;
	range(i, 0, n) {
		while (!s.empty() and a[i] <= a[s.top()]) {
			s.pop();
		}
		
		if (s.empty()) {
			l[i] = -1;
		}
		else {
			l[i] = s.top();
		}
		s.push(i);
	}

	while (!s.empty()) {
		s.pop();
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and a[i] <= a[s.top()]) {
			s.pop();
		}
		
		if (s.empty()) {
			r[i] = n;
		}
		else {
			r[i] = s.top();
		}
		s.push(i);
	}
	// arrPrint(l);
	// arrPrint(r);

	vector<vector<int>> dp(n, vector<int>(n));
	range(i, 0, n) {
		range(j, 0, n) {
			if (j > 0) {
				dp[i][j] = dp[i][j - 1];
			}
			if (l[j] < i and i < r[j]) {
				if (i == 0) {
					dp[i][j] = (dp[i][j] + 1) % MOD;
				}
				else {
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				}
			}
		}
	}
	// range(i, 0, n) {
	// 	arrPrint(dp[i]);
	// }
	print(dp[n - 1][n - 1]);
}
