//oshada97
//oshe ravanz contribution
//enjoy open source

#include <stdio.h>
#include <stdlib.h>

void dispArray(float a[]);                                  //variable names:-      a,n,i,bucket,element,elements,j,k,c
void RandList(float a[],int n);
void BucketSort(float a[]);

void main(){
    float a[20];
    RandList(a,20);
    printf("List before sorting:\n");
    dispArray(a);
    BucketSort(a);
    printf("\nList after sorting:\n");
    dispArray(a);
}

void dispArray(float a[]){                                          //display Array function(array name, last caracter)
    int i;                                                          //ex:-space,dash,newline charcter can be used as last charcter
    for(i=0;i<20;i++){
        printf("%f ",a[i]);
    }
    printf("\n");
}

void RandList(float a[],int n){                                     //random list function(array name,number of elements,range_start,range_end)
    int i;
    for(i=0;i<n;i++){
        a[i]=(float)rand()/RAND_MAX;
    }  
}

void BucketSort(float a[]){                                        //BucketSort function(array name,number of elements)
    float temp,bucket[10][20];
    int element[10]={0,0,0,0,0,0,0,0,0,0};
    int i,j,k,bucket_no,elements,c=0;

    for(i=0;i<20;i++){                                             //putting elements into two dimentional array/bucket
        bucket_no=(int)(a[i]*10.0);
        elements=element[bucket_no];
        bucket[bucket_no][elements]=a[i];
        element[bucket_no]+=1;
    }

    printf("\nList after putting values into the bucket:\n");       //printing elements of the bucket
    for(j=0;j<10;j++){
        if(element[j]!=0)
            printf("%d - ",j);
        for(k=0;k<element[j];k++){
            printf("%f ",bucket[j][k]);
        }
        if(element[j]!=0)
            printf("\n");
    }
    printf("\n");

    for(i=0;i<10;i++){                                                  //use selection sort for each bucket
        if(element[i]!=0){
            for(j=0;j<element[i];j++){
                for(k=j+1;k<element[i];k++){
                    if(bucket[i][k]<bucket[i][j]){
                        temp=bucket[i][k];
                        bucket[i][k]=bucket[i][j];
                        bucket[i][j]=temp;
                    }
                }
            }
        }
    }

    for(j=0;j<10;j++){                                                  //add each value of the bucket into the return array
        if(element[j]!=0){
            for(k=0;k<element[j];k++){
                a[c]=bucket[j][k];
                c++;
            }
        }
    }
}
