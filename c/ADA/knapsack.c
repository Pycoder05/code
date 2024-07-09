#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void greedy(int n,int m,float p[],float w[]){
    int i,k,count;
    int profit = 0,max;
    for(count = 0;count < n;count++){
        max=0;
        for(i = 0;i < n;i++){
            if(p[i]/w[i] > max){
                max = w[i];
                k = i;
            }
        }
        if(w[k] <= max){
            printf("object %d is selected with fraction\n",k+1);
            profit += p[k];
            m -= w[k];
            p[k]=0;
        }else
            break;
    }
    printf("Discrete knapsack problem %f\n",profit);
    profit += (m/w[k]) * p[k];
    printf("Continuos knapsack profit by including %d item with fraction %f=%f\n", k , m/w[k] , profit);
}
int main(){
    int n,m;
    float p[50],w[50];
    printf("Enter number of objects\n");
    scanf("%d",&n);
    printf("Enter knapsack capacity\n");
    scanf("%d",&m);
    printf("Enter profit of each object\n");
    for(int i=0;i<n;i++)
        scanf("%f",&p[i]);
    printf("Enter weight of each object\n");
    for(int i=0;i<n;i++)
        scanf("%f",&w[i]);
    greedy(n,m,p,w);
    return 0;
}