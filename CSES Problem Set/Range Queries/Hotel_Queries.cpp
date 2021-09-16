#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

struct SegTree {
	vector<ll> a;
	ll id;

	ll (*combine) (ll, ll);

	SegTree(int n, int i, ll func(ll, ll)) {
		id = i;
		combine = func;
		a = vector<ll>(2 * pow(2, ceil(log2(n))) - 1, id);
	}

	pair<int, ll> query(int x, int s, int e, int curr) {
		if (s == e) {
			if (a[curr] >= x) {
				return {s + 1, a[curr]};
			}
			return {0, a[curr]};
		}

		int mid = (s + e) / 2;
		if (a[2 * curr + 1] >= x) {
			//There is an element on the left
			return query(x, s, mid, 2 * curr + 1);
		}

		//We must find an element on the right
		return query(x, mid + 1, e, 2 * curr + 2);
	}

	void update(int i, int x, int s, int e, int curr) {
		if (s > i || e < i) {
			return;
		}

		if (s == e) {
			a[curr] = x;
			return;
		}

		int mid = (s + e) / 2;

		update(i, x, s, mid, 2 * curr + 1);
		update(i, x, mid + 1, e, 2 * curr + 2);

		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
	}
};

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	SegTree segTree(n, 0, [](ll a, ll b) {
		return max(a, b);
	});
	
	range(i, 0, n) {
		int x; input(x);
		segTree.update(i, x, 0, n - 1, 0);
	}

	range(i, 0, m) {
		int x; input(x);
		
		//We need to find the first index that has an element >= x
		pair<int, ll> res = segTree.query(x, 0, n - 1, 0);
		if (res.first == 0) {
			cout << "0 ";
		}
		else {
			cout << res.first << " ";
			segTree.update(res.first - 1, res.second - x, 0, n - 1, 0);
		}
	}
}