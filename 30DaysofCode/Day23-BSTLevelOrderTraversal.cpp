#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

/* The resulting level-order traversal is 3->2->5->1->4->7, and we print these data values as a single line of space-separated integers.*/
using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }
	
	// Also Tutorials includes these function; inOrder, postOrder, preOrder
	// Output = 1 2 3 4 5 7 
	void inOrder(Node * root){
		if (root == NULL) return;
		if (root != NULL){
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
	}
	// Output = 1 2 4 7 5 3
	void postOrder(Node * root){
		if (root == NULL) return;
		if (root != NULL){
			inOrder(root->left);
			inOrder(root->right);
			cout << root->data << " ";
		}
	} 
	// Output = 3 2 1 5 4 7 
	void preOrder(Node * root){
		if (root == NULL) return;
		if (root != NULL){
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	// Output = 3 2 5 1 4 7
	void levelOrder(Node * root){
		//Write your code here
		// Base Case
		if (root == NULL) return;
		// Create an empty queue for level order traversal
		queue<Node *> q;
		// Enqueue Root and initialize height
		q.push(root);
		while(q.empty() == false){
			// Print front of queue and remove it from queue
			Node* cur = q.front(); 
			cout << cur->data << " ";
			q.pop();
			/* Enqueue left child */
			if(cur->left != NULL){
				q.push(cur->left);
			}
			/*Enqueue right child */
			if (cur->right !=NULL){
				q.push(cur->right);
			}
		}
	}
};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
