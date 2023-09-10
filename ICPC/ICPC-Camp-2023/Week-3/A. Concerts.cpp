#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();
	int k, n;
	input(k, n);

	vector<int> h(26);
	arrPut(h);

	string s, t;
	input(s, t);

	vector<vector<int>> v(26);
	range(i, 0, n) {
		v[t[i] - 'A'].push_back(i);
	}

	vector<int> dp(n, 0);
	vector<int> l;
	range(i, 0, n) {
		if (t[i] == s[0]) {
			dp[i] = 1;
			l.push_back(i);
		}
	}

	range(j, 1, k) {
		vector<int> nl, ndp(n, 0);
		range(i, 0, n) {
			if (t[i] == s[j]) {
				nl.push_back(i);
			}
		}

		int x = 0;
		int p = 0;
		for (int i : nl) {
			while (x < (int) l.size() and i - l[x] > h[t[l[x]] - 'A']) {
				p += dp[l[x]];
				p %= MOD;
				x++;
			}
			ndp[i] = p;
		}

		l = nl;
		dp = ndp;
	}

	int res = 0;
	for (int i : l) {
		res += dp[i];
		res %= MOD;
	}
	print(res);
}
