#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
// #define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	int N = 1e5;
	vector<set<int>> v(N + 1, {1});
	vector<int> spf(N + 1, 0);
	range(i, 1, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		for (int j : v[i / spf[i]]) {
			v[i].insert(j);
			v[i].insert(j * spf[i]);
		}

		if (spf[i] != i) {
			continue;
		}

		for (int j = i + i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n);
		arrPut(p);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			int x = __gcd(p[i], i + 1);
			a[i] = {p[i] / x, (i + 1) / x};
		}

		map<int, map<int, int>> b;
		long long res = 0;
		range(i, 0, n) {
			for (int j : v[a[i].first]) {
				if (b[a[i].second].count(j)) {
					res += b[a[i].second][j];
				}
			}
			for (int j : v[a[i].first]) {
				b[j][a[i].second]++;
			}
		}

		print(res);
	}
}
