#include "Client.h"

bool Balance::waste_money(double money) {
    if (m_money > money && money > 0){
        m_money -= money;
        return true;
    }
    return false;
}

bool Client::pay_and_receive_order(Order & order){ // empty
    if (m_balance.waste_money(order.get_cost())){
        std::cout << "Not enough money to pay for order!" << std::endl;
        return false;
    }
    order.clear();
    std::cout << "The order is received!" << std::endl;
    return true;
}
