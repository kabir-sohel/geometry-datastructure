class Node {
protected:
	Node *_next;
	Node *_prev;
	int _v;
public:
	/*
	Node(int);
	*/
	Node();
	virtual ~Node();
	Node *next(void);
	Node *prev(void);
	Node *insert(Node*);
	Node *remove(void);
	void splice(Node*);
	/*
	int value();//only for testing purpose
	*/
};