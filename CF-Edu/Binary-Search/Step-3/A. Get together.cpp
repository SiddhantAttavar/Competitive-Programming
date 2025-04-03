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

const double e = 1e-7;

bool solve(double t, vector<int> &x, vector<int> &v) {
	double l = -1e19, r = 1e19;
	range(i, 0, x.size()) {
		l = max(l, x[i] - t * v[i]);
		r = min(r, x[i] + t * v[i]);
	}
	return l <= r;
}

int32_t main() {
	setup();
	cout << setprecision(20);

	int n;
	input(n);

	vector<int> x(n), v(n);
	range(i, 0, n) {
		input(x[i], v[i]);
	}

	double l = 0, r = 3e9, res = 3e9;
	while ((r - l) > e) {
		double m = (l + r) / 2;
		if (solve(m, x, v)) {
			res = m;
			r = m - e;
		}
		else {
			l = m + e;
		}
	}
	print(res);
}
