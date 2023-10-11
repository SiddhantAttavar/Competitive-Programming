#include <stdio.h>

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int x;
		scanf("%d", &x);
		char n[x];
		scanf("%s", n);

		if (x == 1) {
			printf("8\n");
		}
		else if (x == 2) {
			int a = 10 * (n[0] - '0') + (n[1] - '0');
			if (a % 8 != 0) {
				for (int i = 0; i < 10; i++) {
					a = 10 * (n[0] - '0') + i;
					if (a % 8 == 0) {
						n[1] = (char) ((int) '0' + i);
						break;
					}
				}
			}
			printf("%s\n", n);
		}
		else {
			int a = 100 * (n[x - 3] - '0') + 10 * (n[x - 2] - '0') + (n[x - 1] - '0');
			if (a % 8 != 0) {
				for (int i = 0; i < 10; i++) {
					a = 100 * (n[x - 3] - '0') + 10 * (n[x - 2] - '0') + i;
					if (a % 8 == 0) {
						n[x - 1] = (char) ((int) '0' + i);
						break;
					}
				}
			}
			printf("%s\n", n);
		}
	}
	return 0;
}
