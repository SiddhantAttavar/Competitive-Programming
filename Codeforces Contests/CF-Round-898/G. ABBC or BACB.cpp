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
		string s;
		input(s);

		int n = s.size();
		vector<int> p(n + 1, s[0] == 'A'), q(n + 1, s[n - 1] == 'A');
		p[0] = 0;
		range(i, 1, n) {
			if (s[i] != 'A') {
				p[i + 1] = 0;
			}
			else {
				p[i + 1] = p[i] + 1;
			}
		}
		q[n] = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] != 'A') {
				q[i] = 0;
			}
			else {
				q[i] = q[i + 1] + 1;
			}
		}

		vector<int> ind;
		range(i, 0, n) {
			if (s[i] == 'B') {
				ind.push_back(i);
			}
		}

		int m = ind.size();
		if (m == 0) {
			print(0);
			continue;
		}
		ind.push_back(n);

		vector<int> dp1(m), dp2(m);
		dp1[0] = ind[0];
		dp2[0] = ind[1] - ind[0] - 1;
		range(i, 1, m) {
			dp1[i] = dp1[i - 1] + (ind[i] - ind[i - 1] - 1);
			dp2[i] = max(dp1[i - 1], dp2[i - 1]) + (ind[i + 1] - ind[i] - 1);
		}
		print(max(dp1[m - 1], dp2[m - 1]));
	}
}
