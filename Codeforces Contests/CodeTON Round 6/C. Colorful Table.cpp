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
		int n, k;
		input(n, k);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			input(a[i].first);
			a[i].second = i;
			a[i].first--;
		}
		sort(a.begin(), a.end());

		int l = 0, r = n - 1;
		vector<int> res(k, -1);
		vector<bool> visited(n, false);
		for (pair<int, int> p : a) {
			int c, i;
			tie(c, i) = p;

			if (res[c] == -1) {
				res[c] = r - l + 1;
			}

			visited[i] = true;

			while (l < n and visited[l]) {
				l++;
			}
			while (r >= 0 and visited[r]) {
				r--;
			}
		}

		range(i, 0, k) {
			if (res[i] == -1) {
				res[i] = 0;
			}
			else {
				res[i] *= 2;
			}
		}

		arrPrint(res);
	}
}
