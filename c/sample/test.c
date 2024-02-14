#include<stdio.h>
#include<stdlib.h>
int mutex=1,empty=3,full=0,x=0;
main(){
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Enter 1 for Producer\n2 for Consumer\n# for Exit\n");
    while(1){
        printf("Enter your choice:");
        scanf("%d",&n);
        switch(n){
            case 1: if((mutex==1) && (empty!=0))
                        producer();
                    else
                        printf("Buffer is full");
                    break;

            case 2: if((mutex==1) && (full!=0))
                        consumer();
                    else  
                        printf("Buffer is empty");
                    break;
            case 3: exit(0);
                    break;
        }
    }
}
int wait (int s) { return (--s);}
int signal (int s) {return (++s);}
void producer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d\n",x );
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=signal(full);
    empty=signal(empty);
    printf("\n Consumer consumersitem %d\n",x);
    x--;
    mutex=signal(mutex);
}