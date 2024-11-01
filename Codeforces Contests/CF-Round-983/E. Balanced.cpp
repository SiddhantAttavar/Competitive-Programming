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

bool solve(vector<int> &a, vector<int> &res) {
	int n = a.size();
	int x = a[0];
	range(i, 1, n) {
		x = a[i] - x;
	}

	if (n % 2 == 0) {
		if (x != 0) {
			return false;
		}
		res[0] = 0;
	}
	else {
		if (x % 2) {
			return false;
		}
		res[0] = x / 2;
	}

	range(i, 0, n - 1) {
		res[i + 1] = a[i] - res[i];
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		range(i, 0, n) {
			a[i] = -a[i];
		}

		vector<int> w(n);
		if (!solve(a, w)) {
			range(i, 0, n) {
				a[i]++;
			}

			if (!solve(a, w)) {
				print(-1);
				continue;
			}
		}

		int t = w[0];
		range(i, 0, n - 1) {
			w[i] = w[i + 1];
		}
		w[n - 1] = t;

		vector<int> v(n);
		if (!solve(w, v)) {
			range(i, 0, n) {
				w[i]++;
			}

			if (!solve(w, v)) {
				print(-1);
				continue;
			}
		}

		int x = *min_element(v.begin(), v.end());
		range(i, 0, n) {
			v[i] -= x;
		}
		arrPrint(v);
	}
}
