#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
  char *name;
  char *phone;
} contact;
int action;
int listAllContacts(void);
int listASpecificContact(void);
int addNewContact(void);
int quit(void);

int pickAction(int action)
{
  while (action < 1 || action > 4)
  {
    printf("\n1. (List all contacts)\n");
    printf("2. (List a specific contact)\n");
    printf("3. (Add a new contact)\n");
    printf("4. (Exit)\n\n");

    scanf("%d", &action);

    switch (action)
    {
    case 1:
      listAllContacts();
      break;
    case 2:
      listASpecificContact();
      break;
    case 3:
      addNewContact();
      break;
    case 4:
      quit();
      break;
    default:
      printf("\nInvalid Action!\n");
      printf("Select a valid Action!\n\n");
      break;
    }
  }
}

#define MAX_CONTACTS 100
contact contacts[MAX_CONTACTS];
int contactCount = 0;

int listAllContacts(void)
{
  printf("\n");
  if (contactCount != 0)
  {
    for (int i = 0; i < contactCount; i++)
    {
      printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
  }
  else
  {
    printf("Hasn't anyone contact saved.\n");
  }

  action = 0;
  pickAction(action);
}

int listASpecificContact(void)
{
  printf("\n");
  if (contactCount != 0)
  {
    char *searchContact;
    printf("Enter the name or phone: ");
    scanf("%s", searchContact);
    for (int i = 0; i < contactCount; i++)
    {
      if (strcmp(contacts[i].name, searchContact) == 0 || strcmp(contacts[i].phone, searchContact) == 0)
      {
        printf("\n");
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
      }
      else
      {
        printf("\nContact wasn't founded!\n");
      }
    }
    action = 0;
    pickAction(action);
  }
  else
  {
    printf("Hasn't anyone contact saved.\n");
    action = 0;
    pickAction(action);
  }
}

int addNewContact(void)
{
  printf("\n");
  if (contactCount < MAX_CONTACTS)
  {
    contact newContact;

    printf("Enter a name for the new contact: ");
    scanf("%ms", &newContact.name);

    printf("Enter a phone number for the new contact: ");
    scanf("%ms", &newContact.phone);

    contacts[contactCount] = newContact;
    contactCount++;

    action = 0;
    pickAction(action);
  }
  else
  {
    printf("Cannot add more contacts. Maximum limit reached.\n");
    action = 0;
    pickAction(action);
  }
}

int quit(void)
{
  printf("\nSuccessfully quited!\n");
}

int main(void)
{
  printf("Hello, how can I help you?\n");
  pickAction(action);

  for (int i = 0; i < contactCount; i++)
  {
    free(contacts[i].name);
    free(contacts[i].phone);
  }

  return 0;
}