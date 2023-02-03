#ifndef CONTACT_H
#define CONTACT_H
struct contact{
	char fname[25];
	char lname[25];
	char mob_no[11];
	char email[50];
	char address[100];
};
void initializeContact(struct contact* data);
void copyContact(struct contact* , struct contact* );
struct contact* newContact();
void displayContact(struct contact a);
void displayContact2(struct contact a);

#endif // CONTACT_H
