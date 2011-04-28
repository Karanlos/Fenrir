#ifndef NODEBASE_H
#define NODEBASE_H

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <map>

namespace fne {

    class NodeBase;

	enum nodeErrorType {
		/**
		 * If the current node and the node it's being connected to creates a loop NODE_ERROR_LOOP is thrown
		 */
		NODE_ERROR_LOOP,
		/**
		 * If a external loop somewhere is found somewhere outside the current loop check NODE_ERROR_EXTERNAL_LOOP is thrown.
		 */
		NODE_ERROR_EXTERNAL_LOOP
	};
	
	struct ErrorInfo {
		/**
		 * Which type the error is.
		 */
		nodeErrorType type;
		/**
		 * At which node the error was found.
		 */
		NodeBase* n;
	};
	
    enum sTypes {
        CONSTANT,
        VEC2,
        VEC3,
        VEC4,
        MAT2,
        MAT3,
        MAT4
    };
    
//    const char* sTypesName[] = {"CONSTANT",
//                        "VEC2",
//                        "VEC3",
//                        "VEC4"};
    
    struct SocketConnectionInfo {
        NodeBase* node;
        char socketID;
    };

    struct SocketInfo {
        
        /**
         *  Socket type. See sTypes.
         */
        sTypes type;
        
        /**
         *  True indicates it's an input socket. False indicates int's and output socket.
         */
        bool input;
        
        /**
         * Name of the socket. Etc. r, g or b.
         */
        std::string name;
        
        /**
         * List of nodes the socket is connected to. List always has a length of maximum 1 if it's an input socket.
         */
        std::list<SocketConnectionInfo> nodes;
    };

    class NodeBase {
    public:
        NodeBase(const std::list<NodeBase*>* nodes);
        virtual ~NodeBase();

        /**
         * Two way connection member function that connects the node with the other specified node.
         * @param n is the node it's being connected to.
         * @param socket is the socket ID the node is being connect from.
         */
        void connectTo(NodeBase* n, char socketID, char socketIDTo);
        /**
         * Two way disconnection member function that disconnects the node with the other specified node.
         * @param n is the node it's being disconnected to.
         * @param socket is the socket that is being disconnected.
         * @param socketFrom is the socket ID 
         */
        void disconnect(char socketID);
        
        /**
         * Returns the socket type of the specified socket.
         * @param socketID indetifies the socket that whos type is wanted.
         * @return 
         */
        sTypes getSocketType(char socketID);
        bool getInputType(char socketID);
        
        void print();

    protected:
        /**
         * 
         * @param n
         */
        void addNodeConnectTo(NodeBase* n, char socketID, char socketIDTo);
        void addNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom);

        void removeNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom);

        void isCircular(NodeBase* n, std::map<NodeBase*, bool>* checkedNodes) throw (ErrorInfo);
        
		/**
		 * Renders a node with minimum(which is 50px or the nessasery width to display the node properly with all sockets) width and 0 height.
         */
		virtual void render();
		/**
		 * Renders a node with the specified width and height. If the width is less than the nessasery width to see all the sockets it will choose the minimum needed size for the rendering.
         * @param width defines how wide the node is.
         * @param height defines how tall the midsection is.
         */
		void render(unsigned short width, unsigned short height);

        std::vector<SocketInfo> sockets;
        
        std::string name;
        
        int loopMax;
        
        const std::list<NodeBase*>* nodes;

    };

}

#endif //NODEBASE_H