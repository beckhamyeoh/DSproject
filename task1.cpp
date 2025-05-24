#include <unordered_map>
#include <iostream>

using namespace std;

struct Player{
    string first_name;
    string last_name;
    string team;
};

vector<Player> FindDupes (vector<Player> basketball, vector<Player> football){
    unordered_map<string, Player> player_map;
    for (Player p : basketball){
        player_map.insert({p.first_name + " " + p.last_name, p});
    }
    
    vector<Player> temp;
    for (int i = 0; i < football.size(); i++){
        auto find = player_map.find(football.at(i).first_name + " " + football.at(i).last_name);
        if (find != player_map.end()){
            temp.push_back(football.at(i));
        }
    }
    return temp;
    
};

int main() {
    vector<Player> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };
    
    vector<Player> football_players = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };
    
    vector<Player> dupes = FindDupes(basketball_players, football_players);
    
    for (Player p : dupes) cout << p.first_name << " " << p.last_name << endl;
    
    return 0;
}
