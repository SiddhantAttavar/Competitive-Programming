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
	cin.ignore();
	
	set<string> s;
	range(i, 0, n) {
		string line, word;
		getline(cin, line);
		for (char c : line) {
			if (isalpha(c)) {
				word += tolower(c);
			}
			else if (c == ' ') {
				if (word.size() > 0) {
					s.insert(word);
				}
				word.erase();
			}
		}
		if (word.size() > 0) {
			s.insert(word);
		}
	}

	print(s.size());
	for (string i : s) {
		print(i);
	}
}
