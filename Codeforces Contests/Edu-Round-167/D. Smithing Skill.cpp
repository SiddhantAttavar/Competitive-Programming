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

int32_t main() {
	int N = 1e6;
	setup();
	int n, m;
	input(n, m);

	vector<int> a(n), b(n), c(m);
	arrPut(a);
	arrPut(b);
	arrPut(c);

	vector<pair<int, int>> v(n);
	range(i, 0, n) {
		v[i] = {a[i], a[i] - b[i]};
	}

	sort(v.begin(), v.end());
	range(i, 1, n) {
		v[i].second = min(v[i].second, v[i - 1].second);
	}

	vector<int> dp(N + 1, 0);
	int x = 0;
	int i = 0;
	range(j, v[0].first, N + 1) {
		while (i < n - 1 and j == v[i + 1].first) {
			i++;
		}
		int k = (j - v[i].first) / v[i].second + 1;
		dp[j] = dp[j - k * v[i].second] + k;
	}

	int res = 0;
	for (int j : c) {
		if (j <= N) {
			res += dp[j];
		}
		else {
			int k = (j - v[n - 1].first) / v[n - 1].second + 1;
			res += dp[j - k * v[i].second] + k;
		}
	}

	print(res * 2);
}
