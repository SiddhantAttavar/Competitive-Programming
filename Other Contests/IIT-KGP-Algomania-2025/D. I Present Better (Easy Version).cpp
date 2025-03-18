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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();
	int n, a, b;
	input(n, a, b);

	vector<int> p(n);
	arrput(p);
	p.push_back(-1);

	vector<int> f, g;
	ordered_set x;
	rep(i, 0, n + 1) {
		int k = x.order_of_key(a) - (x.size() - x.order_of_key(a + 1));
		f.push_back(k);
		x.insert(p[i]);
	}

	x.clear();
	rep(i, 0, n + 1) {
		int k = x.order_of_key(b) - (x.size() - x.order_of_key(b + 1));
		g.push_back(k);
		x.insert(p[i]);
	}

	int res = 0;
	rep(i, 0, n + 1) {
		res += (f[i] - (a < b) + (a > b)) > g[i];
		res += f[i] > (g[i] + (a < b) - (a > b));
	}

	x.clear();
	rep(i, 0, n + 1) {
		res += x.order_of_key(f[i] - (a < b) + (a > b));
		x.insert(g[i]);
	}

	x.clear();
	rep(i, 0, n + 1) {
		res += x.size() - x.order_of_key(g[i] + (a < b) - (a > b) + 1);
		x.insert(f[i]);
	}

	print(res);
}
