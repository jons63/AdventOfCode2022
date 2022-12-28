#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Missing input file!\n";
        return EXIT_FAILURE;
    }

    std::ifstream dataFile(argv[1]);

    if (!dataFile.is_open())
     {
        std::cerr << "Could not open input file '" << argv[1] << "'!\n";
        return EXIT_FAILURE;
     }

    int elf = 0;
    std::vector<int> elves = {};
    std::string line;

    while (std::getline(dataFile, line))
    {
        if (!line.empty())
        {
            elf += std::stoi(line);
        }
        else
        {
            elves.push_back(elf);  
            elf = 0;
        }
    }

    dataFile.close();

    std::sort(elves.begin(), elves.end(), std::greater<int>());
    
    std::cout << "The top three elves are carrying:\n" 
    << "    " << elves[0] << " calories\n"
    << "    " << elves[1] << " calories\n"
    << "    " << elves[2] << " calories\n"
    << "and combined they are carrying " 
    << elves[0]+elves[1]+elves[2] << " calories" << std::endl;
}