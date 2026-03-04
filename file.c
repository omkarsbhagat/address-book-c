#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp=fopen("contacts.txt","w");
    fprintf(fp,"%d \n",addressBook->contactCount);
     for(int i=0;i<addressBook->contactCount;i++){
    fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
     }
     fclose(fp);
  
}
void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("Warning: Contact file not found or could not be opened.\n");
        addressBook->contactCount = 0;
        return;
    }

    if (fscanf(fp, "%d\n", &addressBook->contactCount) != 1) {
        printf("Error reading contact count from file.\n");
        addressBook->contactCount = 0;
        fclose(fp);
        return;
    }

    if (addressBook->contactCount > MAX_CONTACTS) {
        printf("Warning: File contains too many contacts. Limiting to %d.\n", MAX_CONTACTS);
        addressBook->contactCount = MAX_CONTACTS;
    }

    for (int i = 0; i < addressBook->contactCount; i++) {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("%d contacts loaded successfully.\n", addressBook->contactCount);
}
