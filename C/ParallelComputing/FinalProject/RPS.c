#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>
#include <string.h>
#include <time.h>

//----------CHANGABLE CONSTANTS DECLARATION

#define MAXTHREADS 10                        // highest number of threads program can run on
#define MAXSTRING 20                        // largest possible string size
#define NUMGAMESPERROUND 3                  // number of games played in each round
#define SEESENDREPORTS 0                    // shows the send traffic of threads: 0 false --- 1 true

//----------CHANGEABLE CONSTANTS END-------

#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'

char randRPS();
char inputRPS(char name[MAXSTRING]);
int decideWinner(char mymove, char opponentmove);

int main()
{
    int world_rank;
    int world_size;
    int player_count;
//    int played_against_bool[MAXTHREADS] = {0};

    char my_player_name[MAXSTRING];
    char player_names[MAXTHREADS][MAXSTRING];
    char CPU_string[MAXSTRING] = "CPU 1";
//    char ROCK = 'R';
//    char PAPER = 'P';
//    char SCISSORS = 'S';
    char my_move[NUMGAMESPERROUND + 1];
    char opponent_move;

    int my_score = 0;
    int sendto;
    int final_scores[MAXTHREADS] = {0};

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    srand(time(NULL) + world_rank);

    if (world_size < 2 || world_size > MAXTHREADS)
    {
        if (world_rank == 0)
            printf("Invalid Number of threads must be between 2 and %d. Please change MAXTHREADS to desired max.\n", MAXTHREADS);

        MPI_Finalize();
        exit(0);
    }

    if (world_rank == 0)
    {
        system("clear");
        printf("Welcome to Rock Paper Scissors Round Robin Tournament!\n");
        fflush(stdout);
        printf("How many human players? (max is %d, selecting 0 will run all computers and turn on display send traffic): ", world_size);
        fflush(stdout);
        scanf("%d", &player_count);
        while ( player_count > world_size || player_count < 0 )
        {
            printf("Invalid number of players\n");
            fflush(stdout);
            printf("How many players? (max is %d): ", world_size);
            fflush(stdout);
            scanf("%d", &player_count);
        }
    }

    MPI_Bcast(&player_count, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for ( int i = 0; i < player_count; i++)
    {
        if ( world_rank == 0 )
        {
            printf("What is player %d's name?:", i);
            fflush(stdout);

            if ( i == 0 )
            {
                scanf("%s", my_player_name);
                strcpy(player_names[0], my_player_name);
            }
            else
            {
                scanf("%s", player_names[i]);
                MPI_Send(player_names[i], MAXSTRING, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            }
        }
        else if ( i == world_rank )
        {
            MPI_Recv(&my_player_name, MAXSTRING, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
    if (player_count < world_size)
    {
        for (int i = player_count; i < world_size; i++) {
            if (world_rank == 0) {
                char tmp = (char) (i - player_count + 48); //ascii table
                CPU_string[4] = tmp;
                strcpy(player_names[i], CPU_string);
                MPI_Send(CPU_string, MAXSTRING, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            }
            if (world_rank == i)
                MPI_Recv(&my_player_name, MAXSTRING, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        //if (world_rank == 0 && player_count == 0)
          // CPU_string[4] = 1;
    }

    for ( int i = 0; i < world_size; i++ )
        MPI_Bcast(player_names[i], MAXSTRING, MPI_CHAR, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

        for ( int k = 1; k < world_size; k++ )
        {
            if ( world_rank == 0 )
            {
                for ( int z = player_count - 1; z >= 0; z-- )
                {
                    for (int g = 0; g < NUMGAMESPERROUND; g++)
                    {
                        my_move[g] = inputRPS(player_names[z]);
                    }
                    if ( z != 0 )
                        MPI_Send(my_move, NUMGAMESPERROUND, MPI_CHAR, z, 0, MPI_COMM_WORLD);
                }
            }

            if ( world_rank != 0 && world_rank < player_count )
                MPI_Recv(my_move, NUMGAMESPERROUND, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);


            if ( (world_rank % 2 == 0) && (world_size % 2 == 0) )
            {
                //printf("rank even, size even, %s", my_player_name);

                sendto = world_rank - k;
                sendto = (world_size + sendto) % world_size;
                //printf("Process %d calculated sendto = %d\n",world_rank,sendto);
                if ( sendto % 2 == 0 )
                {
                    if ( world_rank > sendto )
                    {
                        for ( int m = 0; m < NUMGAMESPERROUND; m++ )
                        {
//                            if (world_rank < player_count)
//                                my_move = inputRPS(my_player_name);
//                            else
                            if (world_rank >= player_count)
                                my_move[m] = randRPS();

                            if ( player_count == 0 || SEESENDREPORTS )
                            {
                                printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m], player_names[sendto]);
                                fflush(stdout);
                            }
                            MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                            MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                            my_score += decideWinner(my_move[m],opponent_move);
                        }
                    }
                    else
                    {
                        for ( int m = 0; m < NUMGAMESPERROUND; m++ )
                        {
/*                            if (world_rank < player_count)
                                my_move = inputRPS(my_player_name);
                            else
 */                         if (world_rank >= player_count)
                                my_move[m] = randRPS();

                            MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                            if ( player_count == 0 || SEESENDREPORTS)
                            {
                                printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m], player_names[sendto]);
                                fflush(stdout);
                            }
                            MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);

                            my_score += decideWinner(my_move[m],opponent_move);
                        }
                    }
                }
                else
                {
                    for ( int m = 0; m < NUMGAMESPERROUND; m++ )
                    {
/*                        if (world_rank < player_count)
                            my_move = inputRPS(my_player_name);
                        else
  */                    if (world_rank >= player_count)
                            my_move[m] = randRPS();

                        if ( player_count == 0 || SEESENDREPORTS)
                        {
                            printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m], player_names[sendto]);
                            fflush(stdout);
                        }
                        MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                        my_score += decideWinner(my_move[m],opponent_move);
                    }
                }
            }
            else if ( (world_rank % 2 == 1) && (world_size % 2 == 0) )
            {
                //printf("rank odd, size even, %s", my_player_name);
                sendto = (world_rank + k) % world_size;
                //printf("Process %d calculated sendto = %d\n",world_rank,sendto);
                if ( sendto % 2 == 1 )
                {
                    if ( world_rank > sendto )
                    {
                        for ( int m = 0; m < NUMGAMESPERROUND; m++ )
                        {
/*                            if (world_rank < player_count)
                                my_move = inputRPS(my_player_name);
                            else
  */                        if (world_rank >= player_count)
                                my_move[m] = randRPS();

                            if ( player_count == 0 || SEESENDREPORTS)
                            {
                                printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m], player_names[sendto]);
                                fflush(stdout);
                            }
                            MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                            MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

                            my_score += decideWinner(my_move[m],opponent_move);
                        }
                    }
                    else
                    {
                        for ( int m = 0; m < NUMGAMESPERROUND; m++ )
                        {
/*                            if (world_rank < player_count)
                                my_move = inputRPS(my_player_name);
                            else
  */                        if (world_rank >= player_count)
                                my_move[m] = randRPS();

                            MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                            if ( player_count == 0 || SEESENDREPORTS)
                            {
                                printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m], player_names[sendto]);
                                fflush(stdout);
                            }
                            MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);

                            my_score += decideWinner(my_move[m],opponent_move);
                        }
                    }
                }
                else
                {
                    for ( int m = 0; m < NUMGAMESPERROUND; m++ )
                    {
/*                        if (world_rank < player_count)
                            my_move = inputRPS(my_player_name);
                        else
 */                     if (world_rank >= player_count)
                            my_move[m] = randRPS();


                        MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        if ( player_count == 0 || SEESENDREPORTS )
                        {
                            printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m], player_names[sendto]);
                            fflush(stdout);
                        }
                        MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);

                        my_score += decideWinner(my_move[m],opponent_move);
                    }
                }
            }
            else if ( world_size % 2 == 1 )//&& k % 2 == 1 )
            {
               // printf(", size odd, %s", my_player_name);

                for (int m = 0; m < NUMGAMESPERROUND; m++ )
                {

                    if (world_rank % 2 == 0)
                    {
                        if (world_rank >= player_count)
                            my_move[m] = randRPS();

                        sendto = (world_rank + k) % world_size;
                        if (player_count == 0 || SEESENDREPORTS)
                        {
                            printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m],
                                   player_names[sendto]);
                            fflush(stdout);
                        }
                        MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        my_score += decideWinner(my_move[m],opponent_move);

                        if (world_rank >= player_count)
                            my_move[m] = randRPS();

                        sendto = (world_rank - k + world_size) % world_size;
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        if (player_count == 0 || SEESENDREPORTS)
                        {
                            printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m],
                                   player_names[sendto]);
                            fflush(stdout);
                        }
                        MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                        my_score += decideWinner(my_move[m],opponent_move);


                    }
                    else
                    {
                        if (world_rank >= player_count)
                            my_move[m] = randRPS();

                        sendto = (world_rank - k + world_size) % world_size;
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        if (player_count == 0 || SEESENDREPORTS)
                        {
                            printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m],
                                   player_names[sendto]);
                            fflush(stdout);
                        }
                        MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                        my_score += decideWinner(my_move[m],opponent_move);

                        if (world_rank >= player_count)
                            my_move[m] = randRPS();

                        sendto = (world_rank + k) % world_size;
                        if (player_count == 0 || SEESENDREPORTS)
                        {
                            printf("R:%d G:%d %s sending %c to %s\n", k, m + 1, my_player_name, my_move[m],
                                   player_names[sendto]);
                            fflush(stdout);
                        }
                        MPI_Send(&my_move[m], 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD);
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, sendto, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        my_score += decideWinner(my_move[m],opponent_move);
                    }

                }
            }
           // else if ( world_size % 2 == 1 && k % 2 == 0 )
            //{

            //}
            //if (world_size % 2 == 0 )//&& player_count > 0)
            //    MPI_Barrier(MPI_COMM_WORLD);
            //printf("Proc %d completed Round %d\n",world_rank,k);
            fflush(stdout);
        }

    if (world_rank == 0)
    {
        int highest_score = -1;
        int highest_scoring_player = 0;
        printf("\n\n\n");
        fflush(stdout);
        MPI_Gather(&my_score, 1, MPI_INT, final_scores, 1, MPI_INT, 0, MPI_COMM_WORLD);
        for (int m = 0; m < world_size; m++ )
        {
            printf("%s completed the tournament with %d points\n", player_names[m], final_scores[m]);
            fflush(stdout);
            if (final_scores[m] > highest_score)
                highest_score = final_scores[m];
        }
        printf("\nWinner(s)-----\n\n");
        for (int m = 0; m < world_size; m++ )
        {
            if (final_scores[m] == highest_score)
                printf("%s Wins!\n", player_names[m]);
            fflush(stdout);
        }
    }
    else
    {
        MPI_Gather(&my_score, 1, MPI_INT, NULL, 0, 0, 0, MPI_COMM_WORLD);
    }

    fflush(stdout);
    MPI_Finalize();

    return 0;
}

