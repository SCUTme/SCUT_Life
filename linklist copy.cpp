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
class singlelist//单链表
{
public:
    snode *head=NULL;
    int size=1;
    void init()
    {
        snode *p=new snode();
        head=p;
        p->value=1;
        for(int i=3;i<=11;i+=2)
        {
            size++;
            p->next=new snode();
            p=p->next;
            p->value=i;
        }
    }
    void show()//遍历打印该链表
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
    snode* find(int v)
    {
        snode *p=head;
        while(p!=NULL&&p->value!=v)
        {
            p=p->next;
        }
        return p;
    }
    int GetSize()//返回链表大小
    {
        return size;
    }
    void insert(int x)
    {
        snode *pos=find(x),*tem=head;
        if(pos==NULL)
        {
            size++;
            if(tem==NULL)
            {
                head=new snode();
                head->value=x;
                return;
            }
            pos=new snode();
            pos->value=x;
            while(tem->next!=NULL)  
                tem=tem->next;
            tem->next=pos;
        }
        cout<<"\nNew List is:\n";
        show();
    }
    void Delete(int x)
    {
        snode *pos=find(x),*tem=head;
        if(pos!=NULL)
        {
            size--;
            if(pos==head)
            {
                head=pos->next;
                delete tem;
            }
            else
            {
                while(tem->next->value!=x)
                    tem=tem->next;
                tem->next=pos->next;
                delete pos;
            }
        }
        cout<<"\nNew List is:\n";
        show();
    }
};

int main()
{
    singlelist sl,sl2,reasult;
    sl.init();
    int a;
    cout<<"List 1:";
    sl.show();
    
    sl2.init();
    sl2.head->value=5;
    cout<<"List 2:";sl2.show();

    snode *p1=sl.head,*p2=sl2.head,*tem=sl2.head;
    while(p1!=NULL)
    {
        p2=tem;
        while(p2!=NULL)
        {
            if(p1->value==p2->value)
            {
                tem=p2;
                reasult.insert(p1->value);
                p1=p1->next;
            }
            p2=p2->next;
        }
        if(p1==NULL) break;
        p1=p1->next;
    }
    cout<<"Answer is:";
    reasult.show();
    system("pause");
}