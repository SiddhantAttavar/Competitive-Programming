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

		vector<vi> a(n);
		map<int, vi> m;
		rep(i, 0, n) {
			int l;
			input(l);
			vi v(l);
			arrput(v);

			reverse(all(v));
			set<int> s;
			rep(j, 0, sz(v)) {
				if (!s.count(v[j])) {
					s.insert(v[j]);
					a[i].push_back(v[j]);
					m[v[j]].push_back(i);
				}
			}
		}

		vi res;
		vi b(n, false);
		rep(k, 0, n) {
			int i = -1;
			rep(j, 0, n) {
				if (!b[j] and (i == -1 or a[j] < a[i])) {
					i = j;
				}
			}
			b[i] = true;
			for (int x : a[i]) {
				res.push_back(x);
				for (int j : m[x]) {
					if (j != i) {
						a[j].erase(find(all(a[j]), x));
					}
				}
			}
		}
		arrprint(res);
	}
}
