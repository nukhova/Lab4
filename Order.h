#pragma once
#include "Position.h"
#include <vector>

class Client;

class Order {
public:
    void add_position(Position* ptr_pos);
    double get_cost();
    void get_info();
    bool empty() { return m_ptr_positions.empty(); }
    friend Client;
private:
    void clear() { m_ptr_positions.clear(); }
    std::vector<Position*> m_ptr_positions;
};
