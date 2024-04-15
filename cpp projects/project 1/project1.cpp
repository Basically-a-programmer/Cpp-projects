#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

	int input;
	string text, old, user, pass, name, age, word, word1;
	string password[3], creds[2], cp[2];

	cout << " Security System " << endl << endl;
	cout << "   Register ->1 " << endl;
	cout << "   Login ->2 " << endl;
	cout << "   Change Password ->3 " << endl;
	cout << "   END Program ->4 " << endl;
	cout << endl;

	do {
		cout << "Enter Your Choice: ";
        cin >> input;
        cin.ignore(); // Clear the input buffer

		switch (input) {
		case 1: {
			cout << "-----------------X-------------" << endl;
			cout << "-------------Register----------" << endl;
			cout << endl << endl;
			cout << "Enter your username: ";
			cin >> name;
			cout << "Enter the Password: ";
			cin >> password[0];
			cout << "Please Enter your age: ";
			cin >> age;

			ofstream of1;
			of1.open("file.txt");
			if (of1.is_open()) {
				of1 << name << "\n" << endl;
				of1 << password[0] << "\n" << endl;
				cout << "Registration Successful" << endl;
				of1.close(); // Close the file after writing
			}

			break;
		}
		case 2: {
			int i = 0;
			cout << "----------------------------------" << endl << endl;
			cout << "----------------LOGIN-------------" << endl << endl;
			cout << "-----------------------------------" << endl << endl;
			ifstream of2;
			of2.open("file.txt");
			cout << "Enter the username: ";
			cin >> user;
			cout << "Enter the Password: ";
			cin >> pass;
			if (of2.is_open()) {
				while (getline(of2, text)) {
					istringstream iss(text);
					iss >> word;
					creds[i] = word;
					i++;
				}
				of2.close(); // Close the file after reading
				if (user == creds[0] && pass == creds[1]) {
					cout << "----Login Successful----" << endl << endl;
					cout << " Details " << endl;
					cout << " Username : " + name << endl;
					cout << " Password : " + pass << endl;
					cout << " Age :  " + age << endl;
				}
				else {
					cout << endl;
					cout << "Incorrect Credentials " << endl;
					cout << " Login ---> 2   " << endl;
					cout << "  Change Password-----> 3" << endl;
				}
			}

			break;
		}
		case 3: {
			int i = 0;
			cout << "------------Change Password----------" << endl;
			ifstream of0;
			of0.open("file.txt");
			cout << "Enter the old password: ";
			cin >> old;
			if (of0.is_open()) {
				while (getline(of0, text)) {
					istringstream iss(text);
					iss >> word1;
					cp[i] = word1;
					i++;
				}
				of0.close(); // Close the file after reading
				if (old == cp[1]) {
					ofstream of1;
					of1.open("file.txt");
					if (of1.is_open()) {
						cout << " Enter the new Password : ";
						cin >> password[1];
						cout << " Enter the Password again : ";
						cin >> password[2];

						if (password[1] == password[2]) {
							of1 << cp[0] << '\n';
							of1 << password[1] << endl;
							cout << "Password changed successfully" << endl;
						}
						else {
							cout << "Password doesn't Match" << endl;
						}
						of1.close(); // Close the file after writing
					}
				}
				else {
					cout << "Please enter the valid Password" << endl;
				}
			}

			break;

		}
		case 4: {
			cout << "------------Thank You---------" << endl;
			break;
		}

		default:
			cout << "----Enter the Valid choice" << endl;
			break;
		}
	} while (input != 4);

	return 0;
}


