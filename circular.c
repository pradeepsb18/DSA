#include<stdio.h>
#define size 3
void Insert();
void Delete();
void display();
int front=-1;
int rear=-1;
int arr[size];

//circular que
 void Insert(){
     int value;
     if(front==0&&rear==size-1||front==rear-1){
        printf("the que is full");
     }
     else{
        if(front==-1)
            front=0;
        printf("Enter the value to be inserted : ");
        scanf(" %d",&value);
        rear=(rear+1)%size;
        arr[rear]=value;
     }
 }
 void Delete(){
     if(front==-1){
        printf("The array is empty");
     }
     else if(front==rear){
        front=rear=-1;
     }
     else{
        front=(front+1)%size;
     }
 }
  void display(){
     if(front==-1){
        printf("The array is empty ");
     }
     else{
            while(1){
                int i=front;
                printf("%d",arr[i]);
                if(front==rear)
                    break;
                front=(front+1)%size;
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

