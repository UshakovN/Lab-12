#pragma once
#include<iostream>

class BADTYPE
{
private:
	const char* error;

public:
	BADTYPE(const char* str);
	void GetInfo() const;
};

class EMPTY
{
private:
	const char* error;

public:
	EMPTY(const char* str);
	void GetInfo() const;
};


