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
	{}
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
BNode*  prefind(BNode* p, int data) // находит отца указанного элемента 
{
	if (p != nullptr)
	{

		if (p->left != nullptr && data < p->data)
		{

			if (p->left->data == data )
				return p;
			else
				return prefind(p->left, data);
		}
		else if (p->right != nullptr && data > p->data)
		{
			if (p->right->data == data)
				return p;
			else
				return prefind(p->right, data);
			/* }
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
			*/
		}
		else
		{
			return nullptr;
		}
	}
}
bool del(BNode* root , BNode* &DEL)
{
	if (DEL == nullptr)
	{
		return false;
	}
	else
	{ // Необходимо проработать удаление для случая двух соседей(для случая если у удаляемого есть соседи) 
		if (DEL->left != nullptr && DEL->right != nullptr) // удаление на случай если есть оба соседа. 
		{
			if (DEL != root)
			{
				BNode* left = leftmost(DEL->right);
				BNode* prevleft = prefind(root, left->data);
				BNode* prev = prefind(root, DEL->data);
				DEL->data = left->data;
				prev->left = left->right;
				if (prevleft->left == left)
					prevleft->left = nullptr;
				else
					prevleft->right = nullptr;
				left = nullptr;
			}
			else
			{

				BNode* left = leftmost(DEL->right);
				BNode* prevleft = prefind(root, left->data);
				DEL->data = left->data;
				if (prevleft->left == left)
					prevleft->left = nullptr;
				else
					prevleft->right = nullptr;
				left = nullptr;
			}
		}
		else if (DEL ->left == nullptr && DEL ->right != nullptr) // удаление в случаае только правого соседа. 
		{
			if (DEL == root)
			{
				root = root->right; 
				DEL = nullptr; 
			}
			else
			{
				DEL->data = DEL->right->data;
				BNode* p = DEL->right;
				DEL->right = p->right;
				DEL->left = p->left;
				p = nullptr;
			}
		}
		else if (DEL ->right == nullptr && DEL ->left != nullptr) // Удаление в случае только левого соседа 
		{
			if (root == DEL)
			{
				root = root->left;  
				delete DEL; 
			}
			else
			{
				DEL->data = DEL->left->data;
				BNode* p = DEL->left;
				DEL->left = p->left;
				DEL->right = p->right;
				p = nullptr;
			}
		}
		else if (DEL ->right == nullptr && DEL->left == nullptr) // удаление в случае отсутствия соседей. 
		{
			DEL = nullptr;
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

	// удаление без соседей работает 
	del(r4, find(r4, 73));
	t1->print();
	del(r4, find(r4, 40));
	t1->print();
}