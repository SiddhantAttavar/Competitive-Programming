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

const int N = 1e6; 

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> l(N, N);
	rep(i, 0, n) {
		int a, b;
		input(a, b);
		l[a - 1] = min(l[a - 1], b - 1);
	}
	for (int i = N - 2; i >= 0; i--) {
		l[i] = min(l[i + 1], l[i]);
	}

	vector<vector<int>> v(N, vector<int>(20, N));
	for (int i = N - 1; i >= 0; i--) {
		v[i][0] = l[i];
		rep(j, 1, 20) {
			if (v[i][j - 1] < N) {
				v[i][j] = v[v[i][j - 1]][j - 1];
			}
		}
	}

	while (q--) {
		int a, b;
		input(a, b);
		a--;
		b--;

		int res = 0;
		for (int j = 19; j >= 0; j--) {
			if (v[a][j] <= b) {
				res |= 1 << j;
				a = v[a][j];
			}
		}
		print(res);
	}
}
