#ifndef SHOES_H
#define SHOES_H
#include"Product.h"
class Shoes: public Product{
    unsigned int sz;
public:
    Shoes(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, unsigned int s);
    void setSize(unsigned int s);
    unsigned int getSize() const;
    Shoes* clone() const override;
    void print(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Shoes& s);
};
#endif
