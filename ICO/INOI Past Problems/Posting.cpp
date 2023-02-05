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

	int n, m;
	input(n, m);

	vector<int> a(n + 1);
    range(i, 1, n + 1) {
        input(a[i]);
    }
	sort(a.begin() + 1, a.end());

	vector<vector<int>> b(m + 1, vector<int>(3));
	range(i, 1, m + 1) {
		arrPut(b[i]);
	}
	sort(b.begin() + 1, b.end());

	vector<vector<int>> dp(m + 1, vector<int>(n + 1 ,1e16));
	vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

	dp[0][0] = 0;
	range(i, 1, m + 1) {
		range(j, 1, n + 1) {
			pref[i][j] += pref[i][j - 1] + abs(a[j] - b[i][0]);
		}
	}

	range(i, 1, m + 1) {
		deque<pair<int, int>> dq;
		range(j, b[i][1], n + 1) {
			// cout << i << ' ' << j << endl;
			int x = pref[i][j - b[i][1]] - dp[i - 1][j - b[i][1]];

			while (!dq.empty() and x > dq.back().second) {
				dq.pop_back();
			}

            // print(j - b[i][1], x);
			dq.push_back({j - b[i][1], x});

			while (!dq.empty() and dq.front().first < j - b[i][2]) {
				dq.pop_front();
			}

            // print(dq.front().first, dq.front().second);

			dp[i][j] = min(dp[i][j], pref[i][j] - dq.front().second);
		}
	}

	if (dp[m][n] == 1e16) {
		print(-1);
	}
	else {
		print(dp[m][n]);
	}
}

