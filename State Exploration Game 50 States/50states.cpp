#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

struct GameState {
    string name;
    long money;
    string vehicle;
};

// Retro Typewriter effect
void slowPrint(string text, int speed = 10) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Global Fact Database
map<string, vector<string>> stateDatabase;

void loadFacts() {
    ifstream file("facts.txt");
    string line, currentState;
    if (!file.is_open()) {
        slowPrint("!!! CRITICAL ERROR: facts.txt NOT FOUND !!!", 50);
        return;
    }
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line[0] == '[') { // New State header: [Wisconsin]
            currentState = line.substr(1, line.find(']') - 1);
        } else {
            stateDatabase[currentState].push_back(line);
        }
    }
    file.close();
}

void saveGame(GameState& s) {
    ofstream f("save.dat");
    f << s.name << "\n" << s.money << "\n" << s.vehicle;
}

int main() {
    srand(time(0));
    loadFacts();
    
    GameState player = {"Guest", 5000, "None"};
    ifstream load("save.dat");
    if (load.is_open()) {
        getline(load, player.name);
        load >> player.money;
        load.ignore();
        getline(load, player.vehicle);
    } else {
        slowPrint("PROMPT: ENTER PILOT IDENTIFICATION...");
        getline(cin, player.name);
    }

    vector<string> states;
    for(auto const& [name, facts] : stateDatabase) states.push_back(name);

    bool run = true;
    while (run) {
        clearScreen();
        cout << "============================================================\n";
        cout << " PILOT: " << player.name << " | CREDITS: $" << player.money << " | UNIT: " << player.vehicle << "\n";
        cout << "============================================================\n\n";
        cout << "1. TRAVEL TO SECTOR (STATE)\n2. WORK (DATA ENTRY)\n3. VEHICLE DEPOT\n4. EXIT\n\nCMD> ";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (player.vehicle == "None") { slowPrint("ERROR: PURCHASE TRANSPORT FIRST."); this_thread::sleep_for(chrono::seconds(1)); continue; }
            
            for (int i = 0; i < states.size(); i++) {
                cout << setw(2) << i + 1 << ". " << setw(15) << states[i];
                if ((i + 1) % 3 == 0) cout << endl;
            }
            cout << "\nSELECT SECTOR: ";
            int sPick; cin >> sPick;
            
            if (sPick > 0 && sPick <= states.size()) {
                string sName = states[sPick - 1];
                player.money -= 200;
                clearScreen();
                slowPrint(">>> ACCESSING " + sName + " ARCHIVES...", 30);
                // Pick a random fact from the 25 available
                vector<string>& fList = stateDatabase[sName];
                slowPrint("DATA: " + fList[rand() % fList.size()], 20);
                saveGame(player);
                cout << "\n(Press Enter to return)";
                cin.ignore(); cin.get();
            }
        } 
        else if (choice == 2) {
            slowPrint("PROCESSING...");
            player.money += 500;
            slowPrint("CREDITS EARNED: $500");
            this_thread::sleep_for(chrono::seconds(1));
        }
        else if (choice == 3) {
            cout << "1. Tesla ($50000)\n2. Donkey ($100)\nCHOICE: ";
            int v; cin >> v;
            if (v == 1 && player.money >= 50000) { player.vehicle = "Tesla"; player.money -= 50000; }
            if (v == 2 && player.money >= 100) { player.vehicle = "Donkey"; player.money -= 100; }
        }
        else if (choice == 4) run = false;
        saveGame(player);
    }
    return 0;
}