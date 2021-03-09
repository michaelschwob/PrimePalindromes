#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

void printVec(vector<int>); // prints the passed vector to console
void printVec2(vector<int>); // prints the passed vector to a file
int getPair(vector<int>); // obtains the palindrome pair of the passed base 2 vector
bool prime(int); // determines if the passed number is a prime number

int main(){

    int a, b, pair, max;
    vector<int> base2; // will be the input number in base 2
    vector<int> backwards; // the base 2 conversion backwards
    ofstream file; // to write output to a file

    file.open("output.txt");
    file << "Prime1   In Base2   Prime2   In Base2   Palindrome Pair   In Base2" << endl;

    cout << "Enter the maximum number to consider when matching prime palindromes in base 2: ";
    cin >> max;

    cout << endl;

    for(int i = 0; i <= max; i++){ // we cycle through every number up to the max

        if(prime(i)){

            a = i;
            base2.clear();
            backwards.clear();

            while(a != 0){
                b = a%2;
                a = a/2;
                base2.insert(base2.begin(), b); // adds b to beginning of vector
                backwards.push_back(b);
            }

            pair = getPair(base2); // converts the backward vector into an integer in base10

            if(prime(pair)){ // if the pair is prime, we found a prime palindrome pair
                cout << "(" << i << ", " << pair << ") is ";
                printVec(base2);
                printVec(backwards);
                cout << endl;

                file <<  i << "   ";
                for(int i = 0; i < base2.size(); i++){
                    file << base2[i];
                }
                file << "   " << pair << "   ";
                for(int i = 0; i < backwards.size(); i++){
                    file << backwards[i];
                }
                file << "   (" << i << ", " << pair << ")   ";
                for(int i = 0; i < base2.size(); i++){
                    file << base2[i];
                }
                for(int i = 0; i < backwards.size(); i++){
                    file << backwards[i];
                }

                file << endl;

            }
            
        }

    }

    cout << endl << endl;

    file.close();

    system("pause");

    return 0;
}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
}

void printVec2(vector<int> vec){
    ofstream file;
    for(int i = 0; i < vec.size(); i++){
        file << vec[i];
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
    
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true; 
}
