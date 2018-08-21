/*
The first line contains two integers T (1 <= T <= 20), number of teams, P (1<= P <= 10)
number of problems.
The next T lines are the team’s names (one word per name).
The next line contains an integer S (1 <= S <= 1000), number of solutions sent.
The next S lines contains: the team name, the name of the problem (A, B, C, …),
the time when this solutions was sent and the judgment (A = Accepted, W = Wrong Solution).

In ACM ICPC, teams are ranked according to the most problems solved.
Teams who solve the same number of problems are ranked by least total time.

The total time is the sum of the time consumed for each problem solved.
The time consumed for a solved problem is the time elapsed from the beginning of
the contest to the submittal of the accepted run plus 20 penalty minutes for
every previously rejected run for that problem regardless of submittal time.
There is no time consumed for a problem that is not solved. Given the data of
the contest, you have to build the final score.
*/
#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>

using namespace std;

struct teams_t {
  string nombre;
  //errores
  int errores[10];
  int accepted = 0;
  int time = 0;
};

inline
bool operator<(const teams_t &a, const teams_t &b)
{
  if(a.accepted == b.accepted){
    return a.time < b.time;
  }else{
    return b.accepted < a.accepted;
  }
}
bool acompare(teams_t a, teams_t b) {
  return  b < a;
}


void results(teams_t teamsSolutions[],int iNumTeams){
  int iC = 1;
  std::sort(teamsSolutions,teamsSolutions+iNumTeams,acompare);
  for(int i = 0; i < iNumTeams; i++){
    std::cout <<iC<<" - "<<teamsSolutions[iNumTeams-iC].nombre<<" "<<teamsSolutions[iNumTeams-iC].accepted;
    if(teamsSolutions[iNumTeams-iC].time == 0){
      cout<<" "<<"-"<<'\n';
    }else{
      cout<<" "<<teamsSolutions[iNumTeams-iC].time<<'\n';
    }
    iC++;
  }
}


int main(int argc, char const *argv[]) {
  //string var to store the name of the team
  string nameTeam;
  //char vars to store type of problem and the judgment
  char problemName,judgment;
  //int vars to store total number of teams, total number of problems and solutions sent
  int iNumTeams = 0,iNumProb = 0 ,numSolSend = 0,times = 0;
  //Read and store number of teams and number of problems
  std::cin >> iNumTeams >> iNumProb;
  //Creates and array of objects type teams with length equal to the number of teams
  teams_t teams[iNumTeams];
  for (size_t j = 0; j < iNumTeams; j++) {
    for(int h = 0; h < iNumProb; h++){
      teams[j].errores[h] = 0;
    }
  }

  //store teams names in teams array
  for(int i = 0; i < iNumTeams; i++){
    cin>>teams[i].nombre;
  }
  //read and store number of solutions sent
  std::cin >> numSolSend;
  //loop for read the solutions sent and store the data
  for (size_t j = 0; j < numSolSend; j++) {
    //storing the name of the team that sent the solution
    cin>>nameTeam;
    //loop to find the corresponding team with the corresponding name
    for (size_t h = 0; h < iNumTeams; h++) {
      //if the name is found then store the solution data
      if(teams[h].nombre == nameTeam){
          //read and store the type of problem, the time when submitted, and the judgment
          cin>>problemName>>times>>judgment;
          //if the judgment is accepted
          if(judgment == 'A'){
            //add 1 point to the team
            teams[h].accepted++;
            teams[h].time += times;
            if(teams[h].errores[problemName-65] >= 1){
              teams[h].time += 20;
            }
          }else{
            //store the error in the error array at the ascii -65 position to store errors for diferent tipes of problems
            teams[h].errores[problemName-65]++;
          }
      }
    }
  }
  results(teams,iNumTeams);
  return 0;
}
