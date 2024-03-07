// AdrianG Assessment 2 Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "String_Utility.h"

using namespace std;

// The main function of the custom string class assessment
int main() {

	// making the class
	String* Test = new String("Hello World");
	String* Test_1(Test);



	//// Testing that the functions work for Assessment 2, just requires uncommmenting

	//cout << "The Length of the string \n";
	//Test->Length();  // expected result ---  11

	//cout << "The Character 2 at \n";
	//Test->CharacterAt(2);    // expected result ---   l

	//cout << "Is the string equal to Hello World \n";
	//Test->StrEqualTo("Hello World");    // expected result ---  True

	//cout << "Appending the string with look \n";
	//Test->StrAppend(" look");    // expected result ---  Hello World look

	//cout << "Prepending the string with World \n";
	//Test->StrPreppend("World ");    // expected result ---  World Hello World

	//cout << "Printing the string \n";
	//Test->CStr();    // expected result ---  Hello World

	//cout << "Setting all the characters to lowercase \n";
	//Test->ToLower("HELLO WORLD");    // expected result --- hello world

	//cout << "Setting all the characters to uppercase \n";
	//Test->ToUpper("hello world");    // expected result ---	HELLO WORLD

	//cout << "Finding the word Hello in a txt file \n";
	//Test->Find("Hello");    // text in the txt file - Hello World, from Computer overlords x2    // expected result --- Index > 0

	//cout << "Finding the word computer after the third index in the txt file \n";
	//Test->Find_I(2, "Computer");     // expected result --- Index 3, will return -1 if not in range

	//cout << "Replace all the 'Hello' in the from the txt file with 'Goodbye' \n";
	//Test->Replace("Hello", "Goodbye");   // expected result --- Goodbye World, from Computer overlords Goodbye World, from Computer overlords

	//cout << "Gets input from the user and assigns it a variable \n";
	//Test->Read();    // expected result ---  Successful input of a string without spaces
	//cout << "Prints the inpute from the previous function \n";
	//Test->Write();    // expected result ---	prints the above string

	//cout << "Sees if Hello World is equal to Hello World from the main string \n";
	//Test->operator== ("Hello World");    // expected result --- True 
	//cout << "\n\n\n\n";

	//cout << "Gets the character at the index of 1";
	//cout << Test->operator[](1);    // expected result ---  e
	//cout << "\n\n\n\n";

	//cout << "Replaces the string with Hello \n";
	//Test->operator=("Hello");    // expected result --- Hello

	//cout << "Adds Boo at the end of the string \n";
	//Test->operator+("Boo");    // expected result --- Hello WorldBoo

	//cout << "Appends the string with Hello at the end \n";
	//Test->operator+=(" Hello");    // expected result --- Hello World Hello

	//cout << "Checks to see if the first character is before the first character in the main string \n";
	//Test->operator< ("z");    // expected result --- True
	//cout << "\n\n\n\n";


	// Deletes the class created
	delete Test;
	Test = nullptr;

}