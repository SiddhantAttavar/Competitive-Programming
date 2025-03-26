#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	vector<pair<int, pair<int, int>>> v, w;
	int N = 1e3;
	rep(i, 1, N) {
		if (i % 3 == 0) {
			continue;
		}
		rep(j, 1, N) {
			if (j % 3 == 0) {
				continue;
			}
			v.push_back({i + j + 2 * (min(i % 3, j % 3) == 2), {i, j}});
			if (i % 3 == 1 and j % 3 == 1) {
				w.push_back({i + j, {i, j}});
			}
		}
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> t(n);
		arrput(t);

		set<pair<int, int>> s;
		int l = 0, r = 0;
		for (int i : t) {
			if (i) {
				while (s.count(v[l].second)) {
					l++;
				}
				print(v[l].second.first, v[l].second.second);
				s.insert(v[l].second);
			}
			else {
				while (s.count(w[r].second)) {
					r++;
				}
				print(w[r].second.first, w[r].second.second);
				s.insert(w[r].second);
			}
		}
	}
}
