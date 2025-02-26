#include <iostream>
using namespace std;

// Define the Node structure for the stack
struct Node {
    int data;
    Node* next;

    // Constructor to initialize the Node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class implementation
class Stack {
private:
    Node* top;

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = nullptr;
    }

    // Push data onto the stack
    void push(int data) {
        Node* newNode = new Node(data); // Create a new node
        newNode->next = top;             // Link it to the previous top node
        top = newNode;                   // Move the top pointer to the new node
    }

    // Pop data from the stack
    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;  // Indicating empty stack
        } else {
            int poppedData = top->data;
            Node* temp = top;
            top = top->next;  // Move top to the next node
            delete temp;      // Free the memory of the old top node
            return poppedData;
        }
    }

    // Peek at the top element
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;  // Indicating empty stack
        } else {
            return top->data;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Main function to test the stack
int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Peek at the top element
    cout << "Top element: " << stack.peek() << endl;

    // Pop elements from the stack
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}
