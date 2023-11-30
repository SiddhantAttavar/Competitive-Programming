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

		vector<pair<pair<int, int>, int>> p(n);
		range(i, 0, n) {
			input(p[i].first.first);
			p[i].second = i;
		}
		range(i, 0, n) {
			input(p[i].first.second);
		}
		sort(p.begin(), p.end());

		vector<int> a(n), b(n);
		range(i, 0, n) {
			tie(a[i], b[i]) = p[i].first;
		}

		int s, e;
		range(i, 0, n) {
			if (p[i].second == 0) {
				s = i;
			}
			else if (p[i].second == n - 1) {
				e = i;
			}
		}

		vector<int> dp1(n, 0);
		int x = b[s];
		range(i, s + 1, n) {
			dp1[i] = dp1[i - 1] + x * (a[i] - a[i - 1]);
			x = min(x, b[i]);
		}

		x = p[s].first.second;
		for (int i = s - 1; i >= 0; i--) {
			dp1[i] = dp1[i + 1] + x * (a[i + 1] - a[i]);
			x = min(x, b[i]);
		}

		if (k == 0) {
			print(dp1[e]);
			continue;
		}

		vector<int> dp2(n, 0);
		stack<int> st;
		range(i, e + 1, n) {
			while (!st.empty() and b[st.top()] > b[i]) {
				st.pop();
			}
			if (st.empty()) {
				dp2[i] = b[i] * (a[i] - a[e]);
			}
			else {
				dp2[i] = dp2[st.top()] + b[i] * (a[i] - a[st.top()]);
			}
			st.push(i);
		}
		while (!st.empty()) {
			st.pop();
		}

		for (int i = e - 1; i >= 0; i--) {
			while (!st.empty() and b[st.top()] > b[i]) {
				st.pop();
			}
			if (st.empty()) {
				dp2[i] = b[i] * (a[e] - a[i]);
			}
			else {
				dp2[i] = dp2[st.top()] + b[i] * (a[st.top()] - a[i]);
			}
			st.push(i);
		}

		// arrPrint(dp1);
		// arrPrint(dp2);

		// print("debug");
		// cout.flush();

		int res = 1e18;
		range(i, 0, n) {
			res = min(res, dp1[i] + dp2[i]);
		}

		print(res);
	}
}
