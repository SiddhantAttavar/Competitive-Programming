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

		vector<int> a(n), c(n), b(n), d(n);
		arrPut(a);
		arrPut(c);
		arrPut(b);
		arrPut(d);

		vector<multiset<int>> m(2 * n + 1), o(2 * n + 1);
		range(i, 0, n) {
			m[d[i]].insert(b[i]);
		}
		range(i, 0, n) {
			o[c[i]].insert(a[i]);
		}

		range(i, 0, 2 * n + 1) {
			if (!m[i].empty()) {
				for (int j : o[i]) {
					m[i].insert(j);
				}
			}
		}

		vector<multiset<int>::iterator> l(2 * n + 1);
		range(i, 0, 2 * n + 1) {
			l[i] = m[i].begin();
		}

		bool flag = true;
		int x = 0;
		range(i, 0, n) {
			if (m[c[i]].empty()) {
				if (a[i] >= x) {
					x = a[i];
				}
				else {
					flag = false;
					break;
				}
			}
			else {
				while (l[c[i]] != m[c[i]].end() and *l[c[i]] < x) {
					l[c[i]]++;
				}

				if (l[c[i]] == m[c[i]].end()) {
					flag = false;
					break;
				}
				else {
					x = *l[c[i]];
					l[c[i]]++;
				}
			}
		}

		if (flag) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
