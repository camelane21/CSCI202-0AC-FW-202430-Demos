#include "donut.h"
#include <iostream>
#include <limits>
// x = int(input("Enter a number: "))

void something(Donut *);
void resetStream();
void codeGradeLoopFix(std::string errLocation);
std::string getIcing();
std::string getTopping(std::string);
std::string getDrizzle();

int main()
{
    Donut *d;
    Donut **order;
    int numDonuts;
    std::string ice;
    std::string top;
    std::string driz;
    std::cout << "how many donuts? " << std::endl;
    std::cin >> numDonuts;
    while (!std::cin || numDonuts < 1)
    {
        codeGradeLoopFix("Number of Donuts");
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You entered an invalid number of donuts. " << std::endl;
        std::cout << "how many donuts? " << std::endl;
        std::cin >> numDonuts;
    }
    order = new Donut *[numDonuts];
    for (int i = 0; i < numDonuts; i++)
    {
        std::cout << i + 1 << " Donut of " << numDonuts << std::endl;
        ice = getIcing();
        top = getTopping(ice);
        driz = getDrizzle();
        try
        {
            order[i] = new Donut(ice, top, driz);
            std::cout << *order[i] << std::endl;
        }
        catch (std::invalid_argument e)
        {
            std::cerr << e.what() << '\n';
            i--;
        }
    }
    std::cout << "Your order:" << std::endl;
    for (int i = 0; i < numDonuts; i++)
    {
        std::cout << *order[i] << std::endl;
        delete order[i];
    }
    delete[] order;

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation);
    }
}

std::string getIcing()
{
    std::string ice;
    std::cout << "Choose your icing from the choices below:" << std::endl;
    for (std::map<Donut::icingType, std::string>::const_iterator it = Donut::iceToStr.begin(); it != Donut::iceToStr.end(); ++it)
    {
        std::cout << it->second << std::endl;
    }
    std::cin >> std::ws;
    std::getline(std::cin, ice);
    std::string icingLower = ice;
    std::transform(icingLower.begin(), icingLower.end(), icingLower.begin(), ::tolower);
    while (!Donut::strToIce.count(icingLower))
    {
        codeGradeLoopFix("main.cpp::getIcing()");
        std::cout << ice << " is not a valid icing choice." << std::endl;
        std::cout << "Choose your icing from the choices below:" << std::endl;
        for (std::map<Donut::icingType, std::string>::const_iterator it = Donut::iceToStr.begin(); it != Donut::iceToStr.end(); ++it)
        {
            std::cout << it->second << std::endl;
        }
        std::cin >> std::ws;
        std::getline(std::cin, ice);
        icingLower = ice;
        std::transform(icingLower.begin(), icingLower.end(), icingLower.begin(), ::tolower);
    }
    return ice;
}
std::string getTopping(std::string icing)
{
    std::string top;
    std::cout << "Choose your topping from the choices below:" << std::endl;
    std::transform(icing.begin(), icing.end(), icing.begin(), ::tolower);
    if (icing == "none")
    {
        std::cout << "Cinnamon Sugar" << std::endl;
        std::cout << "Powdered Sugar" << std::endl;
        std::cout << "None" << std::endl;
    }
    else
    {
        for (auto it = Donut::topToStr.begin(); it != Donut::topToStr.end(); ++it)
        {
            std::cout << it->second << std::endl;
        }
    }
    std::cin >> std::ws;
    std::getline(std::cin, top);
    std::string topCopy = top;
    std::transform(topCopy.begin(), topCopy.end(), topCopy.begin(), ::tolower);
    if (icing == "none")
    {
        while (topCopy != "cinnamon sugar" && topCopy != "powdered sugar" && topCopy != "none")
        {
            codeGradeLoopFix("main.cpp::getTopping(\"none\")");
            std::cout << "Please choose a topping from the list" << std::endl;
            std::getline(std::cin, top);
            topCopy = top;
            std::transform(topCopy.begin(), topCopy.end(), topCopy.begin(), ::tolower);
        }
    }
    else
    {
        while (!Donut::strToTop.count(topCopy))
        {
            codeGradeLoopFix("main.cpp::getTopping()");
            std::cout << "Please choose a topping from the list" << std::endl;
            std::getline(std::cin, top);
            topCopy = top;
            std::transform(topCopy.begin(), topCopy.end(), topCopy.begin(), ::tolower);
        }
    }
    return top;
}

std::string getDrizzle()
{
    std::string drizzle;
    std::cout << "Choose your drizzle from the choices below:" << std::endl;
    for (std::map<Donut::drizzleType, std::string>::const_iterator it = Donut::drizzleToStr.begin(); it != Donut::drizzleToStr.end(); ++it)
    {
        std::cout << it->second << std::endl;
    }
    std::cin >> std::ws;
    std::getline(std::cin, drizzle);
    std::string drizzleLower = drizzle;
    std::transform(drizzleLower.begin(), drizzleLower.end(), drizzleLower.begin(), ::tolower);
    while (!Donut::strToDrizzle.count(drizzleLower))
    {
        codeGradeLoopFix("main.cpp::getDrizzle()");
        std::cout << drizzle << " is not a valid drizzle choice." << std::endl;
        std::cout << "Choose your drizzle from the choices below:" << std::endl;
        for (std::map<Donut::drizzleType, std::string>::const_iterator it = Donut::drizzleToStr.begin(); it != Donut::drizzleToStr.end(); ++it)
        {
            std::cout << it->second << std::endl;
        }
        std::cin >> std::ws;
        std::getline(std::cin, drizzle);
        drizzleLower = drizzle;
        std::transform(drizzleLower.begin(), drizzleLower.end(), drizzleLower.begin(), ::tolower);
    }
    return drizzle;
}

/* code from previous semester with dynamic array that changes size.

Donut **order;
    std::string ice;
    std::string top;
    std::string driz;
    int numDonuts = 0;
    order = new Donut *[numDonuts];
    int num = 0;
    while (true)
    {
        ice = getIcing();
        top = getTopping(ice);
        driz = getDrizzle();
        Donut **orderCpy;
        orderCpy = new Donut *[numDonuts];
        for (int i = 0; i < numDonuts; i++)
        {
            orderCpy[i] = new Donut(*order[i]);
            delete order[i];
        }
        numDonuts++;
        delete[] order;
        order = new Donut *[numDonuts];
        for (int i = 0; i < numDonuts - 1; i++)
        {
            order[i] = new Donut(*orderCpy[i]);
            delete orderCpy[i];
        }
        delete[] orderCpy;
        try
        {
            order[numDonuts - 1] = new Donut(ice, top, driz);
        }
        catch (std::invalid_argument e)
        {
            std::cout << e.what();
            break;
        }
        char again = 'Y';
        std::cout << "Would you like to order more donuts (Y or N)? ";
        std::cin >> again;
        again = toupper(again);
        if (again == 'N')
        {
            break;
        }
    }
    for (int i = 0; i < numDonuts; i++)
    {
        std::cout << order[i]->toString() << std::endl;
    }
    for (int i = 0; i < numDonuts; i++)
    {
        delete order[i];
    }
    delete[] order;
    return 0;

*/
