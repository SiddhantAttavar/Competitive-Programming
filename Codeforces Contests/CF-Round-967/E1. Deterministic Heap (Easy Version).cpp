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
		int n, k, p;
		input(n, k, p);

		vector<vector<int>> f(n, vector<int>(k + 1, 0)), g(n, vector<int>(k + 1, 0));
		vector<vector<int>> a(n, vector<int>(k + 1, 0)), b(n, vector<int>(k + 1, 0));
		range(z, 0, k + 1) {
			f[n - 1][z] = 1;
			g[n - 1][z] = 1;
			a[n - 1][z] = z + 1;
			b[n - 1][z] = z + 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			range(z, 0, k + 1) {
				range(x, 0, z + 1) {
					g[i][z] = (g[i][z] + g[i + 1][x] * b[i + 1][z - x]) % p;
					if (x) {
						f[i][z] = (f[i][z] + f[i + 1][x] * b[i + 1][min(z - x, x - 1)]) % p;
					}
					if (x < z - x) {
						f[i][z] = (f[i][z] + g[i + 1][x] * (a[i + 1][z - x] - a[i + 1][x] + p)) % p;
					}
				}
				a[i][z] = (f[i][z] + (z == 0 ? 0 : a[i][z - 1])) % p;
				b[i][z] = (g[i][z] + (z == 0 ? 0 : b[i][z - 1])) % p;
			}
		}

		print(f[0][k]);
	}
}
