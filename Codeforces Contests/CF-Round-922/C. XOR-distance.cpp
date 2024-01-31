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

int solve(int a, int b, int r, int i) {
	if (i < 0) {
		return 0;
	}

	if (!((1ll << i) & r)) {
		return solve(a, b, r, i - 1);
	}

	if (((1ll << i) & a) == ((1ll << i) & b)) {
		return solve(a, b, (1ll << i) - 1, i - 1);
	}

	if ((1ll << i) & a) {
		return solve(a, b, (1ll << i) - 1, i - 1);
	}
	return solve(a, b, r, i - 1) ^ (1ll << i);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int a, b, r;
		input(a, b, r);

		if (a == b) {
			print(0);
			continue;
		}

		if (a > b) {
			swap(a, b);
		}

		int j = -1;
		bool flag = false;
		for (int i = 60; i >= 0; i--) {
			if (((1ll << i) & a) != ((1ll << i) & b)) {
				j = i;
				break;
			}
			if ((1ll << i) & r) {
				flag = true;
			}
		}

		if (flag or ((1ll << j) & r)) {
			if (flag) {
				r = (1ll << j) - 1;
			}
			int x = solve(a, b, (1ll << j) - 1, j - 1);
			int y = solve(b, a, r, j - 1) ^ (1ll << j);
			print(min((b ^ x) - (a ^ x), (a ^ y) - (b ^ y)));
		}
		else {
			int x = solve(a, b, r, j - 1);
			print((b ^ x) - (a ^ x));
		}
	}
}
