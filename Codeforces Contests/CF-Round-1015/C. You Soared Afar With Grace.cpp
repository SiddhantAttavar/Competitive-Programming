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

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		map<pair<int, int>, set<int>> m;
		rep(i, 0, n) {
			a[i]--;
			b[i]--;
			m[{a[i], b[i]}].insert(i);
		}

		vector<pair<int, int>> res;
		bool flag = true;
		bool k = false;
		rep(i, 0, n / 2) {
			m[{a[i], b[i]}].erase(i);
			if (m[{b[i], a[i]}].empty()) {
				if (n % 2 == 0 or k or a[i] != b[i]) {
					flag = false;
					break;
				}

				k = true;
				res.push_back({i, n / 2});
				m[{a[i], b[i]}].erase(i);
				m[{a[i], b[i]}].insert(n / 2);
				m[{a[n / 2], b[n / 2]}].erase(n / 2);
				m[{a[n / 2], b[n / 2]}].insert(i);
				swap(a[i], a[n / 2]);
				swap(b[i], b[n / 2]);
				i--;
				continue;
			}

			int j = *m[{b[i], a[i]}].begin();
			m[{b[i], a[i]}].erase(m[{b[i], a[i]}].begin());
			if (j != n - i - 1) {
				res.push_back({j, n - i - 1});
				m[{a[n - i - 1], b[n - i - 1]}].erase(n - i - 1);
				m[{a[n - i - 1], b[n - i - 1]}].insert(j);
				swap(a[j], a[n - i - 1]);
				swap(b[j], b[n - i - 1]);
			}
		}

		if (!flag) {
			print(-1);
			continue;
		}

		print(res.size());
		for (pair<int, int> p : res) {
			print(p.first + 1, p.second + 1);
		}
		// cout.flush();
		// rep(i, 0, n) {
		// 	assert(a[i] == b[n - i - 1]);
		// }
	}
}
