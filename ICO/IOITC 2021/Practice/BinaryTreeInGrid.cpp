#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;
#define int ll

signed main() {
	setup();
	int h, r, c, q;
	input(h, r, c, q);

	int l = 3 * pow(2, h - 1);
	pair<int, int> root = {c, r};
	pair<int, int> bottomLeft = {c - (l - 1), r + (l - 1)};
	pair<int, int> bottomRight = {c + (l - 1), r + (l - 1)};

	range(query, 1, q + 1) {
		//print("Query:", query);
		int rLower, cLower, rHigher, cHigher;
		input(rLower, cLower, rHigher, cHigher);
		
		if (rHigher < r || rLower > r + l) {
			print(0);
			continue;
		}

		int lowerBoundY = max(r, rLower);
		int upperBoundY = min(r + l - 1, rHigher);

		int res = 0;

		//The first level is at row r + l - 1
		//For 1 <= i <= h the level is at row r + l - 3 * 2 ^ (i - 1)
		int bottomRow = r + l - 1;
		if (lowerBoundY <= bottomRow && bottomRow <= upperBoundY) {
			int startX = c - l + 1;
			int endX = c + l - 1;

			if (cHigher >= startX && cLower <= endX) {
				int lowerBoundX = max(startX, cLower);
				int upperBoundX = min(endX, cHigher);

				int left = 0;
				if (lowerBoundX > startX) {
					left = ((lowerBoundX - 1 - startX) / 6) * 2 + 1 + ((lowerBoundX - 1 - startX) % 6 >= 4);
				}
				int right = ((upperBoundX - startX) / 6) * 2 + 1 + ((upperBoundX - startX) % 6 >= 4);

				res += right - left;	
			}
		}

		int currHeight = 3;
		int spacing = 6;
		range(i, 1, h + 1) {
			int row = r + l - currHeight;
			if (row < lowerBoundY) {
				break;
			}
			if (row > upperBoundY) {
				currHeight *= 2;
				spacing *= 2;
				continue;
			}

			int startX = c - l + currHeight;
			int endX = c + l - currHeight;

			if (cHigher < startX || cLower > endX) {
				break;
			}

			int lowerBoundX = max(startX, cLower);
			int upperBoundX = min(endX, cHigher);

			int left = 0;
			if (lowerBoundX > startX) {
				left = (lowerBoundX - 1 - startX) / spacing + 1;
			}
			int right = (upperBoundX - startX) / spacing + 1;

			//print("Valid Nodes in row", i, right - left);

			res += right - left;

			currHeight *= 2;
			spacing *= 2;
		}
		//print("Total Nodes:", res);
		//print("");
		print(res);
	}
}