//oshada97
//oshe ravanz contribution
//enjoy open source

#include <stdio.h>
#include <stdlib.h>

void dispArray(int a[]);                    //variable names:-      a,i,swap,temp,gap
void RandList(int a[]);
void GapSort(int a[]);

void main(){
    int a[10];
    RandList(a);
    printf("List before sorting:\n");
    dispArray(a);
    GapSort(a);
    printf("\nList after sorting:\n");
    dispArray(a);
}

void dispArray(int a[]){                                            //display Array function(array name)
    int i;                                                          
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void RandList(int a[]){                                             //random list function(array name)
    int i;
    for(i=0;i<10;i++){
        a[i]=rand()%100;
    }  
}

void GapSort(int a[]){                                              //GapSort function(array name)
    int i,swap,temp,gap=10/2;
    do{
        do{
            swap=0;
            for(i=0;i+gap<10;i++){
                if(a[i]>a[i+gap]){
                    temp=a[i];
                    a[i]=a[i+gap];
                    a[i+gap]=temp;
                    if(swap==0)
                        swap=1;
                }
            }
        }while(swap==1);
        gap/=2;
    }while(gap>0);
}
