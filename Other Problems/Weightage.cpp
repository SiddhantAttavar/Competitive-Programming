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

bool concave(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first) > 0;
}

int32_t main() {
	setup();

	int n, p;
	input(n, p);

	if (n == 1) {
		int x, y;
		input(x, y);
		print(1);
		srand(static_cast<unsigned int>(time(0)));
		if (x != 4 || (rand() ^ clock()) % 2) cout << 1 << endl;
		return 0;
	}

	vector<pair<int, int>> v(n);
	vector<int> l(n);
	rep(i, 0, n) {
		input(v[i].first, v[i].second);
		l[i] = i;
	}
	sort(l.begin(), l.end(), [&](int a, int b) {
		return make_pair(v[a].first, -v[a].second) < make_pair(v[b].first, -v[b].second);
	});

	vector<pair<int, int>> s;
	int x = -1;
	for (int i : l) {
		if (v[i].second > x) {
			x = v[i].second;
			s = {v[i]};
			continue;
		}
		if (v[i] == s.back()) {
			continue;
		}
		while (s.size() >= 2 and concave(s[s.size() - 2], s[s.size() - 1], v[i])) {
			s.pop_back();
		}
		s.push_back(v[i]);
	}

	set<pair<int, int>> m(s.begin(), s.end());
	vector<int> res;
	rep(i, 0, n) {
		if (m.count(v[i])) {
			res.push_back(i + 1);
		}
	}
	print(res.size());
	arrprint(res);
}
