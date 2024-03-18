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

		bool adding_element(RBTreeNode* &root, int val) {
			if (!root) {
				root = new RBTreeNode(val);
				return true;
			}
			if (val < root->_value) return adding_element(root->_left, val);
			else if (val > root->_value) return adding_element(root->_right, val);
			return false;
		}

		bool element_presence(RBTreeNode*& root, int val) {
			if (!root) {
				return false;
			}
			if (val < root->_value) return element_presence(root->_left, val);
			else if (val > root->_value) return element_presence(root->_right, val);
			return true;
		}

		bool delete_element(RBTreeNode*& root, int val) {
			if (!root) {
				return false;
			}
			if (val < root->_value) return delete_element(root->_left, val);
			else if (val > root->_value) return delete_element(root->_right, val);
			else {
				if (!root->_left) {
					RBTreeNode* node = root->_right;
					delete root;
					root = node;
				}
				else if (!root->_right) {
					RBTreeNode* node = root->_left;
					delete root;
					root = node;
				}
				else {
					RBTreeNode* node = root->_left;
					while (node->_right) {
						node = node->_right;
					}
					root->_value = node->_value;
					delete_element(root->_left, node->_value);
				}
				return true;
			}
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

		RBTreeNode* get_root() const {
			return _root;
		}

		bool erase(int value) {
			return delete_element(_root, value);
		}

		bool contain(int value) {
			return element_presence(_root, value);
		}

		bool insert(int value) {
			return adding_element(_root, value);
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