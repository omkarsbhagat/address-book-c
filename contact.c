#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    for(int i=0;i<addressBook->contactCount;i++){
        printf("%s %s %s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
   //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

int check_ph(char *ph,AddressBook *addressBook){
    if(strlen(ph)!=10){
        return 0;
    }
    for(int i=0;i<addressBook->contactCount;i++)
    if(strcmp(ph,addressBook->contacts[i].phone)==0){
        return 1;
    }
    return 2;
}

int check_email(char *str,AddressBook *addressBook) {
    if (strstr(str, "@") == NULL) {
        return 0;
    }

    if (strstr(str, ".") == NULL) {
        return 0;
    }

    if (strstr(str, "com") == NULL) {
        return 0;
    }

     for(int i=0;i<addressBook->contactCount;i++)
    if(strcmp(str,addressBook->contacts[i].email)==0){
        return 1;
    }
    return 2;
}

void createContact(AddressBook *addressBook)
{
	char name[20],ph[20],email[20];
    int a,b;
    printf("Enter the name:\n");
    scanf(" %[^\n]",name);
    do{
        printf("Enter the phone no:\n");
        scanf(" %[^\n]",ph);
         a=check_ph(ph,addressBook);
        if(a==0){
            printf("Phone no is invalid\n");
        }
        if(a==1){
            printf("Phone no already present \n");
        }
    
}while((a==1)||(a==0));
   do{
        printf("Enter the email:\n");
        scanf(" %[^\n]",email);
         b=check_email(email,addressBook);
        if(b==0){
            printf("Email is invalid\n");
        }
        if(b==1){
            printf("Email already present \n");
        }
    
}while((b==1)||(b==0));

    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,ph);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);
    (addressBook->contactCount++);
}

