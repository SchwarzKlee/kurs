#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Transport {
protected:
	string type, brand, color, number;
	int year, relevance;
	double mileage, price;
public:
	Transport() {}
	Transport(string t, string b, string c, string n, int y, double m, double p, int r): type(t), brand(b), color(c), number(n), year(y), mileage(m), price(p), relevance(r) {}
	string getType() { return type; }
	string getBrand() { return brand;}
	string getColor() { return color; }
	string getNumber() { return number; }
	int getYear() { return year; }
	double getMileage() { return mileage; }
	double getPrice() { return price; }
	int getRelevance() { return relevance; }

	virtual ~Transport() = default;
};

class Car: public Transport {
	string timeUnit = "сутки";
public:
	Car() {}
	Car(string b, string c, string n, int y, double m, double p, int r): Transport("Автомобиль", b, c, n, y, m, p, r){}
	string getTimeUnit() { return timeUnit; }

	friend ostream& operator<<(ostream& out, Car& c);
	friend istream& operator>>(istream& in, Car& c);
};

ostream& operator<<(ostream& out, Car& c) {
	out << c.getType() << " " << c.getBrand() << " " << c.getColor() << " " << c.getNumber() << " " << c.getYear() << " " << c.getMileage() << " " << c.getPrice() << " " << c.getRelevance() << endl;
	return out;
}

istream& operator>>(istream& in, Car& c) {
	string brand, color, number;
	int year, relevance;
	double mileage, price;
	in >> brand >> color >> number >> year >> mileage >> price >> relevance;
	c = Car(brand, color, number, year, mileage, price, relevance);
	return in;
}

class Motorcycle: public Transport {
	string timeUnit = "час";
public:
	Motorcycle() {}
	Motorcycle(string b, string c, string n, int y, double m, double p, int r) : Transport("Мотоцикл", b, c, n, y, m, p, r) {}
	string getTimeUnit() { return timeUnit; }

	friend ostream& operator<<(ostream& out, Motorcycle& m);
	friend istream& operator>>(istream& in, Motorcycle& m);
};

ostream& operator<<(ostream& out, Motorcycle& m) {
	out << m.getType() << " " << m.getBrand() << " " << m.getColor() << " " << m.getNumber() << " " << m.getYear() << " " << m.getMileage() << " " << m.getPrice() << " " << m.getRelevance() << endl;
	return out;
}

istream& operator>>(istream& in, Motorcycle& m) {
	string brand, color, number;
	int year, relevance;
	double mileage, price;
	in >> brand >> color >> number >> year >> mileage >> price >> relevance;
	m = Motorcycle(brand, color, number, year, mileage, price, relevance);
	return in;
}

class Client {
	string passport;
public:
	Client() {}
	Client(string p): passport(p) {}
	string getPassport() { return passport; }
	friend ostream& operator<<(ostream& out, Client& c);
	friend istream& operator>>(istream& in, Client& c);
};

ostream& operator<<(ostream& out, Client& c) {
	out << c.getPassport() << endl;
	return out;
}

istream& operator>>(istream& in, Client& c) {
	string passport;
	in >> passport;
	c = Client(passport);
	return in;
}

class Rent: public Transport, public Client {
	string data;
	int rentDay;
	double fine = 0;
public:
	Rent() {}
	Rent(string t, string b, string c, string n, int y, double m, double p, int r, string pass, string d, int rDay, double f) : Transport(t, b, c, n, y, m, p, r), Client(pass), data(d), rentDay(rDay), fine(f) {}
	string getData() { return data; }
	int getRentDay() { return rentDay; }
	double getFine() { return fine; }

	friend ostream& operator<<(ostream& out, Rent& c);
	friend istream& operator>>(istream& in, Rent& c);
};

ostream& operator<<(ostream& out, Rent& r) {
	out << r.getType() << " " << r.getBrand() << " " << r.getColor() << " " << r.getNumber() << " " << r.getYear() << " " << r.getMileage() << " " << r.getPrice() << " " << r.getRelevance() 
		<< " " << r.getPassport() << " " << r.getData() << " " << r.getRentDay() << " " << r.getFine() << endl;
	return out;
}

