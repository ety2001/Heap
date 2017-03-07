// Node.h
// Node class for creating an operator stack
class Node{
	private:
		Node* right;
    Node* left;
		int val;
	public:
		Node(int);
		Node* getRight();
    Node* getLeft();
		int getVal();
		void setRight(Node*);
		void setLeft(Node*);
};
