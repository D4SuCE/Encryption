#pragma once

#include "hasher.h"

class Decryptor final : public Hasher
{
public:
	std::string hash(const std::string& message);
private:
	std::string getMessage();
	void setMessage(const std::string& message);
};