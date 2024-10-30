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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n < 4) {
			print(-1);
			continue;
		}
		vector<vector<int>> ans = {
			{3, 4, 1, 2},
			{3, 4, 5, 1, 2},
			{4, 5, 6, 1, 2, 3},
			{3, 4, 5, 6, 7, 1, 2}
		};

		vector<int> res = ans[n % 4];
		for (int i = n % 4 + 5; i < n; i += 4) {
			res.push_back(i + 2);
			res.push_back(i + 3);
			res.push_back(i);
			res.push_back(i + 1);
		}
		arrPrint(res);
	}
}
