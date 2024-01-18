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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int h, w, x, y, a, b;
		input(h, w, x, y, a, b);

		if (x > a) {
			print("Draw");
			continue;
		}

		int t = a - x;

		string win = "Bob";

		if (t % 2 == 1) {
			win = "Alice";

			x++;
			if (y < b) {
				y++;
			}
			else if (y > b) {
				y--;
			}

			swap(x, a);
			swap(y, b);
		}

		if (y == b) {
			print(win);
			continue;
		}

		if (y < b) {
			y = max(1ll, y - t / 2);
			b = max(1ll, b - t / 2);
		}
		else {
			y = min(w, y + t / 2);
			b = min(w, b + t / 2);

		}
		if (y == b) {
			print(win);
		}
		else {
			print("Draw");
		}
	}
}
