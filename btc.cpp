#include<iostream>
#include<string.h>
#include <cstring>
#include <cstddef>
#include<stdio.h>
#include<algorithm>
#include <fstream>
using namespace std;
const char* INPUT_FILENAME = "download.png";
float a[100]={4,3,2,4,2,3,23,1,3,5};
float b[100]={1,2,3,34,1,46,13,54,42,25};
float c[100]={1,2,3,4,5,6,7,8,9,10};
float a1=0,b1=0,c1=0;
int len=10,level=10;
void menu();
void mainmenu();
void predictchange(int k);
void clrscr()
{
    for(int i=0;i<100;i++)
        cout<<"\n";
}
/*void plot(float dat[100],int len)
{
ShellExecute(NULL, "open", "file:///C:/Users/sidda/Desktop/ugandan.html",NULL, NULL, SW_SHOWNORMAL);
}
*/
void shortterm()
{
float p[3];
int k=1,m=2;
char x='y';

    //disp();
p[0]=a1;
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
void predictchange(float k,char p[10])
{
level=level+1;	
std::ofstream outfile;
if(strcmp(p,"bit")==0)
{
outfile.open("bit.txt", std::ios_base::app);
outfile <<std::endl<<k<<","<<level; 
}
else if(strcmp(p,"lite")==0)
{
outfile.open("lite.txt", std::ios_base::app);
outfile <<std::endl<<k<<","<<level; 
}
else
{
outfile.open("doge.txt", std::ios_base::app);
outfile <<std::endl<<k<<","<<level; 	
	
}
	
}

void SD(float data[],int k)
{
	level=10;
    int i;
    float x,y,z=0,s=0;
    for(i=0;i<len-1;i++)
    {
        s=s+data[i];
        x=data[i];
        y=data[i+1];
        z=z+(y-x);

    }
    len=10;


    s=s/len;
    int p=1;
    for(i=len;i<len+5;i++)
    {
        if(k==1)
        {
        a[i]=(s+(z*p))/2;
        predictchange((s+(z*p))/2,"bit");
        
        a1=z;
        }
        else if(k==2)
        {
        b[i]=(s+(z*p))/2;
        predictchange((s+(z*p))/2,"lite");
        b1=z;
        }
        else
        {
        c[i]=(s+(z*p))/2;
        predictchange((s+(z*p))/2,"doge");
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
    cout<<"Do you want to view graph....";
    cin>>x;
    if(x=='y')
    plot(a,len);
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
std::ofstream outfile;
char Data[3];
cin>>Data;
outfile.open("test.txt", std::ios_base::app);
outfile <<std::endl<<Data; 
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
    mainmenu();
    return(0);
    //plot(data,len);
}