void searchContact(AddressBook *addressBook) 
{ int opt,flag=0;
    char name[20],ph[20],email[50];
printf("1. Search by name 2. Search by ph no 3. Search by email\n");
printf("Enter the option:\n");
scanf("%d",&opt);
switch(opt){
    case 1 : printf("Enter the name:\n");
            scanf(" %[^\n]",name);
            for(int i=0;i< addressBook->contactCount;i++){
               if( strcmp(name, addressBook->contacts[i].name)==0){
                flag=1;
                 printf("%s %s %s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            if(flag==0){
                printf("Name not found\n");
            }
            break;
    
    case 2:printf("Enter the ph.no:\n");
            scanf(" %[^\n]",ph);
            for(int i=0;i< addressBook->contactCount;i++){
               if( strcmp(ph, addressBook->contacts[i].phone)==0){
                flag=1;
                 printf("%s %s %s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            if(flag==0){
                printf("Phone number not found\n");
            }
            break;    
            
    case 3:printf("Enter the email:\n");
            scanf(" %[^\n]",email);
            for(int i=0;i< addressBook->contactCount;i++){
               if( strcmp(email, addressBook->contacts[i].email)==0){
                flag=1;
                 printf("%s %s %s \n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            if(flag==0){
                printf("Email not found\n");
            }
            break;           

}

}

void editContact(AddressBook *addressBook)
{
	int opt,index=-1,o,i=0;
    char name[20],ph[20],email[50];
printf("1. Select by name 2. Select by ph no 3. Select by email\n");
printf("Enter the option:\n");
scanf("%d",&opt);
switch(opt){
     case 1 : printf("Enter the name:\n");
            scanf(" %[^\n]",name);
            for( i=0;i< addressBook->contactCount;i++){
               if( strcmp(name, addressBook->contacts[i].name)==0){
    
                 printf("%d %s %s %s \n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            printf("Enter the Index:\n");
            scanf("%d",&index);
            if(index!=-1){
                printf("1. Edit by name 2. Edit by ph no 3. Edit by email 4. Edit all:\n");
                printf("Enter the choice: \n");
                scanf("%d",&o);

                switch(o){
                    case 1:    printf("Enter the name:\n");
                               scanf(" %[^\n]",name);
                               strcpy(addressBook->contacts[index].name,name);
                               break;

                    case 2:    printf("Enter the phone no:\n");
                               scanf(" %[^\n]",ph);
                               strcpy(addressBook->contacts[index].phone,ph);
                               break;

                    case 3:    printf("Enter the email:\n");
                               scanf(" %[^\n]",email);
                               strcpy(addressBook->contacts[index].email,email);
                               break;

                    case 4: printf("Enter all the details:\n");
                            printf("Enter the name:\n");
                            scanf(" %[^\n]",name);
                            strcpy(addressBook->contacts[index].name,name);
                            printf("Enter the phone no:\n");
                            scanf(" %[^\n]",ph);
                            strcpy(addressBook->contacts[index].phone,ph);
                            printf("Enter the email:\n");
                            scanf(" %[^\n]",email);
                            strcpy(addressBook->contacts[index].email,email);
                            break;
                        }

            }
            break;

     case 2 : printf("Enter the Ph.no:\n");
            scanf(" %[^\n]",ph);
            for( i=0;i< addressBook->contactCount;i++){
               if( strcmp(ph, addressBook->contacts[i].phone)==0){
    
                 printf("%d %s %s %s \n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            printf("Enter the Index:\n");
            scanf("%d",&index);
            if(index!=-1){
                printf("1. Edit by name 2. Edit by ph no 3. Edit by email 4. Edit all:\n");
                printf("Enter the choice: \n");
                scanf("%d",&o);

                switch(o){
                    case 1:    printf("Enter the name:\n");
                               scanf(" %[^\n]",name);
                               strcpy(addressBook->contacts[index].name,name);
                               break;

                    case 2:    printf("Enter the phone no:\n");
                               scanf(" %[^\n]",ph);
                               strcpy(addressBook->contacts[index].phone,ph);
                               break;

                    case 3:    printf("Enter the email:\n");
                               scanf(" %[^\n]",email);
                               strcpy(addressBook->contacts[index].email,email);
                               break;

                    case 4: printf("Enter all the details:\n");
                            printf("Enter the name:\n");
                            scanf(" %[^\n]",name);
                            strcpy(addressBook->contacts[index].name,name);
                            printf("Enter the phone no:\n");
                            scanf(" %[^\n]",ph);
                            strcpy(addressBook->contacts[index].phone,ph);
                            printf("Enter the email:\n");
                            scanf(" %[^\n]",email);
                            strcpy(addressBook->contacts[index].email,email);
                            break;
                        }

            }
            break;

     case 3 : printf("Enter the email:\n");
            scanf(" %[^\n]",email);
            for( i=0;i< addressBook->contactCount;i++){
               if( strcmp(email, addressBook->contacts[i].email)==0){
    
                 printf("%d %s %s %s \n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            printf("Enter the Index:\n");
            scanf("%d",&index);
            if(index!=-1){
                printf("1. Edit by name 2. Edit by ph no 3. Edit by email 4. Edit all:\n");
                printf("Enter the choice: \n");
                scanf("%d",&o);

                switch(o){
                    case 1:    printf("Enter the name:\n");
                               scanf(" %[^\n]",name);
                               strcpy(addressBook->contacts[index].name,name);
                               break;

                    case 2:    printf("Enter the phone no:\n");
                               scanf(" %[^\n]",ph);
                               strcpy(addressBook->contacts[index].phone,ph);
                               break;

                    case 3:    printf("Enter the email:\n");
                               scanf(" %[^\n]",email);
                               strcpy(addressBook->contacts[index].email,email);
                               break;

                    case 4: printf("Enter all the details:\n");
                            printf("Enter the name:\n");
                            scanf(" %[^\n]",name);
                            strcpy(addressBook->contacts[index].name,name);
                            printf("Enter the phone no:\n");
                            scanf(" %[^\n]",ph);
                            strcpy(addressBook->contacts[index].phone,ph);
                            printf("Enter the email:\n");
                            scanf(" %[^\n]",email);
                            strcpy(addressBook->contacts[index].email,email);
                            break;
                        }

            }
            break;        
}
}

void deleteContact(AddressBook *addressBook)
{
	int opt,index=-1;
    char name[20],ph[20],email[50];
printf("1. Delete by name 2. Delete by ph no 3. Delete by email 4. Edit all:\n");
printf("Enter the option:\n");
scanf("%d",&opt);
switch(opt){
     case 1 : printf("Enter the name:\n");
            scanf(" %[^\n]",name);
            for( int i=0;i< addressBook->contactCount;i++){
               if( strcmp(name, addressBook->contacts[i].name)==0){
    
                 printf("%d %s %s %s \n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            printf("Enter the Index:\n");
            scanf("%d",&index);
            if(index!=-1){
                for(int i=index;i<addressBook->contactCount;i++){
                    addressBook->contacts[i]= addressBook->contacts[i+1];
                }
                (addressBook->contactCount)--;
             }
     break;        

      case 2 : printf("Enter the Ph.no:\n");
            scanf(" %[^\n]",ph);
            for( int i=0;i< addressBook->contactCount;i++){
               if( strcmp(ph, addressBook->contacts[i].phone)==0){
    
                 printf("%d %s %s %s \n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            printf("Enter the Index:\n");
            scanf("%d",&index);
            if(index!=-1){
                for(int i=index;i<addressBook->contactCount;i++){
                    addressBook->contacts[i]= addressBook->contacts[i+1];
                }
                (addressBook->contactCount)--;
             }
     break;        

      case 3 : printf("Enter the Email:\n");
            scanf(" %[^\n]",email);
            for( int i=0;i< addressBook->contactCount;i++){
               if( strcmp(email, addressBook->contacts[i].email)==0){
    
                 printf("%d %s %s %s \n",i,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
               }
            }
            printf("Enter the Index:\n");
            scanf("%d",&index);
            if(index!=-1){
                for(int i=index;i<addressBook->contactCount;i++){
                    addressBook->contacts[i]= addressBook->contacts[i+1];
                }
                (addressBook->contactCount)--;
             }
     break;        

          }
}
