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

		vector<vector<int>> m(n, vector<int>(n));
		range(i, 0, n) {
			arrPut(m[i]);
		}

		if (n == 1) {
			print("YES");
			print(7);
			continue;
		}

		vector<int> a(n, (1 << 30) - 1);
		range(i, 0, n) {
			range(j, 0, n) {
				if (i != j) {
					a[i] &= m[i][j];
				}
			}
		}

		bool flag = true;
		range(i, 0, n) {
			range(j, 0, n) {
				if (i != j) {
					if ((a[i] | a[j]) != m[i][j]) {
						flag = false;
						break;
					}
				}
			}
			if (!flag) {
				break;
			}
		}

		if (flag) {
			print("YES");
			arrPrint(a);
		}
		else {
			print("NO");
		}
	}
}
