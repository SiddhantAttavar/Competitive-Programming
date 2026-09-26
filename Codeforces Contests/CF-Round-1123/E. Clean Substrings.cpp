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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		string s;
		input(s);

		vi t(n, false);
		int res = 0, x = 1;
		rep(i, 1, n) {
			x += s[i] == s[0];
			if (s[i] != s[i - 1]) {
				t[i] = true;
				res += i * (n - i);
			}
		}

		cout << (res + x * (n - x)) / 2;

		while (q--) {
			int i;
			input(i);
			i--;

			if (i == 0) {
				x = n + 1 - x;
				s[0] ^= '0' ^ '1';
			}
			else {
				x -= s[i] == s[0];
				s[i] ^= '0' ^ '1';
				x += s[i] == s[0];

				if (t[i]) {
					res -= i * (n - i);
					t[i] = false;
				}
				else {
					res += i * (n - i);
					t[i] = true;
				}
			}

			if (i + 1 < n) {
				i++;
				if (t[i]) {
					res -= i * (n - i);
					t[i] = false;
				}
				else {
					res += i * (n - i);
					t[i] = true;
				}
			}

			cout << ' ' << (res + x * (n - x)) / 2;
		}
		cout << endl;
	}
}
