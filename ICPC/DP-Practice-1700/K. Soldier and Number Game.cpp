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
	int N = 5e6;
	vector<int> v(N + 1, 0);
	vector<int> p(N + 1, 0);
	range(i, 2, N + 1) {
		if (v[i] == 0) {
			for (int j = i; j <= N; j *= i) {
				for (int k = j; k <= N; k += j) {
					v[k]++;
				}
			}
		}
		p[i] = p[i - 1] + v[i];
	}

	setup(); int tc; input(tc); while (tc--) {
		int a, b;
		input(a, b);

		print(p[a] - p[b]);
	}
}