istream& operator>>(istream& in, Rent& r) {
	string type, brand, color, number, passport, data;
	int year, relevance, rentDay;
	double mileage, price, fine;
	in >> type >> brand >> color >> number >> year >> mileage >> price >> relevance >> passport >> data >> rentDay >> fine;
	r = Rent(type, brand, color, number, year, mileage, price, relevance, passport, data, rentDay, fine);
	return in;
}

void outSpisokCar(vector<unique_ptr<Car>>& cars) {
	cout << "\n=== Список автомобилей ===" << endl;
	if (cars.empty()) cout << "Автомобили не найдены." << endl;
	else {
		for (const auto& car : cars) {
			cout << "  Бренд      : " << car->getBrand() << endl;
			cout << "  Цвет       : " << car->getColor() << endl;
			cout << "  Номер      : " << car->getNumber() << endl;
			cout << "  Год выпуска: " << car->getYear() << endl;
			cout << "  Пробег     : " << car->getMileage() << " тыс. км" << endl;
			cout << "  Цена аренды: " << car->getPrice() << " руб за " << car->getTimeUnit() << endl;
			cout << "--------------------------------" << endl;
		}
	}
}

void outSpisokMoto(vector<unique_ptr<Motorcycle>>& motos) {
	cout << "\n=== Список мотоциклов ===" << endl;
	if (motos.empty()) cout << "Мотоциклы не найдены." << endl;
	else {
		for (const auto& moto : motos) {
			cout << "  Бренд      : " << moto->getBrand() << endl;
			cout << "  Цвет       : " << moto->getColor() << endl;
			cout << "  Номер      : " << moto->getNumber() << endl;
			cout << "  Год выпуска: " << moto->getYear() << endl;
			cout << "  Пробег     : " << moto->getMileage() << " тыс. км" << endl;
			cout << "  Цена аренды: " << moto->getPrice() << " руб за " << moto->getTimeUnit() << endl;
			cout << "--------------------------------" << endl;
		}
	}
}

void chooseCar(vector<unique_ptr<Car>>& cars) {
	cout << "По какой характеристике будет осущетсвлен выбор автомобиля:\n";
	cout << "1 - Марка\n";
	cout << "2 - Пробег\n";
	int com;
	cin >> com;
	switch (com) {
		case 1: {
			Car* t = cars[0].get();
			int choise;
			for (int i = 0; i < cars.size(); i++) cout << i + 1 << " " << cars[i]->getBrand() << endl;
			cout << "Введите порядковый номер автомобиля для выбора: \n";
			cin >> choise;
			if (choise >= 1 && choise <= cars.size()) t = cars[choise - 1].get();
			else {
				cout << "Некорректный номер!\n";
				break;
			}
			cout << "=== Вы выбрали автомобиль ===\n";
			cout << "  Бренд      : " << t->getBrand() << endl;
			cout << "  Цвет       : " << t->getColor() << endl;
			cout << "  Номер      : " << t->getNumber() << endl;
			cout << "  Год выпуска: " << t->getYear() << endl;
			cout << "  Пробег     : " << t->getMileage() << " тыс. км" << endl;
			cout << "  Цена аренды: " << t->getPrice() << " руб за " << t->getTimeUnit() << endl;
			cout << "--------------------------------" << endl;
			break;
		}
		case 2: {
			Car* t = cars[0].get();
			int choise;
			for (int i = 0; i < cars.size(); i++) {
				cout << i + 1 << " " << cars[i]->getMileage() << " тыс. км" << endl;
			}
			cout << "Введите порядковый номер автомобиля для выбора: \n";
			cin >> choise;
			if (choise >= 1 && choise <= cars.size()) t = cars[choise - 1].get();
			else {
				cout << "Некорректный номер!\n";
				break;
			}
			cout << "=== Вы выбрали автомобиль ===\n";
			cout << "  Бренд      : " << t->getBrand() << endl;
			cout << "  Цвет       : " << t->getColor() << endl;
			cout << "  Номер      : " << t->getNumber() << endl;
			cout << "  Год выпуска: " << t->getYear() << endl;
			cout << "  Пробег     : " << t->getMileage() << " тыс. км" << endl;
			cout << "  Цена аренды: " << t->getPrice() << " руб за " << t->getTimeUnit() << endl;
			cout << "--------------------------------" << endl;
		}
	}
}

