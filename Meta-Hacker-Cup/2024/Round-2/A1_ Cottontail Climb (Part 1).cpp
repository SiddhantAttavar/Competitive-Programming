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

bool check(int l, int r, int a, int b, int m) {
	int x = 0;
	range(i, l, r) {
		x = x * 10 + i;
	}
	for (int i = r; i >= l; i--) {
		x = x * 10 + i;
	}
	return x % m == 0 and x >= a and x <= b;
}

int32_t main() {
	setup(); int tc; input(tc); range(t, 0, tc) {
		int a, b, m;
		input(a, b, m);

		int res = 0;
		range(i, 1, 10) {
			range(j, i, 10) {
				res += check(i, j, a, b, m);
			}
		}

		cout << "Case #" << t + 1 << ": " << res << '\n';
	}
}
