#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVec(vector<int>); // prints the passed vector
int getPair(vector<int>); // obtains the palindrome pair of the passed base 2 vector

int main(){

    int input, a, b, pair;
    vector<int> base2; // will be the input number in base 2

    cout << endl << "Enter a number whose palindrome pair you want to find in base 2: ";
    cin >> input; // obtains initial input

    a = input;

    cout << endl;

    while(a != 0){
        b = a%2;
        a = a/2;
        base2.insert(base2.begin(), b); // adds b to beginning of vector
    }

    pair = getPair(base2); // converts the backward vector into an integer in base10

    cout << "Palindrome Pair for " << input << " in base 2 is: " << pair << endl;

    cout << endl;

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
