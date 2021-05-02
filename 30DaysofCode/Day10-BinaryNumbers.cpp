#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string binary_num;
    int max = 0, count = 0;
    
    while (n > 0){
        binary_num = to_string(n%2) + binary_num;
        n = n/2;
    }
    
    for (int i=0; i<binary_num.length(); i++){
        if (binary_num[i] == '1'){
            count += 1;
        }
        if (binary_num[i] == '0' || i == binary_num.length()-1){
            if (count > max){
                max = count;
            }
            count = 0;            
        }
    }
    cout << max << endl;
    
    return 0;
}
