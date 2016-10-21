#include <iostream>
#include <string>
using namespace std;

const int WORDS = 10;
//Part Two
char* replace(char*, char*, char[]);
int find(char*, char[], int&);
char* correctSentence(int ind_start, int ind_end, char[], char*);

int main()
{
	//Part One
	char *slangWords[WORDS] = {"2moro","2nite","BRB","BTW","B4N","FUD","GR8","TYSM","DAT","F9"};
	char *slangMeanings[WORDS] = {"Tomorrow","Tonight","Be Right Back", "By The Way","Bye For Now","Fear, Uncertainty, and Disinformation", "Great", "Thank You So Much", "That", "Fine"};
//Rest of the program
	char sentence[] = "A good night, 2nite, full of FUD.";
	char* corrected = NULL;
	corrected = replace(slangWords[1],slangMeanings[1],sentence);
	cout << corrected;
	delete corrected;
	
	return 0;
}

//Part three

char* replace(char* word, char*meaning, char sen[])
{
	
	int index_start = 8100101;											// search will return an index for starting point of replacement
	int index_end = 8100101;											// Passed by reference, this is to fetch the rest of the sentence after the slang
	index_start = find(word, sen, index_end);
	if (index_start != strlen(sen))
		return correctSentence(index_start, index_end, sen, meaning);
	else
		return sen;
}

int find(char*key, char sen[], int &endex)
{
	for (int i = 0; i < strlen(sen); i++)								//Searches within the bounds of the sentence array
	{
		if (sen[i] == key[0])											//Firstly searches for the initial of the slang
		{
			for (int j = 1; j < strlen(key); j++)						//Subsequently matches the rest of the word with the slang
			{
				if (sen[i + j] != key[j])								//Stops matching if the letters don't match
					break;
				if (j == (strlen(key) - 1))								//Sends indices if all of the letters matched
				{
					endex = i + j;
					return i;
				}
			}
		}
	}
}

char* correctSentence(int index_start, int index_end, char sen[], char* meaning)
{
	char* newArray = new char[0];



	for (int i = 0; i < index_start; i++)
	{
		newArray[i] = sen[i];
		if (i == index_start - 1)
			newArray[i + 1] = '\0';
	}
	strcat(newArray, meaning);
	strcat(newArray, sen + (index_end + 1));



	return newArray;
}