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

		if (k > n + 1) {
			print(-1);
			continue;
		}

		int l = 1, r = k - 1;
		vector<int> res;
		while (l < r) {
			res.push_back(l);
			res.push_back(r);
			l++;
			r--;
		}
		if (l == r) {
			res.push_back(l);
		}

		range(i, k, n + 1) {
			res.push_back(i);
		}

		arrPrint(res);
	}
}
