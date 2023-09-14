//merge sort

#include <stdio.h>
#include <stdlib.h>

void merge(int a[],int l,int mid,int h)
{  
    int b[100],i=l,j=mid+1,k=l;
    while(i<=mid && j<=h)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=h)
    {
        b[k]=a[k];
        k++;
        j++;
    }
    for(i=0;i<=h;i++)
    {
        a[i]=b[i];
    }
}

void mergesort(int a[],int l,int h)
{   int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}


void printarr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d,",a[i]);
    }
}

int main()
{
    int a[100],n;
    printf("enter the size of the array");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   printf("enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("before sorting:");
    printarr(a,n);
    printf("after sorting");
    mergesort(a,0,n-1);
    printarr(a,n);
    return 0;
}
/*output:
enter the size of the array5
enter element 1:5
enter element 2:4
enter element 3:3
enter element 4:2
enter element 5:1
before sorting:5,4,3,2,1,after sorting1,2,3,4,5,
*/


//quick sort
#include <stdio.h>
#include <stdlib.h>
void interchange(int a[],int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partion(int a[],int l,int h)
{   int pivot=a[l],i=l,j=h+1;
    do
    {   do
        {
            i++;
        }while(a[i]<pivot && i<=j);
        do
        {
            j--;
        }while(a[j]>=pivot);
        if(i<j)
        {
            interchange(a,i,j);
        }
    }while(i<j);
    interchange(a,l,j);
    return j;
}
void quicksort(int a[],int l,int h)
{  int j;
   if(l<h)
   {j=partion(a,l,h);
    quicksort(a,l,j-1);
    quicksort(a,j+1,h);
   }
}
void printarr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d,",a[i]);
    }
}
int main()
{
    int a[100],n;
    printf("enter the size of the array");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   printf("enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("before sorting:");
    printarr(a,n);
    printf("after sorting");
    quicksort(a,0,n-1);
    printarr(a,n);
    return 0;
}
/*output:
enter the size of the array5
enter element 1:5
enter element 2:4
enter element 3:3
enter element 4:2
enter element 5:1
before sorting:5,4,3,2,1,after sorting*/
