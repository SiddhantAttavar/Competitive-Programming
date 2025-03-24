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

	int n, m;
	input(n, m);

	vector<int> a(n);
	arrput(a);

	vector<int> b(m);
	arrput(b);

	int l = 0, r = -1;
	map<int, int> s;
	rep(i, 0, n) {
		if (r >= 0 and r < m and b[r] == a[i]) {
			r++;
		}
		if (s.count(a[i])) {
			r = max(r, s[a[i]] + 1);
		}
		if (l < m and b[l] == a[i]) {
			s[b[l]] = l;
			l++;
		}
	}

	if (r == m) {
		print("Yes");
	}
	else {
		print("No");
	}
}
