#include "String.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <ctime>
#include <chrono>

#include "string.h"

using namespace std;

// constructors and destructors
String::String() : holder(nullptr), size(0) {
}
String::String(const char* str) {
	int size = strlen(str);

	holder = new char[size + 1];
	strncpy_s(holder, size + 1, str, size);
}
String::String(const String& other) {
	size = other.size;
	holder = new char[size + 1];
	strncpy_s(holder, size + 1, other.holder, size + 1);
}
String::~String() {
	delete holder;
	holder = nullptr;

	delete holder_1;
	holder_1 = nullptr;
}

// length function
int String::Length() {

	size_t length = strlen(holder);
	cout << length;
	cout << "\n\n\n\n";


	if (length == 11) {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "Test 1 Check Length of String - Successful";
		log.close();

		counter += 1;
	}
	else {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "Test 1 Check Length of String - Failure";
		log.close();
	}

	return length;
}

// function that figures out what is at that index
char String::CharacterAt(int index)
{
	Index = index;
	char CharAt = holder[Index];

	cout << CharAt;
	cout << "\n\n\n\n";

	if (CharAt == holder[2]) {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 2 Check Character of String at index 2 - Successful";
		log.close();

		counter += 1;
	}
	else {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 2 Check Character of String at index 2 - Failure";
		log.close();
	}

	return CharAt;
}

// the function which figures out if one string is the same as another
bool String::StrEqualTo(const char* other)
{
	if (strcmp(holder, other) == 0) { cout << "True"; }
	else { cout << "False"; }

	cout << "\n\n\n\n";

	if (strcmp(holder, other) == 0) {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 3 Check String is Equal to 'Hello World' - Successful";
		log.close();

		counter += 1;
	}
	else {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 3 Check String is Equal to 'Hello World' - Failure";
		log.close();
	}

	return this;
}

// This function appends a char array with another  
void String::StrAppend(const char* other)
{
	string appended = holder;
	appended.append(other);

	if (appended == "Hello World look") {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 4 Check Appended Stringto 'Hello World look' - Successful";
		log.close();

		counter += 1;
	}
	else {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 4 Check Appended of String to 'Hello World look' - Failure";
		log.close();
	}


	cout << appended;
	cout << "\n\n\n\n";
}

// This function prepends a char array with another
void String::StrPreppend(const char* str)
{
	string prepended = str;
	prepended.append(holder);

	if (prepended == "World Hello World") {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 5 Check Prepended String to 'World Hello World' - Successful";
		log.close();

		counter += 1;
	}
	else {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "\n" << "Test 5 Check Prepended Stringto 'World Hello World' - Failure";
		log.close();
	}

	cout << prepended;
	cout << "\n\n\n\n";

}

// This function prints the string that was assigned to the class created
const char* String::CStr() const
{
	cout << holder;
	cout << "\n\n\n\n";

	return holder;
}

// This function makes all uppercase letters, lowercase
void String::ToLower(const char* str)
{
	char holder[20] = "";
	strcpy_s(holder, str);
	for (int i = 0; i < strlen(holder); i++) {
		holder[i] = tolower(holder[i]);
	}

	if (holder == "hello world") {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "Test 1 Check Length of String - Successful";
		log.close();

		counter += 1;
	}
	else {
		ofstream log;
		log.open("logfile.txt", ios_base::app);
		log << "Test 1 Check Length of String - Failure";
		log.close();
	}

	cout << holder;
	cout << "\n\n\n\n";

}

// This function makes all the lowercase letters, uppercase
void String::ToUpper(const char* str)
{
	char holder[20] = "";
	strcpy_s(holder, str);

	for (int i = 0; i < strlen(holder); i++) {
		holder[i] = toupper(holder[i]);

	}

	cout << holder;
	cout << "\n\n\n\n";

}

// This function finds the index of a word inside an array that was got from a txt file
size_t String::Find(const char* str) {
	ifstream file("file.txt");
	string words;
	string letters = str;

	while (getline(file, words)) {
		cout << words << "\n\n";
	}

	string arr[20];

	int i = 0;
	int loc = 0;
	int count = 0;
	int size_w = words.size();
	int found = 0;

	vector<string> txt_file;

	stringstream ssin(words);
	while (ssin.good() && i < size_w) {
		ssin >> arr[i];
		++i;
	}

	for (i = 0; i < arr->size(); i++) {
		string p = arr[i];
		txt_file.push_back(p);
	}

	for (i = 0; i < txt_file.size(); i++) {
		if (txt_file[i] == letters) {

			loc = i;
			count += 1;
			cout << "Index > " << loc;
			found = 1;
		}
	}
	if (found != 1) { loc = -1; cout << loc; }

	cout << "\n\n\n\n";
	return size_t(loc);
}

