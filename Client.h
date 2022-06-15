#pragma once
#include "Order.h"

class Balance {
public:
    void add_money(double money) { m_money += money; }
    bool waste_money(double money);
    double get_money() const { return m_money; }
private:
    double m_money = 0;
};

class Client {
public:
    void earn_money(double money) { m_balance.add_money(money); }
    bool pay_and_receive_order(Order & order);
private:
    Balance m_balance;
};
