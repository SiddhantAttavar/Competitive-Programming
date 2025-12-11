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

		vector<int> x, y;
		for (int i : a) {
			if (i % 2 == 0) {
				x.push_back(i);
			}
			else {
				y.push_back(i);
			}
		}

		sort(y.begin(), y.end());
		reverse(y.begin(), y.end());
		sort(x.begin(), x.end());
		reverse(x.begin(), x.end());

		vector<int> p(x.size() + 1, 0);
		rep(i, 0, x.size()) {
			p[i + 1] = p[i] + x[i];
		}

		rep(l, 1ll, n + 1) {
			if (y.empty()) {
				cout << 0 << ' ';
				continue;
			}

			if (l - 1 <= x.size()) {
				cout << y[0] + p[l - 1] << ' ';
				continue;
			}

			if ((l - x.size()) % 2) {
				cout << y[0] + p.back() << ' ';
				continue;
			}

			if (x.empty() or y.size() + x.size() - 1 < l) {
				cout << 0 << ' ';
			}
			else {
				cout << y[0] + p.back() - x.back() << ' ';
			}
		}
		cout << endl;
	}
}
