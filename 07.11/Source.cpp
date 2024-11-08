#include <iostream>

using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) 
    {
    
    }
};

class Queue 
{
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) 
    {
    
    }

    ~Queue() 
    {
        while (front) 
        {
            dequeue();
        }
    }

    void enqueue(int value) 
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else 
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front)
        {
            front->prev = nullptr;
        }
        else
        {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() const 
    {
        if (isEmpty()) 
        {
            throw out_of_range("Queue is empty. Cannot peek.");
        }
        return front->data;
    }

    bool isEmpty() const 
    {
        return front == nullptr;
    }

    void display() const 
    {
        Node* current = front;
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue elements: ";
    queue.display();

    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue();
    cout << "After dequeue, queue elements: ";
    queue.display();
}
