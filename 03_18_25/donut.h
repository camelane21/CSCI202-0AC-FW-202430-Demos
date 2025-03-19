#ifndef DONUT_H
#define DONUT_H
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Donut
{
public:
    enum icingType
    {
        CHOCOLATEICING,
        CARAMELICING,
        MAPLE,
        VANILLA,
        GLAZE,
        SPECIALICE,
        NOICE
    };
    enum toppingType
    {
        RAINBOWSPR,
        CHOCOLATESPR,
        PEANUTS,
        COCONUT,
        OREO,
        BACON,
        GRAHAM,
        FRUITYPEBBLES,
        REESESPIECES,
        MMS,
        CANDYBAR,
        CHOCOLATECHIPS,
        SEASALT,
        CINSUGAR,
        POWDSUGAR,
        NOTOP
    };
    enum drizzleType
    {
        CARAMELDRIZZLE,
        CHOCOLATEDRIZZLE,
        PEANUTBUTTER,
        RASPBERRY,
        SPECIALDRIZZLE,
        NODRIZZLE
    };
    const static std::map<toppingType, std::string> topToStr;
    const static std::map<icingType, std::string> iceToStr;
    const static std::map<drizzleType, std::string> drizzleToStr;
    const static std::map<std::string, toppingType> strToTop;
    const static std::map<std::string, icingType> strToIce;
    const static std::map<std::string, drizzleType> strToDrizzle;

    Donut(std::string icing, std::string topping, std::string drizzle);
    icingType getIcing() const;
    toppingType getTopping() const;
    drizzleType getDrizzle() const;
    std::string toString() const;
    void setIcing(std::string);
    void setTopping(std::string);
    void setDrizzle(std::string);
    friend std::ostream &operator<<(std::ostream &, const Donut &);

private:
    toppingType topping;
    icingType icing;
    drizzleType drizzle;
};

#endif