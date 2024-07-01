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
	vector<int> p, c;
	int N = (int) 1e5 + 3;
	vector<bool> s(N, true);
	s[0] = s[1] = false;
	range(i, 2, N + 1) {
		if (s[i]) {
			p.push_back(i);
			for (int j = i + i; j <= N; j += i) {
				s[j] = false;
			}
		}
		else {
			c.push_back(i);
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n == 1) {
			print(4);
		}
		else {
			print(p[n - 1] + 1);
		}
	}
}
