#include<Python.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
float a[100]={4,3,2,4,2,3,23,1,3,5,3,32,4,34,24,67,3,2,4,2,3,23,1,3,5,3,32,4,34,24,1,25,21,5,2};
float b[100]={1,2,3,34,1,46,13,54,42,25,2,35,13,32,54,23,2,2,5,15,3,15,24,23,23,1,14,11,25,23,12,34,24,13,34};
float c[100]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,24,8,35,74,45,75,56,35,13,34,45,56,86,34,13,35,56,24,13};
float a1=0,b1=0,c1=0;
int len=35;
void menu();
void mainmenu();
void clrscr()
{
    for(int i=0;i<100;i++)
        cout<<"\n";
}
void plot(float data[100],int len)
{
    string file="[";
    for(int i=0;i <len;i++)
        file+=to_string(data[i])+',';
    file.pop_back();file+=']';

    string command="pl.plot(range("+to_string(len)+"),"+file+")";

    PyRun_SimpleString("import matplotlib.pyplot as pl");
    PyRun_SimpleString(command.c_str());

    PyRun_SimpleString("pl.show()");

}
void shortterm()
{
float p[3];
int k=1,m=2;
char x='y';

    //disp();
p[0]=a1;;
p[1]=b1;
p[2]=c1;
sort(p,p+3);
while(k<=3 && m>=0)
{
cout<<k<<")";
if(p[m]==a1)
cout<<"BITCOIN\n";
else if(p[m]==b1)
cout<<"LITECOIN\n";
else
cout<<"DOGECOIN\n";
k=k+1;
m=m-1;
}
while(x=='y')
{
cout<<"Enter graph you want to view....";
cin>>k;
if(p[k-1]==a[len-1])
plot(a,len);
else if(p[k-1]==b[len-1])
plot(b,len);
else
plot(c,len);
cout<<"Do you want to continue";
cin>>x;
}
menu();

}

void SD(float data[],int k)
{
    int i;
    float x,y,z=0,s=0;
    for(i=0;i<len-1;i++)
    {
        s=s+data[i];
        x=data[i];
        y=data[i+1];
        z=z+(y-x);

    }


    s=s/len;
    int p=0;
    for(i=len;i<len+5;i++)
    {
        if(k==1)
        {
        a[i]=(s+(z*p))/2;
        a1=z;
        }
        else if(k==2)
         {
         b[i]=(s+(z*p))/2;
         b1=z;
         }
        else
        {
        c[i]=(s+(z*p))/2;
        c1=z;
        }
        p=p+1;
    }


}


void predict()
{
    SD(a,1);
    SD(b,2);
    SD(c,3);
    len=len+5;

}
void disp()
{
    for(int i=0;i<len;i++)
        cout<<a[i]<<"\n";

}
void longt()
{
    clrscr();
    float p[3];
    int k=1,m=2;
    char x='y';
    //disp();
    p[0]=a[len-1];
    p[1]=b[len-1];
    p[2]=c[len-1];
    sort(p,p+3);
    while(k<=3 && m>=0)
    {
        cout<<k<<")";
        if(p[m]==a[len-1])
            cout<<"BITCOIN\n";
        else if(p[m]==b[len-1])
            cout<<"LITECOIN\n";
        else
            cout<<"DOGECOIN\n";
        k=k+1;
        m=m-1;
    }
    while(x=='y')
    {
    cout<<"Enter graph you want to view....";
    cin>>k;
    if(p[k-1]==a[len-1])
        plot(a,len);
    else if(p[k-1]==b[len-1])
        plot(b,len);
    else
        plot(c,len);
    cout<<"Do you want to continue";
    cin>>x;
    }
    menu();




}

void about()
{
    char a;
    clrscr();
    cout<<"              About                \n";
    cout<<"BITCOIN\nBitcoin is a cryptocurrency and worldwide payment system. It is the first decentralized digital currency, as the system works without a central bank or single administrator. ... Bitcoin was invented by an unknown person or group of people under the name Satoshi Nakamoto and released as open-source software in 2009.\n\n";
    cout<<"LITECOIN\nLitecoin (LTC or ?[2]) is a peer-to-peer cryptocurrency and open source software project released under the MIT/X11 license.[3] Creation and transfer of coins is based on an open source cryptographic protocol and is not managed by any central authority.[3][4] The coin was inspired by, and in technical details is nearly identical to, Bitcoin (BTC).\n\n";
    cout<<"DOGECOIN\nDogecoin is a cryptocurrency featuring a likeness of the Shiba Inu dog from the  Doge Internet meme as its logo. Introduced as a joke currency on 6 December 2013, Dogecoin quickly developed its own online community and reached a capitalization of US$60 million in January 2014. \n\n";
    cout<<"\n\nEnter any key......";
    cin>>a;
    menu();
}
void menu()
{
    int o;
    clrscr();
    predict();
    cout<<"                     MENU                         \n\n";
    cout<<"1)About\n";
    cout<<"2)Longterm Investment\n";
    cout<<"3)Shortterm Investment\n";
    cin>>o;
    if(o==1)
        about();
    else if(o==2)
        longt();
    else
      shortterm();
}

void login()
{
    char a[10];
    clrscr();
    cout<<"Enter username :";
    cin>>a;
    if(strcmp(a,"trevsteals")==0)
    {

        cout<<"\nENTER PASSWORD:  ";
        cin>>a;
        if(strcmp(a,"jklol")==0)
            {
                cout<<"\n\n Sucess .....";
                menu();
            }
        else
        cout<<"\nInvalid password";
    }
    else
        cout<<"username not registered\n";

}
void chnge()
{
    clrscr();
    char k='y';
    int p;
    cout<<"Do you wish to add any value:";
    cin>>k;
    while(k=='y')
    {
        cout<<"Enter new value for Bitcoin :  ";
        cin>>p;
        a[len]=p;
        cout<<"\nEnter value for Litecoin: ";
        cin>>p;
        b[len]=p;
        cout<<"\nEnter value for Dogecoin: ";
        cin>>p;
        c[len]=p;
        len++;
        cout<<"\n\nDo you wanna continue..... ";
        cin>>k;
    }
    mainmenu();

}
void develop()
{
    char a[10];
    clrscr();
    cout<<"Enter username :";
    cin>>a;
    if(strcmp(a,"secret")==0)
    {

        cout<<"\nENTER PASSWORD:  ";
        cin>>a;
        if(strcmp(a,"password")==0)
            {
                cout<<"\n\n Sucess .....";
                chnge();
            }
        else
        cout<<"\nInvalid password";
    }
    else
        cout<<"username not registered\n";



}
void mainmenu()
{
int o;
clrscr();
cout<<"                  MENU                    \n";
cout<<"1)login\n";
cout<<"2)Developer options\n";
cin>>o;
if(o==1)
login();
else if(o==2)
develop();

}

int main()
{
    
Py_Initialize();
    mainmenu();

    //plot(data,len);
    
Py_Finalize();
}



