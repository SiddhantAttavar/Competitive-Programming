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

int check(vector<int> a) {
	int res = 0;
	range(i, 0ll, a.size()) {
		res += (1ll << i) * a[i];
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int x;
		input(x);

		vector<int> a;
		int y = 0;
		bool flag = true;
		range(i, 0, 31) {
			if (x & (1 << i)) {
				y++;
				flag = false;
			}
			else {
				a.push_back(y);
				y = 0;
			}
		}

		vector<int> res;
		for (int i : a) {
			if (i == 0) {
				res.push_back(0);
			}
			else if (i == 1) {
				res.push_back(1);
				res.push_back(0);
			}
			else {
				res.push_back(-1);
				range(j, 0, i - 1) {
					res.push_back(0);
				}
				res.push_back(1);
			}
		}
		res.push_back(0);
		res.push_back(0);
		// arrPrint(res);
		// print(check(res));

		range(i, 0, res.size() - 2) {
			if (res[i] == 0 or res[i + 1] == 0) {
				continue;
			}

			if (res[i] == 1) {
				if (res[i + 1] == 1) {
					res[i + 2] = 1;
				}
				else {
					res[i + 2] = 0;
				}
				res[i] = -1;
				res[i + 1] = 0;
			}
			else {
				if (res[i + 1] == 1) {
					res[i + 2] = 0;
				}
				else {
					res[i + 2] = -1;
				}
				res[i] = 1;
				res[i + 1] = 0;
			}
		}

		while (res.size() > 32) {
			res.pop_back();
		}

		print(res.size());
		arrPrint(res);
		// print(check(res), x);
		assert(check(res) == x);
	}
}
