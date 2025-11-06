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
		int n, m;
		input(n, m);

		vector<int> a(n), b(m), c(m);
		arrput(a);
		arrput(b);
		arrput(c);

		vector<pair<int, int>> v(m);
		rep(i, 0, m) {
			v[i] = {b[i], c[i]};
		}
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.second == 0 and b.second == 0) {
				return a.first < b.first;
			}
			if (a.second == 0) {
				return false;
			}
			if (b.second == 0) {
				return true;
			}
			return a < b;
		});

		multiset<int> s(a.begin(), a.end());
		int res = 0;
		for (auto [b, c] : v) {
			set<int>::iterator i = s.lower_bound(b);
			if (i == s.end()) {
				continue;
			}
			int x = *i;
			s.erase(i);
			res++;
			if (c) {
				s.insert(max(x, c));
			}
		}
		print(res);
	}
}
