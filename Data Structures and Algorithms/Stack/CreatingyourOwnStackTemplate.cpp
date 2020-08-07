#include<iostream>
using namespace std;
template<typename T>
class Taslim
{
private:
    T *arr;
    int capacity;
    int nextIndex;
public:
    Taslim()
    {
        capacity=0;
        nextIndex=0;
        arr=new T[capacity];
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
    void push(T data)
    {
        if (nextIndex==capacity)
        {
            capacity=2*capacity;
            T *newArray=new T[capacity];
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

    T pop()
    {
        if (nextIndex==0)
        {
            cout<<"Underflow case as Stack is already Empty"<<endl;
            return -1;
        }
        nextIndex--;
        return arr[nextIndex-1];
    }

    T top()
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
    Taslim<float> s;
    s.push(2.5);
    s.push(3.5);
    cout<<s.size()<<endl;
    float ans=s.top();
    cout<<ans;

}