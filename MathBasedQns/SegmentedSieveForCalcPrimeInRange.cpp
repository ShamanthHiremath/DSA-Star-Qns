void segmentedSieve(int L, int R) {
    int limit = sqrt(R);
    std::vector<int> primes;
    simpleSieve(limit, primes);

    std::vector<bool> isPrime(R - L + 1, true);

    for (int p : primes) {
        int start = std::max(p * p, (L + p - 1) / p * p);
        for (int multiple = start; multiple <= R; multiple += p) {
            isPrime[multiple - L] = false;
        }
    }

    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            std::cout << L + i << " ";
        }
    }
    std::cout << std::endl;
}