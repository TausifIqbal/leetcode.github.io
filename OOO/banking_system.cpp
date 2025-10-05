#include<iostream>
#include<string>
#include<vector>

enum class TransactionType{
	WITHDRAWAL,
	DEPOSIT,
	PIN_CHANGE,
	BALANCE_INQUIRY
};

class Transaction{
	public:
		Transaction(TransactionType type, int amount);
		int getId() const;
		TransactionType getType() const;
		int getAmount() const;
	
	private:
		static int nextId;
		int transactionId;
		TransactionType type;
		int amount;
};

Transaction::Transaction(TransactionType type, int amount)
    : transactionId(nextId++), type(type), amount(amount) {}

int Transaction::nextId = 1;
int Transaction::getId() const {
    return transactionId;
}

TransactionType Transaction::getType() const {
    return type;
}

int Transaction::getAmount() const {
    return amount;
}


class Card{
	public:
	    Card(int cardNumber, int pin);
	    void changePin(int newPin);
	    bool authenticate(int enteredPin) const;
	    int getCardNumber() const;
	    
	private:
	    int cardNumber;
	    int pin;
};

Card::Card(int cardNumber, int pin)
    : cardNumber(cardNumber), pin(pin) {}

void Card::changePin(int newPin) {
    pin = newPin;
}

bool Card::authenticate(int enteredPin) const {
    return enteredPin == pin;
}

int Card::getCardNumber() const {
    return cardNumber;
}

class Account {
	public:
	    Account(int accountNumber, std::string userName, int balance, int cardNumber, int pin);
	    
	    int viewBalance() ;
	    int deposit(int amount);
	    int withdraw(int amount);
	    bool changePin(int oldPin, int newPin);
	    
	    int getAccountNumber() const;
	    std::string getUserName() const;
	    const Card& getCard() const;
	    
	private:
	    int accountNumber;
	    std::string userName;
	    int balance;
	    Card debitCard;
	    std::vector<Transaction> transactions;
};

Account::Account(int accountNumber, std::string userName, int balance, 
                 int cardNumber, int pin)
    : accountNumber(accountNumber),
      userName(userName),
      balance(balance),
      debitCard(cardNumber, pin) {}

int Account::viewBalance()  {
    transactions.emplace_back(TransactionType::BALANCE_INQUIRY, 0);
    return balance;
}

int Account::withdraw(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive");
    }
    if (amount > balance) {
        throw std::runtime_error("Insufficient funds");
    }
    balance -= amount;
    transactions.emplace_back(TransactionType::WITHDRAWAL, amount);
    return balance;
}

bool Account::changePin(int oldPin, int newPin) {
    if (debitCard.authenticate(oldPin)) {
        debitCard.changePin(newPin);
        transactions.emplace_back(TransactionType::PIN_CHANGE, 0);
        return true;
    }
    return false;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getUserName() const {
    return userName;
}

const Card& Account::getCard() const {
    return debitCard;
}


int Account::deposit(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive");
    }
    balance += amount;
    transactions.emplace_back(TransactionType::DEPOSIT, amount);
    return balance;
}

class ATM;
class BankingSystem {
	public:
	    void addAccount(const Account& account);
	    void addATM(const ATM& atm);
	    ATM& getATM(int id);
	    Account& getAccount(int accountNumber);
	    Account* findAccountByCard(int cardNumber); 
	    
	private:
	    std::vector<Account> accounts;
	    std::vector<ATM> atms;
};


class ATM {
	public:
	    ATM(int atmId, bool status, int totalCash);
	    
    	    bool authenticate(int cardNumber, int pin, BankingSystem& bank);
	    bool withdraw(Account& account, int amount);
	    bool deposit(Account& account, int amount);
	    int checkBalance( Account& account) const;
	    bool changePin(Account& account, int oldPin, int newPin);
	    
	    int getTotalCash() const;
	    bool isOperational() const;
	    void setStatus(bool status);
	    int getId() const;
	    
	private:
	    int atmId;
	    bool status;
	    int totalCash;
};

ATM::ATM(int atmId, bool status, int totalCash)
    : atmId(atmId), status(status), totalCash(totalCash) {}


bool ATM::authenticate(int cardNumber, int pin, BankingSystem& bank) {
    if (!status) return false;
    
    Account* account = bank.findAccountByCard(cardNumber);
    if (!account) return false;
    
    return account->getCard().authenticate(pin);
}

int ATM::getId() const{
	return atmId;
}

bool ATM::withdraw(Account& account, int amount) {
    if (!status || amount <= 0 || amount > totalCash) {
        return false;
    }
    try {
        account.withdraw(amount);
        totalCash -= amount;
        return true;
    } catch (...) {
        return false;
    }
}


