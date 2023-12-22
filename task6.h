#pragma once

#include<iostream>
#include<memory>

using namespace std;

class BinaryTree{
private:
	struct Node {
		int data;
		shared_ptr<Node> left;
		shared_ptr<Node> right;
	};
	shared_ptr<Node> root;

public:
	BinaryTree() {
		root = nullptr;
	}

	BinaryTree(int temp) {
		shared_ptr<Node> t(new(Node));
		root = t;
		root->data = temp;
		root->left = nullptr;
		root->right = nullptr;
	}

	~BinaryTree() {
	}

	void addData(int temp) {
		if (root) {
			if (temp < root->data) {
				if (!(root->left)) {
					shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					root->left = leave;
				}
				else {
					addBranch(temp, root->left);
				}
			}
			else {
				if (!(root->right)) {
					shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					root->right = leave;
				}
				else {
					addBranch(temp, root->right);
				}
			}
		}
		else {
			shared_ptr<Node> t(new(Node));
			root = t;
			root->data = temp;
			root->left = nullptr;
			root->right = nullptr;
		}
	}

	void addBranch(int temp,shared_ptr<Node> branch) {
			if (temp < branch->data) {
				if (!(branch->left)) {
					shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					branch->left = leave;
				}
				else {
					addBranch(temp, branch->left);
				}
			}
			else {
				if (!(branch->right)) {
					shared_ptr<Node> leave(new(Node));
					leave->data = temp;
					leave->left = nullptr;
					leave->right = nullptr;
					branch->right = leave;
				}
				else {
					addBranch(temp, branch->right);
				}
			}
	}

	void show() {
		if (root) {
			cout << root->data << "\n";
			if (root->left) {
				show(root->left);
			}
			if (root->right) {
				show(root->right);
			}
		}
	};

	void show(shared_ptr<Node> branch) {
		cout << branch->data << "\n";
		if (branch->left) {
				show(branch->left);
		}
		if (branch->right) {
				show(branch->right);
		}
	};

};