#include <string>
using namespace std;

class Card {
public: 
	virtual int getCardsPerCoin(int) const = 0;
	virtual string getName() const = 0;
	virtual void print(ostream&) const = 0;

	friend ostream& operator<<(std::ostream&, const Card*);
};

class Blue : public Card { 
	static const int cardsPerCoin[4];
public: 
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Chili : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Stink : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Green : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class soy : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class black : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class Red : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};

class garden : public Card {
	static const int cardsPerCoin[4];
public:
	static const string name;
	string getName() const override final;
	int getCardsPerCoin(int) const override final;
	void print(ostream&) const override final;
};