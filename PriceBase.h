#pragma once
#include "Client.h"
#include <map>

class PriceBase {
public:
    PriceBase(const PriceBase &) = delete;
    PriceBase & operator = (const PriceBase &) = delete;
    static PriceBase & Instance() {
        static PriceBase pricebase;
        return pricebase;
    }

    WeightProduct get_product_weight_price(std::string name) {
        return m_products_weight_price.at(name); // at кидает исключение, если товара с таким названием нет
    }
    AmmountProduct get_product_ammount_price(std::string name) {
        return m_products_ammount_price.at(name);
    }

protected:
    PriceBase() = default;
private:
    std::map<std::string, ProductInfo> m_products_info = {
            { "Apple", ProductInfo("Green sweet apple") },
            { "Nuts", ProductInfo("Macadamia nut") },
            { "Pencil", ProductInfo("Red pencil with rubber") },
            { "Chair", ProductInfo("Wooden chair with armrests") },
    };
    std::map<std::string, WeightProduct> m_products_weight_price = {
            { "Apple", WeightProduct(m_products_info.at("Apple"), 11.3) },
            { "Nuts", WeightProduct(m_products_info.at("Nuts"), 34.2) },
    };
    std::map<std::string, AmmountProduct> m_products_ammount_price = {
            { "Pencil", AmmountProduct(m_products_info.at("Pencil"), 5.7) },
            { "Chair", AmmountProduct(m_products_info.at("Chair"), 75) },
    };
};
