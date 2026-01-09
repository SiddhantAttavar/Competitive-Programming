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
	setup();

	int n;
	input(n);

	vector<int> x(n);
	arrput(x);

	std::priority_queue<pair<int, int>> pq;
	vector<pair<int, int>> res;
	rep(i, 0, n) {
		pq.push({x[i], i});
	}
	bool flag = true;
	while (!pq.empty()) {
		auto [k, u] = pq.top();
		pq.pop();

		if (k > pq.size()) {
			flag = false;
			break;
		}

		vector<int> l;
		rep(i, 0, k) {
			int v = pq.top().second;
			res.push_back({u, v});
			l.push_back(v);
			pq.pop();
		}

		x[u] = 0;
		for (int v : l) {
			x[v]--;
			if (x[v]) {
				pq.push({x[v], v});
			}
		}
	}

	if (!flag) {
		print("IMPOSSIBLE");
		return 0;
	}

	print(res.size());
	for (auto [u, v] : res) {
		print(u + 1, v + 1);
	}
}
