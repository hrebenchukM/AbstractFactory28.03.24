#include <iostream>
using namespace std;

/*
Абстрактная фабрика - порождающий паттерн проектирования,
который предоставляет интерфейс для создания семейств взаимосвязанных или взаимозависимых объектов,
не специфицируя их конкретных классов.

Применимость
- система не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты;
- входящие в семейство взаимосвязанные объекты должны использоваться вместе и необходимо обеспечить выполнение этого ограничения;
- система должна конфигурироваться одним из семейств составляющих ее объектов;
- необходимо предоставить библиотеку объектов, раскрывая только их интерфейсы, но не реализацию.

Паттерн абстрактная фабрика обладает следующими плюсами и минусами:
 * изолирует конкретные классы.
 * упрощает замену семейств продуктов.
 * гарантирует сочетаемость продуктов.
 * поддержать новый вид продуктов трудно.
*/

// AbstractProductA(Weapon) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
// абстрактный класс - оружие



class Herbivore abstract//Травоядные
{
public:
	virtual string GetName() abstract;
	virtual void EatGrass() abstract;
	virtual int GetPower() abstract;
};








// ConcreteProductA1(Arbalet)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// класс арбалет
class Wildebeest : public Herbivore
{
	
	int weight=200;
	int maxWeight=300;
	bool isAlive = true;
public:
	
	string GetName() override
	{
		return "Wildebeest";
	}
	int GetPower() {
		return weight;
	}
	 void EatGrass()
	{
	  cout << endl << GetName() << " tries to eat...";
		if (!isAlive) {
			cout << " but too dead to eat :((";
			return;
		}

		int newWeight = weight + 10;
		if (newWeight <= maxWeight) {
			weight = newWeight;
		}
		else {
			weight = maxWeight;
		}
		cout << " and now has weight " << weight;
	}
};

// ConcreteProductA2(Sword)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// класс меч
class Bison : public Herbivore
{
public:
	int weight=500;
	int maxWeight=800;
	bool isAlive = true;
public:
	string GetName() override
	{
		return "Bison";
	}
	int GetPower() {
		return weight;
	}
	void EatGrass()
	{
		cout << endl << GetName() << " tries to eat...";
		if (!isAlive) {
			cout << " but too dead to eat :((";
			return;
		}

		int newWeight = weight + 10;
		if (newWeight <= maxWeight) {
			weight = newWeight;
		}
		else {
			weight = maxWeight;
		}
		cout << " and now has weight " << weight;
	}
};














// AbstractProductB(Movement) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
// абстрактный класс движение
class Carnivore abstract//Хищники
{
public:
	virtual string GetName() abstract;
	virtual void Eat(Herbivore* prey) abstract;
	virtual int GetPower() abstract;

};				



// ConcreteProductB1(FlyMovement)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// полет
class Lion : public Carnivore
{
	int power=350;
	
public:
	string GetName() override
	{
		return "Lion";
	}
	int GetPower()
	{
		return power;
	}

	 void Eat(Herbivore* prey) {
		cout << endl << GetName() << " tries to eat...";
		if (prey == 0) {
			cout << "but not found :(";
		}
		else {
			cout << " " << prey->GetName();
		}

		if (power > prey->GetPower()) {
			power += 10;
		}
		else {
			power -= 10;
		}
		cout << " and now has power " << power;
	}
};

// ConcreteProductB2(RunMovement)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// бег
class Wolf : public Carnivore
{
	int power=550;
	
public:
	string GetName() override
	{
		return "Wolf";
	}
	int GetPower()
	{
		return power;
	}

	void Eat(Herbivore* prey) {
		cout << endl << GetName() << " tries to eat...";
		if (prey == 0) {
			cout << "but not found :(";
		}
		else {
			cout << " " << prey->GetName();
		}

		if (power > prey->GetPower()) {
			power += 10;
		}
		else {
			power -= 10;
		}
		cout << " and now has power " << power;
	}
};

/* 
AbstractFactory(HeroFactory) - объявляет интерфейс для операций, создающих абстрактные объекты-продукты
*/

// класс абстрактной фабрики
class ContinentFactory abstract
{
public:
	virtual Carnivore* CreateCarnivore() abstract;
	virtual  Herbivore* CreateHerbivore() abstract;
};

/* 
ConcreteFactory1(ElfFactory) - реализует операции, создающие конкретные объекты-продукты
 */
// Фабрика создания летящего героя с арбалетом
class AfricaFactory : public ContinentFactory
{
public:
	Carnivore* CreateCarnivore() override
	{
		return new Wolf();
	}
	Herbivore* CreateHerbivore() override
	{
		return new Wildebeest();
	}
};

/* ConcreteFactory2(WarriorFactory) - реализует операции, создающие конкретные объекты-продукты
 */
// Фабрика создания бегущего героя с мечом
class AmericaFactory : public ContinentFactory
{
public:
	Carnivore* CreateCarnivore() override
	{
		return new Lion();
	}
	Herbivore* CreateHerbivore() override
	{
		return new Bison();
	}
};

// Cистема не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты
// клиент - сам супергерой
class AnimalWorld
{
	Carnivore* carnivore;
	Herbivore* herbivore;
public:
	AnimalWorld(ContinentFactory* factory)
	{
		carnivore = factory->CreateCarnivore();
		herbivore = factory->CreateHerbivore();
	}
	
	void HerbivoreNutrition() {
		cout << "Herbivore Nutrition" << endl;
		herbivore->EatGrass();
	}

	

	void CarnivoreNutrition() {
		cout << "Carnivore Nutrition" << endl;
		carnivore->Eat(herbivore);
	}

};

void main()
{
	ContinentFactory* factory = new AfricaFactory();
	AnimalWorld* animalWorld = new AnimalWorld(factory);
	animalWorld->HerbivoreNutrition();
	animalWorld->CarnivoreNutrition();
	delete factory;
	delete animalWorld;

	factory = new AmericaFactory();
	animalWorld = new AnimalWorld(factory);
	animalWorld->HerbivoreNutrition();
	animalWorld->CarnivoreNutrition();
	
	delete factory;
	delete animalWorld;

	system("pause");
	
}
