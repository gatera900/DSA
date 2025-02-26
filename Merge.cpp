#include <iostream>
using namespace std;

Void *mid_point(Node *head)
{
    // base case
    if(head == NULL || head->next == NULL)
        return head;
    // recursive case
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if(fast->next == NULL)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
Void * merge_sort(Node *head)
{
   
    if(head == NULL || head->next == NULL)
        return head;
 
    
    Node *mid = mid_point(head);
    Node *a = head;
    Node *b = mid->next;
 
    mid->next = NULL;
 
   
    a = merge_sort(a);
    b = merge_sort(b);
 
    
    Node *c = merge(a, b);
 
    return c;
}

 


