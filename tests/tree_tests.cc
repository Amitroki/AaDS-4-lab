#include <gtest/gtest.h>
#include <C:/Users/Alex/Desktop/AaDS/lab_4/class/tree.cc>

using namespace tree;
using namespace std;

TEST(CreatedSet, Copying1) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	Set<int> b(1);
	b = a;
	b.print_with_recursion();
}
TEST(CreatedSet, Copying2) {
	RBTreeNode<int>* test1_1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2_1 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res_1 = new RBTreeNode<int>(2, test1_1, test2_1);
	Set<int> a(test_res_1);
	RBTreeNode<int>* test1_2 = new RBTreeNode<int>(3);
	RBTreeNode<int>* test2_2 = new RBTreeNode<int>(3);
	RBTreeNode<int>* test_res_2 = new RBTreeNode<int>(3, test1_2, test2_2);
	Set<int> b(test_res_2);
	b.print_with_recursion();
	b = a;
	b.print_with_recursion();
}
TEST(CreatedSet, CopyConstructor) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	Set<int> b(a);
	b.print_with_recursion();
}
TEST(CreatedSet, InsertElement1) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(5);
	a.print_with_recursion();
}
TEST(CreatedSet, InsertElement2) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(3);
	a.print_with_recursion();
}
TEST(CreatedSet, InsertElement3) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(0);
	a.print_with_recursion();
}
TEST(CreatedSet, ContainElement) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(0);
	if (a.contain(0)) {
		cout << "this set contain 0." << endl;
	}
	else cout << "this set is not contain 0." << endl;
}
TEST(CreatedSet, NotContainElement) {
	RBTreeNode<int>* test1 = new RBTreeNode<int>(1);
	RBTreeNode<int>* test2 = new RBTreeNode<int>(4);
	RBTreeNode<int>* test_res = new RBTreeNode<int>(2, test1, test2);
	Set<int> a(test_res);
	a.insert(0);
	if (a.contain(5)) {
		cout << "this set contain 5." << endl;
	}
	else cout << "this set is not contain 5." << endl;
}
TEST(CreatedSet, EraseElement) {
	Set<int> a(1);
	a.insert(0);
	a.insert(5);
	a.insert(3);
	a.insert(2);
	a.insert(4);
	a.insert(6);
	a.print_with_recursion();
	a.erase(5);
	a.print_with_recursion();
}
TEST(CreatedSet, NumberOfElements1) {
	Set<int> a(1);
	a.insert(0);
	a.insert(5);
	a.insert(3);
	a.insert(2);
	RBTreeNode<int>* result = a.get_root();
	cout << "Count of elements: " << get_number_of_elements(result) << endl;
}
TEST(CreatedSet, NumberOfElements2) {
	Set<int> a(1);
	a.insert(0);
	a.insert(5);
	a.insert(3);
	a.insert(2);
	a.insert(2);
	RBTreeNode<int>* result = a.get_root();
	cout << "Count of elements: " << get_number_of_elements(result) << endl;
}
TEST(CreatedSet, NumberOfElements3) {
	Set<int> a(1);
	a.insert(0);
	a.insert(5);
	a.insert(3);
	a.insert(2);
	a.insert(210);
	RBTreeNode<int>* result = a.get_root();
	cout << "Count of elements: " << get_number_of_elements(result) << endl;
}
TEST(CreatedSet, NumberOfElements4) {
	Set<int> a(3);
	a.insert(2);
	a.insert(4);
	cout << a.get_root()->_value;
	a.erase(3);
	cout << a.get_root()->_value;
	a.erase(2);
	cout << a.get_root()->_value;
}
TEST(Task, RemoveDuplicateItems) {
	vector<int> a{ 3, 3, 2, 2, 4, 4, 5, 5, 6, 6 };
	vector<int> result = get_unique_elements(a);
	cout << "Size of resulting array: " << result.size() << endl << "Elements of resulting array: ";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
TEST(Generator, FunctionGenerator1) {
	cout << lcg() << " " << lcg() << " " << lcg() << endl;
}
TEST(ComparisonOfVectorAndSet, FillTime) {
	cout << "Vector time: " << vector_fill_time(1000, 100) << endl;
	cout << "Set time: " << set_fill_time(1000, 100) << endl;
}