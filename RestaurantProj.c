//PROGRAM BASED IN THE ADMIN PERSPECTIVE

#include <stdio.h>
#include <stdlib.h>

struct node{

   char* product;
   int quantity;
   float price;
   struct node*next;
 } typedef NODE;

NODE*heada = NULL;
NODE*headb = NULL;
void menu( );
void adminsection();
void Payment();
void insertToOrder(char*prod , int quant, float p);
void foodtable( );
void viewOrder();
void insertnew(char* prod, float value );


void insertnew(char* prod, float value ){

    NODE * newProduct = (NODE*)malloc(sizeof(NODE));

         newProduct-> product = prod;
         newProduct-> price = value;
         newProduct->next = heada;
         heada = newProduct;

}

void foodtable( ){

      NODE*temp = (NODE*)malloc(sizeof(NODE));
      temp = heada;

         while(temp != NULL){

            printf("Product : %s    Price: %.1f\n", temp->product,temp->price);
            temp = temp->next;
          }
       char choice[100];
       int q;
       float p;
        printf("\n\t\tPlease, insert the name of the product,the quantity , and the price:  \n");
            scanf("%s%d%f", choice, &q, &p);

             printf("Thank you\n");
                insertToOrder(choice,q,p);

                 int opt;
                printf("\n Do you want to choose another product : ( Press 1 to yes, 0 to no)\n");
                     scanf("%d", &opt);
                    if(opt == 1) {
                     system("cls");
                     foodtable();}
                    else if(opt == 0){
                      system("cls");
                      viewOrder();
                     }
          }


void insertToOrder(char*prod , int quant, float p){
  NODE*table = (NODE*)malloc(sizeof(NODE));
   table->product = prod;
   table->quantity = quant;
   table->price = p*quant;
   table->next = headb;
   headb = table;
 }



void Payment()
{     int card;
     printf("Insert the number of yours credit card : ");
      scanf("%d", &card);

        if(card > 0) {

             printf("Your payment was approved, thank you");
        }
        else {

             printf("Payment denied\n Please, insert the number again : ");
               system("cls");
                Payment();

        }

}
void viewOrder(){
   NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode = headb;
   float sum = 0;
     if(newnode == NULL){
         printf("\t\tYou dont have a order yet!");
        for (int c = 1; c <= 22767; c++)
            for (int d = 1; d <= 22767; d++)
            {}
        system("cls");
         menu();
     }
     else {
          printf("\t\t\t\t\t\tOrder\t\t\t\t\t\n\n");

          while(newnode!= NULL){
          printf("Product : %s \nQuantity : %d  \nPrice : %.1f\n", newnode->product,newnode->quantity,newnode->price);
           sum+=newnode->price;
           newnode = newnode->next;
        }
        printf("\nThe order total is : %.1f", sum);
        int option;
       printf("\nPress 1 to follow to payment, or 0 to back to menu of food : ");
         scanf("%d", &option);
        if(option == 1){
             Payment();
        }
        else if(option == 0){
             foodtable();
        }
    }
  printf("\n");
}
void adminsection() {
       int password = 1234;
       int pass;
        int opt;
        char s[100];
        float q;
        printf("Please , insert the password : ");
          scanf("%d", &pass);
              if(pass != password) {
                 printf("Wrong password");
                   //adminsection();
              }
             else if (pass == password){
                    printf("\t\t 1.Insert a product:  \n\t\t 2.Back to menu \n");
                             scanf("%d", &opt);
                             switch(opt){

                             case 1:
                                    printf("Insert the name, and price of the product :  ");
                                    scanf("%s%f", s , &q);
                                    insertnew(s, q);
                                    menu();
                                break;
                             case 2:
                                 menu();
                                 break;
                             }
             }
}


void menu( ) {
 int choose;

  printf("\t\t\t\t MENU \t\t\t\t\n");
   printf("\n\t\tChoose options below \n \t\t1. Menu\n \t\t2. View the order\n \t\t3. Payment \n \t\t4.Admin section\n ");
            scanf("%d", &choose);


   switch (choose){
      case 1 :
       system("cls");
       foodtable();
       break;
      case 2 :
        system("cls");
        viewOrder();
        break;

      case 3:
         system("cls");
         Payment();
        break;

      case 4:
        system("cls");
        adminsection();
        break;
       }


}

int main( )  {

   printf("\t\t\t\t\t Restaurant System");


       for (int c = 1; c <= 22767; c++)
            for (int d = 1; d <= 22767; d++)
            {}

        system("cls");

       insertnew("Pizza",  12.5);
       insertnew("Hamburguer", 9.5);
       insertnew("HotDog ", 5);
       insertnew("Sushi", 7);
       insertnew("Icecream", 5.5);

         menu();


}

