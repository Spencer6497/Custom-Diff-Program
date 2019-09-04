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

	// Create char variables to store user responses and current characters from each file
	char caseI;
	char lettersOnlyVar;
	char current;
	char current2;

	// Create int/float variables to store number of characters, mismatches, and non-letters (for testing letters only) respectively
	int numCharacters = 0;
	float numMismatches = 0.0;
	float nonLetters = 0.0;

	// Ask user for case-insensitivity or letters-only
	printf("Case insensitive? (Y/N): ");
	scanf(" %c", &caseI);

	printf("\nLetters only? (Y/N): ");
	scanf(" %c", &lettersOnlyVar);
	
	// Initialize both variables to the first letter of each file
	current = getc(fp1);
	current2 = getc(fp2);

	// While loop that ensures EOF has not been met
	while(current != EOF) {
		// Increment character count
		numCharacters++;

		// Conditional to test for case insensitivity and/or letters only
		// Surely there is a better, cleaner way to do this, but I'm blanking. This is overtly redundant.

		// If both case insensitive AND letters only
		if ((caseI == 'y') && (lettersOnlyVar == 'y')) {
			// Increment nonLetters if either character isn't alphabetic
			if ((isalpha(current) == 0) || (isalpha(current2) == 0)) {
				nonLetters++;
			// Increment numMismatches if the characters don't equal each other
			} else if (tolower(current) != tolower(current2)) {
				numMismatches++;
			}
		}
		// If case insensitive but not letters only
		else if ((caseI == 'y') && (lettersOnlyVar == 'n')) {
			// Increment numMismatches if characters don't equal
			if (tolower(current) != tolower(current2)) {
				numMismatches++;
			}
		}
		// If case sensitive, but letters only
		else if ((caseI == 'n') && (lettersOnlyVar == 'y')) {
			// Increment nonLetters if either character isn't alphabetic
			if ((isalpha(current) == 0) || (isalpha(current2) == 0)) {
				nonLetters++;
			}
			else if (current != current2) {
				numMismatches++;
			}
		}
		// Default case, neither case insensitive nor letters only
		else {
			if (current != current2) {
				numMismatches++;
			}
		}
		current = getc(fp1);
		current2 = getc(fp2);
	 }

	// Format mismatch percentage, non-tested percentage
	float mismatch = (numMismatches / numCharacters) * 100;
	float notTested = (nonLetters / numCharacters) * 100;

	// Final print statements
	printf("\nComparing %s to %s testing for ", filename1, filename2);


	// If both case insensitive AND letters only
	if ((caseI == 'y') && (lettersOnlyVar == 'y')) {
		printf("case insensitivity and for letters only\n");
		printf("\tFile sizes: %d characters", numCharacters);
		printf("\n\tMismatches: %.2f%%", mismatch);
		printf("\n\t Not tested: %.2f%%\n", notTested);
	}
	// If case insensitive but not letters only
	else if ((caseI == 'y') && (lettersOnlyVar == 'n')) {
		printf("case insensitivity\n");
		printf("\tFile sizes: %d characters", numCharacters);
		printf("\n\tMismatches: %.2f%%\n", mismatch);
	}
	// If case sensitive, but letters only
	else if ((caseI == 'n') && (lettersOnlyVar == 'y')) {
		printf("case sensitivity and for letters only\n");
		printf("\tFile sizes: %d characters", numCharacters);
		printf("\n\tMismatches: %.2f%%", mismatch);
		printf("\n\tNot tested: %.2f%%\n", notTested);
	}
	// Default case, neither case insensitive nor letters only
	else {
		printf("case sensitivity and for all characters\n");
		printf("\tFile sizes: %d characters", numCharacters);
		printf("\n\tMismatches: %.2f%%\n", mismatch);
	}

	 fclose(fp1);
	 fclose(fp2);
	
	// Test
	//printf("%s", caseI);
	//printf("%s", lettersOnlyVar);
	
}