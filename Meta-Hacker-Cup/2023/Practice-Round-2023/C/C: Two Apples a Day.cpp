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
	setup(); int tc; input(tc); range(t, 1, tc + 1) {
		cout << "Case #" << t << ": ";
		int n;
		input(n);

		vector<int> a(2 * n - 1);
		arrPut(a);
		sort(a.begin(), a.end());

		if (n == 1) {
			print(1);
			continue;
		}

		bool flag = true;
		range(i, 0, n - 1) {
			if (a[2 * n - 3 - i] + a[i] != a[0] + a[2 * n - 3]) {
				flag = false;
				break;
			}
		}
		
		if (flag and a[0] + a[2 * n - 3] - a[2 * n - 2] >= 1) {
			print(a[0] + a[2 * n - 3] - a[2 * n - 2]);
			continue;
		}

		bool p = false, q = false;
		int x = -1;
		flag = true;
		range(i, 1, n) {
			if (a[i - q] + a[2 * n - 2 - i + p] != a[0] + a[2 * n - 2]) {
				if (p or q) {
					flag = false;
					break;
				}

				if (a[i] + a[2 * n - 2 - i] > a[0] + a[2 * n - 2]) {
					x = a[0] + a[2 * n - 2] - a[2 * n - 2 - i];
					q = true;
				}
				else {
					x = a[0] + a[2 * n - 2] - a[i];
					p = true;
				}
			}
		}

		if (flag) {
			if (x != -1) {
				print(x);
				continue;
			}

			if (a[0] + a[2 * n - 2] - a[n - 1] >= 0) {
				print(a[0] + a[2 * n - 2] - a[n - 1]);
				continue;
			}
		}

		flag = true;
		range(i, 2, n) {
			if (a[2 * n - 1 - i] + a[i] != a[1] + a[2 * n - 2]) {
				flag = false;
				break;
			}
		}
		
		if (flag and a[1] + a[2 * n - 2] - a[0] >= 1) {
			print(a[1] + a[2 * n - 2] - a[0]);
			continue;
		}

		print(-1);
	}
}
