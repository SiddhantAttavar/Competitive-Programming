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

		vi v(n);
		arrput(v);

		n = min(n, 100ll);
		v.resize(n);

		vector<vector<pii>> p(n, vector<pii>(31, {-1, -1})), s(n, vector<pii>(31, {-1, -1}));
		rep(i, 1, n) {
			p[i] = p[i - 1];
			rep(j, 0, i) {
				p[i][__builtin_popcountll(v[i] ^ v[j])] = {j, i};
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			s[i] = s[i + 1];
			rep(j, i + 1, n) {
				s[i][__builtin_popcountll(v[i] ^ v[j])] = {i, j};
			}
		}

		bool flag = false;
		rep(i, 1, n) {
			rep(j, 0, 31) {
				if (p[i - 1][j].first != -1 and s[i][j].first != -1) {
					print(p[i - 1][j].first + 1, p[i - 1][j].second + 1, s[i][j].first + 1, s[i][j].second + 1);
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			print(-1);
		}
	}
}
