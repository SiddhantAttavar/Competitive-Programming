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

	int n, x;
	input(n, x);

	vector<int> a(n);
	arrput(a);

	if (n == 1) {
		print(a[0] == x);
		return 0;
	}

	vector<int> p(1 << (n / 2)), q(1 << ((n + 1) / 2));
	rep(i, 1, 1 << (n / 2)) {
		int j = 63 - __builtin_clzll(i);
		p[i] = p[i ^ (1 << j)] + a[j];
	}
	rep(i, 1, 1 << ((n + 1) / 2)) {
		int j = 63 - __builtin_clzll(i);
		q[i] = q[i ^ (1 << j)] + a[j + (n / 2)];
	}

	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	int l = q.size(), r = q.size(), res = 0;
	for (int i : p) {
		while (l > 0 and q[l - 1] >= x - i) {
			l--;
		}
		while (r > 0 and q[r - 1] > x - i) {
			r--;
		}
		res += r - l;
	}
	print(res);
}
