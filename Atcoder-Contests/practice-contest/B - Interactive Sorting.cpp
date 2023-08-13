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

bool query(int x, int y) {
	print('?', (char) ('A' + x), (char) ('A' + y));
	string s;
	input(s);
	return s[0] == '<';
}

void subtask3() {
	int a = 0, b = 1, c = 2, d = 3, e = 4;
	if (query(b, a)) {
		swap(b, a);
	}
	if (query(d, c)) {
		swap(d, c);
	}

	if (query(c, a)) {
		swap(a, c);
		swap(b, d);
	}

	// Find position of e in a, c, d
	vector<int> seq;
	if (query(c, e)) {
		if (query(d, e)) {
			seq = {a, c, d, e};
		}
		else {
			seq = {a, c, e, d};
		}
	}
	else {
		if (query(a, e)) {
			seq = {a, e, c, d};
		}
		else {
			seq = {e, a, c, d};
		}
	}

	if (query(seq[2], b)) {
		if (query(seq[3], b)) {
			seq.push_back(b);
		}
		else {
			seq.insert(seq.begin() + 3, b);
		}
	}
	else {
		if (query(seq[1], b)) {
			seq.insert(seq.begin() + 2, b);
		}
		else {
			seq.insert(seq.begin() + 1, b);
		}
	}

	cout << "! ";
	for (int i : seq) {
		cout << (char) ('A' + i);
	}
	cout << endl;
}

int32_t main() {
	// setup();
	
	int n, q;
	input(n, q);

	if (n == 5 and q == 7) {
		subtask3();
		return 0;
	}

	vector<int> res;
	res.push_back(0);
	
	range(i, 1, n) {
		int l = 0, r = res.size() - 1, f = res.size();
		while (l <= r) {
			int m = (l + r) / 2;
			if (query(i, res[m])) {
				f = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		res.insert(res.begin() + f, i);
	}

	cout << "! ";
	for (int i : res) {
		cout << (char) ('A' + i);
	}
	cout << endl;
}
