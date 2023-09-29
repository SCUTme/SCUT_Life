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
		else if(value==0) return;
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
	~num()
	{
		node *p;
		while(head!=NULL)
		{
			p=head;
			head=p->next;
			delete p;
		}
	}
};
num addres,difres,mulres,temres,rever,powres;
void flush(num &);//刷新mulres
void copy(num &source,num & target);//copy函数
bool judge(num&);//判断末尾是否为1
void test();
bool iszero();
void DeleteZero(num &);//消除前导0
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
	flush(temres);
		temres.size=num1.size*num2.size+1;
		node *p1=num1.head,*p2=num2.head,*pos=new node;
		temres.head=pos;		
		int tem=0,count=0;
	
	while(p2->next!=NULL)
	{
		p1=num1.head;
		flush(temres);
		pos=temres.head,tem=0;
				while(p1->next!=NULL)
				{
						//cout<<"\np1 :"<<p1->value<<" p2: "<<p2->value<<'\n';
						int ans=p1->value*p2->value+tem;
						//cout<<"ans is :"<<ans<<'\n';
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
void half(num &num1)
{
	//rever是反转后的，高位在前
	node *p=rever.head;
	int tem=0,ans=0;
	while(p!=NULL)
	{
		ans=(p->value+tem)/2;
		//cout<<"\nans is :"<<ans<<'\n';
		if(p->value%2==1)
			tem=10;
		else
		 	tem=0;
		p->value=ans;
		p=p->next;
	}
	if(rever.head->value==0&&rever.head->next!=NULL) rever.head=rever.head->next;
}
void quickpow(num &num1)//num2传入revers
{
	//结果存储在powres中
	while(!iszero())//num2!=0
	{
		bool tem=judge(rever);
			//cout<<"\n\nrever is :";
			//rever.println();
			//cout<<"\nn&1 is :"<<tem<<'\n';
		if(tem)//rever的最后一位是1
		{
			flush(mulres);
			mul(num1,powres);
			/*	cout<<"\npowres:";
				powres.println();
				cout<<"\nnum1:";
				num1.println();
				cout<<"\nmulres is : ";
				mulres.println();*/
			copy(mulres,powres);//将结果copy给powres
			/*	cout<<"\npowres is : ";
				powres.println();*/
		}
		flush(mulres);
			/*cout<<"\nafter flushing,mulres is ";
			mulres.println();*/
		mul(num1,num1);
		copy(mulres,num1);//结果copy到num1

		//DeleteZero(num1);
			/*cout<<"\nafter mul itself,num1 is : ";
			num1.println();*/
		half(rever);
		//cout<<"\n\nafter half,rever is :";
		//rever.println();
		//system("pause");
	}
}
void reverse(num &num1)
{
	node *p=num1.head;
	node *c=new node;
	c->value=p->value;
	rever.head=c;
	while(p->next!=NULL)
	{
		p=p->next;
		c=new node;
		c->next=rever.head;
		c->value=p->value;
		rever.head=c;
	}
	rever.head=rever.head->next;
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
	DeleteZero(addres);
	addres.println();
	cout<<" end\n";
	
	cout<<" dif is : ";
	if(dif(num1,num2)==-1)	cout<<'-';
	DeleteZero(difres);
	difres.println();
	cout<<" end\n";
	//system("pause");
	cout<<" mul is : ";
	mulres.head=new node;
	mul(num1,num2);
	DeleteZero(mulres);
	mulres.println();
	cout<<" end \n";

	reverse(num2);
	/*cout<<"\n reverse of num2 is :";
	rever.println();
	system("pause");*/

	//test();

	powres.head=new node;
	powres.head->value=1;
	powres.head->next=new node;
	cout<<" num1 pows num2 is : ";
	quickpow(num1);
	DeleteZero(powres);
	powres.println();
	cout<<"end\n";
	system("pause");
	return 0;
}
void flush(num &target)
{
	node *p;
	while(target.head!=NULL)
	{
		p=target.head;
		target.head=p->next;
		delete p;
	}
	target.head=new node;
}
void copy(num &source,num & target)
{
	flush(target);
	node *p=source.head,*c=target.head;
	while(p!=NULL)
	{
		c->value=p->value;
		p=p->next;
		c->next=new node;
		c=c->next;
	}
}
bool judge(num& target)
{
	node *p = target.head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	if(p->value&1) return true;
	else
		return false;
}
void test()
{
	cout<<"\n\n\ncopy testing \n";
	addres.println();
	num a;
	a.head=new node;
	copy(addres,a);
	cout<<"\ncopying \n";
	a.println();

	while(1)
	{
		half(rever);
		cout<<"\n half of rever is : ";
		rever.println();
		cout<<"\nis zero?";
		cout<<iszero();
		system("pause");
	}
}
bool iszero()//判断reverse是否为0
{
	if(rever.head->value==0)
		return true;
	else return false;
}
void DeleteZero(num& num1)
{
	num tem;
	node *p=num1.head;
	node *c=new node;
	c->value=p->value;
	tem.head=c;
	while(p->next!=NULL)
	{
		p=p->next;
		c=new node;
		c->next=tem.head;
		c->value=p->value;
		tem.head=c;
	}
	while(tem.head->value==0&&tem.head->next!=NULL) tem.head=tem.head->next;

	flush(num1);
	p=tem.head;
	c=num1.head;
	c->value=p->value;
	num1.head=c;
	while(p->next!=NULL)
	{
		p=p->next;
		c=new node;
		c->next=num1.head;
		c->value=p->value;
		num1.head=c;
	}
}