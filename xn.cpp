#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

void printVec(vector<int>); // prints the passed vector to console
int getPair(vector<int>); // obtains the palindrome pair of the passed base 2 vector
bool prime(int); // determines if the passed number is a prime number
void convertToBase(int n, int base, vector<int>&, vector<int>&); // converts a number to a base
int convert_decimal(vector<int> vec, int base); // to convert to decimal

int main(){

    // our objective is to print the list of numbers that require the next base to find a prime mirror to form a palindrome

    int max; // the largest number that we will consider
    int X = 2; // will hold which base we are going up to
    int pair; // will be the mirror
    vector<int> listN; // will store the N required to use the next base to find palindrome prime
    vector<int> base; // will be the input number in the current base
    vector<int> backwards; // the base 2 conversion backwards
    bool flag = false; // our boolean flag

    cout << endl << "Enter the largest number that we will consider (N): ";
    cin >> max;
    cout << endl;

    for(int n=2; n <= max; n++){ // we cycle through each number from 2 to max

        flag = false; // we reset the flag

        if(prime(n)){ // if we are currently considering a prime number

            for(int currentBase=2; currentBase <= X; currentBase++){ // we go through each base

                base.clear(); // clear vector
                backwards.clear(); // clear vector

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

                    base.clear(); // clear vector
                    backwards.clear(); // clear vector

                    convertToBase(n, X, base, backwards); // converts n to base
                    pair = convert_decimal(backwards, X); // converts the backward vector into an integer in base10

                    if(prime(pair)){ // if the mirror is prime

                        flag = true;

                    }

                }


                listN.push_back(n); // add N to the integers to require increase in base range

            }

        }

    }

    cout << "The integers that require an increase in base range are: " << endl;
    printVec(listN); // print the sequence

    cout << endl;

    return 0;
}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " "; // prints vector contents
    }
}

int getPair(vector<int> baseVec){

    int pair = 0;
    
    for(int i = 0; i < baseVec.size(); i++){
        if(baseVec[i] == 1){
            pair = pair + pow(2,i);
        }
    }

    return pair;
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

bool prime(int n){
     
    if (n <= 1){ // edge case
        return false;
    }
    
    for (int i = 2; i < n; i++){ // check from 2 to n-1 
        if (n % i == 0){
            return false;
        }
    }
    return true; 
}

void convertToBase(int n, int base, vector<int>& baseVec, vector<int>& backwardsVec){

    int b;

    while(n != 0){
            b = n%base;
            n = n/base;
            baseVec.insert(baseVec.begin(), b); // adds b to beginning of vector
            backwardsVec.push_back(b);
    }
    //cout << "Converted: ";
    //printVec(baseVec);
    //cout << "   Backwards: ";
    //printVec(backwards);

}
