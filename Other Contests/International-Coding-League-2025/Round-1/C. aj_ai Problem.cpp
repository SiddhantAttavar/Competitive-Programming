#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
// #define int long 
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);
		sort(a.begin(), a.end());

		if (n == 2) {
			while (a[1] % a[0] == 0 and a[0] > 1) {
				a[1] /= a[0];
				if (a[1] < a[0]) {
					swap(a[0], a[1]);
				}
			}

			if (a[1] % a[0]) {
				print(3);
			}
			else {
				print(a[0] + a[1]);
			}
			continue;
		}

		bool flag = true;
		int x = 0;
		rep(i, 1, n) {
			if (a[i] == a[i - 1]) {
				continue;
			}
			if (a[i] % a[i - 1]) {
				flag = false;
				break;
			}
			x = __gcd(x, a[i] / a[i - 1]);
		}

		if (!flag) {
			print(n + 1);
			continue;
		}
		if (x == 0) {
			print(n - 1 + a[0]);
			continue;
		}
		if (x == 1) {
			print(n + 1);
			continue;
		}

		while (a[0] % x == 0) {
			a[0] /= x;
		}
		if (a[0] != 1) {
			print(n + 1);
			continue;
		}

		rep(i, 1, n) {
			if (a[i] == a[i - 1]) {
				continue;
			}
			while (a[i] % x == 0) {
				a[i] /= x;
			}
			if (a[i] != 1) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print(n + 1);
		}
		else {
			print(n - 1 + x);
		}
	}
}
