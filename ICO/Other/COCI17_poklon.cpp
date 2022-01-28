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

vector<set<int>> segTree1, segTree2, segTree3;

void build(vector<int> &a, int c, int l, int r) {
	if (l == r) {
		segTree1[c] = {a[l]};
		return;
	}

	int m = (l + r) / 2;
	build(a, 2 * c, l, m);
	build(a, 2 * c + 1, m + 1, r);
	
	for (int x : segTree1[2 * c]) {
		if (!segTree1[2 * c + 1].count(x) and !segTree2[2 * c + 1].count(x) and !segTree3[2 * c + 1].count(x)) {
			segTree1[c].insert(x);
		}
	}
	for (int x : segTree1[2 * c + 1]) {
		if (!segTree1[2 * c].count(x) and !segTree2[2 * c].count(x) and !segTree3[2 * c].count(x)) {
			segTree1[c].insert(x);
		}
	}

	for (int x : segTree2[2 * c]) {
		if (!segTree1[2 * c + 1].count(x) and !segTree2[2 * c + 1].count(x) and !segTree3[2 * c + 1].count(x)) {
			segTree2[c].insert(x);
		}
	}
	for (int x : segTree2[2 * c + 1]) {
		if (!segTree1[2 * c].count(x) and !segTree2[2 * c].count(x) and !segTree3[2 * c].count(x)) {
			segTree2[c].insert(x);
		}
	}

	for (int x : segTree1[2 * c]) {
		if (segTree1[2 * c + 1].count(x)) {
			segTree2[c].insert(x);
		}
	}

	for (int x : segTree2[2 * c]) {
		if (segTree1[2 * c + 1].count(x)) {
			segTree3[c].insert(x);
		}
	}
	for (int x : segTree2[2 * c + 1]) {
		if (segTree1[2 * c].count(x)) {
			segTree3[c].insert(x);
		}
	}

	for (int x : segTree2[2 * c]) {
		if (segTree2[2 * c + 1].count(x)) {
			segTree3[c].insert(x);
		}
	}
}

int query(int c, int l, int r, int s, int e) {
	if (s <= l and r <= e) {
		return segTree2[c].size();
	}

	if (r < s or e < l) {
		return 0;
	}

	int m = (l + r) / 2;
	return (
		query(2 * c, l, m, s, e) + 
		query(2 * c + 1, m + 1, r, s, e)
	);
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);
	vector<int> a(n);
	arrPut(a);

	segTree1.resize(4 * n);
	segTree2.resize(4 * n);
	segTree3.resize(4 * n);

	build(a, 1, 0, n - 1);
	
	for (set<int> s : segTree1) {
		cout << s.size() << ' ';
	}
	cout << endl;
	for (set<int> s : segTree2) {
		cout << s.size() << ' ';
	}
	cout << endl;
	for (set<int> s : segTree3) {
		cout << s.size() << ' ';
	}
	cout << endl;

	while (q--) {
		int l, r;
		input(l, r);
		l--;
		r--;

		print(query(1, 0, n - 1, l, r));
	}
}
