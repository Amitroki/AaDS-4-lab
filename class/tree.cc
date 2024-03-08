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
		void print_with_recursion_algorithm(RBTreeNode* node) {
			if (!node) {
				return;
			}
			print_with_recursion_algorithm(node->_left);
			cout << node->_value << " ";
			print_with_recursion_algorithm(node->_right);
		}
	public:
		Set() {
			RBTreeNode* left = new RBTreeNode(-1);
			RBTreeNode* right = new RBTreeNode(1);
			_root = new RBTreeNode(0, left, right);
		}
		Set(int value) {
			_root = new RBTreeNode(value);
		}
		Set(RBTreeNode* node) {
			_root = new RBTreeNode(node->_value, node->_left, node->_right);
		}
		void print_with_recursion_algorithm() {
			RBTreeNode* node = _root;

		}
		void print() {
			if (_root) {
				print_with_recursion_algorithm(_root);
			}
			cout << endl;
		}
		/*void print_without_recursion_algorithm() {

			RBTreeNode* processing_node = _root;
			bool indicator_of_reaching_the_leftmost_node = false;
			vector<int> printable_result = {};

			while (processing_node) {

				if (!indicator_of_reaching_the_leftmost_node) {
					while (processing_node->_left) {
						processing_node->_parent = processing_node;
						processing_node = processing_node->_left;
					}
				}

				printable_result.push_back(processing_node->_value);
				indicator_of_reaching_the_leftmost_node = true;

				if (processing_node->_right) {
					indicator_of_reaching_the_leftmost_node = false;
					printable_result.push_back(processing_node->_right->_value);
				}

				else if (processing_node->_parent) {
					while (processing_node->_parent && processing_node == processing_node->_parent->_right)
						processing_node = processing_node->_parent;
					if (!processing_node->_parent)
						break;
					processing_node = processing_node->_parent;
				}

				else break;
			}

			for (int i = 0; i < printable_result.size(); i++) {
				cout << printable_result[i];
			}
			return;
		}*/
	};
}