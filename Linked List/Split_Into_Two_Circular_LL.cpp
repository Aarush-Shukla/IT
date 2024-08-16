#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insert(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *n = new Node(d);
        head = n;
        n->next = n;
        return;
    }
    Node *n = new Node(d);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
int getlen(Node *&head)
{
    Node *temp = head;
    int cnt = 1;
    while (temp->next != head)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
Node *split(Node *head, int count)
{
    Node *temp = head;
    if (count % 2 == 0)
    {
        int count2 = 1;
        while (count2 < count / 2)
        {
            count2++;
            temp = temp->next;
        }
        Node *restPart = temp->next;
        Node *restPartNode = restPart;
        temp->next = head;

        count2 = 1;
        while (count2 < count / 2)
        {
            count2++;
            restPart = restPart->next;
        }
        restPart->next = restPartNode;
        return restPartNode;
    }
    else
    {
        int count2 = 0;
        while (count2 < count / 2)
        {
            count2++;
            temp = temp->next;
        }
        Node *restPart = temp->next;
        Node *restPartNode = restPart;
        temp->next = head;

        count2 = 1;
        while (count2 < count / 2)
        {
            count2++;
            restPart = restPart->next;
        }
        restPart->next = restPartNode;
        return restPartNode;
    }
}
void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "Node is empty" << endl;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node *head = NULL;
    insert(head, 10);
    insert(head, 11);
    insert(head, 12);
    insert(head, 13);
    insert(head, 14);
    insert(head, 15);
    insert(head, 16);
    insert(head, 17);
    

    print(head);

    int count = getlen(head);
    Node *restPart = split(head, count);
    print(head);
    print(restPart);
}

// void splitCLL(Node* head, Node** head1, Node** head2){
    
//     Node* slow = head;
//     Node* fast = head;

//     while(fast -> next != head && fast -> next -> next != head){
//         fast = fast -> next -> next;
//         slow = slow -> next;
//     }
//     // After above steps slow is pointing mid and fast is pointing last node
//     if(fast -> next -> next == head){
//         fast = fast -> next;
//     }
//     // Set the head pointer of first half 
//     *head1 = head;

//     // Set the head pointer of second half
//     if (head -> next != head){
//         *head2 = slow -> next;
//     }

//     // Make second half circular
//     fast -> next = slow -> next;
    
//     // Make first half circular
//     slow -> next = head;
    
// }