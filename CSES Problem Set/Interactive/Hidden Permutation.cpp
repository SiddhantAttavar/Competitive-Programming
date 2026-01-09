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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool debug = false;
vector<int> A;
int K = 1e4;

const int N = 1e3;
bitset<N> v[N];

bool query(int i, int j) {
	assert(K);
	K--;
	if (debug) {
		return A[i] < A[j];
	}
	print('?', i + 1, j + 1);
	cout.flush();
	string s;
	input(s);
	return s == "YES";
}

bool comp(int i, int j) {
	if (v[i][j]) {
		return true;
	}
	if (v[j][i]) {
		return false;
	}
	bool b = query(i, j);
	if (b) {
		v[i] |= v[j];
	}
	else {
		v[j] |= v[i];
	}
	return b;
}

vector<int> merge_sort(vector<int> a) {
	if (a.size() <= 1) {
		return a;
	}

	int m = ((int) a.size() - 1) / 2;
	vector<int> b(a.begin(), a.begin() + m + 1), c(a.begin() + m + 1, a.end());
	b = merge_sort(b);
	c = merge_sort(c);

	vector<int> res;
	int i = 0, j = 0;
	while (i < b.size() or j < c.size()) {
		if (i < b.size() and (j == c.size() or comp(b[i], c[j]))) {
			res.push_back(b[i]);
			i++;
		}
		else {
			res.push_back(c[j]);
			j++;
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	K = 1e4;
	if (debug) {
		A.resize(n);
		arrput(A);
	}

	rep(i, 0, n) {
		v[i] = 0;
		v[i][i] = true;
	}

	vector<int> a(n), res(n);
	iota(a.begin(), a.end(), 0);
	a = merge_sort(a);

	rep(i, 0, n) {
		res[a[i]] = i + 1;
	}
	cout << "! ";
	arrprint(res);
	cout.flush();

	if (debug) {
		assert(res == A);
	}
}
