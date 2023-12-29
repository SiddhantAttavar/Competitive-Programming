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

		vector<int> a(n);
		arrPut(a);

		vector<int> x(n + 1, 0), y(n + 1, 0);
		set<int> s;
		s.insert(0);
		range(i, 0, n) {
			x[i + 1] = x[i];
			y[i + 1] = y[i];
			if (i % 2 == 0) {
				x[i + 1] += a[i];
			}
			else {
				y[i + 1] += a[i];
			}
			s.insert(x[i + 1] - y[i + 1]);
		}

		if ((int) s.size() == n + 1) {
			print("NO");
		}
		else {
			print("YES");
		}
	}
}
