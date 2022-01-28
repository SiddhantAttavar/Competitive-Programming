// https://szkopul.edu.pl/problemset/problem/EwpbJWZPly_zZ5i4ytg_8fDE/site/?key=statement
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

int n, m, k, d;
vector<int> segTree;
vector<int> lazy;

void buildTree(vector<int> &l) {
	stack<tuple<int, int, int>> s;
	s.emplace(1, 0, n - 1);
	while (!s.empty()) {
		int c, a, b;
		tie(c, a, b) = s.top();
		s.pop();

		if (a == -1 and b == -1) {
			segTree[c] = segTree[2 * c] + segTree[2 * c + 1];
		}
		else if (a == b) {
			segTree[c] = l[a];
		}
		else {
			s.emplace(c, -1, -1);
			m = (a + b) / 2;
			s.emplace(2 * c, a, m);
			s.emplace(2 * c + 1, m + 1, b);
		}
	}
}

void push(int c, int a, int b) {
	if (lazy[c] != 0) {
		segTree[c] = segTree[2 * c] + segTree[2 * c + 1];

		if (a != b) {
			lazy[2 * c] = lazy[c];
			lazy[2 * c + 1] = lazy[c];
		}

		lazy[c] = 0;
	}
}

void update(int i, int j, int x) {
	stack<tuple<int, int, int>> s;
	s.emplace(1, 0, n - 1);
	while (!s.empty()) {
		int c, a, b;
		tie(c, a, b) = s.top();
		s.pop();

		if (a == -1 and b == -1) {
			segTree[c] = segTree[2 * c] + segTree[2 * c + 1];
		}
		else {
			push(c, a, b);

			if (a > b or a > j or b < i) {
				continue;
			}
			else if (a >= i and b <= j) {
				segTree[c] = segTree[2 * c] + segTree[2 * c + 1];

				if (a != b) {
					lazy[2 * c] = lazy[c];
					lazy[2 * c + 1] = lazy[c];
				}
			}
			else {
				s.emplace(c, -1, -1);
				m = (a + b) / 2;
				s.emplace(2 * c, a, m);
				s.emplace(2 * c + 1, m + 1, b);
			}
		}
	}
}

int query(int n, int i, int j) {
	// s = 
}

int32_t main() {
	setup();
	
	input(n, m, k, d);

	while (m--) {
		int r, x;
		input(r, x);
	}
}
