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

bool debug = false;
vector<int> A;
int K = 10;

const int N = 1e3;

bitset<N> query(bitset<N> &b, int n) {
	assert(K);
	K--;
	if (debug) {
		bitset<N> c;
		rep(i, 0, n) {
			c[i] = b[A[i] - 1];
		}
		return c;
	}
	cout << "? ";
	rep(i, 0, n) {
		cout << b[i];
	}
	cout << endl;
	cout.flush();
	bitset<N> c;
	string s;
	input(s);
	rep(i, 0, n) {
		c[i] = s[i] == '1';
	}
	return c;
}

int32_t main() {
	setup();

	int n;
	input(n);

	K = 10;
	if (debug) {
		A.resize(n);
		arrput(A);
	}

	vector<bitset<N>> v(10, 0);
	rep(i, 0, 10) {
		rep(j, 0, n) {
			v[i][j] = j >> i & 1;
		}
		v[i] = query(v[i], n);
	}

	vector<int> res(n);
	rep(i, 0, n) {
		bitset<N> a = 0;
		rep(j, 0, n) {
			a[j] = true;
		}
		rep(j, 0, 10) {
			if (i >> j & 1) {
				a = a & v[j];
			}
			else {
				a = a & ~v[j];
			}
		}
		assert(a.count() == 1);
		int u = a._Find_first();
		assert(u < n);
		res[u] = i + 1;
	}

	cout << "! ";
	arrprint(res);
}
