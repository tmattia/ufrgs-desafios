#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define TOURN_LENGTH 100
#define NAME_LENGTH  30

struct team
{
    char name[NAME_LENGTH];
    int matches;
    int points;
    int wins;
    int ties;
    int losses;
    int sgoals;
    int agoals;
};

int cmpteams(const team &a, const team &b)
{
    if (a.points != b.points) return a.points > b.points;
    if (a.wins != b.wins) return a.wins > b.wins;
    if ((a.sgoals - a.agoals) != (b.sgoals - b.agoals)) return (a.sgoals - a.agoals) > (b.sgoals - b.agoals);
    if (a.sgoals != b.sgoals) return a.sgoals > b.sgoals;
    if (a.matches != b.matches) return a.matches < b.matches;
    return strcasecmp(a.name, b.name) < 0;
}

int main()
{
    int cases;
    scanf("%d\n", &cases);
    while (cases--) {
        // read tournament name
        char tourn[TOURN_LENGTH];
        gets(tourn);

        // read number of teams
        int nteams;
        scanf("%d\n", &nteams);

        // initialize teams
        struct team teams[nteams];
        for (int i = 0; i < nteams; i++) {
            gets(teams[i].name);
            teams[i].matches = 0;
            teams[i].points = 0;
            teams[i].wins = 0;
            teams[i].ties = 0;
            teams[i].losses = 0;
            teams[i].sgoals = 0;
            teams[i].agoals = 0;
        }

        // read number of games
        int ngames;
        scanf("%d\n", &ngames);

        // read games information and load it to the teams
        for (int i = 0; i < ngames; i++) {
            char line[256];
            gets(line);

            char team1[NAME_LENGTH];
            char team2[NAME_LENGTH];
            int goals1;
            int goals2;
            sscanf(line, "%[^#]#%d@%d#%[^#]", team1, &goals1, &goals2, team2);

            // find each team in teams array to assign their values
            int t1, t2;
            for (int j = 0; j < nteams; j++) {
                if (strcmp(teams[j].name, team1) == 0) {
                    t1 = j;
                } else if (strcmp(teams[j].name, team2) == 0) {
                    t2 = j;
                }
            }

            // assign scores
            teams[t1].sgoals += goals1;
            teams[t1].agoals += goals2;
            teams[t1].matches++;

            teams[t2].sgoals += goals2;
            teams[t2].agoals += goals1;
            teams[t2].matches++;
            if (goals1 > goals2) {
                // team1 wins
                teams[t1].wins++;
                teams[t1].points += 3;

                teams[t2].losses++;

            } else if (goals1 == goals2) {
                teams[t1].ties++;
                teams[t1].points += 1;

                teams[t2].ties++;
                teams[t2].points += 1;

            } else {
                teams[t2].wins++;
                teams[t2].points += 3;

                teams[t1].losses++;
            }
        }

        // sort teams according to cmpteams comparison function
        sort(teams, teams + nteams, cmpteams);

        // output
        printf("%s\n", tourn);
        for (int i = 0; i < nteams; i++) {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    i + 1,
                    teams[i].name,
                    teams[i].points,
                    teams[i].matches,
                    teams[i].wins,
                    teams[i].ties,
                    teams[i].losses,
                    (teams[i].sgoals - teams[i].agoals),
                    teams[i].sgoals,
                    teams[i].agoals);
        }
        if (cases != 0) {
            printf("\n");
        }
    }
    return 0;
}
