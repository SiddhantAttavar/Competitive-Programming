#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) // read start time, end time
		cin >> v[i].second >> v[i].first;
	sort(begin(v), end(v)); // sort by end time

	int ans = 0;
	multiset<int> end_times; // times when members will finish watching movies
	for (int i = 0; i < k; ++i)
		end_times.insert(0);

	for (int i = 0; i < n; i++) {
		auto it = end_times.upper_bound(v[i].second);
		if (it == begin(end_times)) continue;
		// assign movie to be watched by member in multiset who finishes at time *prev(it)
		end_times.erase(--it);
		// member now finishes watching at time v[i].first
		end_times.insert(v[i].first);
		++ ans;
	}

	cout << ans;
}