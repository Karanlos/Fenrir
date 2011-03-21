#ifndef STRUCTS_H
#define	STRUCTS_H

namespace Fenrir {

	struct DrawEngineInfo {
		sf::ContextSettings cSettings;
		sf::VideoMode vMode;
		sf::Window window;
	};

	struct GLBufferInfo {
		GLuint VAOID;
		GLuint VBOID;
		GLuint EBOID;
		GLboolean isStatic;
	};

}

#endif	/* STRUCTS_H */

