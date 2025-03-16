#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 1e4 + 10;
vector<bitset<N>> solve(vector<int> &a, int n) {
	vector<bitset<N>> dp(n + 1);
	dp[0][0] = true;
	for (int i : a) {
		for (int k = n; k > 0; k--) {
			dp[k] |= dp[k - 1] << i;
		}
	}
	return dp;
}

int32_t main() {
	setup();
	string s;
	input(s);

	int n = s.size();

	int a = 0, b = 0;
	int x = 0, y = 0;
	rep(i, 0, n) {
		if (s[i] == '0') {
			x += b;
			a++;
		}
		else {
			y += a;
			b++;
		}
	}

	vector<int> p, q;
	rep(i, 0, n) {
		if (s[i] == '0') {
			p.push_back(i);
		}
		else {
			q.push_back(i);
		}
	}
	// print(y - x);

	vector<bitset<N>> f = solve(p, n);
	vector<bitset<N>> g = solve(q, n);

	// print(f[1]);
	// print(g[1]);

	int z = (y - x) / 2;
	rep(k, 0, n + 1) {
		if ((z >= 0 and (g[k] & (f[k] << z)).any()) or (z < 0 and ((g[k] << -z) & f[k]).any())) {
			print(k);
			break;
		}
	}
}
