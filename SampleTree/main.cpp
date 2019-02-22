#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <memory>
#include "treenode.h"

int main(int argc, char *argv[])
{

    TreeNode<int> a1(1, "dziwak");
    TreeNode<int>* ptr = nullptr;
    a1.addChild(std::make_shared<TreeNode<int>>(1));
    a1.addChild(std::make_shared<TreeNode<int>>(2));
    a1.addChild(std::make_shared<TreeNode<int>>(3));

    ptr = a1.getChild(0);
    ptr -> addChild(std::make_shared<TreeNode<int>>(4));
    ptr -> addChild(std::make_shared<TreeNode<int>>(5));

    ptr = a1.getChild(1);
    ptr -> addChild(std::make_shared<TreeNode<int>>(6));

    ptr = a1.getChild(0);

    ptr = ptr -> getChild(0);
    ptr -> addChild(std::make_shared<TreeNode<int>>(7));

    std::cout << ptr -> serializeTree() <<std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
