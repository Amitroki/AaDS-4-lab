#include <gtest/gtest.h>
#include <C:/Users/Alex/Desktop/AaDS/lab_4/class/tree.cc>

using namespace tree;
using namespace std;

TEST(TreeNodeTests, Print) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.print();
}