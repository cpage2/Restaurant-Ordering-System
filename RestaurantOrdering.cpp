// RestaurantManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using std::cin; using std::cout; using std::to_string;
using std::endl; using std::string;


//Functions
void displayInventory(int& p, int& b, int& s, int& sh, int& c, int& iP, int& iB, int& iS, int& iSh, int& iC);
int orderItems(int& p, int& b, int& s, int& sh, int& c, int& iP, int& iB, int& iS, int& iSh, int& iC, int& opt);
int currInventory(int& a, int& b);


int main()
{


	//variables for menu items quantity (q)
	int qPasta = 0, qBurger = 0, qSoups = 0, qShakes = 0, qChicken = 0;//0 initializes vars

	//vars for items sold (s)
	int sPasta = 0, sBurger = 0, sSoups = 0, sChicken = 0, sShakes = 0;

	//price for items
	double pPasta = 0, pBurger = 0, pSoups = 0, pChicken = 0, pShakes = 0;

	//total prices of items
	double totalPasta = 0, totalBurger = 0, totalSoups = 0, totalChicken = 0, totalShakes = 0;


	cout << "--- Restaurant Ordering System ---" << endl;

	while (1) {

		cout << endl << "--Menu--" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Enter Inventory" << endl;
		cout << "2. Order Items" << endl;
		cout << "3. Check Inventory" << endl;
		cout << "4. Display Total Sales" << endl;

		string mOption;

		cout << "Enter menu option: ";
		cin >> mOption;


		if (mOption == "0") {
			cout << "Goodbye." << endl;
			break;
		}


		//Enter inventory and Price
		if (mOption == "1") {
			cout << endl << "---Quantity/Price of Items---" << endl;
			cout << endl;

			cout << "Enter price of Pasta:";
			cin >> pPasta;
			cout << "Pasta available: ";
			cin >> qPasta;
			cout << endl;

			cout << "Enter price of Burger:";
			cin >> pBurger;
			cout << "Burgers available: ";
			cin >> qBurger;

			cout << endl << "Enter price of Soup:";
			cin >> pSoups;
			cout << "Soups available: ";
			cin >> qSoups;

			cout << endl << "Enter price of Shake:";
			cin >> pShakes;
			cout << "Shakes available: ";
			cin >> qShakes;


			cout << endl << "Enter price of Chicken:";
			cin >> pChicken;
			cout << "Chicken available: ";
			cin >> qChicken;

		}

		//Order items
		if (mOption == "2") {

			while (1) {
				cout << endl << "Please select from option to order:" << endl;
				cout << endl << "1. Pasta";
				cout << endl << "2. Burgers";
				cout << endl << "3. Soups";
				cout << endl << "4. Shakes";
				cout << endl << "5. Chicken";
				cout << endl << "0. Exit";

				cout << endl << endl << "Please enter choice: ";
				int option;
				cin >> option;
				cout << endl;
				orderItems(sPasta, sBurger, sSoups, sShakes, sChicken, qPasta, qBurger, qSoups, qShakes, qChicken, option);

				if (option == 0) {
					break;
				}

			}


		}

		//Check inventory
		if (mOption == "3") {
			displayInventory(sPasta, sBurger, sSoups, sShakes, sChicken, qPasta, qBurger, qSoups, qShakes, qChicken);


		}

		//Display Sales
		if (mOption == "4") {
			//need sold(s), price(p), total(t)

			//total price = sold * price
			totalPasta = sPasta * pPasta;
			totalBurger = sBurger * pBurger;
			totalSoups = sSoups * pSoups;
			totalShakes = sShakes * pShakes;
			totalChicken = sChicken * pChicken;

			//stores items in arrays to print
			string item[] = { "Pasta", "Burgers", "Soups","Shakes","Chicken" };
			int sold[] = { sPasta,sBurger, sSoups, sShakes, sChicken };
			double price[] = { pPasta,pBurger,pSoups,pShakes,pChicken };
			double total[] = { totalPasta,totalBurger,totalSoups,totalShakes,totalChicken };

			cout << endl << " \t \t---Total Sales---" << endl << endl;

			cout << "Item" << " \t | " << " \t Sold" << "\t | " << "\t Price" << "\t | " << "\t Total" << endl;

			for (int i = 0; i < 5; i++) {
				cout << "--------------------------------------------------------" << endl;
				cout << item[i] << "\t | " << " \t" << sold[i] << "\t | " << "\t $" << price[i] << "\t | " << "\t $" << total[i] << endl;
			}

			double totSales = totalBurger + totalChicken + totalPasta + totalShakes + totalSoups;//adds total prices

			cout << endl << "Total sales of items: $" << totSales << endl;

		}

		//Error
		if (mOption < "0" || mOption > "4") {
			cout << "Wrong menu option. Try again." << endl;
		}


	}

	return 0;

}

