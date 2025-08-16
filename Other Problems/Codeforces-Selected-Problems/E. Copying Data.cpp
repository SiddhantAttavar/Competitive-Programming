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

	vector<int> a(n), b(n);
	arrput(a);
	arrput(b);
	b.insert(b.end(), a.begin(), a.end());

	multiset<pair<pair<int, int>, int>> s;
	s.insert({{0, n - 1}, 0});
	while (m--) {
		int o;
		input(o);

		if (o == 1) {
			int x, y, k;
			input(x, y, k);
			// l.upd(y - 1, y + k - 2, x + n - y);

			x--;
			y--;
			int z = y + k - 1;

			while (true) {
				auto i = s.lower_bound({{y, -1}, -1});
				if (i == s.begin()) {
					break;
				}
				i--;
				if (i->first.second < y) {
					break;
				}
				if (i->first.first >= y) {
					s.erase(i);
					continue;
				}

				auto a = *i;
				s.erase(i);
				if (a.first.second > z) {
					auto b = a;
					b.first.first = z + 1;
					s.insert(b);
				}
				a.first.second = y - 1;
				s.insert(a);
				break;
			}

			while (true) {
				auto i = s.lower_bound({{y, -1}, -1});
				if (i == s.end()) {
					break;
				}
				if (i->first.first > z) {
					break;
				}
				if (i->first.second <= z) {
					s.erase(i);
					continue;
				}

				auto x = *i;
				s.erase(i);
				x.first.first = z + 1;
				s.insert(x);
				break;
			}

			s.insert({{y, z}, x + n - y});
		}
		else {
			int x;
			input(x);
			x--;
			auto i = s.upper_bound({{x, n}, -1});
			assert(i != s.begin());
			i--;
			print(b[i->second + x]);
		}
	}
}
