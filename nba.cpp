#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NBATeams {

    private:
     string teamName;
     string coachName;
     int numPlayers;
     string teamHome;
     int FGPercent;

    public:
        NBATeams() {}

        NBATeams(string setTeamName, string setCoachName, int setNumPlayers, string setTeamHome, int setFGPercent) {
            teamName = setTeamName;
            coachName = setCoachName;
            numPlayers = setNumPlayers;
            teamHome = setTeamHome;
            FGPercent = setFGPercent;
        }

        // Destroy this class: 
        ~NBATeams(){};

        void setTeamName(string setTeamName) {
            teamName = setTeamName;
        }

        string getTeamName() {
            return teamName;
        }

        void toString() {
            cout << "Team Name: " << teamName << endl;
            cout << "Coach Name: " << coachName << endl;
            cout << "Number of Players: " << numPlayers << endl;
            cout << "Home Court: " << teamHome << endl;
            cout << "Field Goal Percentage: " << FGPercent << "%" << endl;
        }

};

class NBAPlayers : public NBATeams {

    private:
        string playerName;
        int jerseyNum;
        NBATeams nbaTeams; // Composition relationship with NBATeams
    
    public:
        NBAPlayers(string setPlayerName, int setJerseyNum, NBATeams setTeam) {
            playerName = setPlayerName;
            jerseyNum = setJerseyNum;

            nbaTeams.setTeamName(setTeam.getTeamName()); 

        }

    void toString() {
        NBATeams::toString(); // Call the base class toString method
        cout << "Player Name: " << playerName << endl;
        cout << "Jersey Number: " << jerseyNum << endl;
        cout << "Team Name: " << nbaTeams.getTeamName() << endl; // Call the base class method to get team name
    }

};




int main () {

    // NBA Teams
    NBATeams Grizzlies( "Memphis Grizzlies" , "J.R" , 15, "FedEx Forum", 40 ) ;
    NBATeams Lakers ("Los Angeles Lakers", "JJ Reddick", 15, "Crypto", 10 );
    
    // NBA Players
    NBAPlayers Chris("Chris", 19, Grizzlies);
    NBAPlayers Abu("Abu", 26, Grizzlies);
    NBAPlayers LeBum ("Lebum James", 23, Lakers);

    vector<NBAPlayers> playerList = {Chris, Abu, LeBum};
    vector<NBATeams> teamList = {Lakers, Grizzlies};

    // Call the toString method to display the team information
    // Grizzlies.toString();
    // Chris.toString();
    // Abu.toString();

}