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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define ll long long

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	if ((a - b) % g) {
		return -1;
	}
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int minv(int a, int m) {
	int x, y;
	euclid(a, m, x, y);
	x = (x % m + m) % m;
	assert(a * x % m == 1);
	return x;
}

int get(int x, int v, int n) {
	v %= n;
	int g = gcd(v, n);
	if (x % g) {
		return -1;
	}
	x /= g;
	v /= g;
	n /= g;

	int w = minv(v, n);
	int t = (n - x) * w % n;
	return t;
}

int brute(int x, int y, int vx, int vy, int n) {
	int t = 0;
	while (x % n or y % n) {
		x += vx;
		y += vy;
		t++;
	}
	return t;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x, y, vx, vy;
		input(n, x, y, vx, vy);

		int g = gcd(vx, vy);
		vx /= g;
		vy /= g;

		int a = get(x, vx, n), b = get(y, vy, n), p = n / gcd(vx, n), q = n / gcd(n, vy);
		if (a == -1 or b == -1) {
			print(-1);
			continue;
		}

		assert((x + a * vx) % n == 0);
		assert((y + b * vy) % n == 0);

		int t = crt(a, p, b, q);
		if (t == -1) {
			print(-1);
			continue;
		}
		// assert(t == brute(x, y, vx, vy, n));
		assert((x + t * vx) % n == 0);
		assert((y + t * vy) % n == 0);

		int u = (x + t * vx) / n, v = (y + t * vy) / n;
		int res = u - 1 + v - 1;
		res += (u + v) / 2;
		res += abs(u - v) / 2;
		print(res);
	}
}
