#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	set<int> m;
	map<int, vector<int>> g;
	while (getline(cin, s)) {
		vector<int> v = {0};
		for (char c : s) {
			if (c == ' ') {
				v.push_back(0);
			}
			else if (isdigit(c)) {
				v.back() *= 10;
				v.back() += c - '0';
			}
		}
		int u = v[0];
		m.insert(u);
		v.erase(v.begin());
		for (int i : v) {
			g[u].push_back(i);
			g[i].push_back(u);
		}
	}

	map<int, set<int>> res;
	for (pair<int, vector<int>> p : g) {
		if (m.count(p.first)) {
			continue;
		}
		res[p.first] = set<int>(p.second.begin(), p.second.end());
	}

	for (pair<int, set<int>> p : res) {
		cout << "CS-" << p.first << ":";
		cout << " CS-" << *p.second.begin();
		p.second.erase(p.second.begin());
		for (int i : p.second) {
			cout << ", CS-" << i;
		}
		cout << endl;
	}
}
