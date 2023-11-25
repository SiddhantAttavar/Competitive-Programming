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

		bool flag = true;
		range(i, 0, n - 1) {
			int m = 0;
			range(j, 1, n - i) {
				if (a[j] > a[m]) {
					m = j;
				}
			}

			if (m == 0) {
				flag = false;
				break;
			}

			int t = a[m];
			range(j, m + 1, n - i) {
				a[j - 1] = a[j];
			}
			a[n - i - 1] = t;
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
