#ifndef ORDER_H
#define ORDER_H
#include <QString>

class order
{
private:
    QString number;
    QString place;
    QString automobile;

public:
    order(QString number1, QString place1, QString automobile1)
    {
        number = number1;
        place = place1;
        automobile = automobile1;
    }
    ~order();
    QString getNumber()
    {
        return number;
    }
    void setNumber(QString number1)
    {
        number1 = number;

    }

    QString getPlace()
    {
        return place;
    }
    void setPlace(QString place1)
    {
        place1 = place;
    }

    QString getCar()
    {
        return automobile;
    }
    void setCar(QString automobile1)
    {
        automobile1 =automobile;
    }
    order();
};

#endif // ORDER_H
