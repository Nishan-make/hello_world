#include"stdio.h"
int display(int a[],int n);
int take_array(int a[],int n);
int merge_sort(int a[],int low,int high);
int merge(int a[],int low,int mid,int high);

int main()
{
  int n;
  printf("\n Enter the no of  element in  the  array :");
  scanf("%d",&n);
  int a[n];
  take_array(a,n);
  merge_sort(a,0,n-1);
  display(a,n);
}


int take_array(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
   printf("\n Enter the %d element of the array :",i+1);
   scanf("%d",&a[i]);
 }
}

int display(int a[],int n)
{
  printf("\n Elements of  the array are :");
  for(int i=0;i<n;i++)
   printf("\n %d",a[i]);
}

int merge_sort(int a[],int low,int high)
{
  if(low<high)
  {
    int  mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}

int merge(int a[],int low,int mid,int high)
{
  int n1=mid-low+1;
  int n2=high-mid;
  int ar1[n1];
  int ar2[n2];
  int i=0,j=0;
  int k=low;
  for(int i=0;i<n1;i++)
   ar1[i]=a[low+i];
  for(int i=0;i<n2;i++)
   ar2[i]=a[mid+1+i];
  while(i<n1 &&  j<n2)
  {
    if(ar1[i]<=ar2[j])
     {
       a[low]=ar1[i];
       i++;
     }
     else
     {
       a[low]=ar2[j];
       j++;
     }
     low++;
  }
  while(i<n1)
  {
    a[low]=ar1[i];
    i++;
    low++;
  }
  while(j<n2)
  {
    a[low]=ar2[j];
    j++;
    low++;
  }
}
