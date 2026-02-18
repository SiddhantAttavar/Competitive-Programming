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
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vi f(n);
		for (int i : a) {
			f[i - 1]++;
		}

		vi p, q;
		rep(i, 0, n) {
			if (f[i]) {
				p.push_back(i);
			}
			else {
				q.push_back(i);
			}
		}

		vi res(n);
		int u = p.back();
		rep(i, 0, sz(p) - 1) {
			res[p[i]] = p[i + 1] + 1;
			f[p[i + 1]]--;
		}
		for (int i : q) {
			while (!f[p.back()]) {
				p.pop_back();
			}
			res[i] = p.back() + 1;
			f[p.back()]--;
		}
		while (!f[p.back()]) {
			p.pop_back();
		}
		res[u] = p[0] + 1;
		arrprint(res);
	}
}
