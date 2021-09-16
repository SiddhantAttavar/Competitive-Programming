#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

struct DSU {
	vector<int> v;
	void init(int n) {
		v = vector<int>(n, -1);
	}

	int get(int i) {
		return v[i] < 0 ? i : get(v[i]);
	}

	int size(int i) {
		return -v[get(i)];
	}

	bool unite(int i, int j) {
		i = get(i);
		j = get(j);
		if (i == j) {
			return false;
		}
		if (v[i] > v[j]) {
			swap(i, j);
		}
		v[i] += v[j];
		v[j] = i;
		return true;
	}
};

int main() {
	setup();
	
	input(int, n);
	range(j, 0, n) {
		input(string, dummy);
	}
	n--;

	//Find minimum spanning tree for all nodes other than 0
	vector<pair<int, pair<int, int>>> edges;
	range(i, 0, n) {
		input(string, dummy);
		range(j, 0, n) {
			input(int, w);
			edges.push_back({w, {i, j}});
		}
	}
	sort(edges.begin(), edges.end());

	DSU d;
	d.init(edges.size());
	int res = 0;
	for (pair<int, pair<int, int>> p : edges) {
		if (p.second.first != p.second.second) {
			if (d.unite(p.second.first, p.second.second)) {
				res += p.first;
			}
		}
	}

	print(res);
}