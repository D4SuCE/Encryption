#pragma once
#include <exception>

class HException : public std::exception
{
public:
	virtual const char* what() const = 0;
};

class HRuntimeException : public HException
{
public:
	HRuntimeException(const char* message);

	const char* what() const;

private:
	const char* message;
};

class HPasswordNotSetException : public HException
{
public:
	const char* what() const;
};