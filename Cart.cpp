#include"Cart.h"
#include<cstring>
Cart::Cart(): cart(), price(0), payment(false) {}
Cart::Cart(const Cart& s){
    for(std::size_t i=0; i<s.cart.size(); i++)
        cart.push_back(s.cart[i]->clone());
    price=s.price;
    payment=s.payment;
}
Cart& Cart::operator=(const Cart& s){
    if(this!=&s){
        for(std::size_t i=0; i<cart.size(); i++)
            delete cart[i];
        cart.clear();
        for(std::size_t i=0; i<s.cart.size(); i++)
            cart.push_back(s.cart[i]->clone());
        price=s.price;
        payment=s.payment;
    }
    return *this;
}
Cart::~Cart(){
    for(std::size_t i=0; i<cart.size(); i++)
        delete cart[i];
}
unsigned int Cart::getCnt() const{
    return cart.size();
}
double Cart::getPrice() const{
    return price;
}
void Cart::addProduct(const Product& p){
    price+=p.getPrice();
    cart.push_back(p.clone());
}
void Cart::removeProduct(const Product& p){
    for(std::size_t i=0; i<cart.size(); i++)
        if(*cart[i]==p){
            cart.erase(cart.begin()+i);
            price-=p.getPrice();
            break;
        }
}
bool Cart::pay(Store& s){
    if(cart.empty()) return false;
    for(std::size_t i=0; i<cart.size(); i++){
        cart[i]->buyProduct();
        s.buyProduct(*cart[i]);
    }
    payment=true;
    clearCart();
    return true;
}
void Cart::clearCart(){
    for(std::size_t i=0; i<cart.size(); i++)
        delete cart[i];
    cart.clear();
    price=0;
}
void Cart::printCart() const{
    for(std::size_t i=0; i<cart.size(); i++){
        std::cout << i << ". ";
        cart[i]->print(std::cout);
    }
}
void Cart::removeProductByInd(std::size_t ind){
    if(ind<0 || ind>=cart.size()) throw std::runtime_error("Wrong index");
    removeProduct(*cart[ind]);
}

