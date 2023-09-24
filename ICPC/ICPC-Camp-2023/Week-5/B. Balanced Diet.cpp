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
		int n, m;
		input(n, m);

		vector<int> a(n), b(n);
		vector<pair<int, int>> l;
		range(i, 0, m) {
			input(l[i].first);
			l[i].second = i;
		}
		sort(l.begin(), l.end());

		vector<vector<pair<int, int>>> v(m);
		range(i, 0, n) {
			input(a[i], b[i]);
			b[i]--;
			v[b[i]].push_back({a[i], i});
		}

		range(i, 0, m) {
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
		}

		pair<int, int> res = {-1, -1};
		int curr = 0;
		int j = 0;
		range(i, 1, n + 1) {
			while (j < m and l[j].first == (i + 1)) {

			}
		}
	}
}
