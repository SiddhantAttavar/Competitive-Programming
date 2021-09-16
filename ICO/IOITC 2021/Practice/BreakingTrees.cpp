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

int main() {
	setup();
	int n, k; input(n, k);

	vector<int> graph[n];
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
	}

	int a[n], b[n];
	arrPut(a);
	arrPut(b);

	ll dp[n - k] = {a[0] == a[k] ? max(0, b[0]) : 0};
	ll m = 0;
	range(i, 1, n - k) {
		if (i >= k) {
			m = max(m, dp[i - k]);
		}
		dp[i] = m;
		if (a[i] == a[i + k]) {
			dp[i] = max(dp[i], dp[i - 1] + b[i]);
		}
		else {
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}

	print(*max_element(dp, dp + n - k));
}