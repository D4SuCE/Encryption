#pragma once

#include <string>
#include <vector>
#include <bitset>
#include "exception/exception.h"

template<typename T>
class Hasher
{
public:
	std::string hash(const std::string& message)
	{
		if (passwordCode.size() == 0)
		{
			throw HPasswordNotSetException();
		}

		return static_cast<T*>(this)->hashImpl(message);
	}

	void setPassword(const std::string& password)
	{
		for (auto& c : password)
		{
			passwordCode.push_back(static_cast<int>(c));
		}
	}

protected:
	std::string getMessage()
	{
		return static_cast<T*>(this)->getMessageImpl();
	}

	void setMessage(const std::string& message)
	{
		messageCode = static_cast<T*>(this)->setMessageImpl(message);
	}

protected:
	void plusFront()
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

	void plusBack()
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

	void minusFront()
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

	void minusBack()
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

	void xorFront()
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

	void xorBack()
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

	void reverse()
	{
		std::reverse(messageCode.begin(), messageCode.end());
	}

	void plusConstant(int constant)
	{
		for (auto& e : messageCode)
		{
			e += constant;
		}
	}

	void minusConstant(int constant)
	{
		for (auto& e : messageCode)
		{
			e -= constant;
		}
	}

	void plusSequenceFront()
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

	void plusSequenceBack()
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

	void minusSequenceFront()
	{
		for (int messageI = 1;	messageI < messageCode.size(); ++messageI)
		{
			messageCode[messageI] -= messageCode[messageI - 1];
		}
	}

	void minusSequenceBack()
	{
		for (int messageI = messageCode.size() - 2; messageI >= 0; --messageI)
		{
			messageCode[messageI] -= messageCode[messageI + 1];
		}
	}

protected:
	std::vector<int> messageCode;
	std::vector<int> passwordCode;
};