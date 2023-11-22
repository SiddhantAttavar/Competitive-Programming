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
		int n, d;
		input(n, d);

		vector<int> b(n), c(n);
		arrPut(b);
		arrPut(c);

		if (b[0] != c[0]) {
			print("NO");
			continue;
		}

		if (d == 0) {
			bool flag = true;
			range(i, 1, n) {
				if (b[i] != b[i - 1] or c[i] != c[i - 1]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				print("YES");
				arrPrint(b);
			}
			else {
				print("NO");
			}
			continue;
		}

		vector<int> res(n);
		res[0] = b[0];
		bool flag = true;
		vector<int> v = {0};
		range(i, 1, n) {
			if (b[i] != b[i - 1]) {
				if (b[i] < b[i - 1] or c[i] != c[i - 1]) {
					flag = false;
					break;
				}

				res[i] = b[i];
				v.push_back(i);
			}
			else if (c[i] != c[i - 1]) {
				if (c[i] > c[i - 1]) {
					flag = false;
					break;
				}

				res[i] = c[i];
				v.push_back(i);
			}
			else {
				res[i] = -1;
			}
		}

		if (!flag) {
			print("NO");
		}
		else {
			range(i, 1, (int) v.size()) {
				if (res[v[i - 1]] < res[v[i]]) {
					range(k, v[i - 1] + 1, v[i]) {
						res[k] = min(res[v[i]], res[k - 1] + d);
					}
				}
				else {
					range(k, v[i - 1] + 1, v[i]) {
						res[k] = max(res[v[i]], res[k - 1] - d);
					}
				}
				
				if (abs(res[v[i]] - res[v[i] - 1]) > d) {
					flag = false;
					break;
				}
			}
			range(k, v.back() + 1, n) {
				res[k] = res[k - 1];
			}
			if (flag) {
				print("YES");
				arrPrint(res);
			}
			else {
				print("NO");
			}
		}
	}
}
