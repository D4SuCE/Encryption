#include "hasher/encryptor.h"

std::string Encryptor::getMessageImpl()
{
	std::string message = "";

	for (auto& e : messageCode)
	{
		message += std::bitset<8>(e).to_string();
	}

	return message;
}

std::string Encryptor::hashImpl(const std::string& message)
{
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

std::vector<int> Encryptor::setMessageImpl(const std::string& message)
{
	for (auto& c : message)
	{
		messageCode.push_back(static_cast<int>(c));
	}

	return messageCode;
}
