#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

		vector<int> a(n);
		arrPut(a);

		// vector<pair<int, int>> v;
		// int c = -1;
		// range(i, 0, n) {
		// 	if (a[i] - d * (i - c) > 0) {
		// 		v.push_back({a[i], i});
		// 		c = i;
		// 	}
		// }
		//
		// if (v.size() == 0) {
		// 	print(0);
		// 	continue;
		// }
		// 
		// // print("debug");
		// // cout.flush();
		//
		// int curr = v[0].first - d * v[0].second;
		// int res = curr;
		// range(i, 1, (int) v.size()) {
		// 	curr += v[i].first - d * (v[i].second - v[i - 1].second);
		// 	if (i < m) {
		// 		res = max(res, curr);
		// 	}
		// }
		//
		// // print("debug2");
		// // cout.flush();
		//
		// sort(v.begin(), v.end());
		// range(i, 0, (int) v.size() - m) {
		// 	curr -= v[i].first;
		// }
		// res = max(res, curr);
		//
		// print(res);

		vector<int> dp(n);
		dp[0] = max(0ll, a[0] - d);
		multiset<int> s;
		int c = 0;
		if (a[0] > 0) {
			s.insert(a[0]);
			c = a[0];
		}
		
		range(i, 1, n) {
			if (a[i] > 0) {
				if ((int) s.size() < m) {
					c += a[i];
					s.insert(a[i]);
				}
				else if (a[i] > *s.begin()) {
					c += a[i] - *s.begin();
					s.erase(s.begin());
					s.insert(a[i]);
				}
			}

			// print(c);
			// arrPrint(s);
			// print(*s.begin());
			dp[i] = max(dp[i - 1], c - d * (i + 1));
		}

		// arrPrint(dp);

		print(dp[n - 1]);
	}
}
