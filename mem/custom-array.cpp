//
// Created by seymo on 3/26/2021.
//

#include <iostream>

int main(int argc, char* * argv) {
	std::string arg = argv[1];
	if (arg == "-h" || arg == "--help") {
		std::cout << "-h --help --shell -sh" << std::endl;
	}
	else if (arg == "-sh" ||  arg == "--shell") {
		
	}
}

