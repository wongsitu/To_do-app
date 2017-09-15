#include <stdio.h>
#include <string.h>
#include "Header.h"
#pragma warning(disable:4996)

/***********************************************/
/*Description:This function will print the menu*/
/*Input:N/A                                    */
/*Output:N/A                                   */
/***********************************************/
void PrintMenu(){
	printf("Menu");
	printf("---");
	printf("1.Add new entry\n");
	printf("2.Edit entry description\n");
	printf("3.Toggle the entry status\n");
	printf("4.Delete entry\n");
	printf("5.Delete completed entries\n");
	printf("6.Set view mode\n");
	printf("7.Exit\n");
}

/**********************************************************/
/*Description:This function will scanf() the option from menu*/
/*             It will show the selected option on screen */
/*Input: number from 1 to 7                               */
/*Output: returns the value to main and shows it on screen*/
/**********************************************************/
int Option(){
	int option = 0;
	printf("\nEnter Selection(1,2,3..):");
	scanf("%d", &option);
	getchar();
	return option;
}


/***********************************************************************/
/*Description:This function will add a description to the Todo.txt file*/
/*            It will fprint() the task to the text file               */
/*Input: N/A                                                           */
/*Output: The task will show up in the screen as well as in the txt file*/
/***********************************************************************/
int AddEntry(int i, FILE *fptr) {
	CorA Stat = active;
	int value;
	char empty[]="";
	printf("\nEnter description (empty to cancel):");
	fgets(p[i].description, 30, stdin);
	getchar();
	p[i].description[strlen(p[i].description) - 1] = '\0';
	value = strcmp(p[i].description, empty);
	if (value != 0){
		printf("%d.) %s %d \n", i, p[i].description, Stat);
		fprintf(fptr, "%d.) %s %d \n",i, p[i].description, Stat);
	}
	return i;
}

/**********************************************************/
/*Description:This function will rewrite/edit entries     */
/*Input: N/A                                              */
/*Output: displays the new description                    */
/**********************************************************/
void EditEntryStatus(FILE *fptr) {
	int number,value;
	char Newdescript[30];
	char empty[] = "";
	printf("\n Enter entry	number to edit (1..5; 0	to cancel)");
	scanf("%d", &number);
	getchar();
	if (number != 0){
		printf("\n Enter a	new	description	(empty to cancel):");
		fgets(Newdescript, 30, stdin);
		getchar();
		Newdescript[strlen(Newdescript) - 1] = '\0';
		value = strcmp(Newdescript, empty);
		if (value != 0){
			printf("%d %s %d", number, p[number].description, p[number].Status);
			fprintf(fptr, "%d %s %d", number,p[number].description, p[number].Status);
		}
	}
}


/****************************************************************/
/*Description:This function will switch active/completed entries*/
/*Input: The entry that needs to be changed                     */
/*Output: returns the entry with new status                     */
/****************************************************************/
void ToggleEntrystatus() {
	int n;
	CorA Stat1 = active;
	CorA Stat2 = completed;
	printf("\n Enter entry number to toggle (1..5;	0 to cancel)");
	scanf("%d", &n);
	getchar();
	if (n != 0){
		if (p[n].Status == Stat1){
			p[n].Status = Stat2;
		}
		else 
		if (p[n].Status == Stat2){
			p[n].Status = Stat1;
		}
	}
}

/**********************************************************/
/*Description:This function will delete entries           */
/*Input: Desired entries to delete                        */
/*Output: N/A                                             */
/**********************************************************/
void DeleteEntry() {
	int numb;
	int i;
	char empty[] = "";
	printf("\n Enter entry number to delete (1..5;	0 to cancel)");
	scanf("%d", &numb);
	getchar();
	if (numb != 0){
		for (int i = 0; i < 20; i++) {
			 p[i] = p[i + 1];
	}
}

/**********************************************************/
/*Description:This function will delete completed entries */
/*Input: All completed entries                            */
/*Output: N/A                                             */
/**********************************************************/
void DeleteCompletedEntries(){
	char choice[1];
	int i;
	char empty[] = "";
	CorA Status=completed;
	printf("\n Are you	sure you want to delete	all	completed entries (type	'y' to confirm)?");
	scanf("%c",choice);
	getchar();
	if (choice == "y"){
		for (int i = 0; i < 20; i++) {
			if (p[i].Status == completed){
				//delete
			}
		}
	}
}

/**********************************************************/
/*Description:This function will set the view mode        */
/*Input: N/A                                              */
/*Output: N/A                                             */
/**********************************************************/
void SetViewMode(FILE *fptr) {
	int op,j;
	CorA Stat1 = active;
	CorA Stat2 = completed;
	printf("1.Show all entries\n");
	printf("2.Show active entries only\n");
	printf("3.Show completed entries only\n");
	op = Option();
	switch (op)
	{
	case 1:
		for (j = 0; j < 20; j++){
			printf("%s", p[j].description);
			fprintf(fptr,"%s",p[j].description);
		}
		break;
	case 2:
		for (j = 0; j < 20; j++){
			if (p[j].Status == Stat1){
				printf("%s", p[j].description);
				fprintf(fptr, "%s", p[j].description);
			}
		}
		break;
	case 3:
		for (j = 0; j < 20; j++){
			if (p[j].Status == Stat2){
				printf("%s", p[j].description);
				fprintf(fptr, "%s", p[j].description);
			}
		}
		break;
	default:
		printf("\nError! Wrong Number is Entered\nPlease Try Again");
		break;
	}
}



/**********************************************************/
/*Description:This function will count all active tasks   */
/*Input: the file in which it's going to run              */
/*Output: returns the number of active tasks              */
/**********************************************************/
int ActiveTaskcounter(){
	CorA Stat1 = active;
	int j, counter = 0;
	for (j = 0; j < 20; j++){
		if (p[j].Status = Stat1){
			counter++;
		}
	}
	return counter;
}

/**********************************************************/
/*Description:This function will count all tasks          */
/*Input: the file in which it's going to run              */
/*Output: returns the number of total  tasks              */
/**********************************************************/
int TotalTaskcounter(){
	int totalTask=0;
	CorA Stat1 = active;
	CorA Stat2 = completed;
	int j, counter = 0;
	for (j = 0; j < 20; j++){
		if (p[j].Status = Stat1 || p[j].Status = Stat2){
			totalTask++;
		}
	}
	return totalTask;
}