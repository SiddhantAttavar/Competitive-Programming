<<<<<<< HEAD
#include <iostream>
using namespace std;

int main() {
	printf("Welcome to the Calculator!\n\n");
	
	printf("Enter the operation:\nAddition: 0\nSubtraction: 1\nMultiplication: 2\nDivision: 3\n");
	int oper;
	cin >> oper;

	printf("Enter the two numbers: ");
	int x;
	int y;
	cin >> x;
	cin >> y;

	int ans;

	switch (oper) {
		case 0:
			ans = x + y;
			break;
		case 1:
			ans = x - y;
			break;
		case 2:
			ans = x * y;
			break;
		case 3:
			ans = x / y;
			break;
		default:
			printf("Invalid Input\n");
			cerr << "Invalid Input" << endl;
			return 0;
	}

	printf("The answer is: %d", ans);

	printf("\nDo you want to use the calculator again? (Y / N): \n");
	char reply;
	cin >> reply;
	if (reply == 'Y') {
		printf("\n");
		main();
	}
	else {
		printf("Thank you for using the Calculator\n");
	}
=======
#include <iostream>
using namespace std;

int main() {
	printf("Welcome to the Calculator!\n\n");
	
	printf("Enter the operation:\nAddition: 0\nSubtraction: 1\nMultiplication: 2\nDivision: 3\n");
	int oper;
	cin >> oper;

	printf("Enter the two numbers: ");
	int x;
	int y;
	cin >> x;
	cin >> y;

	int ans;

	switch (oper) {
		case 0:
			ans = x + y;
			break;
		case 1:
			ans = x - y;
			break;
		case 2:
			ans = x * y;
			break;
		case 3:
			ans = x / y;
			break;
		default:
			printf("Invalid Input\n");
			cerr << "Invalid Input" << endl;
			return 0;
	}

	printf("The answer is: %d", ans);

	printf("\nDo you want to use the calculator again? (Y / N): \n");
	char reply;
	cin >> reply;
	if (reply == 'Y') {
		printf("\n");
		main();
	}
	else {
		printf("Thank you for using the Calculator\n");
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}