#include"Belts.h"

Belts::Belts(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, unsigned int len):
    Product(sku, brand, model, color,price, cnt, Product::Type::Belts), length(len) {}
void Belts::setLen(unsigned int len){
    length=len;
}
unsigned int Belts::getLen() const{
    return length;
}
Belts* Belts::clone() const{
    return new Belts(*this);
}
void Belts::print(std::ostream& os) const{
    os << *this << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Belts& b){
    os << (Product&)b;
    os << "Length: " << b.getLen() << std::endl;
    return os;
}
