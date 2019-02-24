#include <cmath>
#include <iostream>
#include <vector>           // My first time using std::vector

int main(int argc, char *argv[])
{
    const int n = 2000;
    
    std::vector<bool> primeList ( n, true);      //Assume all prime (true)!
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primeList[i] == true)                   //Ignore confirmed prime.
        {
            for (int p = i *2; p <= n; p += i)      //All multiples are composite.
                primeList[p] = false;

        }
        
    }
    
for(int i=2;  i<=n ; i++)
    if (primeList[i] == true) {
        std::cout <<i << " ";
    }

    return 0;
}
