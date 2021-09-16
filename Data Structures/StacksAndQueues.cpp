<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
	int value = 10;

	//Stack
	stack<int> stack;
	stack.push(value);
	int stackSize = stack.size();
	int top = stack.top();
	if (stack.empty()) {
		println("The stack is empty");
	}
	else {
		println("The stack is not empty");
	}
	stack.pop();

	//Queue
	queue<int> queue;
	queue.push(value);
	int queueSize = queue.size();
	int front = queue.front();
	int back = queue.back();
	queue.pop();
	if (stack.empty()) {
		println("The queue is empty");
	}
	else {
		println("The queue is not empty");
	}
=======
#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
	int value = 10;

	//Stack
	stack<int> stack;
	stack.push(value);
	int stackSize = stack.size();
	int top = stack.top();
	if (stack.empty()) {
		println("The stack is empty");
	}
	else {
		println("The stack is not empty");
	}
	stack.pop();

	//Queue
	queue<int> queue;
	queue.push(value);
	int queueSize = queue.size();
	int front = queue.front();
	int back = queue.back();
	queue.pop();
	if (stack.empty()) {
		println("The queue is empty");
	}
	else {
		println("The queue is not empty");
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}