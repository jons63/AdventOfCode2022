#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <numeric>

#define index(c) (((c) < 97) ? (c) - 38 : (c) - 96)

int PartOne(const std::string& file)
{
    std::ifstream dataFile(file);

    if (!dataFile.is_open())
    {
        std::cerr << "Could not open input file '" << file << "'!\n";
        return EXIT_FAILURE;
    }

    std::string line;
    std::vector<int> commonItems;

    while (std::getline(dataFile, line))
    {
        std::array<int, 53> compartmentOneItems = {0};
        std::array<int, 53> compartmentTwoItems = {0};

        std::string compartmentOne = line.substr(0,line.length()/2);
        for (const char c : compartmentOne)
        {
            compartmentOneItems[index(c)]++;
        }

        std::string compartmentTwo = line.substr(line.length()/2);
        for (const char c : compartmentTwo)
        {
            compartmentTwoItems[index(c)]++;
        }

        for (int i = 0 ; i < compartmentOneItems.size(); i++)
        {
            if (compartmentOneItems[i] && compartmentTwoItems[i])
            {
                commonItems.push_back(i);
                break;
            }
        }
    }

    std::cout << "Sum of common items: " << std::accumulate(commonItems.begin(), commonItems.end(), 0) << std::endl;
    dataFile.close();
    return 0;
}

int PartTwo(const std::string& file)
{
    std::ifstream dataFile(file);

    if (!dataFile.is_open())
    {
        std::cerr << "Could not open input file '" << file << "'!\n";
        return EXIT_FAILURE;
    }

    std::string line;
    std::vector<int> commonItems;
    std::string memberOneBackpack;
    std::string memberTwoBackpack;
    std::string memberThreeBackpack;
    int teamMemberCount = 0;

    while (std::getline(dataFile, line))
    {
        teamMemberCount++;
        if ((teamMemberCount % 3) == 1)
        {
            memberOneBackpack = line;
            continue;
        }
        else if ((teamMemberCount % 3) == 2)
        {
            memberTwoBackpack = line;
            continue;
        }
        else
        {
            memberThreeBackpack = line;
        }

        std::array<int, 53> memberOneItems = {0};
        std::array<int, 53> memberTwoItems = {0};
        std::array<int, 53> memberTreeItems = {0};

        for (const char c : memberOneBackpack)
        {
            memberOneItems[index(c)]++;
        }

        for (const char c : memberTwoBackpack)
        {
            memberTwoItems[index(c)]++;
        }

        for (const char c : memberThreeBackpack)
        {
            memberTreeItems[index(c)]++;
        }

        for (int i = 0 ; i < memberOneItems.size(); i++)
        {
            if (memberOneItems[i] && memberTwoItems[i] && memberTreeItems[i])
            {
                commonItems.push_back(i);
                break;
            }
        }
    }

    std::cout << "Sum of common items: " << std::accumulate(commonItems.begin(), commonItems.end(), 0) << std::endl;
    dataFile.close();
    return 0;
}

int main(int argc, char *argv[])
{

    if (argc < 2) {
        std::cerr << "Missing input file!\n";
        return EXIT_FAILURE;
    }

    PartOne(argv[1]);
    PartTwo(argv[1]);
}