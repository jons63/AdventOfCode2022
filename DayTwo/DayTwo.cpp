#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

struct Opponent
{
    enum Moves
    {
        rock = 'A',
        paper = 'B',
        scissors = 'C'
    };
};

struct Player
{
    enum Moves
    {
        rock = 'X',
        paper = 'Y',
        scissors = 'Z'
    };
};

enum Outcome
{
    loose = 'X',
    draw = 'Y',
    win = 'Z'
};

int PartOne(const std::string& file)
{
    std::ifstream dataFile(file);

    if (!dataFile.is_open())
    {
        std::cerr << "Could not open input file '" << file << "'!\n";
        return EXIT_FAILURE;
    }

    std::string line;
    int score = 0;
    while (std::getline(dataFile, line))
    {
        auto opponentMove = line.substr(0, 1).c_str();
        auto* playerMove = line.substr(2).c_str();

        if (*opponentMove == Opponent::rock)
        {
            if (*playerMove == Player::rock)
            {
                score += 1+3;
            }
            else if (*playerMove == Player::paper)
            {
                score += 2+6;
            }
            else//scissors
            {
                score += 3+0;
            }
        }
        else if (*opponentMove == Opponent::paper)
        {
            if (*playerMove == Player::rock)
            {
                score += 1+0;
            }
            else if (*playerMove == Player::paper)
            {
                score += 2+3;
            }
            else//scissors
            {
                score += 3+6;
            }
        }
        else//scissors
        {
            if (*playerMove == Player::rock)
            {
                score += 1+6;
            }
            else if (*playerMove == Player::paper)
            {
                score += 2+0;
            }
            else//scissors
            {
                score += 3+3;
            }
        }
    }
    std::cout << "Final score: " << score << std::endl;
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
    int score = 0;
    while (std::getline(dataFile, line))
    {
        auto opponentMove = line.substr(0, 1).c_str();
        auto* playerMove = line.substr(2).c_str();

        if (*opponentMove == Opponent::rock)
        {
            if (*playerMove == Outcome::loose)
            {
                score += 3+0;
            }
            else if (*playerMove == Outcome::draw)
            {
                score += 1+3;
            }
            else//win
            {
                score += 2+6;
            }
        }
        else if (*opponentMove == Opponent::paper)
        {
            if (*playerMove == Outcome::loose)
            {
                score += 1+0;
            }
            else if (*playerMove == Outcome::draw)
            {
                score += 2+3;
            }
            else//win
            {
                score += 3+6;
            }
        }
        else//scissors
        {
            if (*playerMove == Outcome::loose)
            {
                score += 2+0;
            }
            else if (*playerMove == Outcome::draw)
            {
                score += 3+3;
            }
            else//win
            {
                score += 1+6;
            }
        }
    }
    std::cout << "Final score: " << score << std::endl;
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