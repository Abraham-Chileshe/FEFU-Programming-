#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Team{
    int team_number;
    int problems_solved;
    int total_time;
    int wrong_attempts[21];
};

struct Data{
    int team_number;
    int problem_number;
    int time;
    int result;
};

int compare_teams(const void *a, const void *b);
int compare_data(const void *a, const void *b);

int num_teams, num_data;

int main(){
    FILE *In, *Out;
    In = fopen("input.txt", "r");
    Out = fopen("output.txt", "w");

    while (fscanf(In, "%d %d", &num_teams, &num_data) != EOF){
        struct Team teams[num_teams + 1];
        memset(teams, 0, sizeof(teams[0]) * (num_teams + 1));
        for (int i = 1; i <= num_teams; ++i)
            teams[i].team_number = i;

        struct Data data[num_data];
        for (int i = 0; i < num_data; ++i)
            fscanf(In, "%d %d %d %d", &data[i].team_number, &data[i].problem_number, &data[i].time, &data[i].result);

        qsort(data, num_data, sizeof(data[0]), compare_data);

        for (int i = 0; i < num_data; ++i){
            int team_number = data[i].team_number;
            int problem_number = data[i].problem_number;
            int time = data[i].time;
            int result = data[i].result;
            struct Team *team = &teams[team_number];

            if (result == 1){

                if (team->wrong_attempts[problem_number] != -1){
                    team->total_time += (time + team->wrong_attempts[problem_number] * 20 * 60);
                    team->problems_solved++;
                }
                team->wrong_attempts[problem_number] = -1;

            }else{
                if (team->wrong_attempts[problem_number] != -1)
                    team->wrong_attempts[problem_number]++;
            }
        }

        qsort(teams + 1, num_teams, sizeof(teams[0]), compare_teams);

        for (int i = 1; i <= num_teams; ++i){
            fprintf(Out, i == 1 ? "%d" : " %d", teams[i].team_number);
        }

        fprintf(Out, "\n");
    }

    fclose(In);
    fclose(Out);

    return 0;
}

int compare_teams(const void *a, const void *b){
    struct Team *team1 = (struct Team *)a;
    struct Team *team2 = (struct Team *)b;
    if (team1->problems_solved != team2->problems_solved)
        return team2->problems_solved - team1->problems_solved;
    else if (team1->total_time != team2->total_time)
        return team1->total_time - team2->total_time;
    else
        return team1->team_number - team2->team_number;
}

int compare_data(const void *a, const void *b){
    struct Data *data1 = (struct Data *)a;
    struct Data *data2 = (struct Data *)b;
    return data1->time - data2->time;
}
