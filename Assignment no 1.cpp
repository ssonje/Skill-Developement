#include<iostream>
#include<stdlib.h>
using namespace std;
int* accept(int[],int);

int* accept(int arr[],int s)
{
int i;
cout<<"Enter the array elements\n";
for(i=0;i<s;i++)
{
cin>>arr[i];
}
return arr;
}

void display(int a1[],int s)
{
int i;
for(i=0;i<s;i++)
{
cout<<""<<a1[i]<<"\t";
}
}

int fun(int x,int inter[],int ss3)
{
    int i;
    for(i=0;i<ss3;i++)
    {
        if(x==inter[i])
        {
            return 1;
        }
    }
        if(x!=inter[i])
        {
            return 0;
        }
}

void unionn(int s1[],int s2[],int inter[],int ss1,int ss2,int ss3)
{
int i;
cout<<"\nSet of union is:\n";
for(i=0;i<ss3;i++)
{
cout<<""<<inter[i]<<"\t";
}
for(i=0;i<ss1;i++)
{
if(fun(s1[i],inter,ss3))
{
continue;
}
else
{
cout<<""<<s1[i]<<"\t";
}
}

for(i=0;i<ss2;i++)
{
if(fun(s2[i],inter,ss3))
{
continue;
}
else
{
cout<<""<<s2[i]<<"\t";
}
}
}

void diff1(int s1[],int inter[],int ss1,int ss3)
{
int i;
for(i=0;i<ss1;i++)
{
if(fun(s1[i],inter,ss3))
{
continue;
}
else
{
cout<<""<<s1[i]<<"\t";
}
}
}

void intersection(int s1[],int s2[],int ss1,int ss2)
{
int i,j,k=0;
for(i=0;i<ss1;i++)
{
for(j=0;j<ss2;j++)
{
if(s1[i]==s2[j])
{
//inter[k]=s1[i];
k++;
break;
}
}
}
cout<<"\nSize of set of intersection is:"<<k<<"\n";
int inter[k];
k=0;
for(i=0;i<ss1;i++)
{
for(j=0;j<ss2;j++)
{
if(s1[i]==s2[j])
{
inter[k]=s1[i];
k++;
break;
}
}
}

cout<<"Set of intersection is:\n";
display(inter,k);

unionn(s1,s2,inter,ss1,ss2,k);

cout<<"\nA-B is:\n";
diff1(s1,inter,ss1,k);
cout<<"\nB-A is:\n";
diff1(s2,inter,ss2,k);
}

void remove(int arr1[],int ss1,int ele)
{
int i,k;
for(i=0;i<ss1;i++)
{
if(arr1[i]==ele)
k=i;
}

i=k;
cout<<"Position is:"<<k+1<<"\n";
for(k=i;k<ss1-1 ;k++)
{
arr1[k]=arr1[k+1];
}

ss1--;
cout<<"Hence the array becomes:\n";
for(i=0;i<ss1;i++)
{
cout<<""<<arr1[i]<<"\t";
}
}

void subset(int s1[],int s2[],int ss1,int ss2)
{
int i,j=0;
while(j<ss2)
{
if(fun(s2[j],s1,ss1))
{
j++;
}
else
{
cout<<"\nNot a subset\n";
exit(1);
}
}

cout<<"..........................\n";
if(ss2==j)
cout<<"Subset it is\n";

}

int main()
{
int s1,s2;
cout<<"Enter the size of first array\n";
cin>>s1;
int arr1[s1];
accept(arr1,s1);
 int ele;
 cout<<"Enter the element you want to remove\n";
 cin>>ele;
 remove(arr1,s1,ele);
 s1--;
cout<<"Enter the size of second array\n";
cin>>s2;
int arr2[s2];
accept(arr2,s2);
cout<<"\nFirst set is:\n";
display(arr1,s1);
cout<<"\nsecond set is:\n";
display(arr2,s2);
intersection(arr1,arr2,s1,s2);
//unionn(arr1,arr2,s1,s2);

subset(arr1,arr2,s1,s2);
return 0;
}