// This function finds the index of a word after the provided index of a word in a array from a txt file
size_t String::Find_I(int index, const char* str) {
	ifstream file("file.txt");
	string words;
	string letters = str;

	while (getline(file, words)) {
		cout << words << "\n\n";
	}

	string arr[20];

	int i = 0;
	int loc = 0;
	int count = 0;
	int size_w = words.size();
	int found = 0;

	vector<string> txt_file;

	stringstream ssin(words);
	while (ssin.good() && i < size_w) {
		ssin >> arr[i];
		++i;
	}

	for (i = 0; i < arr->size(); i++) {
		string p = arr[i];
		txt_file.push_back(p);
	}

	for (int i = index; i < txt_file.size(); i++) {
		if (txt_file[i] == letters) {

			loc = i;
			count += 1;
			cout << "Index > " << loc;
			found = 1;
		}
	}
	if (found != 1) { loc = -1; cout << loc; }

	cout << "\n\n\n\n";
	return size_t(loc);
}

// This function finds a string and replaces it with a provided string 
void String::Replace(const char* str, const char* replace) {

	ifstream file("file.txt");
	string words;
	string letters = str;
	string Replaced = replace;

	while (getline(file, words)) {
		cout << words << "\n\n";
	}

	string arr[20];

	int i = 0;
	int loc = 0;
	int count = 0;
	int size_w = words.size();
	int found = 0;

	vector<string> txt_file;

	stringstream ssin(words);
	while (ssin.good() && i < size_w) {
		ssin >> arr[i];
		++i;
	}

	for (i = 0; i < 20; i++) {
		string p = arr[i];
		txt_file.push_back(p);
	}

	for (i = 0; i < txt_file.size(); i++) {
		if (txt_file[i] == letters) {
			txt_file[i] = Replaced;
		}
	}
	for (int i = 0; i < txt_file.size(); i++) {
		cout << txt_file[i] << " ";
	}
	cout << "\n\n\n\n";
}

// This functions gets a users input and put it into holder -- ----- -- doesn't like spaces
void String::Read() {
	string user_input;
	cin >> user_input;

	int size = user_input.size();
	holder_1 = new char[size + 1];

	strcpy_s(holder_1, size + 1, user_input.c_str());
	cout << "\n\n\n\n";
}

// This functions prints the users input from the previous function
void String::Write() {
	cout << holder_1;
	cout << "\n\n\n\n";
}

// overloaded == operator
bool String::operator ==(const char* other)
{
	string h_older = holder;
	if (h_older.size() != strlen(other)) {
		cout << "False";
		return false;
	}
	if (h_older.size() == strlen(other)) {

		for (int i = 0; i < h_older.size(); i++) {
			if (h_older[i] != other[i]) {
				cout << "False";
				return false;
			}
			if (h_older[i] == other[i]) {
				cout << "True";
				return true;
			}
		}
	}
	cout << "False";
	cout << "\n\n\n\n";
	return false;
}

// overloaded [] operator
char& String::operator[](size_t index)
{
	if (index >= strlen(holder)) {
		cout << "Index is too high";
	}
	return holder[index];
}

// overloaded = operator, check to see if this is what is meant to do
void String::operator=(const char* str)
{
	int size = strlen(str);

	holder_1 = new char[size + 1];
	strncpy_s(holder_1, size + 1, str, size);

	cout << holder_1;
	cout << "\n\n\n\n";
}

// overloaded + operator, combining the original string with a new one, inside a new string
void String::operator+(const char* str) {
	char* new_str;
	int size = strlen(holder) + strlen(str) + 1;

	new_str = new char[size];
	strncpy_s(new_str, size + 1, holder, size);
	string str_new = new_str;
	str_new.append(str);
	cout << str_new;
	cout << "\n\n\n\n";
}

// overloaded += operator
void String::operator+=(const char* str) {
	string appended = holder;
	appended.append(str);

	cout << appended;
	cout << "\n\n\n\n";
}

// overloaded < operator    ----- check what this is wanting exactly
bool String::operator<(const char* str) const
{
	char string[1];
	if (holder[0] > 90) {
		holder[0] = holder[0] - 32;
	}
	if (str[0] > 90) {
		string[0] = str[0] - 32;
	}

	if (int(holder[0]) < int(string[0])) { cout << "True"; return true; }
	cout << "False";
	cout << "\n\n\n\n";
	return false;
}

// Function to get the time and write it into the txt file
void String::WriteTime()
{
	auto current_time = chrono::system_clock::now();
	time_t tt = chrono::system_clock::to_time_t(current_time);

	char buf[30];
	ctime_s(buf, sizeof(buf), &tt);

	cout << buf;

	ofstream log;
	log.open("logfile.txt", ios_base::app);
	log << "\n" << buf;
	log.close();
}

// Function to check the success rate of the tests
void String::SuccessRate() {
	string success_r = "";
	if (counter == 1) { success_r = "Success Rate 20.00%"; }
	else if (counter == 2) { success_r = "Success Rate 40.00%"; }
	else if (counter == 3) { success_r = "Success Rate 60.00%"; }
	else if (counter == 4) { success_r = "Success Rate 80.00%"; }
	else if (counter == 5) { success_r = "Success Rate 100.00%"; }
	else if (counter == 0) { success_r = "Success Rate 00.00%"; }

	ofstream log;
	log.open("logfile.txt", ios_base::app);
	log << "\n" << success_r << "\n\n";
	log.close();

	cout << counter;
}