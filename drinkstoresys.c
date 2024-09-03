#include <stdio.h>
#include <conio.h>
#include <string.h>
// global declaration
int code[20];
char item[20][30];
int qty[20];
float price[20];
float total[20];
float payment = 0,discount = 0; 
int size =0,i,j,add = 0,search,dis;

/*----------- menu function -------------*/

void Menu(){
	printf("\t\t\t\t-------------- Drink Stor ---------------\n\n");
	printf( 
	        "\t\t\t\t\t 1. Input Product  \n"
	        "\t\t\t\t\t 2. Add Product \n"
			"\t\t\t\t\t 3. Output All Product \n"
			"\t\t\t\t\t 4. Delete Product \n"
			"\t\t\t\t\t 5. Update Product \n"
			"\t\t\t\t\t 6. Payment Product\n"
			"\t\t\t\t\t 7. Sort Product \n"
			"\t\t\t\t\t 8. Discount Product \n"
	);
}

void Input(){
	printf("\t\t\t\t Enter name : ");fflush(stdin);gets(item[i]);
	printf("\t\t\t\t Enter qty  : ");scanf("%d",&qty[i]);
	printf("\t\t\t\t Enter price: ");scanf("%f",&price[i]);
}

void Output(){
	printf("\t\t%d\t\t%s\t\t\tx%d\t\t$%.2f\t\t$%.2f\n",code[i],item	[i],qty[i],price[i],total[i]);
}

void PaymentOut(){
	printf("\t\t\t  %s\t\t\tx%d\t\t$%.2f\t\t$%.2f\n",item[i],qty[i],price[i],total[i]);
}

void Add(int size,int add){
	for(i = size;i < size+add;i++){
			printf("\t\t\t\t[#%d]Product ------------------------------ \n\n",i+1);
			code[i] = i + 1; 
			Input();
			total[i] = price[i] * qty[i];
			puts("");
		}
}
void ScreenPause(){
	again:
		printf("\n\n\t\t\t\t Press enter to continue...");
		if(getch() == 13){
			system("cls");
		}
		else{
			goto again;
    	}
}

void Login(){
	char username[20];
	char pass[20];
	int bar;
	char load = 178;
	char lo = 219;
	
	login:
	printf("\t\t\t\t\t------------------------------------------- \n");
	printf("\t\t\t\t\t                  Login                     \n");
	printf("\t\t\t\t\t------------------------------------------- \n");
	printf("\t\t\t\t\t    Enter Username: ");gets(username);
	printf("\t\t\t\t\t    Enter Password: ");gets(pass);
	printf("\t\t\t\t\t------------------------------------------- \n");
	if((strcmp(username,"admin") == 0) &&   (strcmp(pass,"123") ==0)){
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t\t\tWait....\n");
		printf("\t\t\t\t\t");
		for(bar = 0; bar <= 24; bar++){
			Sleep(80);
			system("color a");
			printf("%c%c",load,lo);	
		}
		system("cls");	
	}else{
		printf("\t\t\t\t\tInvalid username or password!\n");
		ScreenPause();
		goto login;
	}
}

