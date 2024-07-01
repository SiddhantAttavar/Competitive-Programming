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

		vector<int> x;
		range(i, 0, (int) s.size()) {
			if (s[i] == '1') {
				x.push_back(i);
			}
		}

		if (x.size() > 3) {
			print("NO");
		}
		else if (x.size() >= 2) {
			print("YES");
		}
		else if (x.size() == 1 and x[0] < (int) s.size() - 2) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
