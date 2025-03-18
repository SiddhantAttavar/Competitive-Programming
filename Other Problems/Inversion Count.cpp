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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int solve(vector<int> &a, int l, int r) {
	if (l == r) {
		return 0;
	}

	int m = (l + r) / 2;
	int res = solve(a, l, m) + solve(a, m + 1, r);

	int i = l, j = m + 1;
	vector<int> b;
	while (i <= m or j <= r) {
		if (j <= r and (i > m or a[j] <= a[i])) {
			b.push_back(a[j]);
			res += m - i + 1;
			j++;
		}
		else {
			b.push_back(a[i]);
			i++;
		}
	}

	rep(i, 0, b.size()) {
		a[i + l] = b[i];
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		print(solve(a, 0, n - 1));
	}
}
