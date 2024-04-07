#include <iostream>
using namespace std;

/*
����������� ������� - ����������� ������� ��������������,
������� ������������� ��������� ��� �������� �������� ��������������� ��� ��������������� ��������,
�� ������������ �� ���������� �������.

������������
- ������� �� ������ �������� �� ����, ��� ���������, ����������� � �������������� �������� � ��� �������;
- �������� � ��������� ��������������� ������� ������ �������������� ������ � ���������� ���������� ���������� ����� �����������;
- ������� ������ ����������������� ����� �� �������� ������������ �� ��������;
- ���������� ������������ ���������� ��������, ��������� ������ �� ����������, �� �� ����������.

������� ����������� ������� �������� ���������� ������� � ��������:
 * ��������� ���������� ������.
 * �������� ������ �������� ���������.
 * ����������� ������������ ���������.
 * ���������� ����� ��� ��������� ������.
*/

// AbstractProductA(Weapon) - ��������� ���������(����������� �����) ��� ���� �������-��������
// ����������� ����� - ������



class Herbivore abstract//����������
{
public:
	virtual string GetName() abstract;
	virtual void EatGrass() abstract;
	virtual int GetPower() abstract;
};








// ConcreteProductA1(Arbalet)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// ����� �������
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

// ConcreteProductA2(Sword)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// ����� ���
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














// AbstractProductB(Movement) - ��������� ���������(����������� �����) ��� ���� �������-��������
// ����������� ����� ��������
class Carnivore abstract//�������
{
public:
	virtual string GetName() abstract;
	virtual void Eat(Herbivore* prey) abstract;
	virtual int GetPower() abstract;

};				



// ConcreteProductB1(FlyMovement)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// �����
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

// ConcreteProductB2(RunMovement)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// ���
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
AbstractFactory(HeroFactory) - ��������� ��������� ��� ��������, ��������� ����������� �������-��������
*/

// ����� ����������� �������
class ContinentFactory abstract
{
public:
	virtual Carnivore* CreateCarnivore() abstract;
	virtual  Herbivore* CreateHerbivore() abstract;
};

/* 
ConcreteFactory1(ElfFactory) - ��������� ��������, ��������� ���������� �������-��������
 */
// ������� �������� �������� ����� � ���������
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

/* ConcreteFactory2(WarriorFactory) - ��������� ��������, ��������� ���������� �������-��������
 */
// ������� �������� �������� ����� � �����
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

// C������ �� ������ �������� �� ����, ��� ���������, ����������� � �������������� �������� � ��� �������
// ������ - ��� ����������
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
