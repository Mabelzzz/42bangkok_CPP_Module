
# include "Contact.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void set_firstname(std::string firstname)
{
	this->firstname = firstname;
}

void set_lastname(std::string lastname)
{
	this->lastname = firstname;
}

void set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void set_phone(std::string phone)
{
	this->phone = phone;
}

void set_secret(std::string secret)
{
	this->secret = secret;
}

std::string Contact::get_firstname()
{
	// this->firstname = firstname;
	return (this->firstname);
}

std::string Contact::get_lastname()
{
	// this->lastname = lastname;
	return (this->lastname);
}

std::string Contact::get_nickname()
{
	// this->nickname = nickname;
	return (this->nickname);
}

std::string Contact::get_phone()
{
	// this->phone = phone;
	return (this->phone);
}

std::string Contact::get_secret()
{
	// this->secret = secret;
	return (this->secret);
}
