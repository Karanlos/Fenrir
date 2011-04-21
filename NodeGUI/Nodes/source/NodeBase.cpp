#include "NodeBase.hpp"

namespace fne {
    
    bool operator == (const SocketConnectInfo& sci1, const SocketConnectInfo& sci2) {
        return true;
    }

    NodeBase::NodeBase() {
        
    }
    
    NodeBase::~NodeBase() {
        
    }
    
    void NodeBase::connectTo(NodeBase* n, char socketID, char socketIDTo) {
        
        if(sockets[socketID].input) {
            
            addNodeConnectFrom(n, socketID, socketIDTo);
            
            n->addNodeConnectTo(this, socketIDTo, socketID);
            
        } else {
            
            addNodeConnectTo(n, socketID, socketIDTo);
            
            n->addNodeConnectFrom(this, socketIDTo, socketID);
            
        }
        
    }
    
    void NodeBase::disconnect(char socketID) {
        if(sockets[socketID].nodes.size() == 0)
            return;
        
        sockets[socketID].nodes.front().node->removeNodeConnectFrom(this, (sockets[socketID].nodes.front()).socketID, socketID);
        
        sockets[socketID].nodes.pop_front();
        
    }
    
    sTypes NodeBase::getSocketType(char socketID) {
        return sockets[socketID].type;
    }
    
    void NodeBase::print() {
        std::cout << '*' << " " << name << std::endl;
        
        int i = 0;
        
        for(std::vector<SocketInfo>::iterator iteS = sockets.begin(); iteS != sockets.end(); iteS++) {
            std::cout << "    " << (*iteS).name << " (Type: " << "VEC2" << ") # " << i << std::endl;
            
            for(std::list<SocketConnectInfo>::iterator iteSC = (*iteS).nodes.begin(); iteSC != (*iteS).nodes.end(); iteSC++) {
                std::cout << "     Connected to: " << (*iteSC).node->name << " #" << int((*iteSC).socketID) << std::endl;
            }
            
            std::cout << std::endl;
            
            i++;
        }
    }
    
    void NodeBase::addNodeConnectTo(NodeBase* n, char socketID, char socketIDTo) {
        for(std::list<SocketConnectInfo>::iterator ite = sockets[socketID].nodes.begin(); ite != sockets[socketID].nodes.end(); ite++)
            if((*ite).node == n && (*ite).socketID == socketIDTo)
                return;
        
        SocketConnectInfo sci = {n, socketIDTo};
        sockets[socketID].nodes.push_back(sci);
    }
    
    void NodeBase::addNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom) {
        
        SocketConnectInfo sci = {n, socketIDFrom};
            
        if(sockets[socketID].nodes.size() == 1)
            disconnect(socketID);

        sockets[socketID].nodes.push_back(sci);
    }
    
    void NodeBase::removeNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom) {
        SocketConnectInfo sci = {n, socketIDFrom};
        sockets[socketID].nodes.remove(sci);
    }
    
    bool NodeBase::isCircular(NodeBase* n, map<NodeBase*, bool> list) {
        
    }
    
}
