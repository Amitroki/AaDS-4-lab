#include <gtest/gtest.h>
#include <C:/Users/Alex/Desktop/AaDS/lab_4/class/tree.cc>

using namespace tree;
using namespace std;

TEST(TreeNodeTests, Print) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.print_with_recursion();
}
TEST(CreatedSet, Copying1) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	Set b(1);
	b = a;
	b.print_with_recursion();
}
TEST(CreatedSet, Copying2) {
	RBTreeNode* test1_1 = new RBTreeNode(1);
	RBTreeNode* test2_1 = new RBTreeNode(4);
	RBTreeNode* test_res_1 = new RBTreeNode(2, test1_1, test2_1);
	Set a(test_res_1);
	RBTreeNode* test1_2 = new RBTreeNode(3);
	RBTreeNode* test2_2 = new RBTreeNode(3);
	RBTreeNode* test_res_2 = new RBTreeNode(3, test1_2, test2_2);
	Set b(test_res_2);
	b.print_with_recursion();
	b = a;
	b.print_with_recursion();
}
TEST(CreatedSet, CopyConstructor) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	Set b(a);
	b.print_with_recursion();
}
TEST(CreatedSet, InsertElement1) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.insert(5);
	a.print_with_recursion();
}
TEST(CreatedSet, InsertElement2) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.insert(3);
	a.print_with_recursion();
}
TEST(CreatedSet, InsertElement3) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.insert(0);
	a.print_with_recursion();
}
TEST(CreatedSet, ContainElement) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.insert(0);
	if (a.contain(0)) {
		cout << "this set contain 0." << endl;
	}
	else cout << "this set is not contain 0." << endl;
}
TEST(CreatedSet, NotContainElement) {
	RBTreeNode* test1 = new RBTreeNode(1);
	RBTreeNode* test2 = new RBTreeNode(4);
	RBTreeNode* test_res = new RBTreeNode(2, test1, test2);
	Set a(test_res);
	a.insert(0);
	if (a.contain(5)) {
		cout << "this set contain 5." << endl;
	}
	else cout << "this set is not contain 5." << endl;
}