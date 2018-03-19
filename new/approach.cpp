#include<fstream>
#include<iostream>
#include<string>
#include<deque>
using namespace std;
class database
{
    deque<float> dat;
    string file;
    public:
    database(string a)
    {
        file=a;
        fread();
    }
    void trim()
    {
        while(dat.size()>30)
            dat.pop_front();
    }
    void fread()
    {
        ifstream in;
        float a;
        in.open(file,ios::in);
        in.seekg(0);
        while(in>>a)
        {
            dat.push_back(a);
        }
    }

    void fwrite()
    {
        ofstream out;
        out.open(file,ios::trunc);
        trim();
       while(! dat.empty())
       {
          out<<dat.front()<<" ";
          dat.pop_front();
      }
    }
    void insert()
    {
        int n;
        float d;
        cout<<"enter how many values you want to enter:";
        cin>>n;
        cout<<"enter the values";
        for(int i=0;i<n;i++)
        {
            cin>>d;
            dat.push_back(d);
        }
        trim();
        fwrite();
    }
};

int main()
{
    database bit("bit.txt"),doge("doge.txt"),lite("lite.txt");

    return 0;
}
