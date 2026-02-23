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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

vi get(vector<pii> &a) {
	vi z;
	for (auto [l, r] : a) {
		z.push_back(l);
		z.push_back(r);
	}
	sort(all(z));
	z.erase(unique(all(z)), z.end());

	int n = sz(a), m = sz(z);
	vector<vi> p(m), q(m);
	rep(i, 0, n) {
		p[lower_bound(all(z), a[i].first) - z.begin()].push_back(i);
		q[lower_bound(all(z), a[i].second) - z.begin()].push_back(i);
	}
	multiset<int> s;
	vi res(n, 0);
	rep(i, 0, m) {
		for (int j : p[i]) {
			s.insert(a[j].first);
		}
		for (int j : q[i]) {
			multiset<int>::iterator u = prev(s.upper_bound(a[j].first));
			if (u != s.begin()) {
				res[j] = a[j].first - *prev(u);
			}
		}
		for (int j : q[i]) {
			s.erase(s.find(a[j].first));
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<pii> a(n), b(n);
		rep(i, 0, n) {
			int l, r;
			input(l, r);
			a[i] = {l, r};
			b[i] = {-r, -l};
		}
		vi x = get(a), y = get(b);
		rep(i, 0, n) {
			print(x[i] + y[i]);
		}
	}
}
