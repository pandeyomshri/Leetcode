//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int zero=0,one=0,two=0;
        while(head){
            if(head->data==0)
            zero++;
            if(head->data==1)
            one++;
            if(head->data==2)
            two++;
            head=head->next;
        }
        int total=zero+one+two;
        Node* ans=new Node(0);
        Node* finalAns=ans;
        
        while(total--)
        {
            if(zero){
                // Node* temp=new Node(0);
                ans->next=new Node(0);
                ans=ans->next;
                zero--;
            }
            else if(one){
                // Node* temp=new Node(1);
                ans->next=new Node(1);
                ans=ans->next;
                one--;
            }
            else if(two){
                // Node* temp=new Node(2);
                ans->next=new Node(2);
                ans=ans->next;
                two--;
            }
            
        }
        return finalAns->next;
        // Add code here
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends