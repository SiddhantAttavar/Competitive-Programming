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

int count(int n) {
	int x = 0;
	range(i, 0, 60) {
		x += (n >> i) & 1;
	}
	return x;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (count(n) % 2 == 0) {
			print("first");

			for (int i = 59; i >= 0; i--) {
				if ((1ll << i) & n) {
					print(1ll << i, n ^ (1ll << i));
					break;
				}
			}
		}
		else {
			print("second");
		}

		while (true) {
			int x, y;
			input(x, y);

			if (x == -1) {
				return 0;
			}

			if (x == 0) {
				break;
			}

			if (count(x) % 2) {
				x = y;
			}

			for (int i = 59; i >= 0; i--) {
				if ((1ll << i) & x) {
					print(1ll << i, x ^ (1ll << i));
					break;
				}
			}
		}
	}
}
