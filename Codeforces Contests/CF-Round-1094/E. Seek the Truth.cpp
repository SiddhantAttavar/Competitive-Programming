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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

bool debug = false;
set<int> S;
int N = -1, K = -1, C = -1;

int f(int x) {
	if (K == 1) {
		return x & C;
	}
	else if (K == 2) {
		return x | C;
	}
	else {
		return x ^ C;
	}
}

int query1(int x) {
	assert(N--);
	if (debug) {
		S.insert(f(x));
		return sz(S);
	}

	print('I', x);
	cout.flush();
	int l;
	input(l);
	return l;
}

int query2(int y) {
	assert(N--);
	if (debug) {
		int res = 0;
		for (int i : S) {
			res += i >= y;
		}
		return res;
	}

	print('Q', y);
	cout.flush();
	int l;
	input(l);
	return l;
}

void printa(int a) {
	if (debug) {
		S.insert(a);
	}
	else {
		print(a);
		cout.flush();
	}
}

int solve_and(int n) {
	int x = 1, c = 0;
	rep(i, 0, n) {
		if (query1(1ll << i) > x) {
			x++;
			c |= 1ll << i;
		}
	}
	return c;
}

int binary_search(int n) {
	int c = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (query2(c | (1ll << i))) {
			c |= 1ll << i;
		}
	}
	return c;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		N = n + 3;
		if (debug) {
			S.clear();
			input(K, C);
		}

		int z = (1ll << n) - 1;
		printa(0);

		int k = -1, c = -1;
		if (query1(0) == 1) {
			k = 1;
			c = solve_and(n);
		}
		else {
			c = binary_search(n);
			if (c == z) {
				query1(1);
				k = query2(z ^ 1) == 2 ? 3 : 2;
			}
			else {
				query1(z);
				k = query2(z) ? 2 : 3;
			}
		}

		print('A', k, c);
		cout.flush();

		if (debug) {
			assert(k == K and c == C);
		}
	}
}
