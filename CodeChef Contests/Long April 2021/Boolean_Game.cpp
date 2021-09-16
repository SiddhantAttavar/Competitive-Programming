#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
#define int ll

signed main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		ll a[n][n];
		range(i, 0, n) {
			fill(a[i], a[i] + n, 0);
		}
		range(i, 0, n) {
			input(a[i][i]);
		}
		range(i, 0, m) {
			int u, v, d;
			input(u, v, d);
			a[u - 1][v - 1] = d;
		}
		range(l, 2, n + 1) {
			range(i, 0, n - l + 1) {
				int j = i + l - 1;
				a[i][j] += a[i + 1][j] + a[i][j - 1] - a[i + 1][j - 1];
			}
		}

		vector<ll> dp[n];
		if (k == 1) {
			dp[0] = {max((ll) 0, a[0][0])};
		}
		else {
			if (a[0][0] > 0) {
				dp[0] = {a[0][0], 0};
			}
			else {
				dp[0] = {0, a[0][0]};
			}
		}
		range(i, 1, n) {
			//If we don't choose i, we get dp[i - 1]
			vector<int> possible(dp[i - 1].begin(), dp[i - 1].end());
			range(j, 0, i + 1) {
				//If we choose everything from j -> i we get add[j][i] + dp[j - 2]
				//since we must have a gap of atleast 1
				if (j < 2) {
					possible.push_back(a[j][i]);
				}
				else {
					for (ll l : dp[j - 2]) {
						possible.push_back(a[j][i] + l);
					}
				}
			}
			sort(possible.begin(), possible.end());
			reverse(possible.begin(), possible.end());
			dp[i].insert(dp[i].end(), possible.begin(), possible.begin() + (min(k, (ll) possible.size())));
		}

		arrPrint(dp[n - 1]);
	}
}