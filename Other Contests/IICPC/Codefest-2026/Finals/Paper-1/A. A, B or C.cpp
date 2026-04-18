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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n), b(n), c(n);
		rep(i, 0, n) {
			input(a[i], b[i], c[i]);
		}

		vector<multiset<int>> v(n);
		vector<pii> l;
		rep(i, 0, n) {
			v[i].insert(a[i]);
			v[i].insert(b[i]);
			v[i].insert(c[i]);
			l.push_back({a[i], i});
			l.push_back({b[i], i});
			l.push_back({c[i], i});
		}
		sort(all(l));

		multiset<int> s;
		rep(i, 0, n) {
			s.insert(*v[i].begin());
		}

		int res = 1e18;
		for (auto [x, i] : l) {
			res = min(res, *s.rbegin() - x);
			v[i].erase(v[i].find(x));
			s.erase(s.find(x));
			if (v[i].empty()) {
				break;
			}
			s.insert(*v[i].begin());
		}
		print(res);
	}
}
