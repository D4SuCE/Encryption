#include "exception/exception.h"

HRuntimeException::HRuntimeException(const char* message)
	: message(message) {}

const char* HRuntimeException::what() const
{
	return message;
}

const char* HPasswordNotSetException::what() const
{
	return "Password not set.";
}