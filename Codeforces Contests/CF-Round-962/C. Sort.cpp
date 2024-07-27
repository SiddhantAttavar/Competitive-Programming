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
		int n, q;
		input(n, q);

		string a, b;
		input(a, b);

		vector<vector<int>> s(n + 1, vector<int>(26, 0)), t(n + 1, vector<int>(26, 0));
		range(i, 0, n) {
			s[i + 1] = vector<int>(s[i].begin(), s[i].end());
			t[i + 1] = vector<int>(t[i].begin(), t[i].end());
			s[i + 1][a[i] - 'a']++;
			t[i + 1][b[i] - 'a']++;
		}

		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;

			int res = 0;
			range(i, 0, 26) {
				res += abs(s[r + 1][i] - s[l][i] - t[r + 1][i] + t[l][i]);
			}
			print(res / 2);
		}
	}
}
