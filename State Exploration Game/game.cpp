#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <string>
#include <vector>


 // Seed random number generator



std::vector<std::string> wisconsinFacts = {
        "Wisconsin produces about 25% of all the cheese in the United States.",
        "The nickname 'The Badger State' comes from 1820s miners who lived in 'badger dens' dug into hills.",
        "The very first kindergarten in the United States was opened in Watertown, Wisconsin, in 1856.",
        "Wisconsin is the Cranberry Capital of the world, producing over half of the global supply.",
        "There are more than 15,000 lakes in Wisconsin, including borders with two Great Lakes.",
        "Lambeau Field in Green Bay is the oldest continually operating stadium in the NFL.",
        "Harley-Davidson motorcycles were founded in a small wooden shed in Milwaukee in 1903.",
        "Two different Wisconsin cities claim to have invented the ice cream sundae in the late 1800s.",
        "Neenah, Wisconsin is known as the 'Paper Capital of the World' for its long history of manufacturing.",
        "The American Water Spaniel is the official state dog and was developed specifically in Wisconsin."
};

std::vector<std::string> illinoisFacts = {
        "Illinois was the first state in the U.S. to ratify the 13th Amendment, which abolished slavery.",
        "The world's first modern skyscraper, the Home Insurance Building, was built in Chicago in 1885.",
        "The nickname 'Land of Lincoln' comes from the fact that Abraham Lincoln lived and worked here for 31 years.",
        "Morton, Illinois, is known as the 'Pumpkin Capital of the World,' processing 85% of the world's canned pumpkin.",
        "Twinkies were invented in Schiller Park, Illinois, in 1930 during the Great Depression.",
        "The Chicago River is the only river in the world that was permanently made to flow backwards by engineers.",
        "The world's largest public library, the Harold Washington Library Center, is located in Chicago.",
        "Illinois is the leading producer of nuclear power in the United States.",
        "Walt Disney, the creator of Mickey Mouse, was born in Chicago in 1901.",
        "The official state snack food of Illinois is popcorn!"
};

std::vector<std::string> minnesotaFacts = {
        "Minnesota is known as the 'Land of 10,000 Lakes,' but it actually has 11,842 lakes over 10 acres in size.",
        "The Mall of America in Bloomington is so large it could fit 78 football fields inside.",
        "Water skiing was invented in 1922 on Lake Pepin by 18-year-old Ralph Samuelson.",
        "Minnesota is the birthplace of many famous inventions, including Scotch Tape, Post-it Notes, and the stapler.",
        "The source of the mighty Mississippi River is located in Minnesota at Lake Itasca.",
        "The name 'Minnesota' comes from the Dakota Sioux word 'Mnisota,' meaning 'sky-tinted water.'",
        "Minnesota produces more turkeys each year than any other state in the country.",
        "The first open-heart surgery and the first bone marrow transplant in the U.S. were performed in Minnesota.",
        "Minneapolis has the world's longest skyway system, connecting over 70 city blocks for indoor walking.",
        "The official state bird is the Common Loon, which is known for its haunting, beautiful call."
};

std::vector<std::string> iowaFacts = {
        "Iowa's nickname 'The Hawkeye State' is a tribute to the Sauk leader, Chief Black Hawk.",
        "The machine that creates sliced bread was invented by Otto Rohwedder in Davenport, Iowa.",
        "Iowa is the top corn-producing state in the U.S., growing billions of bushels annually.",
        "It is the only state whose east and west borders are formed entirely by navigable rivers.",
        "The movie 'Field of Dreams' was filmed in Dyersville; the baseball field is still a tourist site.",
        "Pigs outnumber people in Iowa! There are roughly 7 pigs for every 1 human resident.",
        "Riverside, Iowa is the 'official' future birthplace of Star Trek's Captain James T. Kirk.",
        "Iowa has one of the highest literacy rates in the nation, often reaching 99%.",
        "Burlington, Iowa is home to Snake Alley, one of the most crooked streets in the world.",
        "The modern trampoline was invented in 1930 at the University of Iowa."
};

std::vector<std::string> michiganFacts = {
        "Michigan is the only U.S. state made up of two distinct peninsulas.",
        "It is the only state that borders four of the five Great Lakes.",
        "Michigan has over 3,200 miles of freshwater coastline—the most in the world.",
        "Motor vehicles are banned on Mackinac Island; people use horses or bikes.",
        "Detroit is known as the 'Motor City' for its massive role in the auto industry.",
        "Battle Creek is the 'Cereal Capital of the World' and home to Kellogg's.",
        "Michigan has the world's only floating post office, the J.W. Westcott II.",
        "Though nicknamed 'The Wolverine State,' wolverines are not found in its wilds.",
        "Colon, Michigan is officially known as the 'Magic Capital of the World.'",
        "No matter where you are in Michigan, you are never more than 6 miles from water."
};




using namespace std;

