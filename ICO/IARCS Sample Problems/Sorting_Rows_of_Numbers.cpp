#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

bool compare(vector<int> &a, vector<int> &b) {
	range(i, 0, min(a.size(), b.size())) {
		if (a[i] < b[i]) {
			return true;
		}
		else if (a[i] > b[i]) {
			return false;
		}
	}
	return a.size() < b.size();
}

int main() {
	setup();
	input(int, n);
	vector<int> a[n];
	range(i, 0, n) {
		input(int, x);
		while (x != -1) {
			a[i].push_back(x);
			cin >> x;
		}
	}
	
	sort(a, a + n, compare);

	for (vector<int> v : a) {
		for (int i : v) {
			cout << i << " ";
		}
		print("");
	}
}