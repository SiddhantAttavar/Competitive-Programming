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
	string s;
	input(s);

	int n = s.size();

	int a = 0, b = 0;
	int x = 0, y = 0;
	range(i, 0, n) {
		if (s[i] == '0') {
			x += b;
			a++;
		}
		else {
			y += a;
			b++;
		}
	}

	vector<int> m;
	range(i, 0, n) {
		range(j, i + 1, n) {
			if (s[i] == '0' and s[j] == '1') {
				m.push_back(j - i);
			}
			else if (s[i] == '1' and s[j] == '0') {
				m.push_back(i - j);
			}
		}
	}

	vector<vector<int>> dp(m.size() + 1, vector<int>(6000, 1e15));
	dp[0][3000] = 0;
	range(i, 1, (int) m.size() + 1) {
		range(j, 0, 6000) {
			dp[i][j] = dp[i - 1][j];
		}
		range(j, max(0ll, m[i - 1]), min(6000ll, 6000 + m[i - 1])) {
			dp[i][j] = min(dp[i][j], dp[i][j - m[i - 1]] + 1);
		}
	}

	print(dp[m.size()][3000 + y - x]);
}
