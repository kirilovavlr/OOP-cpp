#ifndef JEANS_H
#define JEANS_H
#include"Product.h"
class Jeans: public Product{
public:
    enum class Sz{
        S, M, L
    };
private:
    Sz sz;
public:
    Jeans(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, Sz sz);
    Sz getSize() const;
    void setSize(Sz s);
    Jeans* clone() const override;
    void print(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Jeans& j);
};
#endif // JEANS_H
