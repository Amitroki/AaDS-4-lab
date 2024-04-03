#include <fstream>
#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

namespace tree {

	template<typename T>
	struct RBTreeNode {

		T _value;
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;

		RBTreeNode(T number) : _value(number), _left(nullptr), _right(nullptr), _parent(nullptr) {}
		RBTreeNode(T number, RBTreeNode* ref1, RBTreeNode* ref2) : _value(number), _left(ref1), _right(ref2), _parent(nullptr) {}

	};

	template<typename T>
	class Set {
	private:

		RBTreeNode<T>* _root;
		
		RBTreeNode<T>* copying(RBTreeNode<T>* root) {
			if (root) {
				RBTreeNode<int>* copied_el = new RBTreeNode<int>(root->_value);
				copied_el->_left = copying(root->_left);
				copied_el->_right = copying(root->_right);
				return copied_el;
			}
			return nullptr;
		}

		bool adding_element(RBTreeNode<T>* &root, T val) {
			if (!root) {
				root = new RBTreeNode(val);
				return true;
			}
			if (val < root->_value) return adding_element(root->_left, val);
			else if (val > root->_value) return adding_element(root->_right, val);
			return false;
		}

		bool element_presence(RBTreeNode<T>*& root, T val) {
			if (!root) {
				return false;
			}
			if (val < root->_value) return element_presence(root->_left, val);
			else if (val > root->_value) return element_presence(root->_right, val);
			return true;
		}

		bool delete_element(RBTreeNode<T>*& root, T val) {
			if (!root) {
				return false;
			}
			if (val < root->_value) return delete_element(root->_left, val);
			else if (val > root->_value) return delete_element(root->_right, val);
			else {
				if (!root->_left) {
					RBTreeNode<T>* node = root->_right;
					delete root;
					root = node;
				}
				else if (!root->_right) {
					RBTreeNode<T>* node = root->_left;
					delete root;
					root = node;
				}
				else {
					RBTreeNode<T>* node = root->_left;
					while (node->_right) {
						node = node->_right;
					}
					root->_value = node->_value;
					delete_element(root->_left, node->_value);
				}
				return true;
			}
		}

		void deletion(RBTreeNode<T>* root) {
			if (root) {
				deletion(root->_left);
				deletion(root->_right);
				delete root;
			}
			return;
		}

