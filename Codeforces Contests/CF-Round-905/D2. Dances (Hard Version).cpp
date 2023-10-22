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
		int n, m;
		input(n, m);

		vector<int> a(n - 1);
		arrPut(a);
		a.insert(a.begin(), 1);

		vector<int> b(n);
		arrPut(b);

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
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
		print(n - res);
	}
}