int main(){
	int op,code_auto = 0;
	
	Login();
	system("color 3");
	do{
		int check = 0;
		Menu();
		printf("\t\t\t\t\t  Chose one option: ");scanf("%d",&op);
		switch(op){
			case 1:{
				system("cls");
				printf("\t\t\t\t----------- Enter Customer Product -----------\n");
				printf("\t\t\t\tHow many product: ");scanf("%d",&size);
				puts("");			
				for(i = 0;i<size;i++){
					printf("\t\t\t\t[#%d]Product ------------------------------ \n\n",i+1);
					code[i] = i + 1; 
					Input();
					total[i] = price[i] * qty[i];
					puts("");
				}
				printf("\t\t\t\t-------------------------------------------\n");
				printf("\t\t\t\tCreate Success...\n");
				
				ScreenPause();

				break;
			}
			case 2:{
				system("cls");
				printf("\t\t\t\t--------------- Add more Product ----------------\n");
				printf("\t\t\t\tYour current products: %d items\n",size);
				if(size == 0){
					printf("\t\t\t\tYou need to create product first before add..!\2");
					getch();
					system("cls");
					break;
				}
				printf("\t\t\t\tHow many product u want to add: ");scanf("%d",&add);
				Add(size,add);
				printf("\t\t\t\t-------------------------------------------\n");
				printf("\t\t\t\tAdd Success...\n");
				size += add;	
				ScreenPause();
				break;
			}
			case 3:{
				system("cls");
				printf("\t\t                              [-PRODUCT RECORD-]                                \n");
				printf("\t\t--------------------------------------------------------------------------------\n");
				printf("\t\tCode\t\tItem\t\t\tQTY\t\tPrice\t\tTotal\n");
				printf("\t\t--------------------------------------------------------------------------------\n");
				if(size == 0){
					printf("\t\tProduct not record....");
					getch();
					system("cls");
					break;
				}
				for(i = 0;i<size;i++){
					Output();
				}
				getch();
				system("cls");
				break;
			}
			case 4:{
				system("cls");
				printf("\t\t                              [-DELETE RECORD-]                                \n");
				printf("\t\t--------------------------------------------------------------------------------\n");
				if(size == 0){
					printf("\t\tProduct not record....");
					getch();
					system("cls");
					break;
				}
				printf("\t\tEnter code you want to delete: ");scanf("%d",&search);
				for(i = 0; i < size ;i++){
					if(code[i] == search){
						for(j = i;j < size-1;j++){
							code[j] = code[j+1];
							strcpy(item[j],item[j+1]);
							qty[j] = qty[j+1];
							price[j] = price[j+1];
							total[j] = total[j+1];
						}
						check = 1;
						payment=0;
						size--;
					}
				}
				if(check == 0){
					printf("\t\tProduct not found!");
				}else{
					printf("\t\tDelete Successfully!");
				}	
				ScreenPause();
				break;
			}
			case 5:{
				payment=0;
				system("cls");
				printf("\t\t\t\t----------- Update Product -----------\n");
				if(size == 0){
					printf("\t\t\t\tProduct not record....");
					getch();
					system("cls");
					break;
				}
				printf("\t\t\t\t Enter code you want to update: ");scanf("%d",&search);
				for(i = 0; i < size ;i++){
					if(code[i] == search){
						printf("\n\t\t\t\t[#%d]Product ------------------------------ \n\n",i+1);
						Input();
						total[i] = price[i] * qty[i];
						check = 1;
						puts("");
						
					}
					
				}
				if(check == 0){
					printf("\t\t\t\tProduct not found!");
				}else{
					printf("\t\t\t\t---------------------------------------------\n");
					printf("\t\t\t\t Update Successfully!");
				}	
				ScreenPause();
				break;
			}
			case 6:{
				payment = 0;
				system("cls");
				printf("\t\t\t                            [-RECIEPT-]                                 \n");
				printf("\t\t\t------------------------------------------------------------------------\n");
				printf("\t\t\t  Item\t\t\tQTY\t\tPrice\t\tTotal\n");
				printf("\t\t\t------------------------------------------------------------------------\n");
				if(size == 0){
					printf("\t\t\tProduct not record....");
					getch();
					system("cls");
					break;
				}
				for(i = 0;i<size;i++){
					PaymentOut();
					payment = payment + total[i]; 
//					payment+=total[i];
				}
		
				printf("\t\t\t---------------------------------------------------------------------------\n");
				printf("\t\t\t  Discount      : %%%d \n",dis);
				printf("\t\t\t  Your Discount : $%.2f \n",discount);
				printf("\t\t\t  Your Payment  : $%.2f \n",payment - discount);
				
				ScreenPause();
				break;
			}
			case 7:{
				int tmpc,tmpq;
				float tmpp,tmpt;
				char tmpn[20];	
				
				for(i = 0;i < size;i++){
					for(j = i+1;j<size;j++){
						if(total[i] < total[j]){
							tmpc = code[j];
							code[j] = code[i];
							code[i] = tmpc;
							
							tmpq = qty[j];
							qty[j] = code[i];
							qty[i] = tmpq;
							
							tmpp = price[j];
							price[j] = price[i];
							price[i] = tmpp;
							
							tmpt = total[j];
							total[j] = total[i];
							total[i] = tmpt;
							
							strcpy(tmpn,item[j]);
							strcpy(item[j],item[i]);
							strcpy(item[i],tmpn);
						}				
					}
				}	
				printf("\t\t\t\tSort Success....");
				ScreenPause();	
				break;
			}
			case 8:{
				system("cls");
				printf("\t\t\t\t--------------- Discount Product ----------------\n");
				if(size == 0){
					printf("\t\t\t\tYour current products: %d items\n",size);
					printf("\t\t\t\tPlease buy product first...\2");
					getch();
					system("cls");
					break;
				}
				printf("\t\t\t\tHow many percent do you want to discount: %%");scanf("%d",&dis);
				discount = payment * dis / 100;
				printf("\t\t\t\tYour product discount is: $%.2f \n",discount);
				ScreenPause();		
				break;
			}
		}
	}while(op < 9);
}

