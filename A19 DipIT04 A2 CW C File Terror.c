#include<stdio.h>
#include<conio.h>
#include<string.h>


struct product
{
	int id;
	char name[50];
	int quan;
	float price;
}p[100];
	    
	    
	  
	  
void loading(){
	int i;
	system("cls");
	printf("\nPlease wait loading...");
	for(i=0;i<50;i++){
		printf("%c",219);
		Sleep(30);
	}
	system("cls");
	printf("\n\nContent loaded successfully\n\n");
}
	  
	    
	    
//This is for add button we can add products from this function
 void add(){
		while(1){
		system("CLS");
		int id;
		char name[50];
		int quan;
		char ch;
		float price;
		printf("\t\t\tEnter the id of product:");
		scanf("%d",&id);
		printf("\t\t\tEnter the name of product:");
		scanf("%s",&name);
		printf("\t\t\tQuantity:");
		scanf("%d",&quan);
		printf("\t\t\tPrice:");
		scanf("%f",&price);
		FILE *fp1;
		fp1=fopen("Name.txt","a");
		fprintf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %.2f",id,name,quan,price);
		fclose(fp1);
		printf("\t\t\t%d %s of Rs %.2f is added.\n\n\n",quan,name,price);
    	printf("\t\t\tDo you want to continue(y/n):\t",ch);
	    scanf(" %c",&ch);
	if(ch=='y')
	{
	}
	else{
		break;
	}
	}
}







//We can view the added products from this function
void view()
		{
		system("CLS");
		FILE *fp1;
	    int i=0,j;
		fp1=fopen("Name.txt","r");
    	printf("\t\t\t==================================================================");	
        printf("\n\n\t\t\t=================\tTHE STOCK ITEMS ARE\t==================");
        printf("\n\n\t\t\t==================================================================\n");
    	printf("\n\n\t\t\t ID\tPARTICULARS\t\tSTOCK AVAILABLE\t\t PRICE(Rs)");
    	printf("\n\n\t\t\t==================================================================\n");
		while(!feof(fp1)){
		fscanf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %f",&p[i].id,&p[i].name,&p[i].quan,&p[i].price);
		i++;
    	}
    	for(j=0;j<i;j++){
		
    		printf("\n\t\t\t %d\t%s\t\t\t  %d\t\t\t  %.2f",p[j].id,p[j].name,p[j].quan,p[j].price);
        }
    	printf("\n\n\t\t\t==================================================================\n");
    	getch();
    	fclose(fp1);
	}
	
	
	
	
	
	
	
	
//Added products can be deleted from this function
void Delete()
     		{
		system("CLS");
		FILE *fp1;
	    int i=0,j;
		fp1=fopen("Name.txt","r");
    	printf("\t\t\t==================================================================");	
        printf("\n\n\t\t\t=================\tTHE STOCK ITEMS ARE\t==================");
        printf("\n\n\t\t\t==================================================================\n");
    	printf("\n\n\t\t\t ID\tPARTICULARS\t\tSTOCK AVAILABLE\t\t PRICE(Rs)");
    	printf("\n\n\t\t\t==================================================================\n");
		while(!feof(fp1)){
		fscanf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %f",&p[i].id,&p[i].name,&p[i].quan,&p[i].price);
		i++;
    	}
    	for(j=0;j<i;j++){
		
    		printf("\n\t\t\t %d\t%s\t\t\t  %d\t\t\t  %.2f",p[j].id,p[j].name,p[j].quan,p[j].price);
        }
    	printf("\n\n\t\t\t==================================================================\n");

    	fclose(fp1);
		fp1=fopen("Name.txt","w");
    	printf("\n\t\t\tEnter the index of product which you want to delete:");
    	int del_choice;
    	scanf("%d",&del_choice);
    	for(j=0;j<i;j++){
	    	if(j==del_choice){
			continue;
		}
			fprintf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %.2f",p[j].id,p[j].name,p[j].quan,p[j].price);
	}
			fclose(fp1);	
}





//If price id name or price needs to be updated this is done from here
void Update()
     	{
		system("CLS");
		FILE *fp1;
	    int i=0,j;
		fp1=fopen("Name.txt","r");
    	printf("\t\t\t==================================================================");	
        printf("\n\n\t\t\t=================\tTHE STOCK ITEMS ARE\t==================");
        printf("\n\n\t\t\t==================================================================\n");
    	printf("\n\n\t\t\t ID\tPARTICULARS\t\tSTOCK AVAILABLE\t\t PRICE(Rs)");
    	printf("\n\n\t\t\t==================================================================\n");
		while(!feof(fp1)){
		fscanf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %f",&p[i].id,&p[i].name,&p[i].quan,&p[i].price);
		i++;
    	}
    	for(j=0;j<i;j++){
		
    	printf("\n\t\t\t %d\t%s\t\t\t  %d\t\t\t  %.2f",p[j].id,p[j].name,p[j].quan,p[j].price);
        }
    	printf("\n\n\t\t\t==================================================================\n");

    	fclose(fp1);
		fp1=fopen("Name.txt","w");
    	printf("\n\t\t\tEnter the index of product which you want to update:");
    	int update_choice;
    	scanf("%d",&update_choice);
    	printf("\n\t\t\tEnter the id of product which you want to update:");
    	scanf("%d",&p[update_choice].id);
    	printf("\n\t\t\tEnter the name of product which you want to update:");
    	scanf("%s",&p[update_choice].name);
    	printf("\n\t\t\tEnter the quantity of product which you want to update:");
    	scanf("%d",&p[update_choice].quan);
    	printf("\n\t\t\tEnter the price of product which you want to update:");
    	scanf("%f",&p[update_choice].price);
    	for(j=0;j<i;j++){
	    	
			fprintf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %.2f",p[j].id,p[j].name,p[j].quan,p[j].price);
		}
	
			fclose(fp1);	
} 






