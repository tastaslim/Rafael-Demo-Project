#include<iostream>
using namespace std;

class TaslimMadeStack {
private:
    int *arr;
    int capacity;
    int nextIndex;
public:
    TaslimMadeStack()
    {
        nextIndex=0;
        capacity=nextIndex;
        arr=new int[capacity];
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        if (nextIndex==0)
            return true;
        return false;
    }
    void push(int data)
    {
        if (nextIndex==capacity)
        {
            capacity=2*capacity;
            int *newArray=new int[capacity];
            for (int i=0;i<capacity;i++)
            {
                newArray[i]=0;
            }
            for (int i=0;i<capacity/2;i++)
            {
                newArray[i]=arr[i];
            }
            delete[] arr;
            arr=newArray;
            arr[nextIndex]=data;
            nextIndex++;
        }
        else
        {
            arr[nextIndex]=data;
            nextIndex++;
        }
    }

    int pop()
    {
        if (nextIndex==0)
        {
            cout<<"Underflow case as Stack is already Empty"<<endl;
            return -1;
        }
        nextIndex--;
        return arr[nextIndex-1];
    }

    int top()
    {
        if (nextIndex==0)
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[nextIndex-1];
    }
};

int main()
{
    TaslimMadeStack s;
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.size()<<endl;
    s.push(4);
    cout<<s.size()<<endl;
    s.push(5);
    cout<<s.top()<<endl;
    s.push(6);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    return 0;
}