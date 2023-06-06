#include <iostream>

#include <dictionary.hpp>

int main()
{
	Dict::dictionaryImpl<std::string_view, int > dict;
	dict.set("one", 1);
	dict.set("two", 2);

	try {
		std::cout << dict.get("one") << std::endl;  // Output: 1
		std::cout << dict.get("two") << std::endl;  // Output: 2
		std::cout << dict.get("three") << std::endl;  // Throws not_found_exception
	}
	catch (const Dict::not_found_exception<std::string_view>& e) {
		std::cout << "Key not found: " << e.get_key() << std::endl;
	}
	return 0;
}
