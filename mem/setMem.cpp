//
// Created by seymo on 3/26/2021.
//





#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>
#include <dirent.h>
#include <algorithm>

#include <quarilo/query.h>


Quarilo::Query<std::string>* NewAllocations{ };

static void add_alloc(int c)
{
	/**
	 * I Forgot i added quarillax.
	 * Pushes items to the allocations Chart.
	 */
	NewAllocations->additems(std::to_string(c));
}

static std::string first_alloc()
{
	return NewAllocations->first();
}

static std::string lookup(const std::string& T)
{
	return NewAllocations->get(T);
}
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <climits>

std::string exec(const char* cmd) {
	char buffer[128];
	std::string result;
	FILE* pipe = popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
			result += buffer;
		}
	} catch (...) {
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return result;
}
int get_files(const char* path)
{
	DIR* dir;
	struct dirent* ent;
	if ((dir = opendir(path)) != nullptr)
	{
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != nullptr)
		{
			printf("~/%s\n", ent->d_name);
		}
		closedir(dir);
	}
	else
	{
		/* could not open directory */
		perror("");
		return EXIT_FAILURE;
	}
	return 0;
}

int main(int argc, char** argv)
{
	
	std::string arg = argv[1];
	
	get_files(".");
	if (!arg.empty())
	{
		
		if (arg == "-h" || arg == "--help")
		{
			std::cout << "-h | --help \n-t | --test\n-shell | -sh" << std::endl;
		}
		else if (arg == "--shell") {
			std::cout << "ok" << std::endl;
			system("cls");
			
			
			
			
			while (true) {
				std::string T;
				std::cout << "(shell) ";
				getline(std::cin, T);
				std::remove_if(T.begin(), T.end(), isspace);
				
				
				std::string func = T.substr(0, T.find('('));
				if (func == "hello") {
					std::cout << "Hello, World!" << std::endl;
				}
				else if (func == "help") {
					std::cout << "help menu" << std::endl;
				}
				else if (func == "exit") {
					break;
				}
				else if (func == "getIPConfig") {
					exec("ipconfig > ip.txt");
					std::cout << "View ip.txt to view IP Log." << std::endl;
				}
				else if (func == "printf") {
					std::string f = T.substr(T.find('(')+1);
					f.erase(std::remove(f.begin(), f.end(), ')'), f.end());
					std::cout << f << std::endl;
				}
				else {
					if (T.find('(') == std::string::npos) {
						std::cout << "\nKeyword Is not a function." << std::endl;
					}
					else
					{
						std::cout << "'(' Was unexpected at this time." << std::endl;
					}
					
					
				}
				
				
			}
		}
	}
}
