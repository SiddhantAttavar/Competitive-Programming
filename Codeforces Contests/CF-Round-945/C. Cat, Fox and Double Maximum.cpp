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

int check(vector<int> &p, vector<int> &q) {
	vector<int> a(p.size());
	range(i, 0, p.size()) {
		a[i] = p[i] + q[i];
	}

	int res = 0;
	range(i, 1, p.size() - 1) {
		res += a[i] > max(a[i - 1], a[i + 1]);
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<pair<int, int>> b, c;
		for (int i = 1; i < n - 1; i += 2) {
			b.push_back({a[i], i});
		}
		for (int i = 0; i < n; i += 2) {
			c.push_back({a[i], i});
		}
		c.push_back({a[n - 1], n - 1});
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());

		vector<int> res(n);
		range(i, 0, b.size()) {
			res[b[i].second] = n - i;
		}
		range(i, 0, c.size()) {
			res[c[i].second] = i + 1;
		}

		if (check(res, a) == n / 2 - 1) {
			arrPrint(res);
			continue;
		}

		b.clear();
		c.clear();
		for (int i = 2; i < n; i += 2) {
			b.push_back({a[i], i});
		}
		for (int i = 1; i < n; i += 2) {
			c.push_back({a[i], i});
		}
		c.push_back({a[0], 0});
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());

		range(i, 0, b.size()) {
			res[b[i].second] = n - i;
		}
		range(i, 0, c.size()) {
			res[c[i].second] = i + 1;
		}
		
		arrPrint(res);
		assert(check(res, a) == n / 2 - 1);
	}
}
