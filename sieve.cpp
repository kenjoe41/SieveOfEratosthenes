#include <cstdlib>
#include <numeric>
#include <iostream>
#include <set>
#include <iterator>
 
using namespace std;
/**
Sieve of Eratosthenes
By: Kenjoe41
For: EZ challenge 17
Site:https://evilzone.org/weekly-challenge/challenge-17-sieve-of-eratosthenes/
 
Algorithm:
 
Create a contiguous list of numbers from two to some highest number n.
Strike out from the list all multiples of two (4, 6, 8 etc.).
The list's next number that has not been struck out is a prime number.
Strike out from the list all multiples of the number you identified in the previous step.
Repeat steps 3 and 4 until you reach a number that is greater than the square root of n (the highest number in the list).
All the remaining numbers in the list are prime.
**/
void sieveOfEratosthenes(unsigned int n)
{
    if(n >= 2)//i don't remember prime number smaler than 2
    {
        set<unsigned int> sieve; //room for 0
        //std::iota(sieve.begin(); sieve.end();0);
        for(auto it=2;it < n;++it)
    {
        sieve.insert(it);
    }
 
        typedef set<unsigned int>::iterator iterator;
        // A set is ordered.
        // So going from beginning to end will give all the values in order.
        for(iterator it = sieve.begin(); it != sieve.end(); ++it)
        {
            //Next item in set in prime
            //since it aint deleted, must be a prime number
            int prime = *it;
 
            //iterate through all elements
            //remove any divisible by this prime number.
            iterator deleter = it;
            ++deleter;
 
            while (deleter != sieve.end())
            {
                if(((*deleter) % prime) == 0)
                {
                    //if modulus is 0
                    //hence it ain't a prime number
                    //so erase from set
                    //postfix: return old value for erase method and increment iterator
                    sieve.erase(deleter++);
                }
                else
                {
                    //then just increment iterator
                    ++deleter;
                }
            }
        }
        //copy all remaining elements to std output.
        copy(sieve.begin(),sieve.end(), ostream_iterator<int>(cout,"\n"));
    }
}
 
int main(int argc, char* argv[])
{
    // for each number passed to the program
    for (auto p = argv + 1; p != argv + argc; ++p)
    {
        cout << "Prime numbers up to "<< string(*p) << " are: \n";
        cout << "==========================\n";
        auto num = atoi(*p);
        sieveOfEratosthenes(num);
        cout <<endl;
    }
    return 0;
}
 
