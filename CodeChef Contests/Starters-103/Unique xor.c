#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k;
		scanf("%d %d", &n, &k);
		char s[n];
		scanf("%s", s);

		int res1 = 0, res2 = 0;
		int flag = 1;
		for (int i = 0; i < k; i++) {
			int x = 0, y = 0;
			for (int j = i; j < n; j += k) {
				x += s[j] == '1';
				y++;
			}

			int a = x / 2 + 2 * (x % 2);
			res1 += a;
		}
		for (int i = 0; i < k; i++) {
			int x = 0, y = 0;
			for (int j = i; j < n; j += k) {
				x += s[j] == '1';
				y++;
			}

			int b = (y - x);
			if (x == 0) {
				flag = 0;
				break;
			}
			res2 += b;
		}
		if (flag == 0 || res1 < res2) {
			printf("%d\n", res1);
		}
		else {
			printf("%d\n", res2);
		}
	}
	return 0;
}
