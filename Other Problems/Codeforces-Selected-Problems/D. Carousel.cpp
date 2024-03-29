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

bool check(vector<int> &a, vector<int> &t) {
	int n = t.size();
	range(i, 0, n) {
		if (t[i] != t[(i + 1) % n] and a[i] == a[(i + 1) % n]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> t(n);
		arrPut(t);

		bool flag = true;
		int u = -1;
		range(i, 0, n) {
			if (t[i] == t[(i + 1) % n]) {
				u = i;
			}
			else {
				flag = false;
			}
		}

		if (flag) {
			print(1);
			vector<int> res(n, 1);
			arrPrint(res);
			// cout.flush();
			// assert(check(res, t));
			continue;
		}

		if (n % 2 == 0) {
			print(2);
			vector<int> res(n);
			range(i, 0, n) {
				res[i] = 1 + i % 2;
			}
			arrPrint(res);
			// cout.flush();
			// assert(check(res, t));
			continue;
		}

		vector<int> res(n);
		if (u == -1) {
			print(3);
			range(i, 0, n - 1) {
				res[i] = 1 + (i % 2);
			}
			res[n - 1] = 3;
			arrPrint(res);
			// cout.flush();
			// assert(check(res, t));
			continue;
		}

		print(2);
		range(i, 0, u + 1) {
			res[i] = 1 + (i % 2);
		}
		range(i, u + 1, n) {
			res[i] = 2 - (i % 2);
		}
		arrPrint(res);
		// cout.flush();
		// assert(check(res, t));
	}
}