int decideWinner(char mymove, char opponentmove)
{
    //printf("\ndecide func %c && %c------------\n",mymove,opponentmove);

    if ( mymove == ROCK )
    {
        if (opponentmove == ROCK)
            return 0;
        else if (opponentmove == PAPER)
            return 0;
        else if (opponentmove == SCISSORS)
            return 1;
    }
    else if ( mymove == PAPER )
    {
        if (opponentmove == ROCK)
            return 1;
        else if (opponentmove == PAPER)
            return 0;
        else if (opponentmove == SCISSORS)
            return 0;
    }
    else if ( mymove == SCISSORS )
    {
        if (opponentmove == ROCK)
            return 0;
        else if (opponentmove == PAPER)
            return 1;
        else if (opponentmove == SCISSORS)
            return 0;
    }
    printf("ERROR EVAL WINNER\n");
    fflush(stdout);
    return 0;
}

char inputRPS(char name[MAXSTRING])
{
    int num;
    char ans;
    system("clear");
    printf("%s Chose Rock(0), Paper(1), or Scissors(2):", name);
    fflush(stdout);
    scanf("%d",&num);

    if ( num == 0 )
        return ROCK;
    else if ( num == 1 )
        return PAPER;
    else if ( num == 2 )
        return SCISSORS;
}

char randRPS()
{
    int num;
    //srand(time(NULL) + seed);
    num = rand() % 3;

    if ( num == 0 )
        return ROCK;
    if ( num == 1 )
        return PAPER;
    if ( num == 2 )
        return SCISSORS;
    printf("ERROR RAND\n");
    fflush(stdout);
    return 4;
}
