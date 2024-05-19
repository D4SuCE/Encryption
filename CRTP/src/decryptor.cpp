#include "hasher/decryptor.h"

std::string Decryptor::getMessageImpl()
{
	std::string message = "";

	for (auto& e : messageCode)
	{
		message += e;
	}

	return message;
}

std::string Decryptor::hashImpl(const std::string& message)
{
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

std::vector<int> Decryptor::setMessageImpl(const std::string& message)
{
	for (int i = 0; i < message.size(); i += 8)
	{
		messageCode.push_back(std::bitset<8>(message.substr(i, 8)).to_ulong());
	}

	return messageCode;
}
