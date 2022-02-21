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
	vector<int> a(n);
	range(i, 0, n) {
		a[i] = s[i] - '0';
	}

	vector<int> dp(n, -1);
	vector<int> x(3);
	x[a[0]] = 0;
	dp[0] = a[0] % 3 == 0;

	range(i, 1, n) {
		if (x[0] != -1) {
			dp[i] = dp[x[0]] + 1;
		}
		range(j, 0, 3) {
			if (x[j] != -1) {
				x[(a[0] + j) % 3] = i;
			}
		}
	}
	
	print(dp[n - 1]);
}
