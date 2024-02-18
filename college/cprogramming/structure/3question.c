#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account{
    int accNum;
    char name[20];
    float balance;
};

void displayLessBalanceUser(struct account customer[], int size){
    int count = 0;
    printf("\nCustomer with balance less than Rs.100 \n");
    for(int i = 0; i < size; i++){
        if(customer[i].balance < 100){
            printf("Account Holder Name : %s\n", customer[i].name);
            printf("Account Number : %d\n", customer[i].accNum);
            printf("Current Balance : %f\n\n", customer[i].balance);
            count++;
        }
    }
    if(count == 0){
        printf("\n>>>>> No customer found with less balance than Rs.100\n");
    }
}

void showAllAccounts(struct account customer[], int size){
    if(size == 0){
        printf("\nNo customer available currently\n");
        return;
    }
    for(int i = 0; i < size; i++){
        printf("\nAccount Holder Name : %s\n", customer[i].name);
        printf("Account Number : %d\n", customer[i].accNum);
        printf("Current Balance : %f\n", customer[i].balance);
    }
    printf("\n");
}

int main() {
    struct account customer[10];
    int count = 0;
    int accNum, choice, isFound = 0;
    char name[20];
    float amount;

    while(1){
        printf("\n1.Deposit\n2.Withdrawl\n3.Create Account\n4.Show account lesst than Rs.100\n5.Show all accounts\n6.Exit\n\nEnter Your Choice ----> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                isFound = 0;
                printf("Enter account number : ");
                scanf("%d", &accNum);
                printf("Enter account holder name : ");
                scanf("%s", name);
                for(int i = 0; i < count; i++){
                    if(customer[i].accNum == accNum && (strcmp(customer[i].name, name) == 0)){
                        printf("Enter amount to deposit : ");
                        scanf("%f", &amount);
                        customer[i].balance += amount;
                        isFound = 1;
                        printf("\n>>>>> Amount deposited successfully\n");
                        break;
                    }
                }
                if(isFound == 0){
                    printf("\n>>>>> No account exist matching the credentials\n");
                }
                break;
            case 2:
                isFound = 0;
                printf("Enter account number : ");
                scanf("%d", &accNum);
                printf("Enter account holder name : ");
                scanf("%s", name);
                for(int i = 0; i < count; i++){
                    if(customer[i].accNum == accNum && (strcmp(customer[i].name, name) == 0)){
                        printf("Enter amount to withdrawl : ");
                        scanf("%f", &amount);
                        if(customer[i].balance - amount > 0){
                            customer[i].balance -= amount;
                            printf("\n>>>>> Amount withdrawn successfully\n");
                        }else{
                            printf("\n>>>>> Insufficient balance unable to withdrawl\n");
                        }
                        isFound = 1;
                        break;
                    }
                }
                if(isFound == 0){
                    printf("\n>>>>> No account exist matching the credentials\n");
                }
                break;
            case 3:
                isFound = 0;
                printf("Enter account number : ");
                scanf("%d", &accNum);
                for(int i = 0; i < count; i++){
                    if(customer[i].accNum == accNum){
                        printf("\n>>>>> This account number is already taken\n");
                        isFound = 1;
                        break;
                    }
                }
                if(isFound == 1){
                    break;
                }
                customer[count].accNum = accNum;
                printf("Enter name : ");
                scanf("%s", customer[count].name);
                printf("Enter initial balance : ");
                scanf("%f", &customer[count].balance);
                printf("\n>>>>> Account created successfully\n");
                count++;
                break;
            case 4:
                displayLessBalanceUser(customer, count);
                break;
            case 5:
                showAllAccounts(customer, count);
                break;
            case 6:
                printf("\n>>>>> THANKS FOR USING BYE :)\n");
                exit(0);
            default:
                printf("\n>>>>> Invalid Input Try Again\n");
                break;
        }
    }
    return 0;
}