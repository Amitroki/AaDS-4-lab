#include <fstream>
#include <iostream>

using namespace std;

namespace tree {
	template<typename T>
	struct treeNode {
	private:
		T _value;
		treeNode* _left;
		treeNode* _right;
	public:
		treeNode() : _value(0), _left(nullptr), _right(nullptr) {}
		treeNode(T number) : _value(number), _left(nullptr), _right(nullptr) {}
		treeNode(T number, treeNode ref1, treeNode ref2) : _value(number), _left(&ref1), _right(&ref2) {}
		void print() const {
			if (this == nullptr) return;
			this->_left->print();
			cout << this->_value << " ";
			this->_right->print();
		}
	};
}