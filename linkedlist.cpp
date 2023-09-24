#include<iostream>
#include<string>
using namespace std;
class node
{
public:
	int value=0;
	node *next=NULL;
	void print()
	{
		if(next!=NULL)
			next->print(); 
		cout<<value;
		return;
	}
};
class num
{
public:
	int size;
	node *head;
	num(string s="0")
	{
		this->size=s.size();
		head=new node;
		head->value=s[size-1]-'0';
		node* pos=new node;
		head->next=pos;
		//cout<<"head value"<<head->value<<'\n';
		for(int i=size-2;i>=0;i--)
		{
			pos->value=s[i]-'0';
			//cout<<pos->value<<' ';
			pos->next=new node;
			pos=pos->next;
		}
	}
	void println()
	{
		head->print();
	}
};
num addres,difres,mulres,temres;
void add(num &num1 ,num &num2)
{
	addres.size=num1.size+num2.size+1;
	node *p1=num1.head,*p2=num2.head,*pos=new node;
	addres.head=pos;
	
	int tem=0;

	while(p1->next!=NULL||p2->next!=NULL)
	{
			if(p1->value+p2->value+tem>=10)
			{
				pos->value=p1->value+p2->value-10+tem;
				tem=1;
			}
			else
			{
				pos->value=p1->value+p2->value+tem;
				tem=0;
			}
			pos->next=new node;
			pos=pos->next;
			
			if(p1->next!=NULL)	p1=p1->next;
			if(p2->next!=NULL)	p2=p2->next;
	}
	if(tem!=0)
		pos->value=tem;
}
void muladd(num &rea ,num & num1)
{
	int tem=0,ans=0;
	node *p1=rea.head,*p2=num1.head;
	while(p2!=NULL)
	{
		ans=p1->value+p2->value+tem;
		if(ans>=10)
		{
			p1->value=ans-10;
			tem=1;
		}
		else
		{
			p1->value=ans;
			tem=0;
		}
		p2=p2->next;
		if(p1->next==NULL) 
		{
			p1->next=new node;
			p1=p1->next;
		}
		else
			p1=p1->next;
	}

	/*cout<<"\n total rea is :";
	rea.println();
	cout<<'\n';*/
}
int dif(num &num1 ,num &num2)
{
	//difres.size=min(num1->size,num2->size);
	node *p1=num1.head,*p2=num2.head,*pos=new node;
	difres.head=pos;
	
	int tem=0;

	while(p1->next!=NULL||p2->next!=NULL)
	{
			if(p1->value-p2->value-tem<0)
			{
				pos->value=p1->value-p2->value+10-tem;
				tem=1;
			}
			else
			{
				pos->value=p1->value-p2->value-tem;
				tem=0;
			}
			//cout<<"pos value :"<<pos->value<<'\n';
			pos->next=new node;
			pos=pos->next;
			
			if(p1->next!=NULL)	p1=p1->next;
			if(p2->next!=NULL)	p2=p2->next;
	}
	
	if(tem==1)
	{
		dif(num2,num1);
		return -1;
	}
	else
	 	return 0;
}
void mul(num &num1 ,num &num2)
{
		temres.size=num1.size*num2.size+1;
		node *p1=num1.head,*p2=num2.head,*pos=new node;
		temres.head=pos;		
		int tem=0,count=0;
	
	while(p2->next!=NULL)
	{
		
				while(p1->next!=NULL)
				{
						int ans=p1->value*p2->value+tem;
						if(ans>=10)
						{
							pos->value=ans%10;
							tem=(ans-pos->value)/10;
						}
						else
						{
							pos->value=ans;
							tem=0;
						}
						pos->next=new node;
						pos=pos->next;
						
						if(p1->next!=NULL)	p1=p1->next;
				}
				if(tem!=0){
					pos->value=tem;
				}
		for(int i=0;i<count;i++)
		{
			node *p =new node;
			p->next=temres.head;
			temres.head=p;
		}
		count++;
				/*cout<<"temres is : ";
				temres.println();
				cout<<'\n';*/
		
				muladd(mulres,temres);
				p2=p2->next;
	}

}
int main()
{
	cout<<" num1 is : "<<'\n';
	string s;
	getline(cin,s);
	num num1(s);
	cout<<"\n num2 is : "<<'\n';
	getline(cin,s);
	num num2(s);
	
	add(num1,num2);
	cout<<" sum is : ";
	addres.println();
	cout<<" end\n";
	
	cout<<" dif is : ";
	if(dif(num1,num2)==-1)	cout<<'-';
	difres.println();
	cout<<" end\n";
	//system("pause");
	cout<<" mul is : ";
	mulres.head=new node;
	mul(num1,num2);
	mulres.println();
	cout<<" end \n";
	system("pause");
	return 0;
}
