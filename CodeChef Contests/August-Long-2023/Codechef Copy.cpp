#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int n = 8;
string c = "codechef";

bool bpm(vector<vector<bool>> &v, int u, vector<bool> &seen, vector<int> &m) {
	range(i, 0, n) {
		if (v[u][i] and !seen[i]) {
			seen[i] = true;
			if (m[i] < 0 or bpm(v, m[i], seen, m)) {
				m[i] = u;
				return true;
			}
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		vector<vector<bool>> v(n, vector<bool>(n, false));
		range(i, 0, n) {
			range(j, 0, n) {
				v[i][j] = s[j] != c[i];
			}
		}

		/* range(i, 0, n) {
			arrPrint(v[i]);
		} */

		vector<int> m(n, -1);

		int res = 0;
		range(u, 0, n) {
			vector<bool> seen(n, false);

			if (bpm(v, u, seen, m)) {
				res++;
			}
		}

		// arrPrint(m);
		
		if (res < n) {
			print(-1);
		}
		else {
			vector<char> x(n);
			range(i, 0, n) {
				x[m[i]] = s[i];
			}
			string z(x.begin(), x.end());
			print(z);
		}
	}
}
