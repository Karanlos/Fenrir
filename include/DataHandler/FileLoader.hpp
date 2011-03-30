#ifndef FILELOADER_H
#define	FILELOADER_H

#include <fstream>
#include <string>

using namespace std;
namespace fen {

	namespace FEnum {
		enum {
			controls,
			graphicsettings
		};
	}

	class FileLoader {

	public:
		FileLoader();
		FileLoader(char* fileName, int sector);
		virtual ~FileLoader();

		void useFile();

	private:
		string fileName;
		fstream file;

	};
	
}

#endif	/* FILELOADER_H */

