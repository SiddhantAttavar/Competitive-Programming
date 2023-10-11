#include <stdio.h>

int get(int a, int b, int c) {
	if (b < c) {
		int t = c;
		c = b;
		b = t;
	}
	if (a < b) {
		int t = b;
		b = a;
		a = t;
	}
	if (b < c) {
		int t = c;
		c = b;
		b = t;
	}

	return 100 * a + 10 * b + c;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int a1, a2, a3, b1, b2, b3;
		scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3);
		int x = get(a1, a2, a3);
		int y = get(b1, b2, b3);

		if (x == y) {
			printf("Tie\n");
		}
		else if (x > y) {
			printf("Alice\n");
		}
		else {
			printf("Bob\n");
		}
	}
	return 0;
}
