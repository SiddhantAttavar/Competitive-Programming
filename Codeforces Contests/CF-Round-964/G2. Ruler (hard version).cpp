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
const int MOD = (int) 1e9 + 7;

int query(int a, int b) {
	print('?', a, b);
	cout.flush();
	int x;
	input(x);
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int l = 2, r = 999, res = -1;
		while (l <= r) {
			int a = l + (r - l) / 3, b = r - (r - l) / 3;
			int x = query(a, b);
			if (x == (a + 1) * (b + 1)) {
				r = a - 1;
				res = a;
			}
			else if (x == a * (b + 1)) {
				r = b - 1;
				res = b;
				l = a + 1;
			}
			else {
				l = b + 1;
			}
		}
		print('!', res);
		cout.flush();
	}
}
