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

int solve(int i, int j, vector<string> v, int t, int k) {
	if (t == k) {
		return 1;
	}
	v[i][j] = '#';

	int res = 0;
	if (i > 0 and v[i - 1][j] == '.') {
		res += solve(i - 1, j, v, t + 1, k);
	}
	if (i < v.size() - 1 and v[i + 1][j] == '.') {
		res += solve(i + 1, j, v, t + 1, k);
	}
	if (j > 0 and v[i][j - 1] == '.') {
		res += solve(i, j - 1, v, t + 1, k);
	}
	if (j < v[i].size() - 1 and v[i][j + 1] == '.') {
		res += solve(i, j + 1, v, t + 1, k);
	}
	return res;
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<string> v(n);
	arrPut(v);

	int res = 0;
	range(i, 0, n) {
		range(j, 0, m) {
			if (v[i][j] == '#') {
				continue;
			}

			vector<string> w(v.begin(), v.end());
			res += solve(i, j, v, 0, k);
		}
	}
	print(res);
}
