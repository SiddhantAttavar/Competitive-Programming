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

int solve(int n, vector<int> &a, vector<int> &b, int x) {
	int k = lower_bound(a.begin(), a.end(), x) - a.begin();
	a.insert(a.begin() + k, x);
	// arrPrint(a);
	// arrPrint(b);
	int j = 0;
	int res = 0;
	range(i, 0, n) {
		while (j < n and b[j] <= a[i]) {
			j++;
		}
		if (j < n) {
			res++;
			j++;
		}
	}
	// print('d', res);
	a.erase(a.begin() + k);
	return n - res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n - 1);
		arrPut(a);

		vector<int> b(n);
		arrPut(b);

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int x = solve(n, a, b, 1);
		// print(x);
		int l = 1, r = m, res = -1;
		while (l <= r) {
			int k = (l + r) / 2;
			if (solve(n, a, b, k) == x) {
				l = k + 1;
				res = k;
			}
			else {
				r = k - 1;
			}
		}
		print(x * res + (x + 1) * (m - res));
	}
}

