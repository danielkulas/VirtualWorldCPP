#include "World.h"


World::World()
{
	int x, y;
	cout << "Podaj rozmiar planszy(x): " << endl;
	cin >> x;
	setXGameSize(x);
	cout << "Podaj rozmiar planszy(y): " << endl;
	cin >> y;
	setYGameSize(y);
	setRound(0);
	alsureInfo = "wylaczona";
	info = "............................";
	system("cls");
}

void World::setXGameSize(int x)
{
	xGameSize = x;
}

void World::setYGameSize(int y)
{
	yGameSize = y;
}

void World::setRound(int rd)
{
	round = rd;
}

void World::setInfo(string info)
{
	(*this).info = info;
}

void World::setAlsureInfo(string alsureInfo)
{
	(*this).alsureInfo = alsureInfo;
}

int World::getXGameSize()
{
	return xGameSize;
}

int World::getYGameSize()
{
	return yGameSize;
}

int World::getRound()
{
	return round;
}

void World::gotoxy(int x, int y)
{
	COORD point = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void World::drawFrame(int sx, int sy)
{
	int xpos = GAME_X_POSITION;
	int ypos = GAME_Y_POSITION;

	gotoxy(xpos, ypos);
	for (int i = -1; i < sy + 1; i++)
	{
		for (int j = -1; j < sx + 1; j++)
		{
			if (i == -1 || i == sy)
				cout << "-";
			else if (j == -1 || j == sx)
				cout << "|";
			else
				cout << " ";
		}
		gotoxy(xpos, ++ypos);
	}
}

void World::drawLegend()
{
	int xpos = LEGEND_X_POSITION;
	int ypos = LEGEND_Y_POSITION;

	gotoxy(xpos++, ypos++);
	cout << "Daniel Kulas, 168813";
	gotoxy(xpos, ypos++);
	gotoxy(xpos++, ypos++);
	cout << "Legenda: ";
	gotoxy(xpos, ypos++);
	cout << "Strzalki - poruszanie";
	gotoxy(xpos, ypos++);
	cout << "i - zapisz gre";
	gotoxy(xpos, ypos++);
	cout << "o - wczytaj gre";
	gotoxy(xpos, ypos++);
	cout << "p - wlacz tarcze";
	gotoxy(xpos, ypos++);
	cout << "q - wyjscie";
	gotoxy(xpos, ypos++);
	gotoxy(xpos, ypos++);
	cout << "W - wilk";
	gotoxy(xpos, ypos++);
	cout << "O - owca";
	gotoxy(xpos, ypos++);
	cout << "L - lis";
	gotoxy(xpos, ypos++);
	cout << "Z - zolw";
	gotoxy(xpos, ypos++);
	cout << "A - antylopa";
	gotoxy(xpos, ypos++);
	cout << "C - czlowiek";
	gotoxy(xpos, ypos++);
	gotoxy(xpos, ypos++);
	cout << "t - trawa";
	gotoxy(xpos, ypos++);
	cout << "m - mlecz";
	gotoxy(xpos, ypos++);
	cout << "g - guarana";
	gotoxy(xpos, ypos++);
	cout << "j - wilcze jagody";
	gotoxy(xpos, ypos++);
	cout << "b - barszcz sosnowskiego";
	gotoxy(--xpos, ypos++);
	cout << "Tarcza: ";
	cout << alsureInfo;
	gotoxy(xpos, ypos++);
	cout << "Info: ";
	cout << info;
}

void World::sortArray()
{
	//Sortowanie wzgl. inicjatywy, oraz wieku
	int flaga = 1;
	Organism *swap;
	
	if (organism.size() != 0)
	{
		while (flaga == 1)
		{
			flaga = 0;
			for (int i = 1; i < organism.size(); i++)
			{
				if (organism[i - 1]->getInitiative() < organism[i]->getInitiative() || (organism[i - 1]->getInitiative() == organism[i]->getInitiative() && organism[i - 1]->getAge() < organism[i]->getAge()))
				{
					swap = organism[i];
					organism[i] = organism[i - 1];
					organism[i - 1] = swap;
					flaga = 1;
				}
			}
		}
	}
}

void World::initialization()
{
	setRound(1);
	//Losowanie liczby organizmow
	srand(time(NULL));
	int numberOfOrganisms;
	int maxNumberOfOrganisms = ((getXGameSize() * getYGameSize()) / 100)*NUMBER_OF_ORGANISMS;
	if (maxNumberOfOrganisms <= 0)
		maxNumberOfOrganisms = 1;

	numberOfOrganisms = rand() % maxNumberOfOrganisms + 1;
	if (numberOfOrganisms <= 0 || numberOfOrganisms >= getXGameSize() * getYGameSize())
		numberOfOrganisms = 1;

	//Umieszczanie ogranizmow w grze
	organism.push_back(new Human(*this));

	for (int k = 0; k < NUMBER_OF_ORGANISMS_TYPES; k++)
	{
		for (int i = 0; i < numberOfOrganisms; i++)
		{
			Organism *tab[] = { new Wolf(*this), new Sheep(*this), new Fox(*this), new Turtle(*this), new Antelope(*this), new Grass(*this), new Dandelion(*this), 
								new Guarana(*this), new DeadlyNightshade(*this), new SosnowskyHogweed(*this) };

			organism.push_back(tab[k]);
			int k = organism.size() - 1;
			for (int j = 0; j < k; j++)
			{
				if (organism[k]->getXPosition() == organism[j]->getXPosition() && organism[k]->getYPosition() == organism[j]->getYPosition())
				{
					organism.pop_back();
					break;
				}
			}
		}
	}
}

void World::checkTheEnd()
{
	int flag = 0;
	for (int i = 0; i < organism.size(); i++)
	{
		if (organism[i]->name == "Human")
			flag = 1;
	}

	if (flag == 0)
		exit(2);
}

void World::makeTurn()
{
	if (getRound() < 1)
		initialization();
	
	sortArray();
	drawLegend();
	drawFrame(getXGameSize(), getYGameSize());
	for (int i = 0; i < organism.size(); i++)
		organism[i]->draw();

	info = "............................";
	gotoxy(0, 0);

	for (int i = 0; i < organism.size(); i++)
	{
		organism[i]->setAge(organism[i]->getAge() + 1);
		organism[i]->action();
	}

	for (int i = 0; i < organism.size(); i++)
		organism[i]->collision();

	checkTheEnd();
}

void World::save()
{
	ofstream file;
	file.open("save.txt");
	file << xGameSize << " " << yGameSize << " " << round << " " << info << " " << alsureInfo << " " << organism.size() << " " << "\n";
	for (int i = 0; i < organism.size(); i++)
	{
		file << organism[i]->getName() << " " << organism[i]->getXPosition() << " " << organism[i]->getYPosition() << " ";
		file << organism[i]->getInitiative() << " " << organism[i]->getAge() << " " << organism[i]->getForce() << " ";
		file << "\n";
	}
	file.close();
}

void World::load()
{
	string word;
	int number, size;
	ifstream file;
	file.open("save.txt");
	vector<Organism*>().swap(organism);
	system("cls");

	//Wczytywanie swiata
	file >> number;
	setXGameSize(number);
	file >> number;
	setYGameSize(number);
	file >> number;
	setRound(number);
	file >> word;
	setInfo(word);
	file >> word;
	setAlsureInfo(word);
	file >> size;

	//Wczytywanie organizmow
	for (int i = 0; i < size; i++)
	{
		file >> word;
		if (word == "Human")
			organism.push_back(new Human(*this));
		else if (word == "Wolf")
			organism.push_back(new Wolf(*this));
		else if (word == "Sheep")
			organism.push_back(new Sheep(*this));
		else if (word == "Fox")
			organism.push_back(new Fox(*this));
		else if (word == "Turtle")
			organism.push_back(new Turtle(*this));
		else if (word == "Antelope")
			organism.push_back(new Antelope(*this));
		else if (word == "Grass")
			organism.push_back(new Grass(*this));
		else if (word == "Dandelion")
			organism.push_back(new Dandelion(*this));
		else if (word == "Guarana")
			organism.push_back(new Guarana(*this));
		else if (word == "DeadlyNightshade")
			organism.push_back(new DeadlyNightshade(*this));
		else if (word == "SosnowskyHogweed")
			organism.push_back(new SosnowskyHogweed(*this));

		file >> number;
		organism[i]->setXPosition(number);
		file >> number;
		organism[i]->setYPosition(number);
		file >> number;
		organism[i]->setInitiative(number);
		file >> number;
		organism[i]->setAge(number);
		file >> number;
		organism[i]->setForce(number);
	}

	file.close();
}

World::~World()
{
	vector<Organism*>().swap(organism);
}