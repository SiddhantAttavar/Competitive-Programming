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
typedef long long ll;

int n;
vector<int> a;
vector<int> res;

bool valid(vector<int> p, vector<int> q) {
	range(i, 0, p.size()) {
		if (i > 0 && p[i] <= p[i - 1]) {
			return false;
		}
		range(j, 0, p.size()) {
			if (i != j && __gcd(a[p[i]], a[p[j]]) > 1) {
				return false;
			}
		}
	}

	range(i, 0, q.size()) {
		if (i > 0 && q[i] <= q[i - 1]) {
			return false;
		}
		range(j, 0, q.size()) {
			if (i != j && __gcd(a[q[i]], a[q[j]]) > 1) {
				return false;
			}
		}
	}

	return true;
}

void solve(int i, vector<bool> curr) {
	if (i == n) {
		vector<int> p, q;
		range(i, 0, n) {
			if (curr[i]) {
				p.push_back(i);
			}
			else {
				q.push_back(i);
			}
		}

		if (!valid(p, q)) {
			return;
		}

		if (res.size() == 1 && res[0] == -1) {
			res.clear();
			res.insert(res.end(), p.begin(), p.end());
			return;
		}

		if (p.size() > res.size()) {
			res.clear();
			res.insert(res.end(), p.begin(), p.end());
			return;
		}
		else if (p.size() < res.size()) {
			return;
		}

		range(i, 0, n) {
			if (res[i] < p[i]) {
				return;
			}
			if (res[i] > p[i]) {
				res.clear();
				res.insert(res.end(), p.begin(), p.end());
				return;
			}
		}

		return;
	}

	vector<bool> next0, next1;
	next0.insert(next0.end(), curr.begin(), curr.end());
	next1.insert(next1.end(), curr.begin(), curr.end());
	next0.push_back(0);
	next1.push_back(1);

	solve(i + 1, next0);
	solve(i + 1, next1);
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		input(n);
		a.resize(n);
		arrPut(a);

		res = {-1};
		solve(0, {});

		if (res.size() == 1 && res[0] == -1) {
			print(-1);
		}
		else {
			print(res.size());
			for (int i : res) {
				cout << i + 1 << ' ';
			}
			cout << endl;
		}
	}
}