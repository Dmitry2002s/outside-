#include <iostream>

using namespace std; 

struct BNode
{
	int data;
	BNode* left, * right; 
	BNode(int d, BNode *l = nullptr, BNode* r = nullptr) : 
		data(d), left(l),right(r) {}
};

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
void cprint(BNode* r)
{
	cout << "---------------------------------------------" << endl; 

	f_print(r);
	cout << "---------------------------------------------" << endl;
} // функция отображения с полосками(для удобства) 
struct BThree
{
	BNode* root; 
	BThree (BNode * p ) : root(p) {} 
	void print()
	{
		cprint(root);
	}
};
BThree quest1() // создание дерева из задания 
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

bool delete_leftmost(BThree d)
{
	BNode* del = leftmost(d.root); 
	BNode* prev = d.root; 
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

// homework 2
bool scale(BThree d)
{
	BNode* r = d.root; 
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
int sum(BThree d , int result = 0)
{

	BNode* r = d.root; 
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
int count_neg(BThree d, int result = 0)
{
	BNode* r = d.root; 
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
int height(BThree d, int result = 0)
{
	BNode* r = d.root;
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
bool reflect(BThree d)
{
	BNode* r = d.root;
	if (r == nullptr)
	{
		return true; 
	}
	if (r->right != nullptr || r->left != nullptr)
	{
		BNode* l = d.root->left;
		d.root->left = d.root->right; 
		d.root->right = l; 
		reflect(r->right);
		reflect(r->left);
	}
	
}
int mult(BThree d, int result = 1)
{
	BNode* r = d.root;
	if (r != nullptr)
	{
		(r->right != nullptr && r->left != nullptr) ? result = result * r->data : result = result; 
		result = result *  mult(d.root->right) * (mult(d.root->left));
		return result; 
	}
	else
	{
		return result; 
	}
}
int eval(BThree d, int result = 0)
{
	BNode* r = d.root;
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
int min(BNode *d, int result = 99999999999)
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

	cout << endl << endl<<  "Check homework 2" << endl;
	p->print();
	scale(p->root);
	p->print(); 
	cout << "summ p = " << sum(p->root) << endl; 
	cout << "count_neg p = " << count_neg(p->root) << endl; 
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
	reflect(*p);
	cout << "test reflect -  " << endl; 
	p->print();
	cout << "test mult p " << mult(*p) << endl; 
	k.print();
	cout << "test mult k " << mult(k) << endl; 
	cout << "test eval k = " << eval(k) << endl; 
	cout << "print k "; 
	k.print();
	cout << "test k.min = " << min(k.root) << endl; 

	p->print();
	cout << "test p.min = " << min(p->root) << endl; 

	return EXIT_SUCCESS; 
}