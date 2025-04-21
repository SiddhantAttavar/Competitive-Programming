#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

const int N = 4e5;
int seg[4 * N][10], lazy[4 * N][10];
void push(int l, int r, int i) {
	vector<int> v(10, 0);
	for (int j = 0; j < 10; j++) {
		v[lazy[i][j]] += seg[i][j];
	}
	for (int j = 0; j < 10; j++) {
		seg[i][j] = v[j];
	}
	if (l == r) {
		for (int j = 0; j < 10; j++) {
			lazy[i][j] = j;
		}
		return;
	}

	vector<int> a(10), b(10);
	for (int j = 0; j < 10; j++) {
		a[j] = lazy[i][lazy[2 * i][j]];
		b[j] = lazy[i][lazy[2 * i + 1][j]];
	}
	for (int j = 0; j < 10; j++) {
		lazy[2 * i][j] = a[j];
		lazy[2 * i + 1][j] = b[j];
	}

	for (int j = 0; j < 10; j++) {
		lazy[i][j] = j;
	}
}

void combine(int a[], int b[], int c[]) {
	for (int i = 0; i < 10; i++) {
		c[i] = a[i] + b[i];
	}
}

void update(int l, int r, int s, int e, int i, vector<int> &a) {
	push(s, e, i);
	if (e < l or s > r) {
		return;
	}
	if (l <= s and e <= r) {
		for (int j = 0; j < 10; j++) {
			lazy[i][j] = a[j];
		}
		push(s, e, i);
		return;
	}
	int m = (s + e) / 2;
	update(l, r, s, m, 2 * i, a);
	update(l, r, m + 1, e, 2 * i + 1, a);
	combine(seg[2 * i], seg[2 * i + 1], seg[i]);
}

void query(int l, int r, int s, int e, int i, int res[]) {
	push(s, e, i);
	if (e < l or s > r) {
		return;
	}
	if (l <= s and e <= r) {
		combine(res, seg[i], res);
		return;
	}
	int m = (s + e) / 2;
	query(l, r, s, m, 2 * i, res);
	query(l, r, m + 1, e, 2 * i + 1, res);
}

void build(int s, int e, int i, vector<int> &a) {
	for (int j = 0; j < 10; j++) {
		seg[i][j] = 0;
		lazy[i][j] = j;
	}
	if (s == e) {
		seg[i][a[s]] = 1;
		return;
	}
	int m = (s + e) / 2;
	build(s, m, 2 * i, a);
	build(m + 1, e, 2 * i + 1, a);
	combine(seg[2 * i], seg[2 * i + 1], seg[i]);
}

long long mod_pow(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	vector<int> id(10);
	for (int i = 0; i < 10; i++) {
		id[i] = i;
	}
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc; cin >> tc; while (tc--) {
		int n, q;
		cin >> n >> q;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		build(0, n - 1, 1, a);

		while (q--) {
			int o, l, r;
			cin >> o >> l >> r;
			l--;
			r--;

			if (o == 1) {
				vector<int> a(10);
				for (int i = 0; i < 10; i++) {
					cin >> a[i];
					a[i]--;
				}
				update(l, r, 0, n - 1, 1, a);
			}
			else {
				int v[10];
				for (int j = 0; j < 10; j++) {
					v[j] = 0;
				}
				query(l, r, 0, n - 1, 1, v);
				long long res = 1;
				for (int i = 0; i < 10; i++) {
					res = res * mod_pow(i + 1, v[i]) % MOD;
				}
				cout << res << '\n';
			}
		}
	}
}
