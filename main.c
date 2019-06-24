#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>
#include<errno.h>
#include<math.h>

/*int main()
{
   /* int a[10];  //declaring data type values into variables
    char name[20];//declaring data type values into variables

    int i =0; int b=0; //for loop purposes

    for( i=0;i<10;i++){

        for(b=1;b<=10;b++){

    char name[20];
    printf("Enter  Student ==>(%d) name: ",b);
    scanf("%s", name);
    printf("Student(%d) ==>Your name is %s.\n\n",b,name);

        }break;
    }
*/

    struct Student_Details{//book

        int Student_Grade;//bno
        char name[10];

    };

    int main(){

        FILE *fp;
        struct Student_Details b[10];
        int i;
        fp = fopen("Student.txt","wb");
        if(fp==NULL)
        {
            printf("\nError cannot open file");
            exit(1);
        }

        printf("\nEnter 10 |==============STUDENTS===========| details ===>(Grade with Name....)\n\n\n");
        for(i=0;i<10;i++)
        {
            printf("\nEnter %d Student Grade (A,B,C,D)  = ",i+1);//pass value to buffer to next step
            fflush(stdin);
            scanf("%d",&b[i].Student_Grade);
            printf("\nEnter %d Student name= ",i+1);
            fflush(stdin);
            gets(b[i].name);
        }

        fwrite(b,sizeof(struct Student_Details),10,fp);
        printf("\n Congrats!!!!........Student Data is sorted successfully..\n");
        fclose(fp);

    return 0;
}
