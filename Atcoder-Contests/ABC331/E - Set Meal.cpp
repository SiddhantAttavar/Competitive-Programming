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
	setup();

	int n, m, l;
	input(n, m, l);

	vector<int> a(n);
	arrPut(a);

	vector<pair<int, int>> b(m);
	range(i, 0, m) {
		input(b[i].first);
		b[i].second = i;
	}
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	vector<set<int>> graph(n);
	range(i, 0, l) {
		int u, v;
		input(u, v);

		graph[u - 1].insert(v - 1);
	}

	int res = 0;
	range(i, 0, n) {
		range(j, 0, m) {
			if (!graph[i].count(b[j].second)) {
				res = max(res, a[i] + b[j].first);
				break;
			}
		}
	}

	print(res);
}
