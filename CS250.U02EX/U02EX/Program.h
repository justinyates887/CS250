#pragma once
#ifndef _PROGRAM
#define _PROGRAM

#include <string>
#include <vector>
using namespace std;

class Program {

	public:
		void Run();

		//Menu Items
		void Menu_Main();
		void Menu_LoadList();
		void Menu_SaveList();
		void Menu_AddToList();
		void Menu_UpdateListItem();
		void Menu_RemoveFromList();

		//Helper functions
		int GetChoice(int min, int max);
		void DisplayHeader(string text);
		void DisplayList();

	private:
		vector<string> m_todoItems;
};

#endif