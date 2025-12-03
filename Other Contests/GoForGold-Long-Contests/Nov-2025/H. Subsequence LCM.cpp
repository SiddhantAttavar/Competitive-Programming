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

using namespace std;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

template <typename T, auto &M> struct Mod {
	using V = conditional_t<sizeof(T) <= 4, u64, u128>;
	static V inv(V x, V m) { return x > 1 ? m - inv(m % x, x) * m / x : 1; }
	make_unsigned_t<T> x;
	Mod() : x(0) {}
	template <typename U> Mod(U y) : x(y % M) { x >= M ? x += M : x; }
	operator T() const { return x; }
	Mod operator-() const { return Mod() -= *this; }
	template <typename U> Mod operator+(U rhs) const { return Mod(*this) += rhs; }
	template <typename U> Mod operator-(U rhs) const { return Mod(*this) -= rhs; }
	template <typename U> Mod operator*(U rhs) const { return Mod(*this) *= rhs; }
	template <typename U> Mod operator/(U rhs) const { return Mod(*this) /= rhs; }
	Mod &operator+=(Mod rhs) { return (x += rhs.x) >= M ? x -= M : x, *this; }
	Mod &operator-=(Mod rhs) { return (x -= rhs.x) >= M ? x += M : x, *this; }
	Mod &operator*=(Mod rhs) { return x = x * V(rhs.x) % M, *this; }
	Mod &operator/=(Mod rhs) { return x = x * inv(rhs.x, M) % M, *this; }
	template <typename U> Mod pow(U y) const { // O(log y) | 0^(-inf,0] -> 1
		Mod ans(1), base(*this);
		for (auto e = y < 0 ? ~y + u128(1) : +y; e; e >>= 1, base *= base) {
			e & 1 ? ans *= base : ans;
		}
		return y < 0 ? Mod(1) /= ans : ans;
	}
};

using Mint = Mod<int, MOD>;

const int N = 1e6;
Mint pow2[N + 1];

int32_t main() {
	pow2[0] = 1;
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}

	set<int> l = {1};
	vector<pair<int, int>> e[41];
	rep(i, 1, 41) {
		set<int> nl = l;
		for (int j : l) {
			int k = lcm(i, j);
			nl.insert(k);
			e[i].push_back({j, k});
		}
		reverse(e[i].begin(), e[i].end());
		l = nl;
	}

	vector<int> v(l.begin(), l.end());
	map<int, int> m;
	rep(i, 0, v.size()) {
		m[v[i]] = i;
	}
	rep(i, 0, 41) {
		rep(j, 0, e[i].size()) {
			e[i][j] = {m[e[i][j].first], m[e[i][j].second]};
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> f(41, 0);
		while (n--) {
			int x;
			input(x);
			f[x]++;
		}

		Mint dp[v.size()];
		fill(dp, dp + v.size(), 0);
		dp[0] = 1;
		rep(i, 1, 41) {
			Mint z = pow2[f[i]] - 1;
			for (auto [j, k] : e[i]) {
				dp[k] += dp[j] * z;
			}
		}

		dp[0] -= 1;
		Mint res = 0;
		rep(i, 0, v.size()) {
			res += dp[i] * v[i];
		}
		print(res);
	}
}
