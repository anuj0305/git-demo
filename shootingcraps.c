#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void play(void);
int throw(void);

main()
{
    int SEED;
    char answer= 'Y';
    printf("Welcome to the Game of craps \n\n");
    printf(" To throw the dice, press Enter \n\n");
    srand(SEED);
    
    while(toupper(answer) !='N')
    {
        play();
        printf("\n Do you want to play again? (Y/N)");
        scanf("%c", &answer);
        printf("\n");
    }
    printf("Bye , have a nice day");
    
}
void play(void)
{
    int score1 , score2;
    char dummy;

    printf("\nPlease Throw The Dice . . . .");
    scanf("%c",&dummy);
    printf("\n");
    score1= throw();
    printf("\n %2d", score1);
    switch (score1)
    {
        case 7:
        case 11:
        printf(" - CONGRATULATION!  You Win on the first throw. \n");
        break;
    
        case 2:
        case 3:
        case 12:
         printf(" - SORRY You lost in first throw. \n");
         break;

        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
        case 10:

        do {
            printf("Throw the dice Again . . .");
            scanf("%c",&dummy);
            score2= throw();
            printf("\n%2d", score2);
        }
        while (score2 !=score1 && score2 != 7);
         
         if(score2==score1)
         printf(" - You WIN by matching your first score\n");
         else 
         printf(" - You LOSE by failing to match your first score\n");
         break; 

    }
    return;
}
int throw(void)
{
    float x1 , x2;
    int n1 , n2;
    x1= rand() / 32768.0;
    x2= rand() / 32768.0;
    n1= 1 + (int) (6 * x1);
    n2= 1 + (int) (6 * x2);
    return (n1 + n2); 
}
