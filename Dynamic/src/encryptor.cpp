#include "hasher/encryptor.h"
#include "exception/exception.h"

std::string Encryptor::getMessage()
{
	std::string message = "";

	for (auto& e : messageCode)
	{
		message += std::bitset<8>(e).to_string();
	}

	return message;
}

std::string Encryptor::hash(const std::string& message)
{
	if (passwordCode.size() == 0)
	{
		throw HPasswordNotSetException();
	}

	setMessage(message);

	plusSequenceBack();

	plusFront();

	plusBack();

	plusConstant(13);

	plusSequenceFront();

	minusConstant(64);

	minusBack();

	minusSequenceBack();

	minusFront();

	minusSequenceFront();

	return getMessage();
}

void Encryptor::setMessage(const std::string& message)
{
	for (auto& c : message)
	{
		messageCode.push_back(static_cast<int>(c));
	}
}
