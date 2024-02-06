namespace binarySearchTree {
	template<typename T>
	class treeNode {
	private:
		T _value;
		treeNode* _left;
		treeNode* _right;
	public:
		treeNode() : _value(0), _left(nullptr), _right(nullptr) {}
	};
}