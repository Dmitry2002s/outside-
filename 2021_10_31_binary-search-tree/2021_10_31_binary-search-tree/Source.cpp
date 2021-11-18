#include<iostream>
#include<stack>
using namespace std;
struct BNode
{
	int data;
	BNode* left, * right;
	BNode(int d, BNode* l = nullptr, BNode* r = nullptr) :
		data(d), left(l), right(r) {}
};
void f_print(BNode* r, int d = 0) // ôóíêöèÿ îòîáðàæàþùàÿ äåðåâî  
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
void c_print(BNode* r)
{
	if (r == nullptr)
	{
		cout << "BThree is empty" << endl;
		return;
	}
	else
	{
		f_print(r);
	}
}
void cprint(BNode* r)
{
	cout << "---------------------------------------------" << endl;

	c_print(r);
	cout << "---------------------------------------------" << endl;
} // ôóíêöèÿ îòîáðàæåíèÿ ñ ïîëîñêàìè(äëÿ óäîáñòâà) 
void f_del(BNode*& p)
{
	if (p == nullptr)
		return;
	f_del(p->left);
	f_del(p->right);
	p = nullptr;
	delete p;
}
struct BThree
{
	~BThree()
	{
		f_del(root);
	}
	BNode* root;
	BThree(BNode* p) : root(p) {}


	void del0(BNode*& p)
	{
		if (p != nullptr)
		{
			if (p->data == 0)
			{
				f_del(p);
			}
			else if (p->right != nullptr)
				del0(p->right);
			else  if (p->left != nullptr)
			{
				del0(p->left);
			}
		}
		else
		{

		}
	}
	void print()
	{
		cprint(root);
	}

};
BNode*& find(BNode* &r, int data)
{
	if (r == nullptr)
	{
		return r;
	}
	else if (r->data == data)
	{
		return r;
	}
	else if (data < r->data)
	{
		return find(r->left, data);
	}
	else
	{
		return find(r->right, data);
	}
}
BNode* searchRe(BNode* p, int data)
{
	if (p != nullptr)
	{
		if (p->data == data)
		{
			return p;
		}
		else
		{
			if (searchRe(p->left, data) != nullptr)
				return searchRe(p->left, data);
			if (searchRe(p->right, data) != nullptr)
				return searchRe(p->right, data);

		}
	}
	else
	{
		return nullptr;
	}
}
BNode* searchCy(BNode* p, int data)
{
	stack <BNode*> stack;

	BNode* check = p;
	if (p != nullptr)
	{
		stack.push(p);
	}
	else
	{

	}
	while (!stack.empty())
	{
		check = stack.top();
		if (check->data == data)
		{
			return check;
		}
		stack.pop();
		if (check->left != nullptr)
			stack.push(check->left);

		if (check->right != nullptr)
			stack.push(check->right);

	}
	return nullptr;
}
bool addRe(BNode*& p, int data)
{
	if (p != nullptr)
	{
		if (p->data < data)
		{
			addRe(p->right, data);
		}
		else if (p->data == data)
		{
			return false;
		}
		else
		{
			addRe(p->left, data);
		}
	}
	else
	{
		p = new BNode(data);
	}

}
bool addCy(BNode* &p, int data)
{
	stack<BNode*> stack;
	BNode* check = p;
	if (check != nullptr)
	{
		stack.push(check);
	}
	while (!stack.empty())
	{
		check = stack.top();
		stack.pop();
		if (check->data == data)
		{
			return false;
		}
		else if (check->data < data)
		{
			if (check->right != nullptr)
				stack.push(check->right);
			else
			{
				check->right = new BNode(data);
				return true;
			}
		}
		else
		{
			if (check->left != nullptr)
				stack.push(check->left);
			else
			{
				check->left = new BNode(data);
				return true;
			}
		}
	}
}
BNode* leftmost(BNode* p)
{
	if (p == nullptr)
	{
		return p;
	}
	else
	{
		if (p->left == nullptr)
		{
			return p;
		}
		else {
			return leftmost(p->left);
		}
	}
}
BNode*  prefind(BNode* p, int data)
{

	if (p != nullptr)
	{
		if (p->left != nullptr)
		{
			if (p->left->data == data)
			{
				return p;
			}
		}
		else if (p->right != nullptr)
		{
			if (p->right->data == data)
			{
				return p;
			}
		}
		else
		{
			if (searchRe(p->left, data) != nullptr)
				return searchRe(p->left, data);
			if (searchRe(p->right, data) != nullptr)
				return searchRe(p->right, data);

		}
	}
	else
	{
		return nullptr;
	}

}
bool del(BNode* & r)
{
	if (r == nullptr)
	{
		return false;
	}
	else
	{
		if (r->left != nullptr && r->right != nullptr)
		{
			
			BNode* left = leftmost(r->right);
			r->data = left->data;
			BNode* prev = prefind(r->right, left->data);
			
			prev->left = left->right;
			left = nullptr;


		}
		else if (r->left == nullptr && r->right != nullptr)
		{
			if (r->right == nullptr)
			{
				r = nullptr;
			}
			else
			{
				r->data = r->right->data;
				BNode* p = r->right;
				r->right = p->right;
				r->left = p->left;
				p = nullptr;
			}

		}
		else if (r->right == nullptr && r->left != nullptr)
		{
			r->data = r->left->data;
			BNode* p = r->left;
			r->left = p->left;
			r->right = p->right;
			p = nullptr;
		}
		else if (r->right == nullptr && r->left == nullptr)
		{
			r = nullptr;
		}
		return true;
	}
}

int main()
{
	BNode* r1 = new BNode(10);
	BNode* r6 = new BNode(60);
	BNode* r7 = new BNode(70, r6, nullptr);
	BNode* r5 = new BNode(50, nullptr, r7);
	BNode* r2 = new BNode(30);
	BNode* r3 = new BNode(20, r1, r2);
	BNode* r4 = new BNode(40, r3, r5);
	BThree* t1 = new BThree(r4);
	t1->print();
	cout << find(r4, 30)->data;
	addRe(r4, 123);
	addRe(r4, 73);
	addRe(r4, 83);
	addRe(r4, 13);
	addRe(r4, 543);
	addRe(r4, 2);
	addRe(r4, 23);
	addRe(r4, 13);
	addRe(r4, 43);
	addRe(r4, 1);
	t1->print();
	del(r4);
	t1->print();
	del(r7);
	t1->print();
	del(r6);
	cout << "TEST" << endl;
	t1->print();
	del(find(r4, 1));
	del(find(r4, 60));

	t1->print();
}