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

	int n;
	input(n);

	vector<int> t(n);
	arrPut(t);
	sort(t.begin(), t.end());
	arrPrint(t);

	priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;

	int c = 0;
	for (int i : t) {
		c += i;
	}

	int u;
	for (u = n - 1; u >= 1; u--) {
		c -= t[u];
		if (c <= t[u]) {
			print(u);
			pq.push({c, false});
			pq.push({t[u], true});
			break;
		}
	}

	range(i, u + 1, n) {
		pq.push({pq.top().first + t[i], pq.top().second});
		pq.pop();
	}

	print(pq.top().first);
	pq.pop();
	print(pq.top().first);
	print(2 * pq.top().first);
}
