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

		vector<int> f(n);
		arrPut(f);
		f.push_back(0);

		vector<int> g(f.begin(), f.end());

		vector<int> res(n + 1, 0);
		range(i, 1, n + 1) {
			res[i] = res[i - 1];
			if (f[i - 1]) {
				continue;
			}

			int x = (i - 1) / 2;
			int c = 1;
			while (f[x] == 1) {
				if (x == 0) {
					break;
				}
				x /= 2;
				c++;
			}

			if (f[x] <= 1) {
				res[i] = -1;
			}
			else {
				f[x]--;
				f[i - 1]++;
			}
			// print(i, x);
			// arrPrint(f);

			if (res[i] == -1) {
				fill(res.begin() + i + 1, res.end(), -1);
				break;
			}

			res[i] += c;
		}

		range(i, 0, n + 1) {
			if (res[i] != -1) {
				res[i] += g[i];
			}
		}

		arrPrint(res);
	}
}
