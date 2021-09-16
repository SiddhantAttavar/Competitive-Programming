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
	pair<int, int> b[n];
	range(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	range(i, 0, n) {
		cin >> b[i].first;
		b[i].second = i + 1;
	}

	sort(a, a + n);
	sort(b, b + n);

	int res = 0;
	int pairing[n];
	int low = 0, high = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[high].first > b[i].first) {
			pairing[a[high].second] = b[i].second;
			res++;
			high--;
		}
		else {
			pairing[a[low].second] = b[i].second;
			low++;
		}
	}

	print(res);
	for (int i : pairing) {
		print(i);
	}
}