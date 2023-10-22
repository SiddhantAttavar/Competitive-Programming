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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		map<int, int> m;
		for (int i : a) {
			m[i]++;
		}

		vector<int> dp(n);
		dp[0] = (m[a[0]] == 1);
		m[a[0]]--;
		set<int> s;
		s.insert(a[0]);
		range(i, 1, n) {
			s.insert(a[i]);
			// arrPrint(s);
			if (m[a[i]] == 1) {
				dp[i] = s.size();
			}
			m[a[i]]--;
		}
		// arrPrint(dp);

		int res = 0;
		for (int i : dp) {
			res += i;
		}

		print(res);
		// print("");
	}
}
