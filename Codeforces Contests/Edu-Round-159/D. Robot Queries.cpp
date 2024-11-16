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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	string s;
	input(s);

	vector<int> a(n + 1, 0);
	vector<int> b(n + 1, 0);
	map<pair<int, int>, vector<int>> m;
	m[{0, 0}] = {0};
	range(i, 0, n) {
		a[i + 1] = a[i] + (s[i] == 'R') - (s[i] == 'L');
		b[i + 1] = b[i] + (s[i] == 'U') - (s[i] == 'D');
		m[{a[i + 1], b[i + 1]}].push_back(i + 1);
	}

	while (q--) {
		int x, y, l, r;
		input(x, y, l, r);

		if (m.count({x, y}) and (m[{x, y}][0] < l or m[{x, y}].back() >= r)) {
			print("YES");
			continue;
		}

		x = a[l - 1] + a[r] - x;
		y = b[l - 1] + b[r] - y;
		if (!m.count({x, y})) {
			print("NO");
			continue;
		}

		int i = lower_bound(m[{x, y}].begin(), m[{x, y}].end(), l) - m[{x, y}].begin();
		if (i < m[{x, y}].size() and m[{x, y}][i] < r) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
