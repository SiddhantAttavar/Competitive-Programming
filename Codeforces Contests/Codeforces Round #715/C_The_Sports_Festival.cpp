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
#define int ll

signed main() {
	setup();
	int n; input(n);
	multiset<int> a;
	range(i, 0, n) {
		int x; input(x);
		a.insert(x);
	}

	vector<int> l;
	for (int i : a) {
		l.push_back(i);
	}

	double mean = 0;
	for (int i : l) {
		mean += i;
	}
	mean /= n;
	//print(mean);

	int u = 0;
	range(i, 1, n) {
		if (abs(l[i] - mean) < abs(l[u] - mean)) {
			u = i;
		}
	}

	for (multiset<int>::iterator j = a.begin(); j != a.end(); j++) {
		if (*j == l[u]) {
			a.erase(j);
			break;
		}
	}

	ll res = 0;
	int currMin = l[u], currMax = l[u];
	
	range(i, 0, n - 1) {
		multiset<int>::iterator u;
		int currDeviation = 1e9;

		for (multiset<int>::iterator j = a.begin(); j != a.end(); j++) {
			int tempMin = min(currMin, *j);
			int tempMax = max(currMax, *j);
			//print(*j, tempMin, tempMax);
			if (tempMax - tempMin <= currDeviation) {
				u = j;
				currDeviation = tempMax - tempMin;
			}
		}
		print(currDeviation);

		currMin = min(currMin, *u);
		currMax = max(currMax, *u);
		res += currDeviation;
		a.erase(u);
	}

	print(res);
}