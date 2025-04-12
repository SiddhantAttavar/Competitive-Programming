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

int32_t main() {
	int N = 1e7;
	vector<int> spf(N + 1);
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
	set<int> p;
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		p.insert(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrput(a);

		vector<int> v(4);
		rep(i, 0, n) {
			if (a[i] == 1) {
				v[0]++;
			}
			else if (p.count(a[i])) {
				v[1]++;
			}
			else if (a[i] % 2 == 0 or p.count(a[i] - 2)) {
				v[2]++;
			}
			else {
				v[3]++;
			}
		}

		rep(i, 0, k) {
			if (v[3]) {
				v[3]--;
				v[1]++;
			}
			else if (v[2]) {
				v[2]--;
				v[1]++;
			}
		}

		print(v[1] + v[2] * 2 + v[3] * 3);
	}
}
