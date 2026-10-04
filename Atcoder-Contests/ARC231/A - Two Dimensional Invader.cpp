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
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

const int K = 500;

int get(int i, int j, vi &l) {
	if (l[i] > l[j]) {
		return 0;
	}
	int p = l[j] - l[i], q = 2 * (j - i);
	return (p + q - 1) / q;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vi> v(K, vi(K, 1e18));
		int c = 0, res = 0;
		rep(i, 0, n) {
			int x, y, z;
			input(x, y, z);

			int a = c + x * x + y * y;
			rep(j, 0, K) {
				a = min(a, c + (x - j) * (x - j) + v[j][y]);
			}
			c += z;
			res = min(res, a - c);

			rep(j, 0, K) {
				v[x][j] = min(v[x][j], a - c + (y - j) * (y - j));
			}
		}
		
		print(c + res);
	}
}
