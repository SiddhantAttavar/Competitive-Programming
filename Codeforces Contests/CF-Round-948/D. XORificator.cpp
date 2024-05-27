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
    mt19937_64 rng((int) chrono::steady_clock::now().time_since_epoch().count());
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<bool>> a(n, vector<bool>(m));
		range(i, 0, n) {
			string s;
			input(s);
			range(j, 0, m) {
				a[i][j] = s[j] == '1';
			}
		}

		vector<int> b(n);
		range(i, 0, n) {
			b[i] = rng();
		}

		map<int, pair<int, int>> s;
		map<int, int> t;
		range(j, 0, m) {
			int c = 0;
			range(i, 0, n) {
				if (a[i][j]) {
					c ^= b[i];
				}
			}

			range(i, 0, n) {
				int x = c ^ b[i];
				t[x]++;
				s[x] = {i, j};
			}
		}

		int k = -1;
		pair<int, int> p = {-1, -1};
		for (pair<int, int> i : t) {
			if (i.second <= k) {
				continue;
			}

			k = i.second;
			p = s[i.first];
		}

		vector<bool> res(n);
		range(i, 0, n) {
			res[i] = a[i][p.second];
		}
		res[p.first] = !res[p.first];

		print(k);
		range(i, 0, n) {
			cout << res[i];
		}
		cout << endl;
	}
}
