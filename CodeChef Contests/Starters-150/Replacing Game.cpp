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
		int n, k;
		input(n, k);

		string a, b;
		input(a, b);

		if (a == b) {
			print(0);
			continue;
		}

		int x = 1;
		int u = -1;
		range(i, 1, n) {
			if (b[i] != b[i - 1]) {
				x = 0;
			}
			x++;
			if (x == k) {
				u = i;
				break;
			}
		}

		if (u == -1) {
			print(-1);
			continue;
		}

		vector<pair<int, char>> res;
		range(i, 0, u - k + 1) {
			res.push_back({i + 1, b[i]});
		}
		for (int i = n - k; i >= u - k + 1; i--) {
			res.push_back({i + 1, b[i + k - 1]});
		}

		print(res.size());
		for (pair<int, char> p : res) {
			print(p.first, p.second);
		}
	}
}
