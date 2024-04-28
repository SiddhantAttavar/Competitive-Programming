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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		if (n < m) {
			print("NO");
			continue;
		}

		vector<int> res = {n};
		int x = n;
		for (int i = 59; i >= 0; i--) {
			if (!((1ll << i) & x) or ((1ll << i) & m)) {
				continue;
			}

			int j = i - 1;
			while (j >= 0 and !((1ll << j) & m)) {
				j--;
			}

			int y = (x ^ (1ll << i)) | ((1ll << (j + 1)) - 1);
			if (max(x ^ y, y) >= x) {
				res.clear();
				break;
			}
			x = y;
			res.push_back(x);
		}

		if (res.empty() or res.back() != m) {
			print(-1);
		}
		else {
			print(res.size() - 1);
			arrPrint(res);
		}
	}
}
