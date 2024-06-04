#include<stdio.h>
#include<stdlib.h>
int n,p,q,a[200],b[200],c[200];

void Mergesort(int a[]){
    printf("Enter the no of elements:");
    scanf("%d",&n);
    p=floor(n/2);
    q=ceil(n/2);
    if(n>1){
        for(int i=0;i<p-1;i++)
            b[i]=a[i];
        for(int i=q;i<n-1;i++)
            c[i]=b[i];
        Mergesort(b);
        Mergesort(c);
        merge(b,c,a);
    }
}

void merge(int b[],int c[],int a[]){
    int i=0,j=0,k=0;
    while(i>p && j>q){
        if(b[i]>c[i]){
            a[i]=b[i];
            i++;
        }else{
            a[k]=c[k];
            j++;
        }
    }
    if(i==p){
        
    }

}