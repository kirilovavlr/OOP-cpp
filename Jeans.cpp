#include"Jeans.h"

Jeans::Jeans(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, Sz sz):
    Product(sku, brand, model, color, price, cnt, Product::Type::Jeans), sz(sz) {}
Jeans::Sz Jeans::getSize() const{
    return sz;
}
void Jeans::setSize(Sz s){
    sz=s;
}
Jeans* Jeans::clone() const{
    return new Jeans(*this);
}
void Jeans::print(std::ostream& os) const{
    os << *this << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Jeans& j){
    os << (Product&)j;
    int s=(int)j.getSize();
    os << "Size: ";
    switch(s){
        case 0: os << "S"; break;
        case 1: os << "M"; break;
        case 2: os << "L"; break;
    }
    os << std::endl;
    //os << "Size: " <<  (int)j.getSize() << std::endl;
    return os;
}

