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

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<int> p(n);
	arrput(p);

	map<int, int> m;
	vector<bool> v(n, false);
	rep(i, 0, n) {
		int u = i, c = 0;
		while (!v[u]) {
			c++;
			v[u] = true;
			u = p[u] - 1;
		}
		if (c > 0) {
			m[c]++;
		}
	}

	int x = 0;
	for (pair<int, int> p : m) {
		x += (p.first / 2) * p.second;
	}
	x = min(n, min(x, k) + k);

	vector<int> a;
	for (pair<int, int> p : m) {
		int x = 0, y = 0;
		while (y + (x + 1) <= p.second) {
			x++;
			y += x;
			a.push_back(p.first * x);
		}
		rep(i, y, p.second) {
			a.push_back(p.first);
		}
	}

	const int N = 1e6;
	bitset<N> b = 1;
	for (int i : a) {
		b = b | (b << i);
	}

	print(k + !b[k], x);
}
