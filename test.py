from math import gcd
from collections import defaultdict, Counter

def sieve_primes(limit):
	"""Generates all prime numbers up to a given limit."""
	is_prime = [True] * (limit + 1)
	is_prime[0] = is_prime[1] = False
	primes = []
	for i in range(2, limit + 1):
		if is_prime[i]:
			primes.append(i)
			for j in range(i * i, limit + 1, i):
				is_prime[j] = False
	return primes

def update_divisor_count(x, divisor_count, max_val):
	"""Update the divisor count array for a newly added element x."""
	for d in range(1, int(x**0.5) + 1):
		if x % d == 0:
			divisor_count[d] += 1
			if d != x // d:
				divisor_count[x // d] += 1

def count_non_coprime_pairs(x, divisor_count, max_val):
	"""Count the number of elements in the array not co-prime with x."""
	non_coprime_count = 0
	for d in range(1, int(x**0.5) + 1):
		if x % d == 0:
			non_coprime_count += divisor_count[d]
			if d != x // d:
				non_coprime_count += divisor_count[x // d]
	return non_coprime_count

def construct_array_optimized(N, K, max_val=2000000):
	"""Construct an array A of size N with exactly K coprime pairs."""
	A = []
	primes = sieve_primes(max_val)
	divisor_count = defaultdict(int)  # Tracks the count of divisors
	total_pairs = 0

	# Step 1: Add primes to maximize co-prime pairs
	for p in primes:
		if len(A) < N:
			non_coprime_count = count_non_coprime_pairs(p, divisor_count, max_val)
			co_prime_pairs = len(A) - non_coprime_count
			total_pairs += co_prime_pairs
			A.append(p)
			update_divisor_count(p, divisor_count, max_val)
		if total_pairs == K:
			break

	# Step 2: Add composites if necessary
	if len(A) < N or total_pairs != K:
		composites = [x for x in range(4, max_val + 1) if x not in primes]
		for c in composites:
			if len(A) < N:
				non_coprime_count = count_non_coprime_pairs(c, divisor_count, max_val)
				co_prime_pairs = len(A) - non_coprime_count
				total_pairs += co_prime_pairs
				A.append(c)
				update_divisor_count(c, divisor_count, max_val)
			if total_pairs == K:
				break

	return A

# Example usage
N = 6  # Size of the array
K = 8  # Desired number of co-prime pairs
A = construct_array_optimized(N, K)
print("Constructed Array:", A)
# for _ in range(int(input())):
# 	n, k = map(int, input().split())
# 	a = construct_array_optimized(n, k)
# 	print(*a)
