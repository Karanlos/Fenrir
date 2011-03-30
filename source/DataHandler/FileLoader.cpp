#include "DataHandler/FileLoader.hpp"

namespace Fenrir {

	FileLoader::FileLoader(char* fileName, int sector) {

		this->fileName = fileName;

	}

	FileLoader::~FileLoader() {

		if(file.is_open())
			file.close();

	}

	void FileLoader::useFile() {
		file.open(fileName.c_str(), ios::in | ios::out | ios::binary);
	}

}

