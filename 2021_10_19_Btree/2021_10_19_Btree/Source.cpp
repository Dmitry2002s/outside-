#include <iostream>

using namespace std; 

struct BNode
{
	int data;
	BNode* left, * right; 
	BNode(int d, BNode *l = nullptr, BNode* r = nullptr) : 
		data(d), left(l),right(r) {}
};

void f_print(BNode* r, int d = 0)
{
	if (r == nullptr)
	{
		return; 
	}
	f_print(r->right, d + 3); 
	for (int i = 0; i < d; i++)
	{
		cout << " "; 
	}
	cout << r->data << endl; 
	f_print(r->left, d + 3); 
}
void cprint(BNode* r)
{
	cout << "---------------------------------------------" << endl; 

	f_print(r);
	cout << "---------------------------------------------" << endl;
}
struct BThree
{
	BNode* root; 
	BThree (BNode * p ) : root(p) {} 
	void print()
	{
		cprint(root);
	}
};
BThree quest1()
{
	BNode* p13 = new BNode(13); 
	BNode* p7 = new BNode(7); 
	BNode* p4 = new BNode(4);
	BNode* p14 = new BNode(14, p13);
	BNode* p10 = new BNode(10, nullptr, p14);
	BNode* p6 = new BNode(6, p4, p7);
	BNode* p1 = new BNode(1);
	BNode* p3 = new BNode(3, p1, p6);
	BNode* p8 = new BNode(8, p3, p10);
	BThree result(p8);
	return result; 
}
BNode* leftmost(BNode *p)
{
	BNode* result = p;
	if (p->left != nullptr)
	{
		result = leftmost(p->left);
	}
	else
	{
		return result; 
	}
}
bool branchesNot(BNode* p)
{
	BNode* k = p; 
	while (k != nullptr)
	{
		if (k->left != nullptr && k->right != nullptr)
		{
			return false; 
		}
		else 
		{
			if (k->left != nullptr)
			{
				branchesNot (k->left); 
			}
			if (k->right != nullptr)
			{
				branchesNot (k->right); 
			}
		}
		return true; 
	}
}
BNode* leftmost_sheet(BNode* p)
{
	BNode* left = p; 
	if (left->left != nullptr)
	{
		left = leftmost_sheet(left->left);
	}
	else if(left->right != nullptr)
	{
		left = leftmost_sheet(left->right);
	}
		return left;
	
}
BNode* left2_sheet(BNode* p)
{
	BNode* roat = p; 
	BNode* second = p; 
	BNode* result  = p;
	BNode* sheet = leftmost_sheet(p);
	while (!branchesNot(second->left))
	{
		second = second->left; 
	}
	result = leftmost_sheet(second->right);
	return result;
	
}
bool del(BNode* del, BThree d)
{
	return 0;
}
bool delete_leftmost(BThree d)
{
	BNode* del = leftmost(d.root); 
	BNode* prev = d.root; 
	while (prev->left != del)
	{
		prev = prev->left; 
	}
	if (del->right == nullptr)
	{
		prev->left = nullptr;
		delete del; 
	}
	else
	{
		prev->left = del->right; 
	}
	return true; 
}
bool delete_leftmost_sheet(BThree d)
{
	BNode* del = leftmost_sheet(d.root);
	BNode* prev = d.root;
	while (prev->left != del && prev->right != del)
	{
		if (prev->left != nullptr)
		{
			prev = prev->left;
		}
		else if (prev->right != nullptr)
		{
			prev = prev->right;
		}
	}
	if (prev->left == del)
	{
		delete del;
		prev->left = nullptr; 
	}
	else
	{
		delete del; 
		prev->right= nullptr; 
	}
	
	return true; 
}
bool add_leftmost(int data,BNode* r )
{
	BNode* NEW = new BNode(data) ;
	BNode* prev = leftmost(r);
	prev->left = NEW; 
	return true; 
}
int main()
{
	BNode* p6 = new BNode(6);
	BNode*p5 = new BNode(5);
	BNode*p4 = new BNode(4);
	BNode* p0 = new BNode(0);
	BNode*p3 = new BNode(3 , p6 , p0 );
	BNode*p2 = new BNode(2 , p4 , p5 );
	BNode*p1 = new BNode(1 ,p2 , p3 );
	BThree t(p1); 
	t.print(); 
	BThree* p = new BThree(quest1().root);
	cout << leftmost(p1)->data << endl; 
	p->print();
	cout << leftmost(p->root)->data << endl;
	delete_leftmost(p->root); 
	p->print();
	cout << " test leftmost_sheet " << leftmost_sheet(p->root)->data << endl; 
	add_leftmost(123, p->root);
	cout << "test add_leftmost" << endl; 
	p->print();
	cout << " test leftmost_sheet " << leftmost_sheet(p->root)->data << endl; 
	cout << "test delete_leftmost_sheet"; 
	delete_leftmost_sheet(p->root);
	p->print();
	delete_leftmost_sheet(p->root);
	p->print();
	delete_leftmost_sheet(p->root);
	p->print();
	cout  << left2_sheet(p->root)->data;
	return EXIT_SUCCESS; 

}