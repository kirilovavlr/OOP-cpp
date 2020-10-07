#include"Store.h"
//using namespace std;

Store::Store() {}
Store::Store(const Store& s){
    for(std::size_t i=0; i<s.products.size(); i++)
        products.push_back(s.products[i]->clone());
}
Store& Store::operator=(const Store& s){
    if(this!=&s){
        for(std::size_t i=0; i<products.size(); i++)
            delete products[i];
        products.clear();
        for(std::size_t i=0; i<s.products.size(); i++)
            products.push_back(s.products[i]->clone());
    }
    return *this;
}
Store::~Store(){
    for(std::size_t i=0; i<products.size(); i++)
        delete products[i];
}
bool Store::exists(const Product& pr) const{
    for(std::size_t i=0; i<products.size(); i++)
        if(*products[i]==pr && products[i]->getCount()>0) return true;
    return false;
}
void Store::add(const Product& _product){
	products.push_back(_product.clone());
}

void Store::remove(std::size_t index){
    if(index<0 || index>=products.size()) throw std::runtime_error("Invalid index");
    delete products[index];
	for (std::size_t i=index+1; i<products.size(); i++)
		products[i-1]=products[i];
    products.pop_back();
}

void Store::editProduct(std::size_t index, const Product& _product){
    if(index<0 || index>=products.size()) throw std::runtime_error("Invalid index");
    delete products[index];
	products[index] = _product.clone();
}

/*void Store::print() const{
	for (int i=0; i<products.size(); i++){
        std::cout << products[i];
		std::cout << ' ';
	}
}*/
void Store::filterByPrice(double minPr, double maxPr) const{
    if(minPr<0 || maxPr<0) throw std::runtime_error("Invalid price");
    for(std::size_t i=0; i<products.size(); i++)
        if(products[i]->getPrice()>=minPr && products[i]->getPrice()<=maxPr)
            products[i]->print(std::cout);
}
void Store::filterByBrand(const std::string& brand) const{
    for(std::size_t i=0; i<products.size(); i++)
        if(products[i]->getBrand()==brand)
            products[i]->print(std::cout);
}
void Store::filterByCategory(Product::Type T) const{
    for(std::size_t i=0; i<products.size(); i++)
        if(products[i]->getT()==T)
            products[i]->print(std::cout);
}
void Store::buyProduct(const Product& p){
    for(std::size_t i=0; i<products.size(); i++)
        if(*products[i]==p){
            if(products[i]->getCount()<=0) throw std::runtime_error("Unavailable");
            products[i]->setCount(products[i]->getCount()-1);
            break;
        }
}
void Store::listAllItems() const{
    for(std::size_t i=0; i<products.size(); i++){
        std::cout << i << ". ";
        products[i]->print(std::cout);
    }
}
const Product& Store::productByInd(std::size_t ind) const{
    if(ind<0 || ind>=products.size()) throw std::runtime_error("Wrong index");
    return *products[ind];
}
