#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

void printVec(vector<int>); // prints the passed vector to console
bool prime(int); // determines if the passed number is a prime number
void convertToBase(int n, int base, vector<int>&, vector<int>&); // converts a number to a base
int convert_decimal(vector<int> vec, int base); // to convert to decimal

int main(){

    int max; // the largest number that we will consider
    int X = 2; // will store the maximum base that we are searching through
    int pair; // will store the pair (or, mirror)
    vector<int> listN; // will store the Smaug sequence (the primes that require to use of additional bases to find a palindrome prime)
    vector<int> base; // will be the input number in the current base
    vector<int> backwards; // will be the converted number backwards
    bool flag = false; // our boolean flag

    cout << endl << "Enter the largest number that we will consider (N): ";
    cin >> max;
    cout << endl;

    for(int n=2; n <= max; n++){ // we cycle through each number from 2 to max

        flag = false; // we reset the flag

        if(prime(n)){ // if we are currently considering a prime number

            for(int currentBase=2; currentBase <= X; currentBase++){ // we go through each base

                base.clear();
                backwards.clear();

                convertToBase(n, currentBase, base, backwards); // converts n to base
                pair = convert_decimal(backwards, currentBase); // converts the backward vector into an integer in base10

                if(prime(pair)){ // if the mirror is prime

                    flag = true;

                }


            }

            if(!flag){ // if the flag was never made true/if the number had no prime mirror from base 2-10

                // we need to find the base required to find a prime mirror for the palindrome
                while(!flag){

                    X++; // we increase the base by one

                    base.clear();
                    backwards.clear();

                    convertToBase(n, X, base, backwards); // converts n to base
                    pair = convert_decimal(backwards, X); // converts the backward vector into an integer in base10

                    if(prime(pair)){

                        flag = true;

                    }

                }


                listN.push_back(n); // add N to the integers to require increase in base range

            }

        }

    }

    cout << "The integers that require an increase in base range are: " << endl;

    printVec(listN);

    cout << endl;

    return 0;
}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}

bool prime(int n){
     
    if (n <= 1){ // edge case
        return false;
    }
    
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true; 
}

int convert_decimal(vector<int> vec, int base){

   int len = vec.size();
   int power = 1;
   int num = 0;
   int i;

   for (i = len - 1; i >= 0; i--) {

      if (vec[i] >= base) {
         printf("Invalid Number");
         return -1;
      }

      num += vec[i] * power;
      power = power * base;
   }

   return num;

}

void convertToBase(int n, int base, vector<int>& baseVec, vector<int>& backwardsVec){

    int b;

    while(n != 0){
            b = n%base;
            n = n/base;
            baseVec.insert(baseVec.begin(), b); // adds b to beginning of vector
            backwardsVec.push_back(b);
    }

}
