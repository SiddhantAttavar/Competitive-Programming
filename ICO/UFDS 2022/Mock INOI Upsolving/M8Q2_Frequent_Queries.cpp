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

int s;
int n, q, a, b;
vector<int> v;
vector<multiset<pair<int, int>>> segTree;

multiset<pair<int, int>> merge(multiset<pair<int, int>> a, multiset<pair<int, int>> b) {
	map<int, int> m;
	for (pair<int, int> p : a) {
		m[p.second] += p.first;
	}
	for (pair<int, int> p : b) {
		m[p.second] += p.first;
	}
	multiset<pair<int, int>> res;
	for (pair<int, int> p : m) {
		res.insert({p.second, p.first});
	}
	return res;
}

void update(int c, int i, int l, int r) {
	if (l == r) {
		segTree[c].insert({1, v[i]});
		return;
	}
	int m = (l + r) / 2;
	if (i <= m) {
		update(c * 2, v[i], l, m);
	}
	else {
		update(c * 2 + 1, v[i], m + 1, r);
	}
	segTree[c] = merge(segTree[c * 2], segTree[c * 2 + 1]);
}

multiset<pair<int, int>> query(int c, int s, int e, int l, int r) {
	if (s <= l && r <= e) {
		return segTree[c];
	}
	int m = (l + r) / 2;
	if (e <= m) {
		return query(c * 2, s, e, l, m);
	}
	else if (s > m) {
		return query(c * 2 + 1, s, e, m + 1, r);
	}
	else {
		return merge(query(c * 2, s, e, l, m), query(c * 2 + 1, s, e, m + 1, r));
	}
}

int32_t main() {
	setup();
	input(s);
	input(n, q, a, b);
	v.resize(n);
	arrPut(v);

	segTree.resize(4 * n + 1);
	range(i, 0, n) {
		update(1, i, 0, n - 1);
	}

	while (q--) {
		int l, r; input(l, r);
		multiset<pair<int, int>> m = query(1, l, r, 0, n - 1);
		multiset<pair<int, int>>::iterator it = m.lower_bound({a, -1});	
		if (it == m.end() or (*it).first > b) {
			print(-1);
		}
		else {
			print((*it).second);
		}
	}
}