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

int check(vector<int> &a) {
	int res = 0;
	range(i, 0, (int) a.size()) {
		res += abs(a[i] - i - 1);
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		if (k % 2) {
			print("No");
			continue;
		}

		int o = k;
		vector<int> res(n);
		range(i, 0, n) {
			res[i] = i + 1;
		}
		int l = 0, r = n - 1;
		while (l <= r and k) {
			if (k >= 2 * (r - l)) {
				swap(res[l], res[r]);
				k -= 2 * (r - l);
				l++;
				r--;
			}
			else {
				l++;
			}
		}

		if (k == 0) {
			print("Yes");
			arrPrint(res);
			assert(check(res) == o);
		}
		else {
			print("No");
		}
	}
}
