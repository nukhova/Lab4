#pragma once
#include "Client.h"
#include <map>

class PriceBase {
public:
    PriceBase(const PriceBase&) = delete;
    PriceBase& operator =(const PriceBase&) = delete;
    static PriceBase& Instance() {
        static PriceBase pricebase;
        return pricebase;
    }

    WeightProduct get_product_weight_price(std::string name) {
        return m_products_weight_price.at(name);
    }
    AmmountProduct get_product_ammount_price(std::string name) {
        return m_products_ammount_price.at(name);
    }

protected:
    PriceBase() = default;
private:
    std::map<std::string, ProductInfo> m_products_info;
    std::map<std::string, WeightProduct> m_products_weight_price;
    std::map<std::string, AmmountProduct> m_products_ammount_price;
};
