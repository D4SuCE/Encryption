#include "hasher/hasher.h"

void Hasher::setPassword(const std::string& password)
{
	for (auto& c : password)
	{
		passwordCode.push_back(static_cast<int>(c));
	}
}

void Hasher::plusFront()
{
	for (int messageI = 0, passwordI = 0; messageI < messageCode.size();)
	{
		messageCode[messageI++] += passwordCode[passwordI++];

		if (passwordI >= passwordCode.size())
		{
			passwordI = 0;
		}
	}
}

void Hasher::plusBack()
{
	for (int messageI = messageCode.size() - 1, passwordI = passwordCode.size() - 1; messageI >= 0;)
	{
		messageCode[messageI--] += passwordCode[passwordI--];

		if (passwordI < 0)
		{
			passwordI = passwordCode.size() - 1;
		}
	}
}

void Hasher::minusFront()
{
	for (int messageI = 0, passwordI = 0; messageI < messageCode.size();)
	{
		messageCode[messageI++] -= passwordCode[passwordI++];

		if (passwordI >= passwordCode.size())
		{
			passwordI = 0;
		}
	}
}

void Hasher::minusBack()
{
	for (int messageI = messageCode.size() - 1, passwordI = passwordCode.size() - 1; messageI >= 0;)
	{
		messageCode[messageI--] -= passwordCode[passwordI--];

		if (passwordI < 0)
		{
			passwordI = passwordCode.size() - 1;
		}
	}
}

void Hasher::xorFront()
{
	for (int messageI = 0, passwordI = 0; messageI < messageCode.size();)
	{
		messageCode[messageI++] ^= passwordCode[passwordI++];

		if (passwordI >= passwordCode.size())
		{
			passwordI = 0;
		}
	}
}

void Hasher::xorBack()
{
	for (int messageI = messageCode.size() - 1, passwordI = passwordCode.size() - 1; messageI >= 0;)
	{
		messageCode[messageI--] ^= passwordCode[passwordI--];

		if (passwordI < 0)
		{
			passwordI = passwordCode.size() - 1;
		}
	}
}

void Hasher::reverse()
{
	std::reverse(messageCode.begin(), messageCode.end());
}

void Hasher::plusConstant(int constant)
{
	for (auto& e : messageCode)
	{
		e += constant;
	}
}

void Hasher::minusConstant(int constant)
{
	for (auto& e : messageCode)
	{
		e -= constant;
	}
}

void Hasher::plusSequenceFront()
{
	for (int messageI = 1, previous = messageCode[messageI - 1], current = messageCode[messageI];
		messageI < messageCode.size();
		++messageI)
	{
		current = messageCode[messageI];
		messageCode[messageI] += previous;
		previous = current;
	}
}

void Hasher::plusSequenceBack()
{
	for (int messageI = messageCode.size() - 2, previous = messageCode[messageI + 1], current = messageCode[messageI];
		messageI >= 0;
		--messageI)
	{
		current = messageCode[messageI];
		messageCode[messageI] += previous;
		previous = current;
	}
}

void Hasher::minusSequenceFront()
{
	for (int messageI = 1; messageI < messageCode.size(); ++messageI)
	{
		messageCode[messageI] -= messageCode[messageI - 1];
	}
}

void Hasher::minusSequenceBack()
{
	for (int messageI = messageCode.size() - 2; messageI >= 0; --messageI)
	{
		messageCode[messageI] -= messageCode[messageI + 1];
	}
}