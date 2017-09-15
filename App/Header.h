#pragma once
#include <stdio.h>

// Data types for competed or incompleted tasks
typedef enum {
	active,
	completed,
} CorA;

//Table structure
typedef struct Tab{
	char description[50];
	CorA Status;
}table;

table p[20];

//here are all the prototypes
void PrintMenu();
int Option();
int AddEntry(int,FILE);
void EditEntryStatus(FILE);
void ToggleEntrystatus();
void DeleteEntry();
void DeleteCompletedEntries();
void SetViewMode(FILE);
int ActiveTaskcounter();
int TotalTaskcounter();