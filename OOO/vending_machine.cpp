#include<iostream>
#include<string>
#include<vector>

// Diagram   https://lucid.app/lucidchart/7a1c6a5a-372c-4e79-98de-d232f778394b/edit?viewport_loc=202%2C-2662%2C1588%2C1674%2C0_0&invitationId=inv_8e744418-21ab-45c8-9eff-bc0af943e9d8

struct Product{
	int id;
	std::string name;
	int price;
	int quantity;
	Product(int id,std::string name,int price,int quantity):id(id),name(name),price(price),quantity(quantity){};
	void decrease_quantity(){
		quantity--;
	}
	void increase_quantity(){
		quantity++;
	}
};

class ProductInventory{
	std::vector<Product* > products;
	public:

	Product* find_product(int id){
		auto p = std::find_if(products.begin(),products.end(),[ id ](const  Product*  p){
			return p->id == id;
		});
		if(p != products.end()){
			return *p;
		}
		return nullptr;
	};
	
	bool add_product(Product* p){
		products.emplace_back(p);
		return true;
	}	

	void show(){
		for(auto product: products){
			std::cout<<"product name "<< (product->name) <<"  product price " << (product->price)<<"  quantity "<<(product->quantity) <<std::endl; 
		}
	
	}
	
};


class PaymentSystem{
	
	public:
		virtual bool process_payment(double amount) const=0;
		virtual ~PaymentSystem()=default; 

};

class CashPayment:public PaymentSystem{

	public:
		CashPayment(){};

		bool process_payment(double amount) const override{
			std::cout<<"Paid "<<amount <<" using CASH\n";
			return true;
		}
};

class CreditCardPayment:public PaymentSystem{

	int credit_card_number{};
	public:
		CreditCardPayment(){}; // figure out how to pass credit card number, or should I use credit card object?
		
		bool process_payment(double amount) const override{
			std::cout<<"Paid "<<amount <<" using CREDIT CARD\n";
			return true;
		}
};

enum class PaymentType {CASH,CARD};

class PaymentFactory{

	public:
	static PaymentSystem* create_payment(PaymentType type){
			if(type == PaymentType::CASH){
				return new CashPayment();
			}
			if(type == PaymentType::CARD){
				return new CreditCardPayment();
			}

			return nullptr;
		}
};

class Payment{

	double amount;
	PaymentType type;
	PaymentSystem*  paymentSystem;
	public:
		Payment(double amount, PaymentType type):amount(amount),type(type){
			paymentSystem = PaymentFactory::create_payment(type);
		}
	bool process(){

		if(paymentSystem){
			return paymentSystem->process_payment(amount);
		}
		return false;
	}
};

class Display;

class VendingMachine{

	int machine_id {};
	double current_balance {};
	ProductInventory* inventory;
	Display* display ;

	public:
	
	VendingMachine(int machine_id,ProductInventory* inventory):machine_id(machine_id),inventory(inventory){};	
	void add_product(Product* product){ // make this friend to staff class
		inventory->add_product(product);
	}
	void display_products(){
		std::cout<<"Displaying products"<<std::endl;
		inventory->show();	
	}
	
	Product* select_product_id(int id){
		return inventory->find_product(id);
	}

	bool make_payment( double amount, PaymentType type ){
		Payment payment(amount,type);
		
		return payment.process(); 
	};

	bool dispense_product(Product* product){
		product->decrease_quantity();
		std::cout<<"Dispensing product " << (product->name) <<" \n";
		return true;
	};
		
};

int main(){



	Product soda(1,"soda",5,2);
	Product coke(2,"soda",7,2);
	ProductInventory inventory;
	inventory.add_product(&soda);
	inventory.add_product(&coke);
	VendingMachine vendingMachine(2341,&inventory);

	vendingMachine.display_products();
	auto p = vendingMachine.select_product_id(2);
	bool status=vendingMachine.make_payment(p->price,PaymentType::CARD);

	if(status){
		vendingMachine.dispense_product(p);
	}
	vendingMachine.display_products();
}
