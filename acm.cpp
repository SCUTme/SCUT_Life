#include<iostream>
#include<string>
using namespace std;
struct node
{
    int value;
    node *next=NULL;
};
class num
{
private:
    int size;
    node *head;
public:
    num(string s="0")
    {

    }
};
int main()
{
    cout<<"Please enter the first number:"<<'\n';
    string s;
    getline(cin,s);

    system("pause");
}