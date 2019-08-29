/* 
   This project takes two files as input and compares them byte-by-byte to record mismatches.
   It performs much like the Linux diff program.
   Spencer Peace
   CSC 362-001
   Dr. Richard Fox
   8/26/19
   Project 1
*/

// Avoid warnings
#define _CRT_SECURE_NO_WARNINGS

// Necessary includes
#include<stdio.h>
#include<stdbool.h>

void main() {
	// Hardcode filenames for input files, save to character arrays
	char filename1[] = "file1a.txt";
	char filename2[] = "file1b.txt";

	// Create file pointers for input files
	FILE* fp1, * fp2;

	// Open files
	fp1 = fopen(filename1, "r");
	fp2 = fopen(filename2, "r");

	// Declare variables for user options
	bool caseInsensitivity = true;
	bool lettersOnly = true;

	// Create char variables to store user responses and current characters from each file
	char caseI;
	char lettersOnlyVar;
	char current;
	char current2;

	// Ask user for case-insensitivity or letters-only
	printf("Case insensitive? (Y/N): ");
	scanf(" %c", &caseI);

	printf("Letters only? (Y/N): ");
	scanf(" %c", &lettersOnlyVar);
	
	// While loop that ensures EOF has not been met
	
	current = getc(fp1);
	 while(current != EOF) {
		 printf("%c", current);
		current = getc(fp1);
	 }
	 fclose(fp1);
	 fclose(fp2);
	
	// Test
	//printf("%s", caseI);
	//printf("%s", lettersOnlyVar);
	
}