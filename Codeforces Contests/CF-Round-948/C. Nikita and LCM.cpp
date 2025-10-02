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
	vector<int> p;
	rep(i, 0, N + 1) {
		spf[i] = i;
	}
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

		vector<int> a(n);
		arrput(a);

		int x = *max_element(a.begin(), a.end());
		bool flag = false;
		for (int i : a) {
			if (x % i) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print(n);
			continue;
		}

		map<int, int> m;
		for (int i : p) {
			while (x % i == 0) {
				m[i]++;
				x /= i;
			}
		}
		if (x > 1) {
			m[x]++;
		}

		vector<int> l = {1};
		for (auto [k, v] : m) {
			int z = 1;
			vector<int> nl = l;
			rep(i, 0, v) {
				z *= k;
				for (int j : l) {
					nl.push_back(j * z);
				}
			}
			l = nl;
		}

		int res = 0;
		set<int> s(a.begin(), a.end());
		for (int i : l) {
			if (s.count(i)) {
				continue;
			}

			int c = 0, x = 0;
			for (int j : a) {
				if (i % j == 0) {
					c++;
					x = x == 0 ? j : x * j / gcd(x, j);
				}
			}
			if (x == i) {
				res = max(res, c);
			}
		}
		print(res);
	}
}
