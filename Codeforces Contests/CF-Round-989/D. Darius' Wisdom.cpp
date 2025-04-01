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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		set<int> x, y, z;
		rep(i, 0, n) {
			if (a[i] == 0) {
				x.insert(i);
			}
			else if (a[i] == 1) {
				y.insert(i);
			}
			else {
				z.insert(i);
			}
		}

		vector<pair<int, int>> res;
		for (int i = n - 1; i >= n - z.size(); i--) {
			if (a[i] == 2) {
				continue;
			}
			z.insert(i);

			if (a[i] == 0) {
				x.erase(i);
				int j = *y.begin();
				a[i] = 1;
				a[j] = 0;
				y.erase(j);
				x.insert(j);
				res.push_back({i + 1, j + 1});
			}

			y.erase(i);
			int j = *z.begin();
			a[i] = 2;
			a[j] = 1;
			z.erase(j);
			y.insert(j);
			res.push_back({i + 1, j + 1});
		}

		rep(i, 0, x.size()) {
			if (a[i] == 0) {
				continue;
			}
			x.insert(i);

			y.erase(i);
			int j = *x.rbegin();
			a[i] = 0;
			a[j] = 1;
			x.erase(j);
			y.insert(j);
			res.push_back({i + 1, j + 1});
		}

		print(res.size());
		for (pair<int, int> p : res) {
			print(p.first, p.second);
		}
	}
}
