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

vi get(vi &v) {
	vi res;
	rep(i, 0, 1 << sz(v)) {
		int c = 0;
		rep(j, 0, sz(v)) {
			if (i >> j & 1) {
				c += v[j];
			}
		}
		res.push_back(c);
	}
	return res;
}

int32_t main() {
	setup();

	int n, s;
	input(n, s);

	vi a(n);
	arrput(a);

	vi b;
	while (sz(a) > sz(b)) {
		b.push_back(a.back());
		a.pop_back();
	}

	vi p = get(b), q = get(a);
	map<int, int> m;
	for (int i : q) {
		m[i]++;
	}

	int res = 0;
	for (int i : p) {
		res += m[s - i];
	}
	print(res);
}
