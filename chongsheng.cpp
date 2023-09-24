#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class score
{
    public:
    char name[10];
    char id[9];
    int math,chinese,english;//三个成绩
    public:
    score(const char *name1="",const char *id1="",int math1=0,int chinese1=0,int english1=0)
    {
        strcpy(name,name1);
        strcpy(id,id1);
        math=math1,chinese=chinese1,english=english1;
    }
    void show()
    {
        cout<<"Name: "<<name<<'\n';
        cout<<"Id: "<<id<<'\n';
        cout<<"Grades: "<<math<<'\t'<<english<<'\t'<<chinese<<'\n';
    }
};
score sc;
void append()
{

}
class myin
{
    public:
    string s[10];
    myin(string s1)
    {
        string tem="";
        int count=0;
        for(int i=0;i<=s1.length();i++)
        {
            if(s1[i]==','||s1[i]==0)
            {
                s[count++]=tem;
                tem="";
            }
            else
                tem+=s1[i];
        }
    }
};
int main()
{
    fstream ifile;
    ifile.open("D:\\homework\\MyCode\\20230420-1.txt",ios::in);
    if(ifile.fail())
    {
        cout<<"Error"<<'\n';
        system("pause");
        exit(1);
    }
    string s;
    fstream iofile;
    iofile.open("D:\\homework\\MyCode\\test1.txt",ios::out|ios::binary);
    if(iofile.fail())
    {
        cout<<"Creat error!";
        system("pause");
        exit(1);
    }
    getline(ifile,s);
    ifile.close();
    myin in(s);
    int a=atoi(in.s[2].c_str()),b=atoi(in.s[3].c_str()),c=atoi(in.s[4].c_str());
    score sc(in.s[1].c_str(),in.s[0].c_str(),a,b,c);
    sc.show();
    iofile.seekg(0,ios::beg);
    iofile.write(reinterpret_cast<char *>(&sc),sizeof(sc));
    score sc1;
    iofile.seekg(0,ios::beg);
    iofile.read(reinterpret_cast<char *>(&sc1),sizeof(sc1));
    sc1.show();
    iofile.close();
    system("pause");

    /*while(getline(ifile,s))
    {
        myin in(s);

    }*/
}