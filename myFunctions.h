class Product
{
	int _id = 0;
	char* _name = nullptr;
	char* _description = nullptr;
	double _price = 0;
	short _discount = 0; // 0-100%
public:
	Product();
	Product(const char* name, double price);
	double getPrice();
	double getDiscountPrice();
	int getId();
	void setId(int id);
	void setPrice(double price);
	void setDiscount(short discount);
	void setDescription();
	void print();
	~Product();
};

// Note: Hər iki class-a aid qeydlər:
// Constructors: Default, Parameterized
// Accessors: Getter, Setter
// Destructor
// Delegation of constructors
// Constructor Overlaodin


Product::Product() {
	this->_id = 1;
	_description = new char[] {"Default product"};
	_price = 0;
	
}




Product::Product(const char* name, double price) : Product()
{
	_name = new char[10];
	strcpy_s(_name, sizeof(_name), name);
	if (price < 0)
		assert(!"PRICE CANNOT BE LOWER THAN 0!");

	_price = price;
}

double Product::getPrice() { return this->_price; }

double Product::getDiscountPrice() {
	if (_discount != 0)
		return _price * _discount / 100;
	return -1;
}

int Product::getId() { return _id; }

void Product::setPrice(double price) {
	if (price <= 0)
		assert(!"INVALID DATA!");
	_price = price;
}

void Product::setDiscount(short discount) {
	if (_discount < 0)
		assert(!"NUMBER YOU'VE ENTERES IS SO LOW");
	_discount = discount;
}

void Product::print() {
	cout << "\t\t~~~ PRODUCT INFO~~~" << endl;
	cout << "Id: " << this->getId() << endl;
	cout << "Name: " << this->_name << endl;
	cout << "Price: " << this->_price << endl;
	cout << "Discount: " << this->_discount << endl;
	cout << "Discounted price: " << this->getDiscountPrice() << endl;
	cout << "Description: " << this->_description << endl;
}

void Product::setDescription() {
	char* newText = new char[30];
	cout << "Name: " << this->_name << endl;
	cout << "Write description of the product (max 30 symbols):" << endl;
	cin.getline(newText, 30);
}

Product::~Product() {
	if (_name != nullptr)
		delete[] _name;
	if (_description != nullptr)
		delete[] _description;
}

void Product::setId(int id) {
	if (id < 0)
		assert(!"INVALID DATA!");
	_id = id;
}

class Stock {
	char* _name = nullptr;
	Product** _products = nullptr;
	size_t _count = 1;
	void deleteProducts();
public:
	void print();
	Product* getProductById(int id);
	char* getName();
	void setName(const char* name);
	Stock();
	Stock(const char* name);
	void addToArray(Product* pr);
	void deleteProductById(int id);
};

Stock::Stock() {
	_name = new char[10];
}

Stock::Stock(const char* name) : Stock()
{
	if (strlen(name) > 10)
		assert(!"NAME IS TOO LONG!");
	strcpy_s(_name, sizeof(_name), name);
}

void Stock::deleteProducts() {
	for (size_t i = 0; i < _count; i++)
		delete[] _products[i];
}

char* Stock::getName() { return _name; }

void Stock::setName(const char* name) {
	if (strlen(name) > 10)
		assert(!"NAME IS TOO LONG!");
	strcpy_s(_name, sizeof(_name), name);
}

void Stock::addToArray(Product* pr) {

	Product** newPr = new Product * [_count + 1];
	for (size_t i = 0; i < _count; i++)
	{
		newPr[i] = _products[i];
	}
	newPr[_count] = pr;
	deleteProducts();
	_count++;
	for (size_t i = 0; i < _count; i++)
		_products[i] = newPr[i];

}

Product* Stock::getProductById(int id)
{
	for (size_t i = 0; i < this->_count; i++)
		if (id == _products[i]->getId())return _products[i];
}


void Stock::deleteProductById(int id) {
	Product** newPr = new Product * [_count - 1];

	for (size_t i = 0; i < this->_count; i++)
	{
		if (_products[i] == getProductById(id)) {
			delete _products[i];
		}
		else {
			newPr[i] = _products[i];
		}
	}
	deleteProducts();
	_count--;
	for (size_t i = 0; i < _count; i++)
		_products[i] = newPr[i];
}


void Stock::print() {
	cout << "\t\t ~~ STOCK INFO ~~ " << endl;
	for (size_t i = 0; i < this->_count; i++)
		_products[i]->print();
}

Product apple;
Product k("Kiwi", 3.7);

k.setDiscount(20);

cout << k.getId() << endl;
cout << k.getPrice() << endl;
cout << k.getDiscountPrice() << endl;

k.print();

Stock d("gugu");
d.addToArray(&k);
d.addToArray(&apple);
d.print();

