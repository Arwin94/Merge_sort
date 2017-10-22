#include<iostream>
#include<stdlib.h>
using namespace std;
int merge(int a[],int low,int middle,int high)
{
    int n1=middle-low+1;
	int n2=high-middle;
	int l[n1];
	int r[n2];	
	for(int i=0;i<n1;i++)
	{
		l[i]=a[low+i];
	}
		for(int j=0;j<n2;j++)
	{
		r[j]=a[middle+1+j];
	}
	int i=0,j=0,k=low;
	while(i<n1 && j<n2)
	{
		if(l[i]<=r[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=r[j];
			j++;
		}
		k++;
	}
	 while (i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int m=(low+(high-1))/2;
		mergesort(a,low,m);
		mergesort(a,m+1,high);
		merge(a,low,m,high);
	}
}
int main()
{
	int a[20];
	int n;
	cout<<" enter no of elements ";
	cin>>n;
	cout<<"enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
    cout<<"elements are "<<endl;
   	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	mergesort(a,0,n-1);
	cout<<"array after mergesort "<<endl;
   	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	return(0);
}

