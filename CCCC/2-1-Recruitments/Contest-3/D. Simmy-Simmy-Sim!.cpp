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

bool check(vector<int> &a, int k) {
	// print('k', k);
	int y = 0;
	vector<int> p(30, -1);
	range(i, 0, k) {
		y |= a[i];
		range(j, 0, 30) {
			if (a[i] & (1 << j)) {
				p[j] = i;
			}
		}
	}

	range(i, k, a.size()) {
		range(j, 0, 30) {
			if (a[i] & (1 << j)) {
				p[j] = i;
			}
			if (!(y & (1 << j)) ^ (p[j] <= i - k)) {
				return false;
			}
		}
	}

	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int l = 1, r = n, res = n;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(a, m)) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		print(res);
	}
}
