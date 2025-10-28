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

bool debug = false;
vector<int> b;
int K = 0;

void swap_q(int i, vector<int> &l, vector<int> &a) {
	assert(K);
	K--;
	l.push_back(i);
	swap(a[i], a[i + 1]);
	if (!debug) {
		print("swap", i + 1);
		cout.flush();
		return;
	}
	swap(b[i], b[i + 1]);
}

int throw_q(int i) {
	assert(K);
	K--;
	if (!debug) {
		print("throw", i + 1);
		cout.flush();
		int x;
		input(x);
		return x;
	}
	int res = 0;
	while (i < b.size()) {
		i += b[i];
		res++;
	}
	return res;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		K = (3 * n + 1) / 2;
		if (debug) {
			b.resize(n);
			arrput(b);
		}

		vector<int> l;
		vector<int> a(n, 0), dp(n + 2, 0);
		a[n - 2] = 3 - throw_q(n - 2);
		swap_q(n - 2, l, a);
		a[n - 2] = 3 - throw_q(n - 2);
		dp[n - 1] = 1;
		dp[n - 2] = 1 + (a[n - 2] == 1);

		for (int i = n - 3; i >= 0; i--) {
			if (dp[i + 1] == dp[i + 2]) {
				dp[i] = dp[i + 1] + 1;
			}
			else {
				a[i] = throw_q(i) == dp[i + 1] + 1 ? 1 : 2;
				dp[i] = a[i] == 1 ? dp[i + 1] + 1 : dp[i + 2] + 1;
			}
		}
		rep(i, 0, n) {
			if (a[i] == 0) {
				swap_q(i, l, a);
				a[i + 1] = throw_q(i + 1) == dp[i + 2] + 1 ? 1 : 2;
			}
		}

		reverse(l.begin(), l.end());
		for (int i : l) {
			swap(a[i], a[i + 1]);
		}
		cout << "! ";
		arrprint(a);
		cout.flush();
	}
}
