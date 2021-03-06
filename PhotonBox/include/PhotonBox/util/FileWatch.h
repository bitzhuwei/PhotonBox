#ifndef FILE_WATCH_H
#define FILE_WATCH_H

class Shader;

#include <iostream>
#include <map>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#define stat _stat


class FileWatch
{
public:
	struct ShaderFile
	{
		__time64_t stamp;
		Shader* shader;
	};

	static void addToWatchList(std::string filePath, Shader* shader);
	void checkValidity();
private:
	static std::map<std::string, ShaderFile> _watchList;
};

#endif FILE_WATCH_H
