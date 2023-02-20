#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Keeps track of names and repetitions
struct NameCount
{
	char name[30];
	int count;
};

int main(int argc, char **argv)
{
	//Verify if argument with filename is given
	//Else output error
	if(argc == 1)
	{
		fprintf(stderr, "Error - Enter filename as an argument\n");
		exit(1);
	}

	//Open file
	//If file doesn't exist output error
	FILE *f = fopen(argv[argc - 1], "r");
	if(f == NULL)
	{
		fprintf(stderr, "Error - File %s doesn't exist\n", argv[argc - 1]);
		exit(1);
	}

	//Names can be up 30 characters long
	//Go over names line by line
	//If name doesn't exist output warning
	char current_name[30];
	int line = 0;
	struct NameCount names[100];
	int individual_names = 0;
	while(fgets(current_name, 30, f))
	{
		line += 1;
		//If empty line skip
		if(current_name[0] == '\n')
		{
			fprintf(stderr, "Warning - Line %i is empty\n", line);
			continue;
		}

		//Go over names and find repetitions
		for(int i = 0; i <= 100; i++)
		{
			//If name has not been registered yet
			//register the name
			if(i == 100)
			{
				strcpy(names[individual_names].name, current_name);
				names[individual_names].count = 1;
				individual_names += 1;
				break;
			}

			//Compare the names and add count
			if(strcmp(names[i].name, current_name) == 0)
			{
				names[i].count += 1;
				break;
			}
		}
	}

	//Output names and repetitions
	for(int i = 0; i < individual_names; i++)
	{
		fprintf(stdout, "%s:%i\n", names[i].name, names[i].count);
	}

	fclose(f);
	return 0;
}
