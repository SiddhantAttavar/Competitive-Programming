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
		int n, m, d;
		input(n, m, d);

		vector<int> s(m);
		arrPut(s);
		s.insert(s.begin(), 1 - d);
		s.push_back(n + 1);

		int res = 2e9;
		vector<int> v;
		range(i, 1, m + 1) {
			int a = s[i] - s[i - 1] - 1;
			int b = s[i + 1] - s[i] - 1;
			int c = s[i + 1] - s[i - 1] - 1;
			int y = c / d - (a / d + b / d);
			if (y < res) {
				res = y;
				v.clear();
			}
			if (y == res) {
				v.push_back(s[i]);
			}
		}

		range(i, 1, (int) s.size()) {
			res += (s[i] - s[i - 1] - 1) / d;
		}
		res += m - 1;

		print(res, v.size());
	}
}
