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

int32_t main() {
	setup();

	int n;
	input(n);
	vector<int> a(n);
	arrPut(a);

	int m;
	input(m);
	vector<int> b(m);
	arrPut(b);

	vector<int> l(n, -1);
	vector<vector<pair<int, pair<int, int>>>> dp(n, vector<pair<int, pair<int, int>>>(m, {0, {-1, -1}}));
	range(j, 0, m) {
		range(i, 0, n) {
			if (a[i] == b[j]) {
				l[i] = j;
				dp[i][j] = {1, {-1, -1}};
				range(k, 0, i) {
					if ((a[k] < a[i]) and (l[k] != -1)) {
						if ((1 + dp[k][l[k]].first) > dp[i][j].first) {
							dp[i][j] = {1 + dp[k][l[k]].first, {k, l[k]}};
						}
					}
				}
			}
		}
	}

	/* range(i, 0, n) {
		range(j, 0, m) {
			cout << dp[i][j].first;
		}
		print("");
	} */

	pair<int, pair<int, int>> res = {0, {-1, -1}};
	int s = -1;
	range(i, 0, n) {
		range(j, 0, m) {
			if (dp[i][j].first > res.first) {
				res = dp[i][j];
				s = i;
			}
		}
	}
	print(res.first);

	vector<int> v;
	if (s != -1) {
		v.push_back(a[s]);
	}
	while (res.second.first != -1) {
		v.push_back(a[res.second.first]);
		res = dp[res.second.first][res.second.second];
	}

	reverse(v.begin(), v.end());
	arrPrint(v);
}
