#pragma once
#include <string>
#include <unordered_map>

using std::string;

class Scene;

class Paths
{
public:
	void put(string, Scene*);
	bool check(string key);

	Scene* get(string);

private:
	std::unordered_map<string, Scene*> map;
};