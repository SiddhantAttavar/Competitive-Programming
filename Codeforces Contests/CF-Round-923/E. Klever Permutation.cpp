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

bool check(vector<int> a, int k) {
	int x = 0;
	range(i, 0, k) {
		x += a[i];
	}

	if (*max_element(a.begin(), a.end()) > a.size() or *min_element(a.begin(), a.end()) < 1) {
		return false;
	}

	set<int> s(a.begin(), a.end());
	if (s.size() != a.size()) {
		return false;
	}

	int l = x, r = x;
	range(i, k, a.size()) {
		x += a[i] - a[i - k];
		l = min(l, x);
		r = max(r, x);
	}

	// print(l, r);
	// cout.flush();
	return (r - l) <= 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> res(n);
		int t = 1;
		range(i, 0, k) {
			if (i % 2 == 0) {
				for (int j = i; j < n; j += k) {
					res[j] = t;
					t++;
				}
			}
			else {
				int x = 0;
				for (int j = i; j < n; j += k) {
					x = j;
				}
				for (int j = x; j >= 0; j -= k) {
					res[j] = t;
					t++;
				}
			}
		}

		// vector<int> res(n);
		// int l = 1, r = n;
		// range(i, 0, n) {
		// 	if (i % 2 == 0) {
		// 		res[i] = l;
		// 		l++;
		// 	}
		// 	else {
		// 		res[i] = r;
		// 		r--;
		// 	}
		// }

		arrPrint(res);
		// cout.flush();
		// assert(check(res, k));
	}
}
