#include "Paths.h"
#include "Scene.h"

void Paths::put(string key, Scene *value)
{
	map[key] = value;
}

bool Paths::check(string key)
{
	if (map.count(key) > 0)
		return true;

	return false;
}

Scene* Paths::get(string key)
{
	return map[key];
}
