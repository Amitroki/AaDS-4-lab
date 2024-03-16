#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

namespace tree {

	struct RBTreeNode {
		int _value;
		RBTreeNode* _left;
		RBTreeNode* _right;
		RBTreeNode* _parent;
		RBTreeNode(int number) : _value(number), _left(nullptr), _right(nullptr), _parent(nullptr) {}
		RBTreeNode(int number, RBTreeNode* ref1, RBTreeNode* ref2) : _value(number), _left(ref1), _right(ref2), _parent(nullptr) {}
	};

	class Set {
	private:

		RBTreeNode* _root;
		
		RBTreeNode* copying(RBTreeNode* root) {
			if (root) {
				RBTreeNode* copied_el = new RBTreeNode(root->_value);
				copied_el->_left = copying(root->_left);
				copied_el->_right = copying(root->_right);
				return copied_el;
			}
			return nullptr;
		}

		void deletion(RBTreeNode* root) {
			if (root) {
				deletion(root->_left);
				deletion(root->_right);
				delete root;
			}
			return;
		}

		void print(RBTreeNode* node) {
			if (!node) {
				return;
			}
			print(node->_left);
			cout << node->_value << " ";
			print(node->_right);
		}

	public:

		Set() {
			_root = nullptr;
		}

		Set(int value) {
			_root = new RBTreeNode(value);
		}

		Set(RBTreeNode* node) {
			_root = new RBTreeNode(node->_value, node->_left, node->_right);
		}

		Set(const Set& other) {
			_root = copying(other._root);
		}

		Set& operator=(const Set& other) {
			if (this != &other) {
				deletion(_root);
				_root = copying(other._root);
			}
			return *this;
		}

		void print_with_recursion() {
			if (_root) {
				print(_root);
			}
			cout << endl;
		}

		~Set() {
			deletion(_root);
		}
	};
}