#include"Shoes.h"

Shoes::Shoes(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, unsigned int s):
    Product(sku, brand, model, color,price, cnt, Product::Type::Shoes), sz(s) {}
void Shoes::setSize(unsigned int s){
    sz=s;
}
unsigned int Shoes::getSize() const{
    return sz;
}
Shoes* Shoes::clone() const{
    return new Shoes(*this);
}
void Shoes::print(std::ostream& os) const{
    os << *this << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Shoes& s){
    os << (Product&)s;
    os << "Size: " << s.getSize() << std::endl;
    return os;
}
