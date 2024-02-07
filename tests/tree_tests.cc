#include <gtest/gtest.h>
#include <C:/Users/Alex/Desktop/AaDS/lab_4/class/tree.cc>

using namespace tree;
using namespace std;

TEST(TreeNodeTests, Print) {
	treeNode test1(1);
	treeNode test2(4);
	treeNode a(2, test1, test2);
	treeNode b(4);
	treeNode c(10, a, b);
	c.print();
}