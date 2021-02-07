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

    int a, b, pair, max;
    vector<int> base; // will be the input number in the current base
    vector<int> backwards; // the base 2 conversion backwards
    ofstream file; // to write output to a file

    file.open("output.txt");
    file << "Base,Prime1,Prime2,Palindrome" << endl;

    cout << "Enter the maximum number to consider when matching prime palindromes: ";
    cin >> max; // obtains initial input

    cout << endl;

    for(int currentBase = 2; currentBase < 11; currentBase++){

        for(int i = 0; i <= max; i++){ // we cycle through every number up to the max

            if(prime(i)){ // if we are at a prime number...

                a = i; // initialize a
                base.clear(); // clear vector
                backwards.clear(); // clear vector

                // will hopefully do the heavy lifting of conversions
                convertToBase(i, currentBase, base, backwards);
                

                pair = convert_decimal(backwards, currentBase); // converts the backward vector into an integer in base10

                if(prime(pair)){ // if the pair is prime, we found a prime palindrome pair
                    cout << "In Base " << currentBase << ": (" << i << ", " << pair << ") is ";
                    printVec(base);
                    printVec(backwards);
                    cout << endl;

                    file <<  currentBase << "," << i << "," << pair << ",";
                    for(int i = 0; i < base.size(); i++){
                        file << base[i];
                    }
                    for(int i = 0; i < backwards.size(); i++){
                        file << backwards[i];
                    }

                    file << endl;

                }
            
            }

        }

        cout << endl;

    }

    

    cout << endl << endl;

    file.close();

    system("pause");

    return 0;
}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i]; // prints vector contents
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
