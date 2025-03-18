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
	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	if (n % 2 == 0) {
		int res = 0;
		for (int i : a) {
			res |= i;
		}
		print(res);
		return 0;
	}

	vector<int> p(n + 1, 0), s(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] | a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		s[i] = s[i + 1] | a[i];
	}

	int res = 0;
	rep(i, 0, n) {
		res = max(res, p[i] | s[i + 1]);
	}
	print(res);
}
