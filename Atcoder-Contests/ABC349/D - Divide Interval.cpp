#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int l, r;
	input(l, r);

	int x = r - l;
	vector<pair<int, int>> res;
	while (l < r) {
		int k = 0;
		int x = l;
		if (x == 0) {
			k = 60;
		}

		while (x > 0 and x % 2 == 0) {
			x >>= 1;
			k++;
		}

		while ((l + (1ll << k)) > r) {
			k--;
		}

		res.push_back({l, l + (1ll << k)});
		l += 1ll << k;
	}

	print(res.size());
	for (pair<int, int> p : res) {
		print(p.first, p.second);
	}
}
