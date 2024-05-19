#include "hasher/decryptor.h"
#include "exception/exception.h"

std::string Decryptor::getMessage()
{
	std::string message = "";

	for (auto& e : messageCode)
	{
		message += e;
	}

	return message;
}

std::string Decryptor::hash(const std::string& message)
{
	if (passwordCode.size() == 0)
	{
		throw HPasswordNotSetException();
	}

	setMessage(message);

	plusSequenceFront();

	plusFront();

	plusSequenceBack();

	plusBack();

	plusConstant(64);

	minusSequenceFront();

	minusConstant(13);

	minusBack();

	minusFront();

	minusSequenceBack();

	return getMessage();
}

void Decryptor::setMessage(const std::string& message)
{
	for (int i = 0; i < message.size(); i += 8)
	{
		messageCode.push_back(std::bitset<8>(message.substr(i, 8)).to_ulong());
	}
}
