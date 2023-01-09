#include <fstream>
#include <iostream>
#include <string>
#include <array>

int PartOne(const std::string& file)
{
    std::ifstream dataFile(file);

    if (!dataFile.is_open())
    {
        std::cerr << "Could not open input file '" << file << "'!\n";
        return EXIT_FAILURE;
    }

    std::string line;
    if (std::getline(dataFile, line))
    {
        auto it = line.begin();
        for (auto i = 0; i < line.size(); i++)
        {
            int charBitmap = 0;
            bool fourUniqueCharacters = true;
            std::string::iterator it2;
            for (auto j = i; j < i+4; j++)
            {
                if (charBitmap & 1 << int(line[j]))
                {
                    fourUniqueCharacters = false;
                }
                else
                {
                    charBitmap += 1 << int(line[j]);
                }
            }
            if (fourUniqueCharacters)
            {
                std::cout << "Number of characters: " << i+4 << "\n";
                break;
            }
            it++;
        }
    }
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
    if (std::getline(dataFile, line))
    {
        auto it = line.begin();
        for (auto i = 0; i < line.size(); i++)
        {
            int charBitmap = 0;
            bool fourUniqueCharacters = true;
            std::string::iterator it2;
            for (auto j = i; j < i+14; j++)
            {
                if (charBitmap & 1 << int(line[j]))
                {
                    fourUniqueCharacters = false;
                }
                else
                {
                    charBitmap += 1 << int(line[j]);
                }
            }
            if (fourUniqueCharacters)
            {
                std::cout << "Number of characters: " << i+14 << "\n";
                break;
            }
            it++;
        }
    }
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