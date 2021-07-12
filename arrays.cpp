#include<iostream>
#include<array>

using namespace std;

int main()
{
    array<int, 4> a = {1,2,3,4};
    for(int x: a)
    {
        cout<<x<<endl;
    }
    
    cout<<"Element at 2nd index "<<a.at(2)<<endl; //same as a[2]
    cout<<"Array is empty or not"<<a.empty()<<endl; 
    cout<<"First element "<<a.front()<<endl; //same as a[0]
    cout<<"Last element "<<a.back()<<endl; //same as a[a.size()-1]
}