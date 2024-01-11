#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	vector<int> v(98);
	arrPut(v);

	vector<vector<int>> a(4);
	a[0].push_back(1);
	a[1].push_back(1);
	a[2].push_back(100);
	a[3].push_back(100);

	queue<int> q;
	for (int i : v) {
		q.push(i);
	}

	vector<int> hand;
	range(i, 0, 8) {
		hand.push_back(q.front());
		q.pop();
	}

	while (!hand.empty()) {
		bool flag = false;
		// backward trick
		range(i, 0, (int) hand.size()) {
			vector<int> options = {a[0].back() - 10, a[1].back() - 10, a[2].back() + 10, a[3].back() + 10};
			range(j, 0, 4) {
				if (hand[i] == options[j]) {
					a[j].push_back(hand[i]);
					hand.erase(hand.begin() + i);
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		if (flag) {
			if (!q.empty() and hand.size() == 6) {
				hand.push_back(q.front());
				q.pop();
				if (!q.empty()) {
					hand.push_back(q.front());
					q.pop();
				}
			}
			continue;
		}

		// regular
		int m = 1e9, r = 0, u = 0;
		range(i, 0, (int) hand.size()) {
			vector<int> options = {hand[i] - a[0].back(), hand[i] - a[1].back(), a[2].back() - hand[i], a[3].back() - hand[i]};
			range(j, 0, 4) {
				if (options[j] > 0 and m > options[j]) {
					m = options[j];
					u = i;
					r = j;
					flag = true;
				}
			}
		}

		if (flag) {
			a[r].push_back(hand[u]);
			hand.erase(hand.begin() + u);
			if (!q.empty() and hand.size() == 6) {
				hand.push_back(q.front());
				q.pop();
				if (!q.empty()) {
					hand.push_back(q.front());
					q.pop();
				}
			}
		}
		else {
			break;
		}
	}

	for (vector<int> i : a) {
		arrPrint(i);
	}
	arrPrint(hand);
	vector<int> deck;
	while (!q.empty()) {
		deck.push_back(q.front());
		q.pop();
	}
	arrPrint(deck);
}
