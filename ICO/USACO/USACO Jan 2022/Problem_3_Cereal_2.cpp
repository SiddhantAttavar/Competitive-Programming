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

map<int, int> x;
vector<pair<int, int>> v;
vector<set<int>> a;

int32_t main() {
	setup();
	
	int n, m;
	input(n, m);
	v.resize(n);
	range(i, 0, n) {
		input(v[i].first, v[i].second);
		v[i].first--;
		v[i].second--;
	}

	a.resize(m);
	range(i, 0, n) {
		a[v[i].first].insert(i);
		a[v[i].second].insert(i);
	}

	vector<int> ind(n);
	int c = 0;
	range(i, 0, m) {
		// if ()
	}

	int res = 0;
	vector<bool> a(m);
	for (int i : ind) {
		if (a[v[i].first]) {
			if (a[v[i].second]) {
				res++;
			}
			else {
				a[v[i].second] = true;
			}
		}
		else {
			a[v[i].first] = true;
		}
	}
	print(res);

	for (int i : ind) {
		print(i + 1);
	}
}
