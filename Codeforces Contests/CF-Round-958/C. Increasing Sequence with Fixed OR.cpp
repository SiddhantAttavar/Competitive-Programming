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

		vector<int> v;
		range(i, 0, 60) {
			if (n & (1ll << i)) {
				v.push_back(i);
			}
		}

		if (v.size() == 1) {
			print(1);
			print(n);
			continue;
		}

		vector<int>res(v.size(), n);
		range(i, 0, v.size()) {
			res[i] ^= 1ll << v[i];
		}
		reverse(res.begin(), res.end());
		res.push_back(n);
		print(res.size());
		arrPrint(res);

		range(i, 1, res.size()) {
			assert((res[i - 1] | res[i]) == n and res[i] > res[i - 1]);
		}
	}
}
