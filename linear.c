#include<stdio.h>
#define size 3
void Insert();
void Delete();
void display();
int front=-1;
int rear=-1;
int arr[size];

//linear queue
 void Insert(){
     int value;
     if(rear==size-1){
        printf("the que is full");
     }


     else{
         if(front==-1)
            front=0;
         printf("enter the value : ");
         scanf(" %d",&value);
         arr[++rear]=value;
         printf("the inserted value is :  %d",value) ;


     }
 }
 void Delete(){
     if(front==-1||front>rear){
        printf("underflow");
     }
     else{
        printf("the deleted element is %d ",arr[front]);
        front++;

     }
 }
 void display(){
     if(front==-1||front>rear){
        printf("The array is empty ");
     }
     else{
         for(int i=front;i<=rear;i++){
        printf("%d \n",arr[i]);
     }
     }

 }
int main(){
    int choice;
    while(1){
        printf(" \n 1.insert \n 2.delete \n 3.display \n 4.Exit \n Enter your choice : ");
        scanf(" %d",&choice);
        switch(choice){
            case 1:Insert();
                    break;
            case 2:Delete();
                    break;
            case 3:display();
                    break;
            case 4:return 0;
                    break;
            default:printf("invalid choice \n");
                    break;
        }
    }
    return 0;
}
