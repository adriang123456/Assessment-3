#pragma once
#include <string>

class String
{
public: // constructors and destructors
	String();
	String(const char* str);
	String(const String& other);
	~String();

public:		// functions
	int Length();
	char CharacterAt(int index);
	bool StrEqualTo(const char* other);

	void StrAppend(const char* str);
	void StrPreppend(const char* str);

	const char* CStr() const;

	void ToLower(const char* str);
	void ToUpper(const char* str);

	size_t Find(const char* str);
	size_t Find_I(int index, const char* str);

	void Replace(const char* str, const char* replace);

	void Read();
	void Write();

	// need to be implemented
	bool operator == (const char* other);
	char& operator [] (size_t index);

	void operator = (const char* str);
	bool operator < (const char* str) const;

	void operator + (const char* str);
	void operator += (const char* str);

private:	// variables

	int Index;
	unsigned int size = 0;
	char* holder = nullptr;
	char* holder_1 = nullptr;
};