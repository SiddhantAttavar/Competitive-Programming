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
		int n, a, b;
		input(n, a, b);

		if (a == b) {
			print(n / a);
			continue;
		}

		if (a > b) {
			swap(a, b);
		}

		if (n < a) {
			print(0);
			continue;
		}

		int k = n % a;
		int t = a - 1;
		if (n / a <= k) {
			t = n / a;
		}
		else if (n / a - 1 < a - 1) {
			t = n / a - 1;
		}

		print(min(t + 1, k + 1) * (n / a) + max(0ll, t - k) * (n / a - 1) - t * (t - 1) / 2);
	}
}
