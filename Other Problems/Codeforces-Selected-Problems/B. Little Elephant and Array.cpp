#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();
	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	vector<pair<pair<int, int>, int>> v(q);
	rep(i, 0, q) {
		input(v[i].first.first, v[i].first.second);
		v[i].first.first--;
		v[i].first.second--;
		v[i].second = i;
	}

	map<int, int> o;
	vector<int> b(n);
	rep(i, 0, n) {
		if (o.count(a[i])) {
			b[i] = o[a[i]];
		}
		else {
			b[i] = i;
			o[a[i]] = i;
		}
	}

	sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return make_pair(a.first.first / 320, a.first.second) < make_pair(b.first.first / 320, b.first.second);
	});

	int l = 0, r = -1, x = 0;
	vector<int> res(q);
	vector<int> m(n, 0);
	for (pair<pair<int, int>, int> p : v) {
		int s, e;
		tie(s, e) = p.first;

		while (r < e) {
			r++;
			x -= m[b[r]] == a[r];
			m[b[r]]++;
			x += m[b[r]] == a[r];
		}

		while (l > s) {
			l--;
			x -= m[b[l]] == a[l];
			m[b[l]]++;
			x += m[b[l]] == a[l];
		}

		while (r > e) {
			x -= m[b[r]] == a[r];
			m[b[r]]--;
			x += m[b[r]] == a[r];
			r--;
		}

		while (l < s) {
			x -= m[b[l]] == a[l];
			m[b[l]]--;
			x += m[b[l]] == a[l];
			l++;
		}

		res[p.second] = x;
	}

	for (int i : res) {
		print(i);
	}
}

