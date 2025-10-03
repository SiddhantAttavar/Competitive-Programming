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

int get(vector<int> &a) {
	ordered_set o;
	int res = 0;
	for (int i : a) {
		res += o.size() - o.order_of_key(i);
		o.insert(i);
	}
	return res;
}

bool check(vector<int> &b, vector<int> &e) {
	vector<int> a;
	for (int i : b) {
		a.push_back(e[i]);
	}
	return get(a) == get(b);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n), b(n);
	arrput(a);
	arrput(b);

	vector<int> c(n), e(n);
	rep(i, 0, n) {
		a[i]--;
		b[i]--;

		c[a[i]] = b[i];
		e[b[i]] = a[i];
	}

	ordered_set o;
	int k = 0;
	for (int i : c) {
		k += o.size() - o.order_of_key(i);
		o.insert(i);
	}

	if (k % 2 == 1) {
		print("No");
		return 0;
	}

	vector<int> d;
	o.clear();
	for (int i = n - 1; i >= 0; i--) {
		int x = (n - i - 1) - (o.size() - 2 * o.order_of_key(c[i]));
		o.insert(c[i]);
		if (x <= k) {
			k -= x;
			d.push_back(c[i]);
			continue;
		}

		o.clear();
		int u = -1;
		rep(j, 0, d.size()) {
			o.insert(d[j]);
			if ((j + 1) - (o.size() - 2 * o.order_of_key(c[i])) == k) {
				k = 0;
				u = j + 1;
				break;
			}
		}
		if (u != -1) {
			d.insert(d.begin() + u, c[i]);
			d.insert(d.begin(), c.begin(), c.begin() + i);
		}
		else {
			d.insert(d.begin(), c.begin(), c.begin() + i + 1);
		}
		break;
	}

	print("Yes");
	rep(i, 0, n) {
		cout << e[d[i]] + 1 << ' ';
	}
	cout << endl;
	rep(i, 0, n) {
		cout << d[i] + 1 << ' ';
	}
	cout << endl;
	// assert(check(d, e));
}
