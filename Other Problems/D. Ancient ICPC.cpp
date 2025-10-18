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
	setup();

	int n, m;
	input(n, m);

	rep(i, 0, n) {
		int a, b;
		input(a, b);

		vector<tuple<int, int, int>> v(m), res(m);
		vector<pair<pair<int, int>, int>> l;
		rep(i, 0, m) {
			char c;
			input(c);

			if (c == '+') {
				int x, y;
				input(x, c, y);

				v[i] = {1, x, y};
				res[i] = {1, x, y};
				a--;
				b -= 20 * (x - 1) + y;
			}
			else if (c == '?') {
				int x, y;
				input(x, y);

				v[i] = {0, x, y};
				res[i] = {-1, y, 300};
				l.push_back({{x - 1, y - x}, i});
			}
			else if (c == '-') {
				int x;
				input(x);

				v[i] = {-1, x, 300};
				res[i] = {-1, x, 300};
			}
			else {
				v[i] = {-1, 0, 300};
				res[i] = {-1, 0, 300};
			}
		}

		bool flag = false;
		rep(i, 0, 1 << l.size()) {
			if (__builtin_popcount(i) != a) {
				continue;
			}

			int x = 0, y = 0;
			rep(j, 0, l.size()) {
				if (i >> j & 1) {
					x += 240 + 20 * l[j].first.second;
					y += 299 + 20 * (l[j].first.first + l[j].first.second);
				}
			}

			if (x > b or y < b) {
				continue;
			}

			flag = true;
			b -= x;
			rep(j, 0, l.size()) {
				if (!(i >> j & 1)) {
					continue;
				}
				int x = l[j].first.second + 1, y = 240;
				int t = min(l[j].first.first, b / 20);
				x += t;
				b -= 20 * t;
				res[l[j].second] = {1, x, y};
			}
			rep(j, 0, l.size()) {
				if (!(i >> j & 1)) {
					continue;
				}
				auto [z, x, y] = res[l[j].second];
				int t = min(59ll, b);
				y += t;
				b -= t;
				res[l[j].second] = {1, x, y};
			}
			break;
		}

		if (!flag) {
			print("No");
			continue;
		}

		print("Yes");
		rep(i, 0, m) {
			auto [z, x, y] = res[i];
			if (z == 1) {
				cout << "+ " << x << '/' << y << endl;
			}
			else if (x == 0) {
				cout << ".\n";
			}
			else {
				cout << "- " << x << endl;
			}
		}
	}
}
