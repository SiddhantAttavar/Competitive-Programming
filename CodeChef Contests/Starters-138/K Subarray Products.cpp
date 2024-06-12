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

int solve(int l, int r, int k, int m, vector<int> &a) {
	if (r < l) {
		return 0;
	}
	if (l == r) {
		return a[l] % m;
	}

	int x = (l + r) / 2;
	int res = (solve(l, x, k, m, a) + solve(x + 1, r, k, m, a)) % m;

	vector<int> p, q;
	int c = 1;
	for (int i = x; i >= max(l, x - k + 2); i--) {
		c *= a[i];
		c %= m;
		p.push_back(c);
	}

	c = 1;
	range(i, x + 1, min(r + 1, x + k)) {
		c *= a[i];
		c %= m;
		q.push_back(c);
	}

	int y = 0;
	range(i, 0, k - p.size() - 1) {
		if (i == q.size()) {
			break;
		}
		y += q[i];
		y %= m;
	}
	for (int i = p.size() - 1; i >= 0; i--) {
		if (k - i - 2 < q.size()) {
			y += q[k - i - 2];
		}
		y %= m;
		res += p[i] * y;
		res %= m;
	}

	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k, m;
		input(n, k, m);

		vector<int> a(n);
		arrPut(a);
		print(solve(0, n - 1, k, m, a));
	}
}
