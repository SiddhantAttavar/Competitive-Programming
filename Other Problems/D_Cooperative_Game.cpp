#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int interact(vector<int> v) {
	cout << "next";
	for (int i : v) {
		cout << " " << i;
	}
	print("");
	cout.flush();
	input(int, k);
	range(i, 0, k) {
		input(int, x);
	}
	return k;
}

int main() {
	setup();
	do {
		interact({0});
	} while (interact({0, 1}) == 3);
	while (interact({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) == 2);
	print("done");
}