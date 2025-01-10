# Predicting the sequence generation process based on examples provided
# The observed sequence:
# Input: 5 -> Output: 1 1 2 3 5 (Fibonacci sequence of length 5)
# Input: 10 -> Output: 1 1 2 3 5 8 4 3 7 10 (Fibonacci with a twist after 6th term)
# Input: 7 -> Output: 1 1 2 3 5 8 4

def generate_sequence(n):
    sequence = []
    a, b = 1, 1

    for i in range(n):
        if i < 6:  # First 6 terms follow Fibonacci sequence
            sequence.append(a)
            a, b = b, a + b
        else:  # After 6th term, it changes
            sequence.append((sequence[i - 1] + sequence[i - 2]) % 10)

    return sequence

# Testing examples
print(*generate_sequence(int(input())))
