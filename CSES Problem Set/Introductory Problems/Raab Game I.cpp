#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(int a, int b, vector<int> &x, vector<int> &y) {
	set<int> s(x.begin(), x.end());
	set<int> t(y.begin(), y.end());
	if (s.size() != x.size() or t.size() != y.size() or x.size() != y.size()) {
		arrprint(x);
		arrprint(y);
		return false;
	}
	rep(i, 0, x.size()) {
		a -= x[i] > y[i];
		b -= x[i] < y[i];
	}
	return a == 0 and b == 0;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, a, b;
		input(n, a, b);

		if (a == 0 and b == 0) {
			print("YES");
			vector<int> x(n);
			rep(i, 0, n) {
				x[i] = i + 1;
			}
			arrprint(x);
			arrprint(x);
			continue;
		}

		if (a + b > n or a == 0 or b == 0) {
			print("NO");
			continue;
		}

		bool flag = false;
		if (a > b) {
			flag = true;
			swap(a, b);
		}

		vector<int> x, y;
		rep(i, 0, n - a - b) {
			x.push_back(n - i);
			y.push_back(n - i);
		}
		n = a + b;
		int l = 1;
		rep(i, 0, a - 1) {
			x.push_back(l + 1);
			y.push_back(l);
			x.push_back(l);
			y.push_back(l + 1);
			l += 2;
		}
		x.push_back(n);
		y.push_back(l);
		l++;
		rep(i, 0, b - a + 1) {
			x.push_back(l - 1);
			y.push_back(l);
			l++;
		}

		if (flag) {
			swap(x, y);
			swap(a, b);
		}
		print("YES");
		arrprint(x);
		arrprint(y);
		// assert(check(a, b, x, y));
	}
}
