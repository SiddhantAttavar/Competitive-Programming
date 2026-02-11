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
	setup();

	int n;
	input(n);

	vector<string> s(n);
	arrput(s);

	vector<vi> x(2 * n);
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (s[i][j] != '?') {
				x[i + j].push_back(s[i][j] - '0');
			}
		}
	}

	vi y(2 * n);
	rep(i, 0, 2 * n) {
		if (x[i].empty()) {
			y[i] = 0;
			continue;
		}
		if (*min_element(all(x[i])) != *max_element(all(x[i]))) {
			print(-1);
			return 0;
		}
		y[i] = x[i][0];
	}

	rep(i, 0, n) {
		rep(j, 0, n) {
			cout << (char) (y[i + j] + '0');
		}
		cout << endl;
	}
}
