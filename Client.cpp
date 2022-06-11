#include "Client.h"

bool Balance::waste_money(double money) {
    if (m_money > money){
        m_money -= money;
        return true;
    }
    return false;
}

bool Client::pay_and_receive_order(Order & order){
    if (order.get_cost() > m_balance.get_money()){
        std::cout << "Not enough money to pay for order!" << std::endl;
        return false;
    }
    order.clear();
    std::cout << "The order is received!" << std::endl;
    return true;
}
