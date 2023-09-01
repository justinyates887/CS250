#include "Program.h"
#include <iostream>
#include <fstream>
using namespace std;

void Program::Run()
{
	Menu_Main();
}

void Program::Menu_Main()
{
	//This is improper, but i forget how to properly break while loops in cpp
	bool run = true;
	while (run) {

		DisplayHeader("MAIN MENU");
		cout << "Current List: " << endl;
		DisplayList();

		cout << "Options:" << endl
			<< "0. Quit" << endl
			<< "1. Load To-Do List" << endl
			<< "2. Save To-Do List" << endl
			<< "3. Add Item to List" << endl
			<< "4. Update Existing Item" << endl
			<< "5. Remove Item From List" << endl
		;

		int choice = GetChoice(0, 5);

		switch (choice) {
			case 0:
				run = false;
				break;
			case 1:
				Menu_LoadList();
				break;
			case 2: 
				Menu_SaveList();
				break;
			case 3:
				Menu_AddToList();
				break;
			case 4:
				Menu_UpdateListItem();
				break;
			case 5:
				Menu_RemoveFromList();
				break;
		}
	}
}

void Program::Menu_LoadList()
{
	DisplayHeader("LOAD LIST");
	string filename;
	cout << "Filename to load from: ";
	cin.ignore();
	getline(cin, filename);

	ifstream input(filename);
	if (input.fail())
	{
		cout << "ERROR: Could not find \"" << filename << "\"!" << endl;
		return;
	}

	string line;
	while (getline(input, line))
	{
		m_todoItems.push_back(line);
	}

	cout << endl << "File loaded." << endl;
}

void Program::Menu_SaveList()
{
	DisplayHeader("SAVE LIST");

	string filename;
	cout << "Filename to save to: ";
	cin.ignore();
	getline(cin, filename);

	ofstream output( filename );
	for (int i = 0; i < m_todoItems.size(); i++)
	{
		output << m_todoItems[i] << endl;
	}

	cout << endl << "File saved." << endl;
}

void Program::Menu_AddToList()
{
	DisplayHeader("ADD TO LIST");

	string item;
	cout << "Enter to-do item: ";
	cin.ignore();
	getline(cin, item);

	m_todoItems.push_back(item);

	cout << endl << "Item added." << endl;
}

void Program::Menu_UpdateListItem()
{
	DisplayHeader("UPDATE LIST ITEM");
	DisplayList();

	cout << "Which item should I update?" << endl;
	int choice = GetChoice(0, m_todoItems.size() - 1);

	string updatedText;
	cout << "What should I update the value to? ";
	cin.ignore();
	getline(cin, updatedText);

	m_todoItems.at(choice) = updatedText;

	cout << "Item updated" << endl;
}

void Program::Menu_RemoveFromList()
{
	DisplayHeader("REMOVE LIST ITEM");
	DisplayList();

	cout << "Which item should I remove?" << endl;
	int choice = GetChoice(0, m_todoItems.size() - 1);

	m_todoItems.erase(m_todoItems.begin() + choice);

	cout << "Item removed" << endl;
}

void Program::DisplayList()
{
	for (int i = 0; i < m_todoItems.size(); i++) {
		cout << i << ". " << m_todoItems.at(i) << endl;
	}
}

void Program::DisplayHeader(string text)
{
	cout << string(80, '-') << endl;
	cout << text << endl;
	cout << string(80, '-') << endl;
}

int Program::GetChoice(int min, int max)
{
	int choice;
	cout << "-> ";
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Invalid selection! Must be between " << min << " and " << max << "!" << endl;
		cout << "-> ";
		cin >> choice;
	}

	return choice;
}