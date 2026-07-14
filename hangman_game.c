#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct wordwithhint{
    char word[50];
    char hint[50];
};
int main()
{
    int t,l;
    int n=3;
    char guessedword[50];
    int guesses=0;
    char guess;
    srand(time(NULL));
    t=rand() % n;
    struct wordwithhint data[3]={{"elephant","largest animal"},{"pizza","italy"},{"beach","sandy shore"}};
    printf("Hint=%s\n",data[t].hint);
    l=strlen(data[t].word);
    for(int i=0;i<l;i++)
    {
         guessedword[i]= '-';
    }
     guessedword[l]= '\0';
     printf("%s\n", guessedword);
     while(1)
    {
     printf("Enter your guess:");
     scanf(" %c",&guess);
     guesses=guesses+1;
     if(guess<'a'||guess>'z')
     {
         printf("Invalid input\n");
         if(guesses<l+1)
         {
         continue;
         }
     }
     if(guesses<l+1)
     {
     for(int i=0;i<l;i++)
     {
         if(data[t].word[i]==guess)
         {
            guessedword[i]=guess;
         }
     }
      printf("%s\n",guessedword);
       if(strcmp(guessedword,data[t].word)==0)
      {
          printf("YOU WON :)\n");
          printf("_________________\n");
          printf("|                \n");
          printf("|                \n");
          printf("|       o        \n");
          printf("|      /|\\      \n");
          printf("|__    / \\      \n");
          break;
      }
     }
     else 
     {
         printf("YOU LOST  :(\n");
         printf("_________________\n");
         printf("|       |        \n");
         printf("|       o        \n");
         printf("|      /|\\      \n");
         printf("|      / \\      \n");
         printf("|                \n");
         printf("__\n");
         printf("The word is:%s",data[t].word);
         break;
     }
    }
    return 0;
}