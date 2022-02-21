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

	vector<int> p(n);
	p[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		p[i] = p[i + 1] + a[i];
	}

	vector<int> dp(n);
	dp[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = max(
			a[i] + p[i + 1] - dp[i + 1],
			dp[i + 1]
		);
	}

	print(p[0] - dp[0], dp[0]);
}
