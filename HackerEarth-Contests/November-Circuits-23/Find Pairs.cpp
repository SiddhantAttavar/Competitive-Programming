#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 

int32_t main() {
	setup();

	int n, l, r;
	input(n, l, r);

	ordered_set o, e;
	int res = 0;
	range(k, 0, n) {
		int x;
		input(x);

		if (x % 2 == 0) {
			int j = o.order_of_key(r - x + 1);
			int i = o.order_of_key(l - x);
			// print(x, i, j);
			res += j - i;
			e.insert(x);
		}
		else {
			int j = e.order_of_key(r - x + 1);
			int i = e.order_of_key(l - x);
			res += j - i;
			// print(x, i, j);
			o.insert(x);
		}
	}
	print(res);
}
