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

struct Node {
	int x;
	Node *l, *r;
	Node(int _x) : x(_x) {}
};

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<int> a(n, 0);
	rep(i, 0, n) {
		string s;
		input(s);
		rep(j, 0, k) {
			a[i] |= (s[j] == '1') << j;
		}
	}

	int z = 0, res = 1 << 30;
	Node* h = new Node(0);

	for (int z : a) {
		int y = 0;
		Node *u = h;
		for (int j = 29; j >= 0; j--) {
			if (u == NULL) {
				y = (1 << 30) ^ z;
				break;
			}
			if (!(z >> j & 1)) {
				if (u->l != NULL) {
					u = u->l;
				}
				else {
					u = u->r;
					y |= 1 << j;
				}
			}
			else {
				if (u->r != NULL) {
					u = u->r;
					y |= 1 << j;
				}
				else {
					u = u->l;
				}
			}
		}
		res = min(res, __builtin_popcount(z ^ y));

		u = h;
		for (int j = 29; j >= 0; j--) {
			if (z >> j & 1) {
				if (u->r == NULL) {
					u->r = new Node(z >> j);
				}
				u = u->r;
			}
			else {
				if (u->l == NULL) {
					u->l = new Node(z >> j);
				}
				u = u->l;
			}
		}
	}
	print(res);
}
