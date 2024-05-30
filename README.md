# Encryption

Encryption and decryption a message using password.

---

You have 13 methods at your disposal, but you can add your own:
1. ```void plusFront()```;
2. ```void plusBack()```;
3. ```void minusFront()```;
4. ```void minusBack()```;
5. ```void xorFront()```;
6. ```void xorBack()```;
7. ```void reverse()```;
8. ```void plusConstant(int constant)```;
9. ```void minusConstant(int constant)```;
10. ```void plusSequenceFront()```;
11. ```void plusSequenceBack()```;
12. ```void minusSequenceFront()```;
13. ```void minusSequenceBack()```;

## Examples

### Encryption

Message: ```Hello, World!```
Password: ```qwerty1```

```cpp
#include <iostream>
#include "hasher/encryptor.h"

int main()
{
	Encryptor e;

	e.setPassword("qwerty1");

	std::cout << e.hash("Hello, World!") << std::endl;

	return 0;
}
```

After encryption we get the code: ```10110110100101111111011101101000001010010000001101001110001101111000011011000001111110110011010000111001```

___

### Decryption

Code: ```10110110100101111111011101101000001010010000001101001110001101111000011011000001111110110011010000111001```
Password: ```qwerty1```


```cpp
#include <iostream>
#include "hasher/decryptor.h"

int main()
{
	Decryptor d;

	d.setPassword("qwerty1");

	std::cout << d.hash("10110110100101111111011101101000001010010000001101001110001101111000011011000001111110110011010000111001") << std::endl;

	return 0;
}
```

After decryption we get the message: ```Hello, World!```
