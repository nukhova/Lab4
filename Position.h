#pragma once
#include "Product.h"

class Position {
public:
    Position(Product * product) :m_ptr_product(product) {}
    ~Position() { delete m_ptr_product; }
    Product * get_ptr_product() { return m_ptr_product;}
    virtual double get_cost() const = 0;
    virtual double get_quantity() const = 0;
protected:
    Product * m_ptr_product;
};

class AmmountPosition: public Position {
public:
    AmmountPosition(AmmountProduct * product, const size_t ammount) : Position(product), m_ammount(ammount) {}
    double get_cost() const { return m_ptr_product->get_cost(); }
    double get_quantity() const { return m_ammount; }
private:
    size_t m_ammount;
};

class WeightPosition: public Position {
public:
    WeightPosition(WeightProduct * product, const double weight) :Position(product), m_weight(weight) {}
    double get_cost() const { return m_ptr_product->get_cost(); }
    double get_quantity() const { return m_weight; }
private:
    double m_weight;
};
