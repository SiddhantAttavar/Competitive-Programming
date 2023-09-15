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

void solve(int n, vector<int> &ans) {
	if (n == 6) {
		ans[0] = 4;
		ans[1] = 5;
		ans[2] = 6;
		ans[3] = 1;
		ans[4] = 2;
		ans[5] = 3;
	}


	if (n <= 7) {
		ans[n - 2] = 1;
		ans[n - 1] = 2;
		range(i, 3, 8) {
			if (n >= i) {
				ans[i - 3] = i;
			}
		}
	}

	ans[n - 4] = n - 1;
	ans[n - 3] = n;
	ans[n - 2] = n - 3;
	ans[n - 1] = n - 2;
	solve(n - 4, ans);
}

int32_t main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n <= 3) {
			print(-1);
			continue;
		}

		vector<int> res(n);
		solve(n, res);
		arrPrint(res);
	}
}
