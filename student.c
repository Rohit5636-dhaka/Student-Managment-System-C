#include <stdio.h>
#include <string.h>

typedef struct student{
    char name[50];
    int marks;
    int roll;
}student;

void add_student(){
    student s;
    FILE *fp;
    fp = fopen("student.txt", "a");
    
    printf("Enter name :");
    scanf("%s",s.name);

    printf("\nEnter marks :");
    scanf("%d", &s.marks);

    printf("\nEnter roll :");
    scanf("%d", &s.roll);

    fprintf(fp, "%s %d %d",s.name,s.marks,s.roll);

    fclose(fp);

    printf("student added succefully\n");

}

void show_student(){
    student s;
    FILE *fp;

    fp = fopen("student.txt", "r");

    if(fp == NULL){
        printf("No data found!\n");
    }

    printf("=======student deatials list is======\n");
    while(fscanf(fp,"%s %d %d" ,s.name,&s.marks,&s.roll)!=EOF){
        printf("Name = %s\n",s.name);
        printf("marks = %d\n",s.marks);
        printf("Roll = %d\n",s.roll);
        printf("\n");
    }
    fclose(fp);
}

void deleat_student(){
    student s;
    FILE *fp;
    FILE *temp;
    int roll,found = 0;
    printf("Enter roll number");
    scanf("%d",&roll);

    fp = fopen("student.txt","r");

    temp =fopen("temp.txt","a");

    while(fscanf(fp,"%s %d %d",s.name,&s.marks,&s.roll)!=EOF){
        if(s.roll != roll){ 
        fprintf(temp,"%s %d %d",s.name,s.marks,s.roll);
        }

        else{
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found){
        printf("\n");
        printf("Student deleated succefully\n");
    }

    else{
        printf("student not found\n ");
    }

}



int main(){
    int choice;

    while(1){
        printf("\n=====student managment system====\n");
        printf("1. Add student\n");
        printf("2. Show student\n");
        printf("3. search student\n");
        printf("4. Deleat student\n");
        printf("5. Exit\n");

        printf("Enter your chosie:");

        scanf("%d",&choice);

        switch(choice){
            case 1:
                    printf("Add student\n");
                    add_student();
                    break;
            
            case 2:
                    printf("Show student\n");
                    show_student();
                    break;
            case 3:
                    printf("search student\n");
                    break;
            case 4:
                    printf("Deleat student\n");
                    deleat_student();
                    break;
            case 5:
                return 0;
                break;
            default:
                    printf("Envalid choice\n");
        }
    }

    return 0;
}