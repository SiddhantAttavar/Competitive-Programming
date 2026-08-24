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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool on_line(pii a, pii b, pii c) {
	if (c == a or c == b) {
		return true;
	}
	if (a == b) {
		return false;
	}
	return (b.second - a.second) * (c.first - a.first) == (b.first - a.first) * (c.second - a.second);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<pii> v(n);
	rep(i, 0, n) {
		input(v[i].first, v[i].second);
	}

	v.erase(unique(all(v)), v.end());
	rep(i, 0, 100) {
		vector<pii> w = v;
		shuffle(all(w), rng);
		vector<vi> res(4);
		rep(j, 0, 4) {
			// print(i, j, sz(w));
			// for (auto [a, b] : w) {
			// 	cout << a << ',' << b << ' ';
			// }
			// cout << endl;
			if (w.empty()) {
				res[j] = {w[0].first, w[0].second, (int) rng() % ((int) 1e9), (int) rng() % ((int) 1e9)};
				continue;
			}
			if (sz(w) == 1) {
				res[j] = {w[0].first, w[0].second, (int) rng() % ((int) 1e9), (int) rng() % ((int) 1e9)};
				w.clear();
				continue;
			}

			pii a = w[0], b = w[1];
			res[j] = {a.first, a.second, b.first, b.second};
			vector<pii> nw;
			for (pii q : w) {
				if (!on_line(a, b, q)) {
					nw.push_back(q);
				}
			}
			w = nw;
		}

		if (w.empty()) {
			print("possible");
			rep(j, 0, 4) {
				arrprint(res[j]);
			}
			return 0;
		}
	}

	print("impossible");
}
