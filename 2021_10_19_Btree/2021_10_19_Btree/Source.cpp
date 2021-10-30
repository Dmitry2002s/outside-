#include <iostream>
#include <Stack>
using namespace std; 


struct BNode
{
	int data;
	BNode* left, * right; 
	BNode(int d, BNode *l = nullptr, BNode* r = nullptr) : 
		data(d), left(l),right(r) {}
};

void f_del(BNode* &p);
void f_print(BNode* r, int d = 0) // функция отображающая дерево  
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
} // функция отображения с полосками(для удобства) 
struct BThree
{
	~BThree()
	{
		f_del(root);
	}
	BNode* root; 
	BThree (BNode * p ) : root(p) {} 
	

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
BThree *quest1() // создание дерева из задания 
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
	BThree* result = new BThree(p8);
	return result; 
}
BThree* quest2() // создание дерева из задания 
{
	BNode* p13 = new BNode(13);
	BNode* p7 = new BNode(7);
	BNode* p4 = new BNode(4);
	BNode* p14 = new BNode(0, p13);
	BNode* p10 = new BNode(10, nullptr, p14);
	BNode* p6 = new BNode(0, p4, p7);
	BNode* p1 = new BNode(1);
	BNode* p3 = new BNode(0, p1, p6);
	BNode* p8 = new BNode(8, p3, p10);
	BThree* result = new BThree(p8);
	return result;
}
BNode* leftmost(BNode *p) // левейший узел 
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
} // 
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
} // функция проверающая наличие разветвлений у "веток" узла. 
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
	
} // левейший лист 
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
	
}  // функция проверяет наличие веток у элемента - если они есть, 
 // то проверяет следующий по ветке элемент(Сначала левый, в случае отсутствия - правый) на наличие веток.
// Если веток не оказывается - то отправляет в противоположную сторону функцию левейшего листа 

