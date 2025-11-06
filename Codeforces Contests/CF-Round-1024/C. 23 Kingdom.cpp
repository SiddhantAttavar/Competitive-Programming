#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> v(n);
		rep(i, 0, n) {
			a[i]--;
			v[a[i]].push_back(i);
		}

		multiset<int> m;
		vector<int> p, q;
		for (int i = n - 1; i >= 0; i--) {
			m.insert(v[i].begin(), v[i].end());
			if (!m.empty()) {
				p.push_back(*m.begin());
				m.erase(m.begin());
			}
		}
		m.clear();
		for (int i = n - 1; i >= 0; i--) {
			m.insert(v[i].begin(), v[i].end());
			if (!m.empty()) {
				q.push_back(*m.rbegin());
				m.erase(prev(m.end()));
			}
		}
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		reverse(q.begin(), q.end());

		int x = 0, res = 0;
		rep(i, 0, p.size()) {
			x += q[i] - p[i];
			res = max(res, x);
		}
		print(res);
	}
}
