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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, c;
		input(n, c);

		vector<int> a(n);
		arrPut(a);

		int res = (c + 1) * (c + 2) / 2;
		for (int i : a) {
			res -= c - i + 1;
			res -= i / 2 + 1;
		}

		int x = 0, y = 0;
		for (int i : a) {
			x += i & 1;
			y += 1 - i & 1;
		}
		
		for (int i : a) {
			if (i & 1) {
				res += x;
				x--;
			}
			else {
				res += y;
				y--;
			}
		}

		print(res);
	}
}
