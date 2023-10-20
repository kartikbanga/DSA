#include <bits/stdc++.h> 

long long merge(long long *a, long long *temp, int l, int mid, int r)
{
    int i=l,j=mid,k=l;
    long long count=0;
    
    while((i<=mid-1) && j<=r)
    {
        if(a[i]>a[j])
        {
            temp[k++]=a[j++];
            count+=(mid-i);
        }
        else
            temp[k++]=a[i++];
    }
    while(i<=mid-1)
        temp[k++]=a[i++];
    while(j<=r)
        temp[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=temp[i];
    return count;
}


long long mergesort(long long *a, long long* temp, int l, int r)
{
    long long count=0;
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        count+=mergesort(a,temp,l,mid);
        count+=mergesort(a,temp,mid+1,r);
        
        count+=merge(a,temp,l,mid+1,r);
    }
    return count;
}

long long getInversions(long long *a, int n){
    // Write your code here.
//     long long ans=0;
    
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//             if(a[i]>a[j])
//                 ans++;
//     }
//     return ans;
    long long temp[n];
    return mergesort(a,temp,0,n-1);
    
    
}
