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

int solve(vector<int> &a, int k) {
	multiset<int> m(a.begin(), a.end());
	range(i, 0, k) {
		m.insert(2 * *m.begin());
		m.erase(m.begin());
	}

	int res = 0;
	for (int i : m) {
		res = (res + i) % MOD;
	}
	return res;
}

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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);
		sort(a.begin(), a.end());

		vector<int> b(a);

		int x = 0;
		range(i, 0, n - 1) {
			while (a[i] < a.back()) {
				a[i] += a[i];
				x++;
			}
		}

		if (x > k) {
			print(solve(b, k));
			continue;
		}

		k -= x;

		int res = 0;
		for (int i : a) {
			res = (res + i) % MOD;
		}
		int t = mod_pow(2, k / n);
		res = (t * res) % MOD;
		k %= n;
		sort(a.begin(), a.end());
		range(i, 0, k) {
			res = (res + t * a[i]) % MOD;
		}
		print(res);
	}
}
