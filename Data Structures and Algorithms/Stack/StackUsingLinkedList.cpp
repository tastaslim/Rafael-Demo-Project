#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data=data;
        this->next=NULL;
    }
};

template<typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack

public:

    Stack() {
        head=NULL;
        size=0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if (size==0)
            return true;
        return false;
    }

    void push(T element)
    {
        Node<T> *newNode=new Node<T>(element);
        if (!head)
        {
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
        size++;
    }

    T pop()
    {
        if (size==0)
        {
            return 0;
        }
        Node<T>* temp=head;
        T ans=temp->data;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if (size==0)
        {
            return 0;
        }
        return head->data;
    }
};
int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    s.push(4);
    cout<<s.getSize()<<endl;
    s.pop();
    cout<<s.getSize();
    return 0;
}