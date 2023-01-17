class Solution
{
public:
    vector<int> primes;
    vector<bool> is_prime;
    void prime_sieve(int n)
    {
        is_prime.assign(n + 1, 1);
        is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i <= n; i += 2)
            is_prime[i] = 0;
        for (int i = 3; i * i <= n; i += 2)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= n; j += i * 2)
                {
                    is_prime[j] = 0;
                }
            }
        }
        primes.push_back(2);
        for (int i = 3; i <= n; i += 2)
        {
            if (is_prime[i])
            {
                primes.push_back(i);
            }
        }
    }

    vector<int> closestPrimes(int left, int right)
    {
        prime_sieve(right);
        int l = -1, r = -1, mi = INT_MAX;
        for (int i = 1; i < primes.size(); i++)
        {
            if (left <= primes[i - 1] && primes[i] <= right)
            {
                int d = primes[i] - primes[i - 1];
                if (d < mi)
                {
                    mi = d;
                    l = primes[i - 1];
                    r = primes[i];
                }
            }
        }
        return l != -1 && r != 1 ? vector<int>{l, r} : vector<int>{-1, -1};
    }
};