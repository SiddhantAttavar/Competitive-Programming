#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct SegTree {
	vector<int> a;
	int id;

	int (*combine) (int, int);

	SegTree(int n, int i, int func(int, int)) {
		id = i;
		combine = func;
		a = vector<int>(4 * n, id);
	}

	int query(int l, int r, int s, int e, int curr) {
		if (l > e || r < s) {
			return id;
		}

		if (l <= s && r >= e) {
			return a[curr];
		}

		int mid = (s + e) / 2;
		return combine(
			query(l, r, s, mid, 2 * curr + 1),
			query(l, r, mid + 1, e, 2 * curr + 2)
		);
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

int32_t main() {
    //Take input
    int n;
    input(n);
    SegTree segTree(n, 0, [](int a, int b) {
        return a + b;
    });

    vector<int> a(n);
    arrPut(a);
    range(i, 0, n) {
        segTree.update(i, a[i], 0, n - 1, 0);
    }

    //Range queries on the segment tree
    int q;
    input(q);
    range(i, 0, q) {
        int l, r;
        input(l, r);
        print(segTree.query(l, r, 0, n - 1, 0));
    }

    //Point updates on the segment tree
    int u;
    input(u);
    range(i, 0, u) {
        int j, y;
        input(j, y);
        segTree.update(j, y, 0, n - 1, 0);
    }
}
