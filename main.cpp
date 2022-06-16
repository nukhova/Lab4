#include <iostream>
#include "PriceBase.h"

int main() {

    Order order;
    std::cout << std::boolalpha << "Is the order empty?" << order.empty() << std::endl;

    auto u_ptr_apple = WeightPosition(new WeightProduct(ProductInfo("Green sweet apple"), 11.3), 0.5);
    auto u_ptr_pencil = AmmountPosition(new AmmountProduct(ProductInfo("Red pencil with rubber"), 5.7), 2);
    order.add_position(std::make_unique<WeightPosition>(std::move(u_ptr_apple)));
    order.add_position(std::make_unique<AmmountPosition>(std::move(u_ptr_pencil)));

    auto u_ptr_apple2 = WeightPosition(new WeightProduct(ProductInfo("Green sweet apple"), 11.3), 1.5);
    order.add_position(std::make_unique<WeightPosition>(std::move(u_ptr_apple2)));

    Client Ivan;

    order.get_info();

    Ivan.pay_and_receive_order(order);

    Ivan.earn_money(500);
    Ivan.pay_and_receive_order(order);

    return 0;
}
