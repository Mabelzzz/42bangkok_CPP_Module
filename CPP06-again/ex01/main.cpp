#include "Serializer.hpp"

int main()
{
	Data data;
	data.number = 42;
	data.character = 'B';
	data.decimal = 3.14f;
	data.largeDecimal = 3.1415;
	data.text = "Mobile";

	std::cout << GRAY << "-- Original Data -- " << RESET << std::endl;
	std::cout << "Data number: " << data.number << std::endl;
	std::cout << "Data character: " << data.character << std::endl;
	std::cout << "Data decimal: " << data.decimal << std::endl;
	std::cout << "Data largeDecimal: " << data.largeDecimal << std::endl;
	std::cout << "Data text: " << data.text << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << MAGENTA  << "-- Serialized : After converts Data* to the unsigned integer --" << RESET << std::endl;
	std::cout << "Data (uintptr_t): " << serialized  << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << BLUE << "-- Deserialized: After converts the unsigned integer back to Data* --" << RESET << std::endl;
	std::cout << "Data number: " << deserialized->number << std::endl;
	std::cout << "Data character: " << deserialized->character << std::endl;
	std::cout << "Data decimal: " << deserialized->decimal << std::endl;
	std::cout << "Data largeDecimal: " << deserialized->largeDecimal << std::endl;
	std::cout << "Data text: " << deserialized->text << std::endl;

	std::cout << YELLOW << "-- Pointer Comparison -- " << RESET << std::endl;
	std::cout << "Original Data pointer: " << &data << std::endl;
	std::cout << "Deserialized Data pointer: " << deserialized << std::endl;
	if (&data == deserialized)
		std::cout << GREEN << "Success: The deserialized pointer matches the original data pointer." << RESET << std::endl;
	else
		std::cout << RED << "Error: The deserialized pointer does not match the original data pointer." << RESET << std::endl;


	return 0;
}
