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

bool check(string &x, string &y, string &s, string &t) {
	int n = sz(x);
	vi p(n, -1), q(n, -1);
	if (x[0] == '+') {
		p[0] = 1;
		q[0] = y[0] == '+' ? 2 : 0;
	}
	rep(i, 1, n) {
		if (p[i - 1] != -1) {
			p[i] = p[i - 1] + (x[i] == '+' ? 1 : -1);
		}
		if (p[i] != -1) {
			q[i] = p[i] + (y[i] == '+' ? 1 : -1);
		}
		if (q[i - 1] != -1) {
			q[i] = max(q[i], q[i - 1] + (y[i] == '+' ? 1 : -1));
		}
	}
	rep(i, 0, n) {
		if ((p[i] == -1) != (s[i] == '0')) {
			return false;
		}
		if ((q[i] == -1) != (t[i] == '0')) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s, t;
		input(s, t);

		string x(n, '-'), y(n, '-');
		rep(i, 0, n) {
			if (s[i] == '1') {
				x[i] = i % 2 ? '-' : '+';
			}
			else {
				break;
			}
		}

		bool b = false;
		rep(i, 0, n) {
			if (t[i] == '0') {
				b = false;
			}
			else if (b) {
				y[i] = y[i - 1] == '-' ? '+' : '-';
			}
			else {
				b = true;
				y[i] = x[i] == '-' ? '+' : '-';
			}
		}

		if (check(x, y, s, t)) {
			print("YES");
			print(x);
			print(y);
		}
		else {
			print("NO");
		}
	}
}
