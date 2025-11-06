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

int get(int p, int n) {
	int res = 0, z = p;
	while (z <= n) {
		res += n / z;
		z *= p;
	}
	return res;
}

int32_t main() {
	const int N = 1e7 ;
	bitset<N> seive = 0;
	seive = ~seive;
	vector<int> primes;
	rep(i, 2, N + 1) {
		if (!seive[i]) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			seive[j] = false;
		}
		primes.push_back(i);
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<array<int, 3>> a(n, {2, 2, 1});
		for (int p : primes) {
			int z = p, c = 1;
			while (z <= m) {
				int k = get(p, n), l = 1, r = n - 1, u = -1;
				while (l <= r) {
					int m = (l + r) / 2;
					if (k - get(p, m) >= c) {
						u = m;
						l = m + 1;
					}
					else {
						r = m - 1;
					}
				}
				if (u != -1) {
					a[u] = max(a[u], {z, p, c});
				}
				z *= p;
				c++;
			}
		}

		int res = 0;
		rep(i, 1, n) {
			a[i] = max(a[i], a[i - 1]);
			res += get(a[i][1], i) / a[i][2];
			cout << a[i][0] << ' ';
		}
		cout << endl;
		print(res);
	}
}
