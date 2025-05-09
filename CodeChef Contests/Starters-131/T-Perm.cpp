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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> res(n);
		if (n % 3 == 0) {
			for (int i = 0; i < n; i += 3) {
				res[i] = i + 1;
				res[i + 1] = i + 3;
				res[i + 2] = i + 2;
			}
		}
		else  if (n % 3 == 1) {
			res[0] = 1;
			for (int i = 1; i < n; i += 3) {
				res[i] = i + 2;
				res[i + 1] = i + 1;
				res[i + 2] = i + 3;
			}
		}
		else {
			res[0] = 4;
			res[1] = 5;
			res[2] = 2;
			res[3] = 1;
			res[4] = 3;
			for (int i = 5; i < n; i += 3) {
				res[i] = i + 3;
				res[i + 1] = i + 2;
				res[i + 2] = i + 1;
			}
		}
		arrPrint(res);
	}
}
