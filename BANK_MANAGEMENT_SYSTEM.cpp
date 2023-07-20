#include<stdio.h>                                                              
main()                                                                     
{                                                                               
 int a,C_ID,A_ID,balance, deposit, withdraw;
 char name[100];
 while(1)  
 {                                                                                                                                     
  printf("\n<<<<<<<< BANK MANAGEMENT SYSTEM >>>>>>>>");                                                   
  printf("\n................");                                                 
  printf("\n 1 -> ADD CUSTOMER");                                                     
  printf("\n 2 -> CREATE ACCOUNT");                                                    
  printf("\n 3 -> DEPOSIT");                                                     
  printf("\n 4 -> WITHDRAW");
  printf("\n 5 -> DISPLAY ACCOUNTS");                                                         
  printf("\n 0 -> EXIT");                                                        
  printf("\n Enter your choice: ");                                                
  scanf("%d", &a);                                                            
  switch(a)                                                                    
{
  	case 1: 
  	    printf("\n Enter customer ID: ");
  	    scanf("%d",&C_ID);
  	    printf("\n Enter customer name: ");
  	    scanf(" %c",&name);
  	    printf("\n CUSTOMER CREATED SUCCESSFULLY! ");
  	    break;
  	case 2:
  		printf("\n Enter account ID: ");
  		scanf("%d",&A_ID);
  		printf("\n Enter customer ID for the account: ");
  		scanf("%d",&C_ID);
  		printf("\n Enter initial balance: ");
  		scanf("%d",&balance);
  		printf("\n ACCOUNT CREATED SUCCESSFULLY!");
  		break;
  	case 3:
  		printf("\n Enter account ID for deposit: ");
  		scanf("%d",&A_ID);
  		printf("\n Enter deposit amount: ");
  		scanf("%d", &deposit);                                                     
        balance += deposit;
		printf("\n SUCCESSFULLY DEPOSITED! AVAILABLE BALANCE IS : %d",balance);                                                      
        break;
	case 4:
	    printf("\n Enter account ID for withdrawal: ");
		scanf("%d",&A_ID);
		printf("\n Enter withdrawal amount: ");
		scanf("%d", &withdraw);                                                    
        balance -= withdraw;
		printf("\n WITHDRAWL SUCCESSFUL! NEW BALANCE IS : %d",balance);                                                       
        break;
    case 5:
    	printf("\n --- Account Details ---");
    	printf("\n Account ID: ");
    	scanf("%d",&A_ID);
    	printf("\n Customer ID: ");
    	scanf("%d",&C_ID);
    	printf("\n%d",balance);
    	printf("---------------------");
    	break;
	case 0:
	    printf("\n ************************************************ EXIT PROGRAM ***************************************************");
	    break;
	default:                                                                     
        printf("Invalid Operation!");
}
}
}

