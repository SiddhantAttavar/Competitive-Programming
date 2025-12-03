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

int32_t main() {
	int N = 1e5;
	vector<int> spf(N + 1);
	iota(spf.begin(), spf.end(), 0);
	vector<int> p;
	rep(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}
		p.push_back(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		if (n == 1) {
			print(1);
			continue;
		}

		map<int, int> m;
		for (int i : p) {
			while (n % i == 0) {
				m[i]++;
				n /= i;
			}
		}
		if (n > 1) {
			m[n]++;
		}

		int x = 0;
		for (auto [k, v] : m) {
			x += v;
		}
		print(min(x, 3ll));
	}
}
