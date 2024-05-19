#pragma once

#include "hasher.h"

class Encryptor final : public Hasher
{
public:
	std::string hash(const std::string& message);
private:
	std::string getMessage();
	void setMessage(const std::string& message);
};