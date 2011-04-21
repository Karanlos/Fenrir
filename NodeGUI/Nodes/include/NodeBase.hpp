#ifndef NODEBASE_H
#define NODEBASE_H

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <map>

namespace fne {

    class NodeBase;

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
    
    struct SocketConnectInfo {
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
        std::list<SocketConnectInfo> nodes;
    };

    class NodeBase {
    public:
        NodeBase();
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
        
        void print();

    protected:
        /**
         * 
         * @param n
         */
        void addNodeConnectTo(NodeBase* n, char socketID, char socketIDTo);
        void addNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom);

        void removeNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom);

        bool isCircular(NodeBase* n, bool* usedArray);
        
        virtual void update() = 0;

        std::vector<SocketInfo> sockets;
        
        std::string name;

    };

}

#endif //NODEBASE_H