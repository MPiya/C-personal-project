/* Master Piyaboot Prasertsuwan A303 DATALOGI*/
/* John did help me with logic behide lower score section.*/
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #define MAX_DIE_EYES 6

    void scan_data(int* num_dice); /*scan data*/
    void roll_multiple_dice(int dice[],int num_dice); /*     roll n dice  in for loop*/
    void print_dice(int dice[], int num_dice); /* print f dice*/
    void bonus(int* sum); /*bonus*/
    void upper_section(int num_dice, int dice[], int score[]); /*contain a function for upper section */
    void lower_score(int dice[], int numdice, int score[]); /* print lower score */
    void show_score(int score[]); /* scoreboard*/
    int roll_dice(void); /*  roll dice  */
    int x_kind (int dice[], int num_dice, int kind); /*x kind.function */
    int two_pair(int dice[], int num_dice); /* two pair function */
    int small_or_large_s(int dice[], int num_dice, int straight);/* small or large straight function*/
    int house(int dice[], int num_dice); /* house function*/
    int chance(int dice[], int num_dice); /* chance function */
    int yatcy(int dice[], int num_dice); /* yatcy function*/

    int main (void)
    {
       int i, num_dice,* dice;

        int score[16];
        char answer = 'a';
        while(answer!='q'&& answer!='Q')
            {
                for(i=0;i<16;i++)score[i]=0;
                scan_data(&num_dice);
                dice = (int*)malloc(num_dice * sizeof(int));
                srand(time(NULL));
                upper_section(num_dice,dice,score);
                lower_score(dice, num_dice, score);
                printf("\n");
                bonus(score);
                show_score(score);
                printf("Would you like to Play again? Press y to continue and q to exit");
                free(dice);
                 scanf("%c", &answer);

            }



    void upper_section(int num_dice, int dice[], int score[])
    {
        int roll, round;
        for (round = 1; round< 7; round++) /*    1-6 round                 */
        {
            printf("Round %d dice rolled: " ,round);
            roll_multiple_dice(dice, num_dice);

            for (roll = 0; roll < num_dice; roll ++)
            {
                if (dice[roll] == round && score[round]< round* 5 ) /*     check if dices roll is equal to the corresponding round up to 5.                */
                {
                score[round] += round; /*        store score              */
                }
            }

        }

    }


    void bonus(int* sum)
    {   int i;
        for(i= 1; i< 7; i++)
        {
           sum[0]+=sum[i]; /*    Sum from round 1 to 6                 */
        }
       sum[0] = sum[0] >= 63 ? 50 : 0; /*   if sum is over 63 or then get 50 points as bonus                  */
    }

        void scan_data(int* num_dice)
    {
        printf(" Input number of dice to roll:");
        scanf("%d", num_dice);
    }

        void roll_multiple_dice(int dice[], int num_dice)
    {
        int i;
        for (i = 0; i < num_dice ; i ++)
        {
            dice[i] =roll_dice();
            printf("%2d", dice[i]);
        }
    printf("\n");
    }

    int roll_dice(void)
    {
        return rand()%MAX_DIE_EYES +1;
    }

    int x_kind( int dice[], int num_dice, int kind)
    {
    int pip, roll;

        for(pip=6 ;pip > 0 ;pip--) /* loop repeats 6 times                    */
        {
            int x=0;
            for(roll = 0; roll < num_dice; roll ++) /*   roll increases by 1 until n dices                 */
            {
                if( dice[roll] == pip ) /*      Check every array roll dice roll ==  for all pip then + 1 in x               */
                {
                    x += 1;
                }
                if(x == kind)  /*   x== kind then return kind * pip ie kind 1  */
                {
                    return kind*pip;
                }

            }

        }
          return 0;
    }


    int two_pair(int dice[], int num_dice)
    {
        int pip, roll, track = 0;
        for(pip=6 ;pip > 0 ;pip--)
        {
            int x=0;
            for(roll = 0; roll < num_dice; roll ++)
            {
                if( dice[roll] == pip )
                {
                    x += 1;
                }
                if(x== 2  )  /*   x== 2 means it found a pair  of dice                */
                {

                if(track==0)  /* store score of pairs in track then exit for roll. so track will not be 2 after if condition.                */
                {
                   track += 2*pip ;
                     break;


                } else {
                     track += 2*pip;   /*  if the program found one more than pair then track would not be 0 and else starts to work where it store value of dice and return score                   */
                     return track;
                }
                }


            }

        }
          return 0;
    }

    int  small_or_large_s(int dice[], int num_dice, int straight)
    {
        int pip,roll,track;

        for(pip=5+straight ;pip > straight ;pip--)  /*if straight is 0 mean small so it sum 1-5. If straight is 1  it sums from 2-6 if it meets the condition.*/
        {
           track=0;
            for(roll = 0; roll < num_dice; roll ++)
            {
                if( dice[roll] == pip )
                {
                 track =15+5*straight;

                }


            }
    if (!track) {
                    break;
                  }

        }
    return track;
    }

int house(int dice[], int num_dice)
{
        int sum_value_three,sum_value_two;
        int track = 0;
        sum_value_three = x_kind(dice, num_dice,3)/3; /* store highest value of 3 same dices) */
        if(sum_value_three != 0)  /* if this  is not 0 it means it found 3 of kind  else it will exit the loop and track would return 0*/
        {
             sum_value_two = x_kind (dice, num_dice,2)/2;   /* store  highest value of 2 same ices */

            if( sum_value_three ==   sum_value_two)   /* if it equal it means  there are 3 same dices  ie. 6 6 6 5 5 this would make sum_value_three and two equal to each other because it stores both highest value */
            {

              track=two_pair(dice, num_dice); /* this function find two difference pair so ie we have 666 55 then it would be 66 55 which gives 22. now track = 22 and value of three is 6. 22+6 is 28 */
               if(track !=0 )
                {
                track +=sum_value_three;
                }

            }

            else /*  else would work if it the dice rolls are 555 66  so it basically sum value of three and two after multiplication of 3 and 2 */
            {
                track =( sum_value_three *3 ) + ( sum_value_two*2);
            }

        }


    return track;
}

int chance(int dice[], int num_dice)
{     int pip, roll,x=0,track = 0;

        for(pip=6 ;pip > 0 ;pip--) /* sum  everything up to 5 */
        {

            for(roll = 0; roll < num_dice; roll ++)
            {
                if( dice[roll] == pip && track!=5 )
                {
                    x += pip;
                    track+=1;
                }

            }

        }
          return x;
}


int yatcy(int dice[], int num_dice)
{
        int pip, roll,x=0,track= 0;

        for(pip=6 ;pip > 0 ;pip--)
        {

            for(roll = 0; roll < num_dice; roll ++)
                {
                    if(  dice[roll] == pip && track!=5 )
                    {


                        x=50;

                           track+=1;



                    }

            }
            if(track==5)
            {
             break;
            }
    else
    {
        x = 0;
        track = 0;
}

        }
        return x;

        }
void lower_score(int dice[], int num_dice, int score[])
{

    printf("Round 7 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[7] = x_kind(dice, num_dice,2);

    printf("Round 8 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[8] =two_pair(dice, num_dice);

    printf("Round 9 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[9] = x_kind(dice, num_dice,3);

    printf("Round 10 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[10] = x_kind(dice, num_dice,4);

     printf("Round 11 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[11] = small_or_large_s(dice, num_dice,0);

     printf("Round 12 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[12] = small_or_large_s(dice, num_dice,1);


    printf("Round 13 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[13] = house(dice, num_dice);


    printf("Round 14 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[14] = chance(dice, num_dice);


    printf("Round 15 dice rolled: ");
    roll_multiple_dice(dice, num_dice);
    score[15] = yatcy(dice, num_dice);



}

void show_score(int score[])
{
    int i, totalscore = 0;
    printf("Round                         Score\n");
    printf("Ones: %27d\n", score[1]);
    printf("Twos: %27d\n", score[2]);
    printf("Threes: %25d\n", score[3]);
    printf("Fours: %26d\n", score[4]);
    printf("Fives: %26d\n", score[5]);
    printf("Sixs: %27d\n", score[6]);
    printf("Bonus: %26d\n", score[0]);
    printf("1 pair: %25d\n", score[7]);
    printf("2 pair: %25d\n", score[8]);
    printf("3 pair: %25d\n", score[9]);
    printf("4 pair: %25d\n", score[10]);
    printf("Small Straight: %17d\n", score[11]);
    printf("Large Straight: %17d\n", score[12]);
    printf("Full House: %21d\n", score[13]);
    printf("Chance: %25d\n", score[14]);
    printf("Yatcy: %26d\n", score[15]);

    for(i=0;i<16;i++)
    {
        totalscore+=score[i];
    }

    printf("Total score: %d\n",totalscore);


}

