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

int32_t main() {
	setup();

	int n;
	input(n);

	multiset<int> a, b, c, d;
	vi p(n), q(n), r(n), s(n);
	rep(i, 0, n) {
		input(p[i], q[i], r[i], s[i]);
		a.insert(p[i]);
		b.insert(q[i]);
		c.insert(r[i]);
		d.insert(s[i]);
	}

	rep(i, 0, n) {
		a.erase(a.find(p[i]));
		b.erase(b.find(q[i]));
		c.erase(c.find(r[i]));
		d.erase(d.find(s[i]));
		if (*a.rbegin() <= *c.begin() and *b.rbegin() <= *d.begin()) {
			print(*a.rbegin(), *b.rbegin());
			return 0;
		}
		a.insert(p[i]);
		b.insert(q[i]);
		c.insert(r[i]);
		d.insert(s[i]);
	}
	print(-1);
}
