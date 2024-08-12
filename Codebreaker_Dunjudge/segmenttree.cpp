// https://codebreaker.xyz/problem/segmenttree
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<int> segTree;

void update(int c, int l, int r, int i, int x) {
	if (l == r) {
		segTree[c] = x;
		return;
	}

	int m = (l + r) / 2;
	if (i <= m) {
		update(2 * c, l, m, i, x);
	}
	else {
		update(2 * c + 1, m + 1, r, i, x);
	}
	segTree[c] = min(segTree[2 * c], segTree[2 * c + 1]);
}

int query(int c, int l, int r, int s, int e) {
	if (e < l or r < s) {
		return 1e9;
	}
	if (s <= l and r <= e) {
		return segTree[c];
	}
	
	int m = (l + r) / 2;
	return min(
		query(2 * c, l, m, s, e),
		query(2 * c + 1, m + 1, r, s, e)
	);
}

int32_t main() {
	setup();
	int n, q;
	input(n, q);
	segTree.resize(4 * n, 0);
	while (q--) {
		int x, y, z;
		input(x, y, z);
		if (x == 1) {
void update(int c, int l, int r, int i, int x) {
	if (l == r) {
		segTree[c] = x;
		return;
	}

	int m = (l + r) / 2;
	if (i <= m) {
		update(2 * c, l, m, i, x);
	}
	else {
		update(2 * c + 1, m + 1, r, i, x);
	}
	segTree[c] = min(segTree[2 * c], segTree[2 * c + 1]);
}

int query(int c, int l, int r, int s, int e) {
	if (e < l or r < s) {
		return 1e9;
	}
	if (s <= l and r <= e) {
		return segTree[c];
	}
	
	int m = (l + r) / 2;
	return min(
		query(2 * c, l, m, s, e),
		query(2 * c + 1, m + 1, r, s, e)
	);
}
		}
		else {
			print(query(1, 0, n - 1, y, z));
		}
	}
}
