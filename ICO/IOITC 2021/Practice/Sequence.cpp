#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define print(msg) cout << msg << endl
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int n; input(n);
	int a[n]; arrPut(a);

	int pref[n];
	stack<int> s;
	range(i, 0, n) {
		while (!s.empty() && a[s.top()] < a[i]) {
			s.pop();
		}
		pref[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}

	int suff[n];
	s = stack<int>();
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && a[s.top()] <= a[i]) {
			s.pop();
		}
		suff[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}

	ll cost = 0;
	int m = max_element(a, a + n) - a;
	range(i, 0, n) {
		if (i == m) {
			continue;
		}

		if (pref[i] == -1) {
			cost += a[suff[i]];
		}
		else if (suff[i] == -1) {
			cost += a[pref[i]];
		}
		else {
			cost += min(a[pref[i]], a[suff[i]]);
		}
	}

	print(cost);
}