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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int p, q;
		input(p, q);

		vector<int> a(n);
		arrPut(a);
		sort(a.begin(), a.end());

		int l = 0, r = n - 1;
		int x = p + q;
		int res = 0;
		while (r - l > 1 and x > 0) {
			if (a[r - 1] < 0 or (a[l + 1] <= 0 and abs(a[l]) > abs(a[r]))) {
				res += abs(a[l]);
				l++;
			}
			else {
				res += abs(a[r]);
				r--;
			}
			x--;
		}

		print(res + a[r] - a[l]);
	}
}
