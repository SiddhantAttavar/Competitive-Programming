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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool debug = false;
int X = -1;
int K = 30;

int query(int m, int n) {
	assert(K);
	K--;
	if (debug) {
		return gcd(X + m, n);
	}
	print('?', m, n);
	cout.flush();
	int y;
	input(y);
	return y;
}

int32_t main() {
	vi pow6(15, 1);
	rep(i, 1, 15) {
		pow6[i] = 6 * pow6[i - 1];
	}
	setup(); int tc; input(tc); while (tc--) {
		int k;
		input(k);

		K = 30;
		if (debug) {
			input(X);
		}

		int m = 0;
		rep(i, 0, 12) {
			int x = query(m, pow6[i + 1]);
			if (x == pow6[i]) {
				if (query(m + pow6[i], pow6[i + 1]) == pow6[i + 1]) {
					m += pow6[i];
				}
				else {
					m += 5 * pow6[i];
				}
			}
			else if (x == 2 * pow6[i]) {
				if (query(m + 2 * pow6[i], pow6[i + 1]) == pow6[i + 1]) {
					m += 2 * pow6[i];
				}
				else {
					m += 4 * pow6[i];
				}
			}
			else if (x == 3 * pow6[i]) {
				m += 3 * pow6[i];
			}
		}

		print('!', pow6[12] - m);
		cout.flush();

		if (debug) {
			assert(pow6[12] - m == X);
		}
	}
}
