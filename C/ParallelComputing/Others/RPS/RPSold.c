#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>
#include <string.h>

#define MAXTHREADS 4
#define MAXSTRING 10

int main()
{
    int world_rank;
    int world_size;
    int player_count;
    int played_against_bool[MAXTHREADS] = {0};

    char my_player_name[MAXSTRING];
    char player_names[MAXTHREADS][MAXSTRING];
    char CPU_string[MAXSTRING] = "CPU ";
    char ROCK = 'R';
    char PAPER = 'P';
    char SCISSORS = 'S';
    char my_move;
    char opponent_move;

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size < 2)
    {
        if (world_rank == 0)
            printf("Must have at least 2 threads\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (world_rank == 0)
    {
        system("clear");
        printf("Welcome to Rock Paper Scissors Tournament!\n");
        fflush(stdout);
        printf("How many players? (max is %d): ", world_size);
        fflush(stdout);
        scanf("%d", &player_count);
        while ( player_count > world_size || player_count < 1 )
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
                scanf("%s", my_player_name);
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
                char tmp = (char) (i - player_count + 48 + 1); //ascii table
                CPU_string[4] = tmp;
                MPI_Send(CPU_string, MAXSTRING, MPI_CHAR, i, 0, MPI_COMM_WORLD);
            } else if (world_rank == i)
                MPI_Recv(&my_player_name, MAXSTRING, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }

        for ( int k = world_rank + 1; k != world_rank % world_size; k++ )
        {
            k = k % world_size;
            if ( world_rank % 2 == 0 )
            {
                if ( k % 2 == 0 )
                {
                    if ( world_rank > ((world_rank - k) % world_size) )
                    {
                        MPI_Send(&ROCK, 1, MPI_CHAR, ((world_rank - k) % world_size), 0, MPI_COMM_WORLD);
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, ((world_rank - k) % world_size), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    }
                    else
                    {
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, ((world_rank - k) % world_size), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        MPI_Send(&ROCK, 1, MPI_CHAR, ((world_rank - k) % world_size), 0, MPI_COMM_WORLD);
                    }
                }
                else
                {
                    MPI_Send(&ROCK, 1, MPI_CHAR, ((world_rank - k) % world_size), 0, MPI_COMM_WORLD);
                    MPI_Recv(&opponent_move, 1, MPI_CHAR, ((world_rank - k) % world_size), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
            }
            else
            {
                if ( k % 2 == 1 )
                {
                    if ( world_rank > ((world_rank + k) % world_size) )
                    {
                        MPI_Send(&ROCK, 1, MPI_CHAR, ((world_rank + k) % world_size), 0, MPI_COMM_WORLD);
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, ((world_rank + k) % world_size), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    }
                    else
                    {
                        MPI_Recv(&opponent_move, 1, MPI_CHAR, ((world_rank + k) % world_size), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        MPI_Send(&ROCK, 1, MPI_CHAR, ((world_rank + k) % world_size), 0, MPI_COMM_WORLD);
                    }
                }
                else
                {
                    MPI_Recv(&opponent_move, 1, MPI_CHAR, ((world_rank + k) % world_size), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    MPI_Send(&ROCK, 1, MPI_CHAR, ((world_rank + k) % world_size), 0, MPI_COMM_WORLD);
                }
            }
        }

    printf("Process %d completed tournament\n", world_rank);
    fflush(stdout);


    MPI_Finalize();

    return 0;
}

