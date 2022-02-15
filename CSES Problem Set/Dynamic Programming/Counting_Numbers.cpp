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

int solve(int x) {
	if (x < 0) {
		return x + 1;
	}

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = log10(x); i >= 0; i--) {
			int m = pow(10, i);
			if (x / (m * 10) % 10 == x / m % 10) {
				x = (x / m - 1) * m + (m - 1);
				flag = true;
			}
		}
	}

	int n = log10(x) + 1;
	vector<int> dp1(n), dp2(n);
	dp1[0] = 1;
	dp2[0] = 1;
	int res = 1;
	int m = 1;
	range(i, 1, n) {
		dp1[i] = pow(9, i);
		dp2[i] = (x / m % 10) * dp1[i - 1] + dp2[i - 1];
		if (x / (m * 10) % 10 < x / m % 10) {
			dp2[i] -= dp1[i - 1];
		}
		res += dp1[i];
		m *= 10;
	}
	return res + (x / m % 10) * dp1[n - 1] + dp2[n - 1];
}

int32_t main() {
	setup();
	
	int a, b;
	input(a, b);
	print(solve(b) - solve(a - 1));
}