void chooseMoto(vector<unique_ptr<Motorcycle>>& motos) {
	cout << "По какой характеристике будет осущетсвлен выбор мотоцикла:\n";
	cout << "1 - Марка\n";
	cout << "2 - Пробег\n";
	int com;
	cin >> com;
	switch (com) {
		case 1: {
			Motorcycle* t = motos[0].get();
			int choise;
			for (int i = 0; i < motos.size(); i++) cout << i + 1 << " " << motos[i]->getBrand() << endl;
			cout << "Введите порядковый номер мотоцилка для выбора: \n";
			cin >> choise;
			if (choise >= 1 && choise <= motos.size()) t = motos[choise - 1].get();
			else {
				cout << "Некорректный номер!\n";
				break;
			}
			cout << "=== Вы выбрали мотоцикл ===\n";
			cout << "  Бренд      : " << t->getBrand() << endl;
			cout << "  Цвет       : " << t->getColor() << endl;
			cout << "  Номер      : " << t->getNumber() << endl;
			cout << "  Год выпуска: " << t->getYear() << endl;
			cout << "  Пробег     : " << t->getMileage() << " тыс. км" << endl;
			cout << "  Цена аренды: " << t->getPrice() << " руб за " << t->getTimeUnit() << endl;
			cout << "--------------------------------" << endl;
			break;
		}
		case 2: {
			Motorcycle* t = motos[0].get();
			int choise;
			for (int i = 0; i < motos.size(); i++) cout << i + 1 << " " << motos[i]->getMileage() << " тыс. км" << endl;
			cout << "Введите порядковый номер мотоцилка для выбора: \n";
			cin >> choise;
			if (choise >= 1 && choise <= motos.size()) t = motos[choise - 1].get();
			else {
				cout << "Некорректный номер!\n";
				break;
			}
			cout << "=== Вы выбрали мотоцикл ===\n";
			cout << "  Бренд      : " << t->getBrand() << endl;
			cout << "  Цвет       : " << t->getColor() << endl;
			cout << "  Номер      : " << t->getNumber() << endl;
			cout << "  Год выпуска: " << t->getYear() << endl;
			cout << "  Пробег     : " << t->getMileage() << " тыс. км" << endl;
			cout << "  Цена аренды: " << t->getPrice() << " руб за " << t->getTimeUnit() << endl;
			cout << "--------------------------------" << endl;
			break;
		}
	}
}

void statisticsRent(vector<unique_ptr<Rent>>& rents) {
	cout << "=== СТАТИСТИКА ПРОКАТА ЗА 05.2026 ===" << endl;
	int carRentCount = 0, motorcycleRentCount = 0;
	for (const auto& rent : rents) {
		string date = rent->getData();
		if (date.find("05.2026") != string::npos) {
			if (rent->getType() == "Автомобиль") carRentCount++;
			else motorcycleRentCount++;
		}
	}
	cout << "Количество сданных в прокат автомобилей: " << carRentCount << endl;
	cout << "Количество сданных в прокат мотоциклов : " << motorcycleRentCount << endl;
	cout << "Всего транспортных средств в прокате   : " << (carRentCount + motorcycleRentCount) << endl;
}

void revenue(vector<unique_ptr<Rent>>& rents) {
	cout << "=== ВЫРУЧКА ЗА 05.2026 === " << endl;
	double  revenue = 0, fines = 0;
	for (const auto& rent : rents) {
		string date = rent->getData();
		if (date.find("05.2026") != string::npos) {
			if (rent->getRelevance() > 0) revenue += (rent->getPrice() * rent->getRentDay());
			if (rent->getFine() > 0) {
				revenue += rent->getFine();
				fines += rent->getFine();
			}
		}
	}
	cout << "Выручка в месяц составляет: " << revenue << " рублей\n";
	cout << "Сумма выплаченных штрафов : " << fines << " рублей\n";
}

