#include<iostream>
using namespace std;
template<typename T1, typename T2>
class Pair
{
private:
    T1 x;
    T2 y;
public:
    void setX(T1 x)
    {
        this->x=x;
    }
    void setY(T2 y)
    {
        this->y=y;
    }

    T1 getX()
    {
        return x;
    }
    T2 getY()
    {
        return y;
    }
};
int main()
{
    Pair<int, float> p1;
    Pair<Pair<int, float>, float> P;
    p1.setX(12);
    p1.setY(3.5);
    P.setX(p1);
    P.setY(123.485);
    cout<<P.getX().getX()<<endl;
    cout<<P.getY()<<endl;
    cout<<P.getX().getY()<<endl;
}