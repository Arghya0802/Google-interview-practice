Q link: https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) 
    {
        if(n == 0 || n == 1) return 0;

        vector<int> primes(n, 1); // Initially we assume all are primes

        primes[0] = primes[1] = 0; // They are neither prime nor composite

        int countOfPrimes = 0;

        for(int i = 2; i * i < n; i++)
        {
            if(primes[i] == 1) // If primes[i] is a Prime then its multiples cannot be prime
            {
                for(int j = i * i; j < n; j += i)
                primes[j] = 0;
            }
        }

        for(int i = 2; i < n; i++) countOfPrimes += primes[i] == 1;

        return countOfPrimes; 
    }
};
