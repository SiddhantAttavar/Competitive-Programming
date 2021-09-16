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
	input(int, m);
	vector<int> a(m);
	range(i, 0, m) {
		cin >> a[i];
	}
	input(int, n);
	range(i, 0, n) {
		input(int, x);
		print(a[x - 1]);
		a.erase(a.begin() + x - 1);
	}
}