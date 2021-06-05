#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		int getHeight(Node* root){
          //Write your code here
          if(root == NULL){
              return -1; // 0 iken +1 fazla deger gosteriyor.
          }
          else{
              int left_side  = getHeight(root->left);
              int right_side = getHeight(root->right);
              if (left_side > right_side){
                  // cout << "left" << root->data << left_side << endl;
                  left_side++;
              } else {
                  // cout << "right" << root->data << right_side << endl;
                  right_side++;
              }
              return max(left_side, right_side);
          }
        }
}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
