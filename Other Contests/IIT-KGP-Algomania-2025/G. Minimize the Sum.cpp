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

	string s;
	input(s);

	vector<int> a(n);
	arrput(a);

	vector<int> f(n + 1, 0), g(n + 1, 0), h(n + 1, 0);
	int j = n, l = n;
	for (int i = n - 1; i >= 0; i--) {
		int r = min(n, i + k);
		if (j >= r) {
			l = r;
		}
		g[i] = min(f[l], g[i + 1] + a[i]);
		if (s[i] == '1') {
			f[i] = g[i];
			j = i;
		}
		else {
			f[i] = f[i + 1] + a[i];
		}
	}
	arrprint(a);
	arrprint(f);
	arrprint(g);

	print(f[0]);
}
