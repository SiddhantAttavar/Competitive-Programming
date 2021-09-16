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

int main() {
	setup();

	int n; input(n);
	pair<int, int> movies[n];
	for (pair<int, int> &i : movies) {
		input(i.second);
		input(i.first);
	}

	sort(movies, movies + n);

	int curr = 0;
	int res = 0;
	for (pair<int, int> p : movies) {
		if (curr <= p.second) {
			res++;
			curr = p.first;
		}
	}

	print(res);
}