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

	//Input
	input(int, n1);
	input(int, n2);
	input(int, n3);

	arrput(int, a, n1);
	arrput(int, b, n2);
	arrput(int, c, n3);

	unordered_map<int, int> map;
	for (int i : a) {
		map[i]++;
	}
	for (int i : b) {
		map[i]++;
	}
	for (int i : c) {
		map[i]++;
	}

	vector<int> v;
	for (pair<int, int> p : map) {
		if (p.second >= 2) {
			v.push_back(p.first);
		}
	}

	sort(v.begin(), v.end());

	print(v.size());
	for (int i : v) {
		cout << i << " ";
	}
}