#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	int N = 1e7;
	vector<int> spf(N + 1), dp(N + 1, 0);
	range(i, 0, N + 1) {
		spf[i] = i;
	}

	int t = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i += 2) {
		spf[i] = 2;
	}
	for (int i = 3; i <= N; i += 2) {
		if (spf[i] != i) {
			continue;
		}

		t++;
		for (int j = i; j <= N; j += i + i) {
			if (spf[j] == j) {
				spf[j] = i;
				dp[j] = t;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int res = 0;
		for (int i : a) {
			res ^= dp[i];
		}

		if (res) {
			print("Alice");
		}
		else {
			print("Bob");
		}
	}
}
