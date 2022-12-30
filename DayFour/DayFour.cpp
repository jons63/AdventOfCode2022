#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void FindIntersect(
    std::vector<int>& v_intersection,
    std::vector<int>& sectionOne,
    std::vector<int>& sectionTwo,
    std::string line)
{
    std::size_t start = 0;
    std::size_t end = line.find("-");
    const int sectionOneStart = std::stoi(line.substr(start,end));
    start = end+1;
    end = line.find(",", start);
    const int sectionOneEnd = std::stoi(line.substr(start,end));
    start = end+1;
    end = line.find("-", start);
    const int sectionTwoStart = std::stoi(line.substr(start,end));
    start = end+1;
    end = line.find(",", start);
    const int sectionTwoEnd = std::stoi(line.substr(start,end));

    for (int i = sectionOneStart; i < sectionOneEnd+1; i++)
    {
        sectionOne.push_back(i);
    }

    for (int i = sectionTwoStart; i < sectionTwoEnd+1; i++)
    {
        sectionTwo.push_back(i);
    }

    std::set_intersection(sectionOne.begin(), sectionOne.end(),
        sectionTwo.begin(), sectionTwo.end(),
        std::back_inserter(v_intersection));
}

int PartOne(const std::string& file)
{
    std::ifstream dataFile(file);

    if (!dataFile.is_open())
    {
        std::cerr << "Could not open input file '" << file << "'!\n";
        return EXIT_FAILURE;
    }

    int numberOfFullOverlaps = 0;
    std::string line;
    while (std::getline(dataFile, line))
    {
        std::vector<int> v_intersection;
        std::vector<int> sectionOne;
        std::vector<int> sectionTwo;
        FindIntersect(v_intersection, sectionOne, sectionTwo, line);
        if (v_intersection == sectionOne || v_intersection == sectionTwo)
        {
            numberOfFullOverlaps++;
        }
    }

    std::cout << "Number of complete overlaps was: " << numberOfFullOverlaps << std::endl;


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
    int numberOfFullOverlaps = 0;
    std::string line;
    while (std::getline(dataFile, line))
    {
        std::vector<int> v_intersection;
        std::vector<int> sectionOne;
        std::vector<int> sectionTwo;
        FindIntersect(v_intersection, sectionOne, sectionTwo, line);

        if (!v_intersection.empty())
        {
            numberOfFullOverlaps++;
        }
    }

    std::cout << "Number of partial overlaps was: " << numberOfFullOverlaps << std::endl;
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