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

const int MOD = 998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		int n = s.size();
		int x = 0;
		vector<int> dp(n, 1);
		range(i, 1, n) {
			x += s[i] == s[i - 1];
		}

		int y = 1;
		int c = 1;
		int z = 0;
		range(i, 1, n) {
			if (s[i] != s[i - 1]) {
				y = (y * c) % MOD;
				z += c - 1;
				c = 0;
			}
			c++;
		}
		y = (y * c) % MOD;
		z += c - 1;

		int res = y;
		range(i, 2, z + 1) {
			res = (res * i) % MOD;
		}

		print(x, res);
	}
}
