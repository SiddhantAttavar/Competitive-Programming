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
	setup(); int tc; input(tc); while (tc--) {
		int k, m;
		input(k, m);

		vector<vi> res;
		vi a(k);
		rep(i, 0, k) {
			a[i] = 1ll << i;
		}
		bool flag = false;
		rep(i, 0, k) {
			if (m >> i & 1) {
				vi b = a;
				b.erase(b.begin() + i);
				res.push_back(b);
			}
			rep(j, 0, i) {
				if ((m >> j & 1) == (m >> i & 1) or flag) {
					continue;
				}
				flag = true;
				vi c = a;
				c[j] |= c[i];
				c.erase(c.begin() + i);
				res.push_back(c);
			}
		}

		print(sz(res));
		for (vi v : res) {
			cout << sz(v) << ' ';
			arrprint(v);
		}
	}
}
