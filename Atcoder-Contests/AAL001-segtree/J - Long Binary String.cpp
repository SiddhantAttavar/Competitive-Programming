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
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

const ll N = 1e18;
vector<pii> graph = {{-1, -1}};
vector<ll> seg = {0};
vector<bool> lazy = {0};

void pull(int i) {
	seg[i] = (graph[i].first == -1 ? 0 : seg[graph[i].first]) + (graph[i].second == -1 ? 0 : seg[graph[i].second]);
}

void push(int i, ll L, ll R) {
	if (lazy[i]) {
		seg[i] = R - L + 1 - seg[i];
	}
	if (L != R) {
		if (graph[i].first == -1) {
			graph[i].first = sz(graph);
			graph.push_back({-1, -1});
			seg.push_back(0);
			lazy.push_back(false);
		}
		if (graph[i].second == -1) {
			graph[i].second = sz(graph);
			graph.push_back({-1, -1});
			seg.push_back(0);
			lazy.push_back(false);
		}
		if (lazy[i]) {
			lazy[graph[i].first] = !lazy[graph[i].first];
			lazy[graph[i].second] = !lazy[graph[i].second];
		}
	}
	lazy[i] = false;
}

void upd(ll l, ll r, int i = 0, ll L = 1, ll R = N) {
	push(i, L, R);
	if (r < L or l > R) {
		return;
	}
	if (l <= L and R <= r) {
		lazy[i] = true;
		push(i, L, R);
		return;
	}
	ll M = (L + R) / 2;
	upd(l, r, graph[i].first, L, M);
	upd(l, r, graph[i].second, M + 1, R);
	pull(i);
}

ll query(ll l, ll r, int i = 0, ll L = 1, ll R = N) {
	push(i, L, R);
	if (r < L or l > R) {
		return 0;
	}
	if (l <= L and R <= r) {
		return seg[i];
	}
	ll M = (L + R) / 2;
	return query(l, r, graph[i].first, L, M) + query(l, r, graph[i].second, M + 1, R);
}

int32_t main() {
	setup();

	int q;
	input(q);

	while (q--) {
		ll o, l, r;
		input(o, l, r);

		if (o == 1) {
			upd(l, r);
		}
		else {
			print(query(l, r));
		}
	}
}
