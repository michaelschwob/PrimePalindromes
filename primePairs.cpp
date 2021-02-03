#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVec(vector<int>); // prints the passed vector
int getPair(vector<int>); // obtains the palindrome pair of the passed base 2 vector
bool prime(int); // determines if the passed number is a prime number

int main(){

    int a, b, pair, max;
    vector<int> base2; // will be the input number in base 2
    vector<int> backwards; // the base 2 conversion backwards

    cout << endl << "Enter the maximum number to consider when matching prime palindromes in base 2: ";
    cin >> max; // obtains initial input

    for(int i = 0; i <= max; i++){ // we cycle through every number up to the max

        if(prime(i)){ // if we are at a prime number...

            a = i; // initialize a
            base2.clear(); // clear vector
            backwards.clear();

            while(a != 0){
                b = a%2;
                a = a/2;
                base2.insert(base2.begin(), b); // adds b to beginning of vector
                backwards.push_back(b);
            }

            pair = getPair(base2); // converts the backward vector into an integer in base10

            cout << "(" << i << ", " << pair << ") is ";
            printVec(base2);
            printVec(backwards);
            cout << endl;
        }

    }

    return 0;
}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i]; // prints vector contents
    }
}

int getPair(vector<int> base2){

    int pair = 0;
    
    for(int i = 0; i < base2.size(); i++){
        if(base2[i] == 1){
            pair = pair + pow(2,i);
        }
    }

    return pair;
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
