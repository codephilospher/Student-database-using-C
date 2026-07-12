#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//creating databse for the students with linked list
typedef struct student{
    int id;
    char name[100];
    char grade;
    struct student *next;


}student;
student*head=NULL;
//display tool
void display_database(int Id){
    student*current=head;
    if(current==NULL){
        printf(" The Databse is empty.\n");
        return;
    }
    
    while(current!=NULL){
        if(current->id==Id){
            printf("\n-----Student Database-----\n");
            printf("ID:%d|NAME:%s|GRADE:%c",current->id,current->name,current->grade);
            return;
        }
    
    current=current->next;
    }
    printf("student ID %d not found in Database",Id);


}
void add_student(int id, char name[], char grade) {
    // 1. Allocate and initialize the new node
    student *new_student = (student*)malloc(sizeof(student));
    new_student->id = id;
    strcpy(new_student->name, name);
    new_student->grade = grade;
    new_student->next = NULL; // Crucial: terminate the new node

    // 2. If list is empty, make this the head
    if (head == NULL) {
        head = new_student;
       
    } else {
        // 3. Otherwise, traverse to the end
        student *current = head;
       
        while (current->next != NULL) {
            current = current->next;
        }
         printf("making a current");
        // 4. Link the last node to our new node
        current->next = new_student;
    }
       

}
void delete_student(int ID){
    student*current=head;
    student*previous=NULL;
    if(current!=NULL && current->id==ID){
        head=current->next;
        free(current);
        printf("Student %d Deleted.\n",ID);
        return;
    }
    while(current!=NULL && current->id!=ID){
        previous=current;
        current=current->next;
    }
    if(current==NULL){
        printf("Student ID %d is not Found \n",ID);
        return;
    }
    previous->next=current->next;
    free(current);
    printf("Student ID %d Data is Deleted succesfully\n",ID);

}
void edit_student(int ID){
    student*current=head;
    while(current!=NULL && current->id!=ID){
        current=current->next;
    }
    if(current==NULL){
        printf("ID  %d is not Found\n",ID);
    }
    int choice;
    printf("WHAT YOU WANT TO EDIT");
    printf("1.EDIT NAME\n 2.EDIT GRADE\nEnter your coice:-");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter New Name:");
        scanf(" %s",current->name);
        break;
        case 2:
        printf("Enter Your New Grade:");
        scanf(" %c",current->grade);
        break;
        default:
        printf("Invalid Choice");

    }
    printf("Update Succesfull\n");

    
}



int main(){
   
    int choice;
    printf("\t\t\t--------WLELCOME TO THE DATABASE MANAGEMENT SYSTEM--------\t\n");
     while(1){
    printf("WHICH YOU WANT TO PERFORM--\n\n 1.ADD student:\n 2.Edit student Data:\n 3.Delete Student Data:\n 4.Display Student Data:\n5.EXIT\n\n");
    printf("ENTER YOUR CHOICE ");
    scanf("%d",&choice);
    if(choice==5){
        printf("Exiting the program");
        break;
    } 
    switch(choice){
        int Id;
        char name[100];
        char Grade;

        case 1:
        printf("Enter your ID:");
        scanf("%d",&Id);
        printf("Enter your Name:");
        scanf("%s",name);
        printf("Enter your Grade:");
        scanf(" %c",&Grade);
        add_student(Id,name,Grade);
        break;
        case 2:
        printf("Enter your ID:");
        scanf("%d",&Id);
        edit_student(Id);
        break;
        case 3:
        printf("ENter ID to delete:");
        scanf("%d",&Id);
        delete_student(Id);
        break;
        case 4:
        printf("Enter your ID to display Database:");
        scanf("%d",&Id);
        display_database(Id);
        break;
        default:
        printf("Invalid Choice");
      
    }
   


   




    }
    return 0;

}
    
