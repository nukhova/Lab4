#include "Order.h"

void Order::add_position(std::unique_ptr<Position> ptr_pos) {
    size_t t = 1;
    for (const auto & position: m_ptr_positions) {
        if (position->get_ptr_product()->get_info() == ptr_pos->get_ptr_product()->get_info())
            t = 0;
    }
    if (t) m_ptr_positions.push_back(ptr_pos);
}

double Order::get_cost(){
    double cost = 0;
    for (const auto & position: m_ptr_positions) {
        cost += position->get_cost();
    }
    return cost;
}

void Order::get_info(){
    for (const auto & position: m_ptr_positions) {
        std::cout << position->get_ptr_product()->get_info() << std::endl;
        std::cout << "Quantity: " << position->get_quantity() << std::endl;
        std::cout << "Cost: " << position->get_cost() << std::endl;
    }
}
