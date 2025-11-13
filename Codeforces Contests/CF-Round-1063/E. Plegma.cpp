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

vector<bool> x, y;

pair<int, int> encode() {
	int n, c;
	input(n, c);

	vector<vector<bool>> a(n, vector<bool>(n)), b(n, vector<bool>(n));
	rep(i, 0, n) {
		string s;
		input(s);
		rep(j, 0, n) {
			a[i][j] = s[j] == '1';
			b[j][i] = s[j] == '1';
		}
	}

	int p = -1, q = -1;
	int u = -1;
	rep(i, 1, n) {
		if (a[i][0] != a[0][0]) {
			u = i;
			break;
		}
	}

	if (u == -1) {
		rep(j, 1, n) {
			rep(i, 0, n) {
				if (a[i][j] != a[0][0]) {
					u = j;
					break;
				}
			}
			if (u != -1) {
				break;
			}
		}

		p = 0;
		q = c ^ a[0][0] ? u : 0;
	}
	else {
		q = 0;
		p = c ^ a[0][0] ? 0 : u;
	}
	assert(min(p, q) >= 0 and max(p, q) < n);
	x = a[p];
	y = b[q];
	return {p, q};
}

void decode(vector<bool> &x, vector<bool> &y) {
	bool flag = false;
	for (int i : y) {
		if (i != x[0]) {
			flag = true;
			break;
		}
	}
	print(flag ^ x[0]);
}

int32_t main() {
	setup();

	string s;
	input(s);

	int tc;
	input(tc);
	while (tc--) {
		if (s == "first") {
			pair<int, int> p = encode();
			print(p.first + 1, p.second + 1);
		}
		else if (s == "second") {
			int n;
			input(n);
			string s, t;
			input(s, t);

			vector<bool> a(n), b(n);
			rep(i, 0, n) {
				a[i] = s[i] == '1';
				b[i] = t[i] == '1';
			}

			decode(a, b);
		}
		else {
			pair<int, int> p = encode();
			decode(x, y);
		}
	}
}