// A small function to print a dramatic pause (optional)
void pauseLine() {
    cout << "...\n";
}

void clearScreen() {
#ifdef _WIN32 // Check if compiling on Windows
    cout << "\033[2J\033[1;1H";
#else // Assume Unix-based if not Windows
    system("clear");
#endif
}

void mainGame()
{
    srand(time(0));
    
    std::srand(static_cast<unsigned int>(std::time(0)));

    string name;
    int state;
    int vehicle;
    int money;
    int WIFact = std::rand() % wisconsinFacts.size();
    int MNFact = std::rand() % minnesotaFacts.size();
    int ILFact = std::rand() % illinoisFacts.size();
    int IAFact = std::rand() % iowaFacts.size();
    int MIFact = std::rand() % michiganFacts.size();
    char playagain;
    char anotherfact;
    char factfromsamestate;

    
    clearScreen();
        cout << "Welcome! My name is Fred and I will guide you on your journey through the states. Can I please have your name?\n";
        cin >> name;
        cout << "\n";

        money = 150000;
        
        cout << "Well hello, " << name << ", pick the vehicle you want to take on this journey through the states!\n";
        cout << "You you have $" << money << " dollars to start with.\n";
        cout << "1. Tesla Model X $90,000\n";
        cout << "2. Tesla Cybertruck $50,000\n";
        cout << "3. Mercedes Benz $45,000\n";
        cout << "4. GMC Acadia $35,000\n";
        cout << "5. Toyota Camry $25,000\n";
        cout << "6. Donkey $5,000\n";
        cin >> vehicle;
        if (vehicle != 1 && vehicle != 2 && vehicle != 3 && vehicle != 4 && vehicle != 5 && vehicle != 6 && vehicle != 7) {
                clearScreen();
                cout << "Please enter a valid vehicle!\n";
                cin >> vehicle;
        }
        if (vehicle == 1) {
            money = money - 90000;
        }
        else if (vehicle == 2) {
            money = money - 50000;
        }
        else if (vehicle == 3) {
            money = money - 45000;
        }
        else if (vehicle == 4) {
            money = money - 35000;
        }
        else if (vehicle == 5) {
            money = money - 25000;
        }
        else if (vehicle == 6) {
            money = money - 5000;
        }
        pauseLine();
        cout << "You have $" << money << " dollars.\n";
        pauseLine();
        cout << "\n";
    
        cout << "Choose what U.S. state we should explore!\n";
        cout << "1. Wisconsin\n";
        cout << "2. Minnesota\n";
        cout << "3. Illinois\n";
        cout << "4. Iowa\n";
        cout << "5. Michigan\n";
        cout << "Enter 1, 2, 3, 4, or 5: ";
        cin >> state;

        if (state > 5) {
            cout << "Please Choose a listed state!\n";
            pauseLine();
            cout << "Enter 1, 2, 3, 4, or 5!\n";
            cin >> state;
        }
        
        pauseLine();
        


        if (state == 1)
        {
            std::cout << wisconsinFacts[WIFact] << "\n";
        }
        else if (state == 2)
        {
            std::cout << minnesotaFacts[MNFact] << "\n";
        }
        else if (state == 3)
        {
            std::cout << illinoisFacts[ILFact] << "\n";
        }
        else if (state == 4)
        {
            std::cout << iowaFacts[IAFact] << "\n";
        }
        else if (state == 5)
        {
            std::cout << michiganFacts[MIFact] << "\n";
        }
        pauseLine();
        std::cout << "Do you want to hear more facts? (y/n)\n";
        std::cin >> anotherfact;
        if (anotherfact == 'y' || anotherfact == 'Y')
        {
            std::cout << "Would you like a fact from the same state? (y/n)\n";
            std::cin >> factfromsamestate;
            if (factfromsamestate == 'y' || factfromsamestate == 'Y')
            {
                //Reload the random Facts to pick a new one
                WIFact = std::rand() % wisconsinFacts.size();
                MNFact = std::rand() % minnesotaFacts.size();
                ILFact = std::rand() % illinoisFacts.size();
                IAFact = std::rand() % iowaFacts.size();
                MIFact = std::rand() % michiganFacts.size();
                if (state == 1)
                {
                    std::cout << wisconsinFacts[WIFact] << "\n";
                }
                else if (state == 2)
                {
                    std::cout << minnesotaFacts[MNFact] << "\n";
                }
                else if (state == 3)
                {
                    std::cout << illinoisFacts[ILFact] << "\n";
                }
                else if (state == 4)
                {
                    std::cout << iowaFacts[IAFact] << "\n";
                }
                else if (state == 5)
                {
                    std::cout << michiganFacts[MIFact] << "\n";
                }
            }
            else
            {
                //add logic to ask for what state
            }
        }

        
        pauseLine();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playagain;
        clearScreen();
}


int main()
{
    mainGame();
    return 0;
}