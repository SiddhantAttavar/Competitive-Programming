#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	string o = "CDHS";
	map<char, int> m;
	range(i, 0, o.size()) {
		m[o[i]] = i;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		char c;
		input(c);
		int t = m[c];

		vector<vector<int>> v(4);
		range(i, 0, 2 * n) {
			string s;
			input(s);
			// print(m[s[1]], s[0] - '0');
			v[m[s[1]]].push_back(s[0] - '0');
		}

		range(i, 0, 4) {
			sort(v[i].begin(), v[i].end());
		}

		// range(i, 0, 4) {
		// 	print(v[i].size());
		// }

		int x = 0;
		range(i, 0, 4) {
			if (i == t) {
				continue;
			}
			x += v[i].size() % 2;
		}
		if (x > v[t].size()) {
			print("IMPOSSIBLE");
			continue;
		}

		int l = 0;
		range(i, 0, 4) {
			if (i == t) {
				continue;
			}

			range(j, 0, v[i].size() / 2) {
				cout << v[i][2 * j] << o[i] << ' ' << v[i][2 * j + 1] << o[i] << endl;
			}

			if (v[i].size() % 2) {
				cout << v[i].back() << o[i] << ' ' << v[t][l] << o[t] << endl;
				l++;
			}
		}

		range(j, 0, (v[t].size() - l) / 2) {
			cout << v[t][l + 2 * j] << o[t] << ' ' << v[t][l + 2 * j + 1] << o[t] << endl;
		}
	}
}
