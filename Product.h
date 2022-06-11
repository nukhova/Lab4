#pragma once
#include <iostream>

class ProductInfo {
public:
    ProductInfo(const std::string & info = {}) :m_info(info) {}
    std::string get_info() const { return m_info; }
private:
    std::string m_info;
};

class Product {
public:
    Product(const ProductInfo & product_info) :m_product_info(product_info) {}
    ~Product() = default;
    virtual std::string get_info() const = 0;
    virtual double get_cost() const = 0;
protected:
    ProductInfo m_product_info;
private:
};

class WeightProduct: public Product {
public:
    WeightProduct(const ProductInfo & product_info, const double cost) : Product(product_info), m_cost_per_kg(cost) {}
    std::string get_info() const { return get_info() + " : " + std::to_string(m_cost_per_kg) + " per kg"; }
    double get_cost() const { return m_cost_per_kg; }
private:
    double m_cost_per_kg;
};

class AmmountProduct: public Product {
public:
    AmmountProduct(const ProductInfo & product_info, const double cost) : Product(product_info), m_cost_per_one(cost) {}
    std::string get_info() const { return get_info() + " : " + std::to_string(m_cost_per_one) + " per one"; }
    double get_cost() const { return m_cost_per_one; }
private:
    double m_cost_per_one;
};
