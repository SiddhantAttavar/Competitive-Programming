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
		int n, m;
		input(n, m);

		vector<string> v(n);
		arrPut(v);

		int res = 0;
		int a = 0, b = 0, c = n - 1, d = m - 1;
		while (a <= c and b <= d) {
			string s;
			range(j, b, d + 1) {
				s += v[a][j];
			}

			range(i, a + 1, c + 1) {
				s += v[i][d];
			}

			if (a != c) {
				for (int j = d - 1; j >= b; j--) {
					s += v[c][j];
				}
			}
			
			if (b != d) {
				for (int i = c - 1; i > a; i--) {
					s += v[i][b];
				}
			}

			if (s.size() < 4) {
				break;
			}

			s += s.substr(0, 3);
			range(i, 0, s.size() - 3) {
				assert(i + 4 <= s.size());
				res += s.substr(i, 4) == "1543";
			}

			a++;
			b++;
			c--;
			d--;
		}
		print(res);
	}
}
