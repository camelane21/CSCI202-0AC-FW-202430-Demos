#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include "linkedStack.h"
#include "drink.h"
#include "arrayStack.h"

void resetStream();
sizeType inputDrinkSize();
baseType inputDrinkBase();
tempType inputDrinkTemperature();
std::string inputDrinkFlavor();
std::string inputDrinkDairy();
bool numInRange(int num, int lower, int upper);
bool numGT0(int num, int = 0, int = 0);
bool negNum(int num, int = 0, int = 0);
int inputInt(std::string prompt, bool (*func)(int, int, int), int lower = 0, int upper = 0);

int main()
{
    std::string binStr;
    std::cout << "Enter a binary number: ";
    std::cin >> binStr;

    // Validate input: only 0s and 1s allowed
    for (char ch : binStr)
    {
        if (ch != '0' && ch != '1')
        {
            std::cout << "Binary numbers must only contain 0s and 1s." << std::endl;
            return 1;
        }
    }

    // Use a stack to store binary digits
    linkedStack<int> binary;
    for (char ch : binStr)
    {
        binary.push(ch - '0'); // Convert char to int by subtracting '0'
    }

    // Reverse the stack to match right-to-left processing for binary
    linkedStack<int> reverse;
    while (!binary.isEmptyStack())
    {
        reverse.push(binary.pop());
    }

    // Convert binary to decimal
    int decimal = 0;
    int position = 0;
    while (!reverse.isEmptyStack())
    {
        decimal += reverse.pop() * static_cast<int>(pow(2, position));
        position++;
    }

    std::cout << binStr << " is " << decimal << " in decimal." << std::endl;

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

sizeType inputDrinkSize()
{
    std::ostringstream out;

    out << "Please choose the drink size:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << sizeStr[i] << std::endl;
    }
    int drinkSize = inputInt(out.str(), numInRange, 1, 3);

    return sizes[drinkSize - 1];
}

baseType inputDrinkBase()
{
    std::ostringstream out;
    out << "Please choose the drink base:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << baseStr[i] << std::endl;
    }
    int drinkBase = inputInt(out.str(), numInRange, 1, 3);

    return bases[drinkBase - 1];
}

tempType inputDrinkTemperature()
{
    std::ostringstream out;
    int drinkTemp;
    out << "Please choose the drink temperature:" << std::endl;
    for (int i = 0; i < ENUM_NUM; i++)
    {
        out << i + 1 << ": " << tempStr[i] << std::endl;
    }
    drinkTemp = inputInt(out.str(), numInRange, 1, 3);

    return temps[drinkTemp - 1];
}

std::string inputDrinkFlavor()
{
    std::string flavor;
    std::cout << "Please enter a flavor for your drink: ";
    std::cin >> std::ws;
    std::getline(std::cin, flavor);
    return flavor;
}

std::string inputDrinkDairy()
{
    std::string dairy;
    std::cout << "What kind of dairy would you like? ";
    std::cin >> std::ws;
    std::getline(std::cin, dairy);
    return dairy;
}

int *newArray()
{
    int *list;
    int numRand = inputInt("How many numbers do you want? ", numGT0);
    list = new int[numRand];
    for (int i = 0; i < numRand; i++)
    {
        list[i] = rand() % 50 + 1;
    }
    return list;
}

bool numInRange(int num, int lower, int upper)
{
    return lower <= num && num <= upper;
}

bool numGT0(int num, int, int)
{
    return num > 0;
}

bool negNum(int num, int, int)
{
    return num < 0;
}

int inputInt(std::string prompt, bool (*func)(int, int, int), int lower, int upper)
{
    int theNum;
    std::cout << prompt;
    std::cin >> theNum;
    std::cout << std::endl;
    while (!std::cin || !func(theNum, lower, upper))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You have entered invalid data." << std::endl;
        std::cout << prompt;
        std::cin >> theNum;
        std::cout << std::endl;
    }

    return theNum;
}
