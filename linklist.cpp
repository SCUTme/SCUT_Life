#include<iostream>
//数据结构作业
//张哲 202265117190
using namespace std;
class snode//单项链表节点
{
public:
    snode *next=NULL;
    int value;
};
class dnode
{
public:
    dnode *pre=NULL;
    int value;
    dnode *next=NULL;
};
class singlelist//单链表
{
public:
    snode *head=NULL;
    void init()
    {
        snode *p=new snode();
        head=p;
        p->value=1;
        for(int i=3;i<=11;i+=2)
        {
            p->next=new snode();
            p=p->next;
            p->value=i;
        }
    }
    void show()//遍历该链表
    {
        cout<<"single list is :";
        snode * p =head;
        while(p!=NULL)
        {
            cout<<p->value<<' ';
            p=p->next;
        }
        cout<<'\n';
    }
    snode *find(int v)
    {
        snode *p=head;
        while(p->value!=v&&p!=NULL)
        {
            p=p->next;
        }
        if(p->value==v)
            return p;
        else
            return NULL;
    }
    void problem2()
    {
        cout<<"Before changes:\n";
        show();
        cout<<"\nPlease enter two adjacent values a and b, distinguish left and right:\n"<<"a=";
        int a,b;
        cin>>a;
        cout<<"b=";
        cin>>b;
        if(head->value==a)
        {
            snode *tem;
            tem=head;
            head=head->next;
            tem->next=head->next;
            head->next=tem;
        }
        else
        {
            snode *p=head,*ta,*tb;
            while(p->next->value!=a)
                p=p->next;
            ta=p->next;//a
            tb=ta->next;//b
            ta->next=tb->next;
            tb->next=ta;
            p->next=tb;
        }
        cout<<"After change:\n";
        show();
    }
};

class doublelist//双链表
{
public:
    dnode *head=NULL;
    dnode *end=NULL;
    void init()
    {
        dnode *p=new dnode(),*q;
        p->value=2;
        head=p;
        for(int i=4;i<=18;i+=2)
        {
            q=new dnode();
            q->value=i;
            q->pre=p;
            end=q;
            p->next=q;
            p=q;
        }
    }
    void show()//遍历该链表
    {
        cout<<"double list is :";
        dnode * p =head;
        while(p!=NULL)
        {
            cout<<p->value<<' ';
            p=p->next;
        }
        cout<<'\n';
    }
    void problem2()
    {
        cout<<"Before changes:\n";
        show();
        cout<<"\nPlease enter two adjacent values a and b, distinguish left and right:\n"<<"a=";
        int a,b;
        cin>>a;
        cout<<"b=";
        cin>>b;
        dnode *p=head,*tb;
        while(p->value!=a)
            p=p->next;
        tb=p->next;//b
        if(p->pre!=NULL)
        {
            p->pre->next=tb;
            p->next=tb->next;
            tb->next=p;
            tb->next->pre=p;
        }
        else
        {
            p->next=tb->next;
            p->pre=tb;
            head=tb;
            tb->pre=NULL;
            tb->next=p;
        }
        cout<<"After change:\n";
        show();

    }
};
int main()
{
    singlelist sl;
    sl.init();
    sl.problem2();

    cout<<"\n\n\n";

    doublelist dl;
    dl.init();
    dl.problem2();
    system("pause");
}