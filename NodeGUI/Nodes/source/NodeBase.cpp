#include "NodeBase.hpp"

namespace fne {

	bool operator ==(const SocketConnectionInfo& sci1, const SocketConnectionInfo& sci2) {
		return true;
	}

	NodeBase::NodeBase(const std::list<NodeBase*>* nodes) {
		this->nodes = nodes;
		loopMax = 0;
	}

	NodeBase::~NodeBase() {

	}

	void NodeBase::connectTo(NodeBase* n, char socketID, char socketIDTo) {
		if (this == n)
			return;

		std::cout << std::endl << std::endl << "Node: " << this->name << " NodeTo: " << n->name << " socketID: " << int(socketID) << " socketIDTo: " << int(socketIDTo) << std::endl;

		std::map < NodeBase*, bool> checkedNodes;

		for (std::list<NodeBase*>::const_iterator ite = nodes->begin(); ite != nodes->end(); ite++) {
			checkedNodes.insert(std::pair < NodeBase*, bool>((*ite), false));
		}

		if (sockets[socketID].input) {

			if (n->getInputType(socketIDTo)) {
				std::cout << __LINE__ << std::endl;
				return;
			}

			try {
				n->isCircular(this, &checkedNodes);
			} catch (ErrorInfo info) {
				if (info.type == NODE_ERROR_LOOP) {
					std::cout << __LINE__ << std::endl;
					return;
				}
			}

			addNodeConnectFrom(n, socketID, socketIDTo);

			n->addNodeConnectTo(this, socketIDTo, socketID);
		} else {

			checkedNodes.insert(std::pair < NodeBase*, bool>(this, true));

			if (!(n->getInputType(socketIDTo))) {
				std::cout << __LINE__ << std::endl;
				return;
			}

			try {
				n->isCircular(this, &checkedNodes);
			} catch (ErrorInfo info) {
				if (info.type == NODE_ERROR_LOOP) {
					std::cout << __LINE__ << std::endl;
					return;
				}
			}

			addNodeConnectTo(n, socketID, socketIDTo);

			n->addNodeConnectFrom(this, socketIDTo, socketID);

		}

		for (std::map < NodeBase*, bool>::iterator ite = checkedNodes.begin(); ite != checkedNodes.end(); ite++) {
			std::cout << "NodeBase*: " << ite->first << " bool: " << ite->second << std::endl;
		}

	}

	void NodeBase::disconnect(char socketID) {
		if (sockets[socketID].nodes.size() == 0 || !getInputType(socketID))
			return;

		sockets[socketID].nodes.front().node->removeNodeConnectFrom(this, (sockets[socketID].nodes.front()).socketID, socketID);

		sockets[socketID].nodes.pop_front();

	}

	sTypes NodeBase::getSocketType(char socketID) {
		return sockets[socketID].type;
	}

	bool NodeBase::getInputType(char socketID) {
		return sockets[socketID].input;
	}

	void NodeBase::print() {
		std::cout << '*' << " " << name << std::endl;

		int i = 0;

		for (std::vector<SocketInfo>::iterator iteS = sockets.begin(); iteS != sockets.end(); iteS++) {
			std::cout << "    " << (*iteS).name << " (Type: " << "VEC2" << ") # " << i << std::endl;

			for (std::list<SocketConnectionInfo>::iterator iteSC = (*iteS).nodes.begin(); iteSC != (*iteS).nodes.end(); iteSC++) {
				std::cout << "     Connected to: " << (*iteSC).node->name << " #" << int((*iteSC).socketID) << std::endl;
			}

			std::cout << std::endl;

			i++;
		}
	}

	void NodeBase::addNodeConnectTo(NodeBase* n, char socketID, char socketIDTo) {
		for (std::list<SocketConnectionInfo>::iterator ite = sockets[socketID].nodes.begin(); ite != sockets[socketID].nodes.end(); ite++)
			if ((*ite).node == n && (*ite).socketID == socketIDTo)
				return;

		SocketConnectionInfo sci = {n, socketIDTo};
		sockets[socketID].nodes.push_back(sci);
	}

	void NodeBase::addNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom) {

		SocketConnectionInfo sci = {n, socketIDFrom};

		if (sockets[socketID].nodes.size() == 1)
			disconnect(socketID);

		sockets[socketID].nodes.push_back(sci);
	}

	void NodeBase::removeNodeConnectFrom(NodeBase* n, char socketID, char socketIDFrom) {
		SocketConnectionInfo sci = {n, socketIDFrom};
		sockets[socketID].nodes.remove(sci);
	}

	void NodeBase::isCircular(NodeBase* n, std::map<NodeBase*, bool>* checkedNodes) throw (ErrorInfo) {
		if (!checkedNodes->find(this)->second && this == n) {
			std::cout << __LINE__ << std::endl;
			ErrorInfo info = {NODE_ERROR_LOOP, this};
			throw info;
		} else if (checkedNodes->find(this)->second) {
			ErrorInfo info = {NODE_ERROR_EXTERNAL_LOOP, this};
			throw info;
		}

		checkedNodes->at(this) = true;

		for (unsigned char i = 0; i < (unsigned char) (sockets.size()); i++) {
			std::cout << __LINE__ << std::endl;
			if (!sockets[i].input) {
				std::cout << "Node: " << this->name << " Nodes connected: " << sockets[i].name << " " << sockets[i].nodes.size() << std::endl;
				for (std::list<SocketConnectionInfo>::iterator ite = sockets[i].nodes.begin(); ite != sockets[i].nodes.end(); ite++) {
					std::cout << __LINE__ << std::endl;
					try {
						ite->node->isCircular(n, checkedNodes);
					} catch (ErrorInfo info) {
						throw info;
					}
					//					if (ite->node->isCircular(n, checkedNodes)) {
					//						std::cout << __LINE__ << std::endl;
					//						return true;
					//					}
				}
			}
		}

	}

}
