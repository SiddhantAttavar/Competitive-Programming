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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool insert(int x, vector<int> &b) {
	for (int i = 30; i >= 0; i--) {
		if ((x & (1 << i)) == 0) {
			continue;
		}
		if (b[i] == 0) {
			b[i] = x;
			return true;
		}
		x ^= b[i];
	}
	return false;
}

int query(vector<int> &b, int k) {
	int res = 0;
	for (int i = 30; i >= 0; i--) {
		if (b[i] and !(res & (1 << i))) {
			res ^= b[i];
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int k = 0;
		vector<int> b(31, 0);

		vector<int> a(n);
		arrput(a);
		sort(a.begin(), a.end());

		int x = 0;
		if (a[0] == 0) {
			rep(i, 1, n) {
				if (a[i] > a[i - 1] + 1) {
					x = a[i - 1] + 1;
					break;
				}
			}
			if (x == 0) {
				x = a[n - 1] + 1;
			}
		}

		rep(i, 1, n) {
			if (a[i] < x and a[i] == a[i - 1]) {
				k += insert(a[i], b);
			}
		}

		int j = lower_bound(a.begin(), a.end(), x) - a.begin();
		rep(i, j, n) {
			k += insert(a[i], b);
		}

		int res = x + query(b, k);
		for (int i = x - 1; i >= 0; i--) {
			k += insert(i, b);
			res = max(res, i + query(b, k));
		}
		print(res);
	}
}
