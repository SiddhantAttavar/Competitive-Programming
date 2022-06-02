#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, n);
	
	pair<int, int> a[n];
	range(i, 0, n) {
		cin >> a[i].second;
		cin >> a[i].first;
		a[i].first += a[i].second + 1;
	}
	sort(a, a + n);

	int res = 0;
	int curr = 0;
	for (pair<int, int> p : a) {
		if (curr <= p.second) {
			curr = p.first;
			res++;
		}
	}

	print(res);
}