#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    public:
    Difference(vector<int> vec){
        this->elements = vec;
    }
	// Add your code here
    void computeDifference(){
        
        int max = * max_element(std::begin(elements), std::end(elements));
        int min = * min_element(std::begin(elements), std::end(elements));
        
        maximumDifference = abs(max-min);
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;    
    vector<int> a;    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;        
        a.push_back(e);
    }    
    Difference d(a);    
    d.computeDifference();    
    cout << d.maximumDifference;    
    return 0;
}
