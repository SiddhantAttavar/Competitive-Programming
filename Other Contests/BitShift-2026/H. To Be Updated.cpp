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

const int N = 1e6;
vi d[N + 1];
int v[N + 1], w[N + 1];

void add(int x) {
	for (int i : d[x]) {
		v[i]++;
	}
}

void remove(int x) {
	for (int i : d[x]) {
		v[i]--;
	}
}

int get(int x, int g) {
	if (x % g) {
		return 0;
	}
	for (int i : d[x]) {
		w[i] = v[i] - 1;
		for (int j : d[x]) {
			if (j == i) {
				break;
			}
			if (j % i == 0) {
				w[i] -= w[j];
			}
		}
	}
	return w[g];
}

int32_t main() {
	fill(v, v + N + 1, 0);
	rep(i, 1, N + 1) {
		for (int j = i; j <= N; j += i) {
			d[j].push_back(i);
		}
	}
	rep(i, 1, N + 1) {
		reverse(all(d[i]));
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vi a(n);
		arrput(a);

		for (int i : a) {
			add(i);
		}

		while (q--) {
			int o;
			input(o);

			if (o == 1) {
				int i, g;
				input(i, g);
				i--;

				print(get(a[i], g));
			}
			else if (o == 2) {
				int i, x;
				input(i, x);
				i--;

				remove(a[i]);
				a[i] = x;
				add(a[i]);
			}
		}

		for (int i : a) {
			remove(i);
		}
	}
}
