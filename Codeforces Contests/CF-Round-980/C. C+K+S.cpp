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
		int n, k;
		input(n, k);

		int m1, m2;
		vector<int> a(n), b(n);
		vector<vector<int>> g1(n), g2(n);

		arrPut(a);
		input(m1);
		range(i, 0, m1) {
			int u, v;
			input(u, v);

			g1[u - 1].push_back(v - 1);
		}

		arrPut(b);
		input(m2);
		range(i, 0, m2) {
			int u, v;
			input(u, v);

			g2[u - 1].push_back(v - 1);
		}

		if (accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0) != n) {
			print("NO");
			continue;
		}

		print("YES");
	}
}
