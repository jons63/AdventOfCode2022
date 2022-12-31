#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <list>

#define NUMBER_OF_STACKS 9

void PrintStacks(const std::array<std::list<char>, NUMBER_OF_STACKS>& stacks)
{
    for (int i = 0; i < NUMBER_OF_STACKS; i++)
    {
        for (auto j = stacks[i].begin(); j != stacks[i].end(); j++)
        {
            std::cout << "Stack " << i+1 << " contains " << *j << std::endl;
        }
    }
}

int PartOne(const std::string& file)
{
    std::ifstream dataFile(file);

    if (!dataFile.is_open())
    {
        std::cerr << "Could not open input file '" << file << "'!\n";
        return EXIT_FAILURE;
    }
    bool allStackDocumented = false;
    std::array<std::list<char>, NUMBER_OF_STACKS> stacks;
    std::string line;
    while (std::getline(dataFile, line))
    {

        if (line.empty())
        {
            allStackDocumented = true;
        }
        else if (line.data()[1] == '1')
        {
            continue;
        }
        else if (allStackDocumented)
        {
            size_t from = line.find("from");
            size_t to = line.find("to");
            int boxesToMove = std::stoi(line.substr(5, from-6));
            int fromStack = std::stoi(line.substr(from+5, to-from-6))-1;
            int toStack = std::stoi(line.substr(to+3))-1;

            for (int i = 0; i < boxesToMove; i++)
            {
                stacks[toStack].push_front(std::move(stacks[fromStack].front()));
                stacks[fromStack].pop_front();
            }
        }
        else
        {
            for (int i = 0; i < NUMBER_OF_STACKS; i++)
            {
                if (line.data()[i*4+1] != ' ')
                {
                    stacks[i].push_back(line.data()[i*4+1]);
                }
                std::cout << line.data()[i*4+1] << std::endl;
            }
        }
    }

    for (int i = 0; i < NUMBER_OF_STACKS; i++)
    {
        std::cout << stacks[i].front();
    }

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

    bool allStackDocumented = false;
    std::array<std::list<char>, NUMBER_OF_STACKS> stacks;
    std::string line;
    while (std::getline(dataFile, line))
    {

        if (line.empty())
        {
            allStackDocumented = true;
        }
        else if (line.data()[1] == '1')
        {
            continue;
        }
        else if (allStackDocumented)
        {
            size_t from = line.find("from");
            size_t to = line.find("to");
            int boxesToMove = std::stoi(line.substr(5, from-6));
            int fromStack = std::stoi(line.substr(from+5, to-from-6))-1;
            int toStack = std::stoi(line.substr(to+3))-1;

            auto it = stacks[fromStack].begin();
            std::advance(it, boxesToMove);

            stacks[toStack].splice(
                stacks[toStack].begin(),
                stacks[fromStack],
                stacks[fromStack].begin(),
                it);
        }
        else
        {
            for (int i = 0; i < NUMBER_OF_STACKS; i++)
            {
                if (line.data()[i*4+1] != ' ')
                {
                    stacks[i].push_back(line.data()[i*4+1]);
                }
                std::cout << line.data()[i*4+1] << std::endl;
            }
        }
    }

    for (int i = 0; i < NUMBER_OF_STACKS; i++)
    {
        std::cout << stacks[i].front();
    }

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