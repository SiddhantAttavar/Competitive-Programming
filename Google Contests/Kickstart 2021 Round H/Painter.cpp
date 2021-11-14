#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int tc; input(tc);
	range(t, 1, tc + 1) {
		int n; input(n);
		string p; input(p);
		vector<vector<int>> a(n, vector<int>(3));
		range(i, 0, n) {
			if (p[i] == 'U') {
				a[i] = {0, 0, 0};
			}
			else if (p[i] == 'R') {
				a[i] = {1, 0, 0};
			}
			else if (p[i] == 'Y') {
				a[i] = {0, 1, 0};
			}
			else if (p[i] == 'B') {
				a[i] = {0, 0, 1};
			}
			else if (p[i] == 'O') {
				a[i] = {1, 1, 0};
			}
			else if (p[i] == 'P') {
				a[i] = {1, 0, 1};
			}
			else if (p[i] == 'G') {
				a[i] = {0, 1, 1};
			}
			else if (p[i] == 'A') {
				a[i] = {1, 1, 1};
			}
		}
		
		int ans = 0;
		range(i, 0, n) {
			range(j, 0, 3) {
				if (a[i][j] == 0) {
					continue;
				}

				int curr = i + 1;
				while (curr < n and a[curr][j] == 1) {
					a[curr][j] = 0;
					curr++;
				}
				ans++;
			}
		}

		cout << "Case #" << t << ": ";
		print(ans);
	}
}