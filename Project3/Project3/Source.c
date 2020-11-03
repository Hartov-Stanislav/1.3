#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{
	// Opening text file
	FILE* input = fopen("input.txt", "r");
	// Case without file
	if (input == NULL)
	{
		printf("Cannot open file.\n");
		return 1;
	}
	// Creation array of char
	char string[MAX];
	while (!feof(input))
	{
		// Getting string from file
		if (fgets(string, MAX, input))
		{
			int i = 1;
			while (string[i - 1] != '\n')
			{
				// Search equal symbols
				if (string[i] != string[i - 1])
				{
					printf("%c", string[i - 1]);
				}
				// In last string it can't find '\n' and it print nonsense, but there is '\0' before nonsense
				// It will be solution of my proplem
				if (string[i] == '\0')
				{
					fclose(input);
					return 0;
				}
				i++;
			}
			printf("\n");
		}
	}
}