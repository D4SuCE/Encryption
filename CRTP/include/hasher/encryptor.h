#pragma once

#include "hasher.h"

class Encryptor final : public Hasher<Encryptor>
{
public:
	friend class Hasher;

private:
	std::string getMessageImpl();
	std::string hashImpl(const std::string& message);
	std::vector<int> setMessageImpl(const std::string& message);
};