//We can search the added products using its index from this function
void Search()
    	{
        	FILE*fp1;
        	fp1=fopen("Name.txt","r");
        	int id,i=0,j;
        	system("cls");
        	printf("\t\t\tEnter a id which you want to search--");
        	scanf("%d",&id);
			while(!feof(fp1)){
		fscanf(fp1,"\n%d\t\t\t%s\t\t\t%d\t\t\t\t %f",&p[i].id,&p[i].name,&p[i].quan,&p[i].price);
		i++;
    	}
		printf("\t\t\t==================================================================");	
        printf("\n\n\t\t\t=================\tYOU SEARCHED FOR\t==================");
        printf("\n\n\t\t\t==================================================================\n");
    	printf("\n\n\t\t\t ID\tPARTICULARS\t\tSTOCK AVAILABLE\t\t PRICE(Rs)");
    	printf("\n\n\t\t\t==================================================================\n");
		for(j=0;j<=i;j++){
			if(id==p[j].id){
					printf("\n\t\t\t %d\t%s\t\t\t  %d\t\t\t  %.2f",p[j].id,p[j].name,p[j].quan,p[j].price);
					
					break;
					getch();
			}
		}
		if(id>i){
			printf("\t\t\tProduct not found");
		}
		getch();
		fclose(fp1);	
}	






//This code is used to replace the password from asterik
void getPassword(char sanji[]){
	char ch;
	int i =0;
	while(1){
		ch = getch();
		if(ch==13){
			sanji[i]='\0';
			break;
		}
		else if(ch == 8){
			if(i>0){
			printf("%c %c",8,8);
			i--;
		}
			
		}
		else if(ch == ' '|| ch == 9){
			//do nothing
		}
		else{
			sanji[i]=ch;
			printf("*");
			i++;
		} 
	}
}







//Admin can add view delete search and update 
void admin(){
	char username[10];
	char password[10];
	int a;
	
	system("CLS");
	
	printf("Please enter your username : ");
	scanf("%s",&username);
	printf("\nPlease enter your Password : ");
	getPassword(password);
	if(strcmp(username, "abc") ==0){
	if(strcmp(password,"123")==0){
		
	top:	
			system("CLS");
		//	printf("\n\t\t\t\t\t\tWelcome!\n");
		//	printf("\n\t\t\t\t\tYou Have login successfully\n");
			loading();
	printf("\n\t\t\t=============================================================");
	printf("\n\n\t\t\t\t\t   1.  Add\n\n\t\t  \t\t\t   2. View\n\n\t\t  \t\t\t   3. Delete\n\n\t\t  \t\t\t   4. Update\n\n\t\t  \t\t\t   5. Search\n\n\t\t  \t\t\t   6. Exit");
	printf("\n\t\t\t=============================================================");
	printf("\n\n\n\n\n\t\t\t   CHOOSE YOUR OPTION:"); 	
	scanf("%d",&a);
	
	if(a==1)                   
	{
		add();
		goto top;
    }
    
	else if(a==2)        
    {
    	view();
    	goto top;
	}
	
	else if(a==3)       
	{
		Delete();
		goto top;
	}
	
    else if(a==4) 
	 {
		Update();
		goto top;
    }         
			
    else if(a==5) 
	 {
		Search();
		goto top;
	}   
        
	else if(a==6){
		     //exit
           	}
    else{
	  printf("\n\n\tInvalid Operation");   
	  sleep(3);	
	}      	
           	
	}
	
	else{
	  printf("\n\n\tInvalid Password");    //wrong password
	  sleep(3);	
	}
	
    }
}





//The customer can view and search available products in All in one store
void customer()
{
		loading();
    	int b;
    	printf("\n\t\t\t=============================================================");
    	printf("\n\n\t\t\t\t\t   1. View\n\n\t\t  \t\t\t   2. Search\n\n\t\t\t\t\t   3. Exit");
    	printf("\n\n\t\t\t============================================================\n");
    	printf("\n\n\n\n\n\t\t   CHOOSE YOUR OPTION:");
    	scanf("%d",&b);
	switch(b){
		case 1:
			view();
			break;
		
		case 2:
			Search();
			break;
		
		case 3:
			system("cls");
			printf("\n\n\n\n\n\n\t\t----------------------THANKS FOR USING ALL IN STORE-----------------------------\n\n\n\n");
			system("pause");
			break;
		default:
		   printf("invalid operation");
		   sleep(2);		
			
	}

}







//This is the main function of the application
void main()
{
		int input;
	while(1){
	
	system("cls");
	printf("\n\n\n\n\n \t\t\t|============ WELCOME TO ALLINONE STORE ============|");
	printf("\n\n\n\n\n\t\t\t\t   CHOOSE YOUR OPTION");
	printf("\n\t\t\t=============================================================");
	printf("\n\n\t\t\t\t\t   1. Admin\n\n\t\t  \t\t\t   2. Customer");
	printf("\n\n\t\t\t============================================================\n");
	scanf("%d",&input);
	system("CLS");
	switch(input){
		case 1:
			admin();
			break;
		case 2:
		    customer();
		    break;
		case 3:
		    return;
	     	break;
		default:
		   printf("invalid operation");
		   sleep(2);
	}
 }

}






