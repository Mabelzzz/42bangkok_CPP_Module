#include "Sed.hpp"

Sed::Sed() {

}

Sed::Sed(const std::string& file, const std::string& s1, const std::string& s2) : infile(file), s1(s1), s2(s2), str(""), data(""), filename(file) {

}

Sed::~Sed() {
	infile.close();
	outfile.close();
}

void Sed::get_data()
{
	if(infile.is_open())
	{
		std::string	line;

		while (std::getline(infile, line))
  			data = data + line + "\n";
	}
	else
		std::cerr << RED << "Cannot open infile" << std::endl;
}

void	Sed::replace_str()
{
	if (s1 == s2 || s1.empty())
		return ;
	while((cur = data.find(s1, cur)) != std::string::npos)
	{
		str = (data.substr(0, cur) + s2 + data.substr(cur + s1.size()));
		data = str;
		cur += s2.size();
	}
}

int	Sed::create_outfile()
{
	outfile.open(filename + ".replace");
	if(outfile.is_open()){
		outfile << data;
		return (0);
	}
	return (1);
}
