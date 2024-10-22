// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Find relatives in list of names
bool find_relatives(std::vector<std::vector<std::string>> names){
    std::string surnameBeingSearched;

    for (size_t i = 0; i < names.size(); i++)
    {
        surnameBeingSearched = names[i][1];
        for (size_t j = i+1; j < names.size(); j++)
        {
            std::string newSurname = names[j][1];
            if (newSurname == surnameBeingSearched)
            {
                std::cout << "Relatives found!\n";
                std::cout << names[i][0] << " " << names[i][1] << " and " << names[j][0] << " " << names[j][1] << " are related!\n";
                return true;
            }
        }
    }

    return false;
}

// Return a vector of string components from the original string
std::vector<std::vector<std::string>> get_names(std::string str){
    // Create initial 1D vector of data from CSV
    std::vector<std::string> names1D;
    std::string word;

    // Replace commas with spaces
    for (char& c : str) {
        if (c == ',') {
            c = ' ';
        }
    }

    // Use stringstream to split based on spaces
    std::stringstream ss(str);
    while (ss >> word) {
        names1D.push_back(word);
    }

    // Transform it to 2D of [first name][surname]
    std::vector<std::vector<std::string>> names;
    names.resize(names1D.size() / 2);
    for (size_t i = 0; i < names.size(); i++)
    {
        names[i].resize(2);
    }
    for (size_t i = 0; i < names1D.size(); i++)
    {
        int r = i / 2;
        int c = i % 2;
        names[r][c] = names1D[i];
    }

    return names;
}

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::string line;
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    if(file.is_open()){

        getline(file, line);
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Split the line into individual names
    std::vector<std::vector<std::string>> names = get_names(line);

    if (!find_relatives(names))
    {
        std::cout << "No relatives found.\n\n" << std::flush;  
    }  
    return 0;
}
 