#pragma once

#include <string>
#include <vector>
#include <bitset>

class Hasher
{
public:
	virtual std::string hash(const std::string& message) = 0;
	void setPassword(const std::string& password);

protected:
	virtual std::string getMessage() = 0;
	virtual void setMessage(const std::string& message) = 0;

protected:
	void plusFront();
	void plusBack();
	void minusFront();
	void minusBack();
	void xorFront();
	void xorBack();
	void reverse();
	void plusConstant(int constant);
	void minusConstant(int constant);
	void plusSequenceFront();
	void plusSequenceBack();
	void minusSequenceFront();
	void minusSequenceBack();

protected:
	std::vector<int> messageCode;
	std::vector<int> passwordCode;
};