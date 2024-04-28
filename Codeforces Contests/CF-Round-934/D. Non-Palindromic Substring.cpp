#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return (a * mod_pow(b, MOD - 2)) % MOD;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		string s;
		input(s);

		vector<int> a(n), b(n);
		a[0] = -1;
		range(i, 1, n) {
			if (s[i] != s[i - 1]) {
				a[i] = i - 1;
			}
			else {
				a[i] = a[i - 1];
			}
		}

		b[0] = -1;
		b[1] = -1;
		range(i, 2, n) {
			if (s[i] != s[i - 2]) {
				b[i] = i - 2;
			}
			else {
				b[i] = max(b[i - 1], b[i - 2]);
			}
		}

		vector<int> pref(n + 1), suff(n + 1);
		int p = 379;
		range(i, 0, n) {
			pref[i + 1] = (pref[i] + (s[i] - 'a') * mod_pow(p, i)) % MOD;
		}
		for (int i = n - 1; i >= 0; i--) {
			suff[i] = (suff[i + 1] + (s[i] - 'a') * mod_pow(p, n - i - 1)) % MOD;
		}

		while (q--) {
			int l, r;
			input(l, r);
			l--;
			r--;

			int k = r - l + 1;
			int res = 0;
			if (a[r] >= l) {
				int y = (k - 1) - (k - 1) % 2;
				res += max(0ll, ((y + 2) * y) / 4);
			}

			if (b[r] >= l) {
				int y = (k - 1) + (k - 1) % 2 - 1;
				res += max(0ll, ((y + 3) * (y - 1)) / 4);
			}

			int w = mod_div((pref[r + 1] - pref[l] + MOD) % MOD, mod_pow(p, l));
			int z = mod_div((suff[l] - suff[r + 1] + MOD) % MOD, mod_pow(p, n - r - 1));

			// print(w, z);
			if (w != z) {
				res += k;
			}

			print(res);
		}
	}
}
