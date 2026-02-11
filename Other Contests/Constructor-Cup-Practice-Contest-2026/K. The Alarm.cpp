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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = 998244353;

vi val, comp, z, cont;
int Time, m;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = m;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		m++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = m = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vi x(n), y(n), p(n);
	rep(i, 0, n) {
		input(x[i], y[i], p[i]);
	}

	vector<vi> graph(n);
	rep(i, 0, n) {
		rep(j, 0, n) {
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= p[i] * p[i]) {
				graph[i].push_back(j);
			}
		}
	}

	scc(graph, [](vi &v) {});

	vi d(m, 0), s(m, 0);
	rep(i, 0, n) {
		s[comp[i]]++;
		for (int j : graph[i]) {
			if (comp[i] != comp[j]) {
				d[comp[j]]++;
			}
		}
	}

	vi pow2(n + 1);
	pow2[0] = 1;
	rep(i, 0, n) {
		pow2[i + 1] = pow2[i] * 2 % MOD;
	}

	int res = 1;
	rep(i, 0, m) {
		res = (res * (pow2[s[i]] - !d[i] + MOD)) % MOD;
	}
	print(res);
}
