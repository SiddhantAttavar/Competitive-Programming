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

		vector<int> m(n + 1, -1), v(n + 1);
		range(i, 0, n) {
			if (m[a[i]] != -1) {
				m[a[i]] = max(m[a[i]], (i - v[a[i]]) / 2);
			}
			else {
				m[a[i]] = i;
			}
			v[a[i]] = i;
		}

		int res = 1;
		m[1] = max(m[1], n - 1 - v[1]);
		range(i, 2, n + 1) {
			m[i] = max(m[i], n - 1 - v[i]);
			if (m[i] < m[res]) {
				res = i;
			}
		}

		print(res, m[res]);
	}
}