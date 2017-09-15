#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "WK.c"
#pragma warning(disable:4996)

/********************************************************************/
/*Description: Open the Todo.txt file                               */
/*             Main wil be calling all functions using a switch case*/
/*             Closes Todo.txt file                                 */
/*             Exits the program                                    */
/*Input:N/A                                                         */
/*Output:N/A                                                        */
/********************************************************************/
void main() {
	int op, a,actask,m;
	char str1[20] = "No entry to display", str2[20] = "No active entries";
	//Open the Todo.txt file
	FILE *fptr;
	fptr = fopen("Text.txt", "w+");

	int k=1;
	
	for (a = 0;; a++){
		if (fptr == EOF) {
			fprintf(fptr, "%s", str1);
			fprintf(fptr, "%s", str2);
		}
		else
		{
			actask = ActiveTaskcounter();
			fprintf(fptr,"%d active entries",actask);
		}
		PrintMenu();
		op = Option();
		switch (op)
		{
		case 1:
			AddEntry(k, fptr);
			ActiveTaskcounter();
			k++;
			break;
		case 2:
			EditEntryStatus(fptr);
			break;
		case 3:
			ToggleEntrystatus();
			ActiveTaskcounter();
			break;
		case 4:
			DeleteEntry();
			ActiveTaskcounter();
			break;
		case 5:
			DeleteCompletedEntries();
			break;
		case 6:
			SetViewMode(fptr);
			break;
		case 7:
			printf("\n*** Thanks for using the program! Goodbye. ***");
			fclose(fptr);
			exit(0);
		default:
			printf("\nError! Wrong Number is Entered\nPlease Try Again");
			break;
		}
	}
}
