#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	// setup();
	int tc; input(tc); while (tc--) {
		int a, b;
		input(a, b);
		int o = b;
		
		if (a == b){
			print(0);
			continue;
		}
		
		vector<pair<int, int>> v;
		int c = 0;
		v.push_back({b, 0});
		while (b) {
			if (b % 2 == 0) {
				b /= 2;
			}
			else {
				b--;
			}
			// print(b);
			c++;
			v.push_back({b, c});
		}
		reverse(v.begin(), v.end());
		// for (pair<int, int> p : v) {
		// 	cout << p.first << ' ';
		// }
		// cout << endl;
		
		int res = 1e18;
		c = 0;
		if (a <= o) {
			int i = lower_bound(v.begin(), v.end(), pair<int, int>{a, 1e18}) - v.begin();
			if (i < v.size()) {
				res = min(res, c + v[i].second + (v[i].first - a));
			}
		}
		while (a > 1) {
			if (a % 2 == 0) {
				a /= 2;
			}
			else {
				a++;
			}
			// print(a);
			c++;
			if (a < o) {
				int i = lower_bound(v.begin(), v.end(), pair<int, int>{a, 1e18}) - v.begin();
				if (i < v.size()) {
					res = min(res, c + v[i].second + (v[i].first - a));
				}
			}
		}
		print(res);
	}
}
