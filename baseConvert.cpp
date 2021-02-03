#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int a, b;
    vector<int> base2; // will be the input number in base 2

    cout << "Enter a number whose palindrome pair you want to find in base 2: ";
    cin >> a; // obtains initial input

    cout << endl;

    while(a != 0){
        b = a%2;
        a = a/2;
        base2.insert(base2.begin(), b); // adds b to beginning of vector
    }

    cout << "Item in base 2: ";

    for(int i = 0; i < base2.size(); i++){
        cout << base2[i]; // prints vector contents
    }
    
    cout << endl;

    return 0;
}
