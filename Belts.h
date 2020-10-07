#ifndef BELTS_H
#define BELTS_H
#include"Product.h"
class Belts: public Product{
    unsigned int length;
public:
    Belts(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, unsigned int len);
    void setLen(unsigned int len);
    unsigned int getLen() const;
    Belts* clone() const override;
    void print(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Belts& b);
};

#endif
