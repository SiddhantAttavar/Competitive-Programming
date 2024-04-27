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
		int n, m;
		input(n, m);

		vector<vector<bool>> a(n, vector<bool>(m));
		range(i, 0, n) {
			string s;
			input(s);
			range(j, 0, m) {
				a[i][j] = s[j] == 'B';
			}
		}

		bool e = false, b = false, c = false, d = false;
		range(i, 0, n) {
			e = e or a[i][0];
			b = b or a[i][m - 1];
		}
		range(j, 0, m) {
			c = c or a[0][j];
			d = d or a[n - 1][j];
		}

		if (e and b and c and d) {
			print("YES");
			continue;
		}

		e = false, b = false, c = false, d = false;
		range(i, 0, n) {
			e = e or !a[i][0];
			b = b or !a[i][m - 1];
		}
		range(j, 0, m) {
			c = c or !a[0][j];
			d = d or !a[n - 1][j];
		}

		if (e and b and c and d) {
			print("YES");
			continue;
		}

		print("NO");
	}
}
