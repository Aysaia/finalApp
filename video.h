#pragma once
#include <string>

class Video
{
public:
	Video();
	Video(int id, const std::string& name, const std::string& genre, float rating);
	~Video();
	std::string GetName() const { return name; }

protected:
	int id;
	std::string name;
	std::string genre;
	float rating;
};
