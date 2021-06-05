#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          //Complete this method
            if (head == NULL){             // Parametre olarak girilen head NULL mu? NULL ise;
                head = new Node(data);
            } else if(head->next == NULL){ // Parametre olarak girilen head in next i NULL mu? NULL ise;
                Node* tmp = new Node(data);
                head->next = tmp;
            }else {                        // İkisi de NULL değilse insert yap
                insert(head->next, data);
            }
            return head;
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}