		void print(RBTreeNode<T>* node) {
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

		Set(T value) {
			_root = new RBTreeNode<T>(value);
		}

		Set(RBTreeNode<T>* node) {
			_root = new RBTreeNode<T>(node->_value, node->_left, node->_right);
		}

		Set(const Set<T>& other) {
			_root = copying(other._root);
		}

		Set(const vector<T>& other) {
			_root = nullptr;
			for (auto vec : other) {
				insert(vec);
			}
		}

		Set<T>& operator=(const Set<T>& other) {
			if (this != &other) {
				deletion(_root);
				_root = copying(other._root);
			}
			return *this;
		}

		RBTreeNode<T>* get_root() const {
			return _root;
		}

		bool erase(T value) {
			return delete_element(_root, value);
		}

		bool contain(T value) {
			return element_presence(_root, value);
		}

		bool insert(T value) {
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

	template<typename T>
	size_t get_number_of_elements(const RBTreeNode<T>* node) {
		if (!node) return 0;
		return get_number_of_elements(node->_left) +get_number_of_elements(node->_right) + 1;
	}

	/*bool operator<(const string& lhs, const string& rhs) {
		return lhs.compare(rhs) < 0;
	}
	bool operator>(const string& lhs, const string& rhs) {
		return lhs.compare(rhs) > 0;
	}*/

	template <typename T>
	vector<T> get_unique_elements(const vector<T>& vec) {
		Set<T> before_processing(vec);
		vector<T> after_processing = {};
		size_t sas = get_number_of_elements(before_processing.get_root());
		for (int j = 0; j < sas; j++) {
			int counter = 0;
			for (int i = 0; i < vec.size(); i++) {
				if (before_processing.get_root()->_value == vec[i]) {
					counter++;
				}
			}
			if (counter == 1) {
				after_processing.push_back(before_processing.get_root()->_value);
			}
			before_processing.erase(before_processing.get_root()->_value);
		}
		return after_processing;
	}

	size_t lcg() {
		static size_t x = 0;
		x = (1021 * x + 24631) % 116640;
		return x;
	}

	int random(int a, int b) {
		std::random_device random_device;
		std::mt19937 generator(random_device());
		std::uniform_int_distribution<> distribution(a, b);
		int res = distribution(generator);
		return res;
	}

	uint64_t time_now() {
		using namespace std::chrono;
		return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}

	double set_fill_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			Set<int> new_set;
			int current_count_of_elements = 0;
			uint64_t begin = time_now();
			while (current_count_of_elements != numbers_for_filling) {
				if (new_set.insert(random(-15 * numbers_for_filling, 15 * numbers_for_filling))) {
					current_count_of_elements++;
				}
			}
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double vector_fill_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			vector<int> new_vector;
			int current_count_of_elements = 0; 
			uint64_t begin = time_now();
			while (current_count_of_elements != numbers_for_filling) {
				new_vector.push_back(random(-15 * numbers_for_filling, 15 * numbers_for_filling));
				current_count_of_elements++;
			}
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double set_contain_element_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			Set<int> new_set;
			int current_count_of_elements = 0;
			while (current_count_of_elements != numbers_for_filling) {
				if (new_set.insert(random(-15 * numbers_for_filling, 15 * numbers_for_filling))) {
					current_count_of_elements++;
				}
			}
			uint64_t begin = time_now();
			new_set.contain(random(-5 * numbers_for_filling, 5 * numbers_for_filling));
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double vector_contain_element_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			vector<int> new_vector;
			int current_count_of_elements = 0;
			while (current_count_of_elements != numbers_for_filling) {
				new_vector.push_back(random(-15 * numbers_for_filling, 15 * numbers_for_filling));
				current_count_of_elements++;
			}
			uint64_t begin = time_now();
			size_t element = random(-5 * numbers_for_filling, 5 * numbers_for_filling);
			for (int i = 0; i < new_vector.size(); i++) {
				if (new_vector[i] == element) {
					break;
				}
			}
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double set_insert_element_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			Set<int> new_set;
			int current_count_of_elements = 0;
			while (current_count_of_elements != numbers_for_filling) {
				if (new_set.insert(random(-15 * numbers_for_filling, 15 * numbers_for_filling))) {
					current_count_of_elements++;
				}
			}
			uint64_t begin = time_now();
			new_set.insert(random(-5 * numbers_for_filling, 5 * numbers_for_filling));
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double vector_insert_element_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			vector<int> new_vector;
			int current_count_of_elements = 0;
			while (current_count_of_elements != numbers_for_filling) {
				new_vector.push_back(random(-15 * numbers_for_filling, 15 * numbers_for_filling));
				current_count_of_elements++;
			}
			uint64_t begin = time_now();
			new_vector.push_back(random(-5 * numbers_for_filling, 5 * numbers_for_filling));
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double set_erase_element_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			Set<int> new_set;
			int current_count_of_elements = 0;
			while (current_count_of_elements != numbers_for_filling) {
				if (new_set.insert(random(-15 * numbers_for_filling, 15 * numbers_for_filling))) {
					current_count_of_elements++;
				}
			}
			uint64_t begin = time_now();
			new_set.erase(random(-5 * numbers_for_filling, 5 * numbers_for_filling));
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}

	double vector_erase_element_time(int numbers_for_filling, int attempts) {
		double res = 0;
		for (int attempt = 0; attempt < attempts; attempt++) {
			vector<int> new_vector;
			int current_count_of_elements = 0;
			while (current_count_of_elements != numbers_for_filling) {
				new_vector.push_back(random(-15 * numbers_for_filling, 15 * numbers_for_filling));
				current_count_of_elements++;
			}
			uint64_t begin = time_now();
			size_t element = random(-5 * numbers_for_filling, 5 * numbers_for_filling);
			for (int i = 0; i < new_vector.size(); i++) {
				if (new_vector[i] == element) {
					new_vector.erase(new_vector.begin() + i);
					break;
				}
			}
			uint64_t end = time_now();
			res += (end - begin);
		}
		return res / attempts;
	}
}