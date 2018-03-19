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
    double returns(int i)
    {
        int n=0;
        double x[] = {1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        double y[30];
        for(deque<float>::reverse_iterator it=dat.rbegin();it<dat.rend() and n<i;n++,it++)
            y[n++]=*it;

        double b0 = 0;
        double b1 = 0;
        double alpha = 0.01;

        for (int i = 0; i < 20; i ++)
        {
            int idx = i % n;
            double p = b0 + b1 * x[idx];
            double err = p - y[idx];
            b0 = b0 - alpha * err;
            b1 = b1 - alpha * err * x[idx];
        }
        return b1;

    }
};

int main()
{
    database bit("bit.txt"),doge("doge.txt"),lite("lite.txt");
    cout<<bit.returns(4);

    return 0;
}
