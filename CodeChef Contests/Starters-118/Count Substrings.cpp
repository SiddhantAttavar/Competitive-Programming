#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

vector<int> kmp(string s) {
	int N = s.size();
	vector<int> f(N + 1, 0);
	f[0] = -1;

	range(i, 1, N + 1) {
		for (f[i] = f[i - 1]; f[i] != -1 and s[f[i]] != s[i - 1]; f[i] = f[f[i]]);
		f[i]++;
	}

	return f;
}

int getOc(string a, string b) {
	vector<int> f = kmp(a + "@" + b);
	int res = 0;
	range(i, a.size(), b.size() + 1) {
		if (f[i + a.size() + 1] == (int) a.size()) {
			res++;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		string s;
		input(s);

		int x = 1, y = k - 1, z = 2;
		while (y) {
			if (y & 1) {
				x = (x * z) % MOD;
			}

			z = (z * z) % MOD;
			y >>= 1;
		}

		string t(s.begin(), s.end());
		reverse(t.begin(), t.end());
		print(((x * getOc(s, s + t)) % MOD + ((x + MOD - 1) * getOc(s, t.substr(1, n - 1) + s.substr(0, n - 1))) % MOD) % MOD);
	}
}
