#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "binarysearch.h"

int main()
{
    WordEntry list[500];
    FILE  *f;
    FILE *output;
    int occurence;     
    char line[100];
    char word[50];
    int capacity= 10;
    int count = 0;
    char inputfile[50];

    printf("Enter the input file name:");
    gets(inputfile);
    f = fopen(inputfile, "r");
    if(f == NULL)
        return 1;
    
     // Prompt user for a word to search
    char searchWord[100];
    printf("Enter a word to search: ");
    scanf("%s", searchWord);

    while(fgets(line, 1000, f)){
        sscanf( line, "%s %d", word,&occurence);  
        strcpy(list[count].word, word);
        list[count].occurence = occurence;
        count++;
    }

    int result = binarySearch(list,0, count-1,searchWord);

   if (result != -1) {
        printf("'%s' found in the file at index '%d'\n and the frequency is %d", searchWord,result+1,list[result].occurence);
    } else {
        printf("'%s' not found in the file. \n", searchWord);
    }

    return 0;

}