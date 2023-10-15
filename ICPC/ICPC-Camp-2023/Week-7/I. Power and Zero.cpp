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

		vector<int> b(32, 0);
		range(i, 0, n) {
			range(j, 0, 32) {
				b[j] += (a[i] & (1 << j)) > 0;
			}
		}

		bool flag = false;
		range(i, 1, 32) {
			if (b[i - 1] < b[i]) {
				flag = false;
				break;
			}
		}

		while (!flag) {
			for (int i = 31; i > 0; i--) {
				if (b[i - 1] >= b[i]) {
					continue;
				}

				int x;
				if ((b[i] - b[i - 1]) % 3 == 0) {
					x = (b[i] - b[i - 1]) / 3;
				}
				else {
					x = (int) ceil((double) (b[i] - b[i - 1]) / 3);
				}

				b[i] -= x;
				b[i - 1] += 2 * x;
			}

			flag = true;
			range(i, 1, 32) {
				if (b[i - 1] < b[i]) {
					flag = false;
					break;
				}
			}
		}

		print(b[0]);
	}
}