bool ATM::deposit(Account& account, int amount) {
    if (!status || amount <= 0) {
        return false;
    }
    try {
        account.deposit(amount);
        totalCash += amount;
        return true;
    } catch (...) {
        return false;
    }
}

int ATM::checkBalance( Account& account) const {
    return status ? account.viewBalance() : -1;
}

bool ATM::changePin(Account& account, int oldPin, int newPin) {
    return status && account.changePin(oldPin, newPin);
}

int ATM::getTotalCash() const {
    return totalCash;
}

bool ATM::isOperational() const {
    return status;
}

void ATM::setStatus(bool status) {
    this->status = status;
}


void BankingSystem::addAccount(const Account& account) {
    accounts.push_back(account);
}

void BankingSystem::addATM(const ATM& atm) {
    atms.push_back(atm);
}

Account* BankingSystem::findAccountByCard(int cardNumber) {
    for (auto& account : accounts) {
        if (account.getCard().getCardNumber() == cardNumber) {
            return &account;
        }
    }
    return nullptr;  // Card not found
}

ATM& BankingSystem::getATM(int id) {
    auto it = std::find_if(atms.begin(), atms.end(),
        [id](const ATM& atm) { return atm.getId() == id; });
    
    if (it == atms.end()) {
        throw std::runtime_error("ATM not found");
    }
    return *it;
}

Account& BankingSystem::getAccount(int accountNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [accountNumber](const Account& acc) { 
            return acc.getAccountNumber() == accountNumber; 
        });
    
    if (it == accounts.end()) {
        throw std::runtime_error("Account not found");
    }
    return *it;
}


int main(){
    BankingSystem sbiBank;
    
    // Create account with card (card number, pin)
    Account account(12345, "ABC", 1000, 11114444, 1234);
    sbiBank.addAccount(account);
   
    // Add ATM (atmId, status, totalCash)
    ATM atm(11111, true, 100000);
    sbiBank.addATM(atm);
    
    // Get ATM reference
    ATM& atmRef = sbiBank.getATM(11111);
    
    // Authentication
    int enteredPin;
    std::cout << "Enter your PIN: ";
    std::cin >> enteredPin;
    
    Account* userAccount = sbiBank.findAccountByCard(11114444);
    if (!userAccount) {
        std::cout << "Card not recognized\n";
        return 1;
    }

    if (atmRef.authenticate(userAccount->getCard().getCardNumber(), enteredPin, sbiBank)) {
        std::cout << "Authentication successful!\n";
        
        // Example transaction
        int amount;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;
        
        if (atmRef.withdraw(*userAccount, amount)) {
            std::cout << "Withdrawal successful. New balance: " 
                      << userAccount->viewBalance() << "\n";
        } else {
            std::cout << "Withdrawal failed.\n";
        }
    } else {
        std::cout << "Authentication failed!\n";
    }
    
    return 0;
}


/**


+----------------+       +----------------+       +----------------+
|   BankingSystem|       |      ATM       |       |    Account     |
+----------------+       +----------------+       +----------------+
| - accounts     |<>-----| - atmId        |<>-----| - accountNumber|
| - atms         |       | - status       |       | - userName     |
+----------------+       | - totalCash    |       | - balance      |
       ^                 +----------------+       | - transactions |
       |                        ^                 +----------------+
       |                        |                        ^
       |                        |                        |
+----------------+       +----------------+       +----------------+
|   CardReader   |       |     Card       |       |  Transaction   |
+----------------+       +----------------+       +----------------+
| - readerId     |       | - cardNumber   |       | - transactionId|
| - isFunctional |<>-----| - pin          |       | - type         |
+----------------+       | - account      |       | - amount       |
                         +----------------+       | - timestamp    |
                                                  +----------------+
                                                  
                                                  
Relationships                                                   
    BankingSystem to ATM/Account (Aggregation):

        Owns/manages multiple ATMs and Accounts

        Provides account lookup functionality

    ATM to Account (Association):

        Temporary relationship during transactions

        ATM accesses Account through BankingSystem

    Account to Card (Composition):

        Each Account owns exactly one Card

        Card cannot exist without Account

    Account to Transaction (Composition):

        Account maintains transaction history

        Transactions are part of the Account

    CardReader to Card (Association):

        Temporary relationship during card insertion

        CardReader reads card information
        

Sequence Flow

	Card Insertion
	  	[User] -> [CardReader]: Inserts card
		[CardReader] -> [BankingSystem]: Requests account lookup      
        
        Authentication
        	[ATM] -> [Account]: verifyPin()
		[Account] -> [Card]: authenticate()

	Transaction
		[ATM] -> [Account]: withdraw()/deposit()
		[Account] -> [Transaction]: Records new transaction
		
	
*/
