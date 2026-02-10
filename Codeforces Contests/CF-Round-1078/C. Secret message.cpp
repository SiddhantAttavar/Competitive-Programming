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
	const int N = 1e5;
	vector<vi> d(N + 1);
	rep(i, 1, N + 1) {
		for (int j = i; j <= N; j += i) {
			d[j].push_back(i);
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<string> s(k);
		arrput(s);

		vector<bitset<26>> v(n, 0);
		rep(i, 0, n) {
			rep(j, 0, k) {
				v[i][s[j][i] - 'a'] = true;
			}
		}

		for (int x : d[n]) {
			vector<bitset<26>> a(x, 0);
			rep(j, 0, x) {
				a[j] = ~a[j];
			}
			for (int i = 0; i < n; i += x) {
				rep(j, 0, x) {
					a[j] &= v[i + j];
				}
			}
			string s;
			rep(j, 0, x) {
				int u = a[j]._Find_first();
				if (u == 26) {
					break;
				}
				s += u + 'a';
			}
			if (sz(s) < x) {
				continue;
			}
			string res;
			while (sz(res) < n) {
				res += s;
			}
			print(res);
			break;
		}
	}
}