bool delete_leftmost(BThree *d)
{
	BNode* del = leftmost(d->root); 
	BNode* prev = d->root; 
	if (del == prev)
	{

		delete del;
		return true; 
		
	}
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
		delete del; 
	}
	return true; 
}
bool delete_leftmost_sheet(BThree *d)
{
	BNode* del = leftmost_sheet(d->root);
	BNode* prev = d->root;
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

// homework 2
bool scale(BNode* d)
{
	BNode* r = d; 
	if (r != nullptr)
	{
		r->data *=3; 
	}
	if (r->left != nullptr)
	{
		scale(r->left);
	}
	if (r->right != nullptr)
	{
		scale(r->right);
	}
	return true; 
}
int sum(BNode* d , int result = 0)
{

	BNode* r = d; 
	if (r != nullptr)
	{
		result = result + r->data + sum(r->right) + sum(r->left);
		return result; 
	}
	else
	{
		return 0; 
	}
}
int count_neg(BNode* d, int result = 0)
{
	BNode* r = d; 
	if (r != nullptr)
	{
		if (r->data < 0)
		{
			result += 1; 
		}
		result = result + count_neg(r->right) + count_neg(r->left);
		return result;
	}
	else
	{
		return 0; 
	}
}
int height(BNode* d, int result = 0)
{
	BNode* r = d;
	if (r!=nullptr)
	{
		result += 1; 
		result = result += (height(r->left) > height(r->right) ? height(r->left) : (height(r->right)));
		return result; 
	}
	else
	{
		return 0; 
	}
}
bool reflect(BNode* d)
{
	BNode* r = d;
	if (r == nullptr)
	{
		return true; 
	}
	if (r->right != nullptr || r->left != nullptr)
	{
		BNode* l = d->left;
		d->left = d->right; 
		d->right = l; 
		reflect(r->right);
		reflect(r->left);
	}
	
}
int mult(BNode* d, int result = 1)
{
	BNode* r = d;
	if (r != nullptr)
	{
		/*(r->right != nullptr && r->left != nullptr) ?*/ result = result * r->data; /*result = result*/;
		result = result *  mult(d->right) * (mult(d->left));
		return result; 
	}
	else
	{
		return result; 
	}
}
int eval(BNode* d, int result = 0)
{
	BNode* r = d;
	if (r != nullptr)
	{
		if (r->right != nullptr && r->left != nullptr)
		{
			switch (r->data)
			{
			case 1: result = eval(r->right) + eval(r->left); break;
			case 2: result = eval(r->right) - eval(r->left); break;
			case 3: result = eval(r->right) * eval(r->left); break;
			case 4: 	if (eval(r->right) != 0 && (eval(r->left) != 0))
			{
				if (eval(r->right) > 0 && eval(r->right) > 0)
				{
					if (eval(r->right) > eval(r->left))
					{
						return (eval(r->right) / eval(r->left));
					}
					else
					{
						return (eval(r->left) / eval(r->right));
					}
				}
				else
				{
					if (eval(r->right) < eval(r->left))
					{
						return (eval(r->right) / eval(r->left));
					}
					else
					{
						return (eval(r->left) / eval(r->right));
					}
				}
			}
			}
		}
		else if (r->right != nullptr)
		{
			return eval(r->right);
		}
		else if (r->left != nullptr)
		{
			return eval(r->left);
		}
		else
		{
			return r->data;
		}
	}
}
BNode* find(BThree d, int T)
{
	BNode* r = d.root; 
	if (r->data == T)
	{
		return r; 
	}
	else
	{
		if (find(r->left, T) != nullptr)
		{
			return find(r->left, T);
		}
		else if (find(r->right, T) != nullptr)
		{
			return find(r->right, T);
		}
	}
	return nullptr; 
}
int min(BNode *d, int result = INT_MAX)
{
	if (d != nullptr)
	{
		if (result > d->data)
		{
			result = d->data;
		}
		if (result > min(d->left, result))
		{
			result = min(d->left, result);
		}
		if (result > min(d->right), result)
		{
			result = min(d->right, result);
		}
	}
	return result; 

}

// homework 3 
void f_del(BNode* &p)
{
	if (p == nullptr)
		return; 
	f_del(p->left);
	f_del(p->right);
	p = nullptr; 
	delete p;
}
void del0(BNode* &p)
{
	if (p == nullptr)
	{
		

	}
	else
	{
		if (p->data == 0)
		{
			f_del(p);
			return;
		}
		else {
			if (p->right != nullptr)
			{
				del0(p->right);
			}
			if (p->left != nullptr)
			{
				del0(p->left);
			}
		}
	}
}
void delLeaves(BNode* &p)
{
	if (p == nullptr)
	{
		
	}
	else
	{
		if (p->left == nullptr && p->right == nullptr)
		{
			p = nullptr;
			delete p;
		}
		else
		{
			delLeaves(p->left);
			delLeaves(p->right);
		}
	}
}
void enlarge(BNode*& p,int d )
{
	if (p == nullptr)
	{
		BNode* k = new BNode(d);
		p = k; 
	}
	else 
	{
		enlarge(p->left,d );
		enlarge(p->right, d );
	}
}
void dell(BNode*& p)
{
	if (p == nullptr)
	{
		return; 
	}
	else if (p->data == 1)
	{
		f_del(p);
	}
	else
	{
		if(p->left !=nullptr)
		if (p->left->data == 1)
		{
			f_del(p->left->left);
			BNode* k = p->left; 
			p->left = k->right; 
			k = nullptr;
			delete k; 
		}
		if(p->right!=nullptr)
		if (p->right->data == 1)
		{
			f_del(p->right->left);
			BNode* k = p->right;
			p->right = k->right;
			k = nullptr;
			delete k;
		}
		dell(p->right);
		dell(p->left);
	}
}
int sum_alt(BNode* p,int result = 0)
{
	if (p != nullptr)
	{
		if(p->right !=nullptr)
		result += p->right->data + sum_alt(p->right);
		if (p->left != nullptr)
			result -= p->left->data + sum_alt(p->left);
	}
	return result; 
}
//homework 4 
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
bool addRe(BNode* p, int data)
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
		p->data = data; 
	}

}
bool addCy(BNode* p, int data)
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
			return false ; 
		}
		else if (check->data < data)
		{
			if (check->right != nullptr)
				stack.push(check->right);
			else
			{
				check->right =new BNode(data);
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
int main()
{
	BNode* p6 = new BNode(6);
	BNode*p5 = new BNode(5);
	BNode*p4 = new BNode(4);
	BNode* p0 = new BNode(1);
	BNode*p3 = new BNode(3 , p6 , p0 );
	BNode*p2 = new BNode(1 , p4 , p5 );
	BNode*p1 = new BNode(3 ,p2 , p3 );
	BThree t(p1); 
	t.print(); 
	BThree* p = quest1();
	cout << leftmost(p1)->data << endl; 
	p->print();
	cout << leftmost(p->root)->data << endl;
	delete_leftmost(p); 
	p->print();
	cout << " test leftmost_sheet " << leftmost_sheet(p->root)->data << endl; 
	add_leftmost(123, p->root);
	cout << "test add_leftmost" << endl; 
	p->print();
	cout << " test leftmost_sheet = " << leftmost_sheet(p->root)->data << endl; 
	cout << "test delete_leftmost_sheet" << endl; 
	delete_leftmost_sheet(p);
	p->print();
	delete_leftmost_sheet(p);
	p->print();
	delete_leftmost_sheet(p);	
	p->print();
	cout  << left2_sheet(p->root)->data;

	cout << endl << endl<<  "Check homework 2" << endl;
	p->print();
	scale(p->root);
	p->print(); 
	cout << "summ p = " << sum(p->root) << endl; 
	cout << "count_neg p = " << count_neg(p->root) << endl; 
	p->print();
	BNode* s6 = new BNode(6);
	BNode* s5 = new BNode(-5);
	BNode* s4 = new BNode(-4);
	BNode* s0 = new BNode(5);
	BNode* s3 = new BNode(3, s6, s0);
	BNode* s2 = new BNode(4, s4, s5);
	BNode* s1 = new BNode(1, s2, s3);
	BThree k(s1); 
	k.print();
	cout << "count_neg k = " << count_neg(k.root) << endl;
	cout << "height k = " << height(k.root) << endl;
	p->print();
	cout << "height p = " << height(p->root) << endl;
	reflect(p->root);
	cout << "test reflect -  " << endl; 
	p->print();
	cout << "test mult p " << mult(p->root) << endl; 
	p->print();
	k.print();
	cout << "test mult k " << mult(k.root) << endl; 
	cout << "test eval k = " << eval(k.root) << endl; 
	cout << "print k "; 
	k.print();
	cout << "test k.min = " << min(k.root) << endl; 
	k.print();
	p->print();
	cout << "test p.min = " << min(p->root) << endl; 
	p->print();
	cout << "test deleteLeaves" << endl; 
	delLeaves(p->root);
	p->print();
	BThree *N = quest2();
	N->print();
	cout << "test del0" << endl; 
	del0(N->root);
	N->print();
	f_del(N->root);
	N->print();
	enlarge(N->root, 123);
	N->print();

	enlarge(N->root, 123);
	N->print();

	enlarge(N->root, 123);
	N->print();
	p->print();
	enlarge(p->root, 123);
	p->print();
	t.print();
	dell(t.root);
	t.print();
	cout << "sum alt = " << sum_alt(t.root) << endl; 
	p->print();
	cout << "sum alt = " << sum_alt(p->root) << endl;
	N->print();
	cout << "sum alt = " << sum_alt(N->root) << endl;
	BNode* r7 = new BNode(50);
	BNode* r3 = new BNode(10);
	BNode* r2 = new BNode(25,r3,r7);
	BNode* r5 = new BNode(130);
	BNode* r6 = new BNode(120);
	BNode* r4 = new BNode(125,r6,r5);
	BNode* r1 = new BNode(100,r2,r4);
	BThree t1(r1);
	t1.print();
	addCy(r1, 27);
	t1.print();
	addCy(r1, 999);
	t1.print();
	return EXIT_SUCCESS; 
}