void maxMileage(vector<unique_ptr<Car>>& cars, vector<unique_ptr<Motorcycle>>& motos) {
	cout << "=== ТРАНСПОРТНОЕ СТРЕДСТВО С НАИБОЛЬШИМ ПРОБЕГОМ В 05.2026 ===" << endl;
	Transport* maxMileageVehicle = cars[0].get();
	double maxMileage = 0;
	for (const auto& car : cars)
		if (car->getMileage() > maxMileageVehicle->getMileage()) maxMileageVehicle = car.get();
	for (const auto& moto : motos)
		if (moto->getMileage() > maxMileageVehicle->getMileage()) maxMileageVehicle = moto.get();
	cout << "  Тип транспорта: " << maxMileageVehicle->getType() << endl;
	cout << "  Бренд         : " << maxMileageVehicle->getBrand() << endl;
	cout << "  Цвет          : " << maxMileageVehicle->getColor() << endl;
	cout << "  Номер         : " << maxMileageVehicle->getNumber() << endl;
	cout << "  Год выпуска   : " << maxMileageVehicle->getYear() << endl;
	cout << "  Пробег        : " << maxMileageVehicle->getMileage() << " тыс. км" << endl;
	cout << "  Цена аренды   : " << maxMileageVehicle->getPrice() << " руб за ";
	if (dynamic_cast<Car*>(maxMileageVehicle)) cout << dynamic_cast<Car*>(maxMileageVehicle)->getTimeUnit();
	else if (dynamic_cast<Motorcycle*>(maxMileageVehicle)) cout << dynamic_cast<Motorcycle*>(maxMileageVehicle)->getTimeUnit();
	cout << endl;
}

vector<unique_ptr<Car>> getCarVector() {
	vector<unique_ptr<Car>> cars;
	ifstream file("Transports.txt");
	if (!file.is_open()) cout << "Ошибка: не удалось открыть файл Transports.txt" << endl;
	string line;
	while (getline(file, line)) {
		if (line.empty()) continue;
		istringstream iss(line);
		string type;
		iss >> type;
		if (type == "Автомобиль") {
			Car car;
			iss >> car;
			cars.push_back(make_unique<Car>(car));
		}
	}
	file.close();
	return cars;
}

vector<unique_ptr<Motorcycle>> getMotoVector() {
	vector<unique_ptr<Motorcycle>> motos;
	ifstream file("Transports.txt");
	if (!file.is_open()) cout << "Ошибка: не удалось открыть файл Transports.txt" << endl;
	string line;
	while (getline(file, line)) {
		if (line.empty()) continue;
		istringstream iss(line);
		string type;
		iss >> type;
		if (type == "Мотоцикл") {
			Motorcycle moto;
			iss >> moto;
			motos.push_back(make_unique<Motorcycle>(moto));
		}
	}
	file.close();
	return motos;
}

vector<unique_ptr<Rent>> getRentVector() {
	vector<unique_ptr<Rent>> rents;
	ifstream file1("Rents.txt");
	if (!file1.is_open()) cout << "Ошибка: не удалось открыть файл Rents.txt" << endl;
	string line1;
	while (getline(file1, line1)) {
		if (line1.empty()) continue;
		istringstream iss(line1);
		Rent rent;
		iss >> rent;
		rents.push_back(make_unique<Rent>(rent));
	}
	file1.close();
	return rents;
}

int main() {
	setlocale(LC_ALL, "rus");
	auto cars = getCarVector();
	auto motos = getMotoVector();
	auto rents = getRentVector();
	int exit = 1, com;
	while (exit) {
		cout << "Меню:\n";
		cout << "0 - Выход\n";
		cout << "1 - Просмотр автомобилей\n";
		cout << "2 - Просмотр мотоциклов\n";
		cout << "3 - Выбрать автомобиль\n";
		cout << "4 - Выбрать мотоцикл\n";
		cout << "5 - Статистика проката автомобилей и мотоциклов\n";
		cout << "6 - Выручка за месяц\n";
		cout << "7 - Просмотр траспорта с наибольшим пробегом\n";
		cout << "Выберете действие: ";
		cin >> com;
		switch (com) {
			case 1: {
				outSpisokCar(cars);
				break;
			}
			case 2: {
				outSpisokMoto(motos);
				break;
			}
			case 3: {
				chooseCar(cars);
				break;
			}
			case 4: {
				chooseMoto(motos);
				break;
			}
			case 5: {
				statisticsRent(rents);
				break;
			}
			case 6: {
				revenue(rents);
				break;
			}
			case 7: {
				maxMileage(cars, motos);
				break;
			}
			case 0: {
				exit = 0;
				break;
			}
		}
	}
}