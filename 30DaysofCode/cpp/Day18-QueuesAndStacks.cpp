#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //Write your code here
    stack<char> stack_;
    queue<char> queue_;
    char c;
    
    public:
    void pushCharacter(char character){
        stack_.push(character);
    }
    char popCharacter(){
        c = stack_.top();
        stack_.pop();
        return c;
    }
    void enqueueCharacter(char character){
        queue_.push(character);
    }    
    char dequeueCharacter(){
        c = queue_.front();
        queue_.pop();
        return c;
    }
};

int main() {
    // Read the string s.
    string s;
    getline(cin, s);
  	// Create the Solution class object p.
    Solution obj;
    
    // Push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    bool isPalindrome = true;
    
    // Pop the top character from stack.
    // Dequeue the first character from queue.
    // Compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            break;
        }
    }
    // Finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    return 0;
}
