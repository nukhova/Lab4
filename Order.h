#pragma once
#include "Position.h"
#include <vector>

class Client;

class Order {
public:
    void add_position(std::unique_ptr<Position> ptr_pos);
    double get_cost() const;
    void get_info() const;
    bool empty() { return m_ptr_positions.empty(); }
    friend Client;
private:
    void clear() { m_ptr_positions.clear(); }
    std::vector<std::unique_ptr<Position>> m_ptr_positions;
};
