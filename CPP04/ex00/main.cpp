#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* sus = new Animal();
	const Animal* meow = new Cat();
	const Animal* hong = new Dog();

	std::cout << "Animal type: " << meow->get_type() << " " << std::endl;
	std::cout << "Animal sound: ";
	meow->makeSound();

	std::cout << "Animal type: " << hong->get_type() << " " << std::endl;
	std::cout << "Animal sound: ";
	hong->makeSound();

	std::cout << "Unknown Animal sound: ";
	sus->makeSound();	// unknown animal sound

	delete sus;
	delete meow;
	delete hong;

	std::cout << "======================================================" << std::endl;

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "Animal type: " << wrong_cat->get_type() << " " << std::endl;
	std::cout << "Animal sound: ";
	wrong_cat->makeSound();

	std::cout << "Animal type: " << wrong_meta->get_type() << " " << std::endl;
	std::cout << "Animal sound: ";
	wrong_meta->makeSound();

	// std::cout << std::endl;
	delete wrong_meta;
	delete wrong_cat;

	return 0;
}
