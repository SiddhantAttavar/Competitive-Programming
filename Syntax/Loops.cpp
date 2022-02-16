#include <iostream>
using namespace std;

int main() {
	printf("Enter the maximum number: ");
	int max;
	cin >> max;
	printf("\n");

	printf("While Loop\n");
	int i = 0;
	while (i < max) {
		printf("While Loop: %d\n", i);
		i++;
	}
	printf("\n");

	printf("For Loop\n");
	for (int j = 0; j < max; j++) {
		printf("For Loop: %d\n", j);
	}
	printf("\n");

	printf("Do While Loop\n");
	int k = 0;
	do {
		printf("Do While Loop: %d\n", k);
		k++;
	} while (k < max);
}
