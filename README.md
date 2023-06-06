

## Использование

Пример использования класса Dictionary:

```cpp
#include "dictionary.hpp"

int main()
{
    Dictionary<std::string, int> dict;

    dict.set("key1", 10);
    dict.set("key2", 20);

    try {
        int value1 = dict.get("key1");
        int value2 = dict.get("key2");
        int value3 = dict.get("key3"); // throws NotFoundException

        // Дополнительная обработка значений
    } catch (const NotFoundException<std::string>& e) {
        // Обработка исключения отсутствия значения
    }

    return 0;
}```
