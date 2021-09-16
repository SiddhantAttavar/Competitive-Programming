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

	tuple<int, int, int> l[n];
	range(i, 0, n) {
		input(get<0>(l[i]));
		input(get<1>(l[i]));
		get<2>(l[i]) = i;
	}
	sort(l, l + n);

	int k = 0;
	int res[n];
	multiset<pair<int, int>> m;
	for (tuple<int, int, int> t : l) {
		int a, b, i;
		tie(a, b, i) = t;

		multiset<pair<int, int>>::iterator it = m.lower_bound({a, 0});
		int room;
		if (it == m.begin()) {
			//We must use a new room
			k++;
			room = k;
		}
		else {
			//We can go after one of the existing rooms
			it--;
			room = (*it).second;
			m.erase(it);
		}

		m.insert({b, room});
		res[i] = room;
	}

	print(k);
	arrPrint(res);
}