void displayInventory(int& p, int& b, int& s, int& sh, int& c, int& iP, int& iB, int& iS, int& iSh, int& iC)
{
	string iPasta = to_string(currInventory(iP, p));// converts ints to string
	string iBurger = to_string(currInventory(iB, b));
	string iSoups = to_string(currInventory(iS, s));
	string iShakes = to_string(currInventory(iSh, sh));
	string iChicken = to_string(currInventory(iC, c));



	//Item       Stock

	string item[] = { "Pasta", "Burgers","Soups", "Shakes", "Chicken" };
	string inC[] = { iPasta, iBurger, iSoups, iShakes, iChicken };

	cout << endl;
	cout << "ITEM" << "\t" << "\tINVENTORY" << endl;
	cout << "------------------------" << endl;

	for (int i = 0; i < 5; i++) {

		cout << item[i] << "\t " << " | " << "\t " << inC[i] << endl;

	}


	//return string();
}

int orderItems(int& p, int& b, int& s, int& sh, int& c, int& iP, int& iB, int& iS, int& iSh, int& iC, int& opt)
{
	if (opt < 0 || opt >5) {//Error
		cout << "Wrong option. Try again." << endl;
	}
	if (opt == 1) {
		cout << "Enter amount of Pasta to order:";
		cin >> p;
		if ((iP - p) >= 0) {//Checks for if items sold will not go into negatives.
			cout << "Order processed. " << p << " pasta sold." << endl;
			return p;//return value if quantity is at or above 0 after subtraction
		}

		else {// If sold num is greater than quantity it will not return value
			cout << "Not enough inventory." << endl;
		}


	}

	if (opt == 2) {//Burgers
		cout << "Enter amount of Burgers to order:";
		cin >> b;
		if ((iB - b) >= 0) {
			cout << "Order processed. " << b << " burgers sold." << endl;
			return b;
		}


		else {
			cout << "Not enough inventory." << endl;
		}

	}

	if (opt == 3) {//Soups
		cout << "Enter amount of Soups to order:";
		cin >> s;
		if ((iS - s) >= 0) {
			cout << "Order processed. " << s << " soups sold." << endl;
			return s;
		}


		else {
			cout << "Not enough inventory." << endl;
		}

	}

	if (opt == 4) {//Shakes
		cout << "Enter amount of Shakes to order:";
		cin >> sh;
		if ((iSh - sh) >= 0) {
			cout << "Order processed. " << sh << " shakes sold." << endl;
			return sh;
		}

		else {
			cout << "Not enough inventory." << endl;
		}

	}

	if (opt == 5) {//Chicken

		cout << "Enter amount of Chicken to order:";
		cin >> c;

		if ((iC - c) >= 0) {

			cout << "Order processed. " << c << " chicken sold." << endl;
			return c;
		}

		else {
			cout << "Not enough inventory." << endl;
		}

	}




	//return 0;
}

int currInventory(int& a, int& b)
{
	int c = a - b;
	//c = total, a = initial or q, b = sold or s

	return c;
}



