#include"Product.h"
#include"String.h"
#include<cstring>
#include<iostream>
//using namespace std;std::string

Product::Product(): SKU(""), Brand(""), Model(""), Color(""), Price(0), Count(1) {}
Product::Product(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, Type t){
    SKU=sku;
    Brand=brand;
    Model=model;
    Color=color;
    setPrice(price);
    //Size=_size;
    setCount(cnt);
    T=t;
}

/*bool Product::operator==(const Product& p) const{
    return (SKU==p.SKU && Brand==p.Brand && Model==p.Model && Color==p.Color && Price==p.Price && T==p.T);
}*/
void Product::setSKU(const std::string& sku){
    SKU = sku;
}
void Product::setBrand(const std::string& brand){
    Brand = brand;
}
void Product::setModel(const std::string& model){
    Model = model;
}
void Product::setColor(const std::string& color){
    Color = color;
}
void Product::setPrice(double price){
    if(price<0) return;
    Price=price;
}
void Product::setT(Type t){
    T=t;
}
/*void Product::setSize(int _size){
    if(_size<0) return;
    Size=_size;
}*/
void Product::setCount(int cnt){
    if(cnt<0) return;
    Count=cnt;
}
const std::string& Product::getSKU() const{
    return SKU;
}
const std::string& Product::getBrand() const{
    return Brand;
}
const std::string& Product::getModel() const{
    return Model;
}
const std::string& Product::getColor() const{
    return Color;
}
double Product::getPrice() const{
    return Price;
}
Product::Type Product::getT() const{
	return T;
}

/*int Product::getSize() const{
    return Size;
}*/
int Product::getCount() const{
    return Count;
}
void Product::buyProduct(){
    if(Count<=0) throw std::runtime_error("Unavailable");
    Count--;
}
/*std::istream& operator>>(std::istream& in, Product& p){
    char buf[500];
    in.ignore();
    in.getline(buf,500);
    p.setSKU(buf);
    in.getline(buf,500);
    p.setBrand(buf);
    in.getline(buf,500);
    p.setModel(buf);
    in.getline(buf,500);
    p.setColor(buf);
    in >> p.Price;
    //in >> p.Size;
    in >> p.Count;
    return in;
}*/
std::ostream& operator<<(std::ostream& out, const Product& p)
{
   out << "SKU: " << p.getSKU() << std::endl;
   out << "Brand: " << p.getBrand() << std::endl;
   out << "Model: " << p.getModel() << std::endl;
   out << "Color: " << p.getColor() << std::endl;
   out << "Price: " << p.getPrice() << std::endl;
   //out << "Size: " << p.getSize() << std::endl;
   out << "Count: " << p.getCount() << std::endl;
   return out;
}
bool Product::operator==(const Product& p) const{
    return  getSKU()==p.getSKU();
}
void Product::print(std::ostream& os) const{
    os << *this << std::endl;
}

