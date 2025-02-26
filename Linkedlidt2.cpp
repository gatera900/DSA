#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node *next;

    
    Node() : data(0), next(NULL) {}

    
    Node(T d) : data(d), next(NULL) {}
};


Node<int> n4(40);
 

template <typename T>
void display(Node<T> *head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next; 
    }
    cout << "NULL" << endl; 
}

int main() {
    // Creating nodes with integer data
    Node<int> *n1 = new Node<int>();
    Node<int> *n2 = new Node<int>(20);
    Node<int> *n3 = new Node<int>(30);

    // Connecting nodes
    n1->data = 15;
    n1->next = n2;
    n2->next = n3;
    n3->next = &n4;
    // Connect the global node to the linked list

    // Displaying the list
    display(n1);

    // Example with string data
   

    return 0;
}

