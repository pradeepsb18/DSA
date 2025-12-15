#include<stdio.h>
#define tablesize 10
int hash[tablesize];
int hashtable(){
    for(int i=0;i<tablesize;i++){
        hash[i]=-1;

    }
}
int hashfunction(int  key){
    return key%tablesize;
}
int insert(int key){
    int index=hashfunction(key);
    if(hash[index]==-1){
        hash[index]=key;
    }
    else{
        int i=(index+1)%tablesize;
        while(i!=index){
            if(hash[i]==-1){
                hash[i]==key;
                return;
            }
            i=(i+1)%tablesize;
        }
        printf("hash table is full");
    }
}
void display(){
    printf("hash table \n");
    for(int i=0;i<tablesize;i++){
        if(hash[i]!=-1)
            printf("H[%d]=%d \n",i,hash[i]);
        else{
            printf("H[%d]=Empty \n",i);
        }
    }
}
int main(){
    int n,key;
    hashtable();
    printf("enter number of employee records");
    scanf("%d",&n);
    printf("enter employee keys \n");
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key);

    }
    display();
    return 0;
}
