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

int minimax(vector<int> a, vector<int> b) {
	if (a.size() == 0) {
		return 0;
	}

	int res = -1e15;
	range(j, 0, (int) a.size()) {
		if (!a[j] or !b[j]) {
			continue;
		}

		vector<int> x(a.begin(), a.end());
		vector<int> y(b.begin(), b.end());
		x.erase(x.begin() + j);
		y.erase(y.begin() + j);
		res = max(res, -minimax(y, x) + (a[j] - 1));
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		print(minimax(a, b));
	}
}
