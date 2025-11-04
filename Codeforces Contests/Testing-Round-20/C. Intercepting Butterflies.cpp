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

vector<int> l;
vector<int> m(1 << 20, -1);

vector<int> encode() {
	int n;
	input(n);

	int x = l[n - 1];
	vector<int> v;
	rep(i, 0, 20) {
		if (x >> i & 1) {
			v.push_back(i + 1);
		}
	}
	return v;
}

void decode(const vector<int> &v) {
	int x = 0;
	for (int i : v) {
		x |= 1 << (i - 1);
	}
	print(m[x]);
}

int32_t main() {
	setup();

	vector<bool> vis(1 << 20, false);
	rep(i, 0, 1 << 20) {
		bool flag = !vis[i];
		rep(j, 0, 20) {
			flag = flag & !vis[i ^ (1 << j)];
		}
		if (!flag) {
			continue;
		}
		l.push_back(i);
		vis[i] = true;
		rep(j, 0, 20) {
			vis[i ^ (1 << j)] = true;
		}
	}

	rep(i, 0, l.size()) {
		m[l[i]] = i + 1;
		rep(j, 0, 20) {
			m[l[i] ^ (1 << j)] = i + 1;
		}
	}

	string s;
	input(s);

	int tc;
	input(tc);
	while (tc--) {
		if (s == "first") {
			vector<int> v = encode();
			print(v.size());
			arrprint(v);
		}
		else if (s == "second") {
			int n;
			input(n);
			vector<int> v(n);
			arrput(v);

			decode(v);
		}
		else {
			decode(encode());
		}
	}
}
