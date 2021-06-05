#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isPrime(int number){
    bool isPrime = true;
    // 0 and 1 are not prime numbers
    if(number == 0 || number == 1){
        isPrime = false;
    }
    else{
        // A better solution is to store the number's square root in a variable before testing.
        int sq = sqrt(number);
        // This takes one operation out of the loop, saving a lot of CPU cycles when dealing with bigger numbers.
        for(int i=2; i<=sq; i++){
            if(number%i == 0){
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, num;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        if(isPrime(num) == true){
            cout << "Prime" << endl;
        }else{
            cout << "Not prime" << endl;
        }
    }
    return 0;
}
