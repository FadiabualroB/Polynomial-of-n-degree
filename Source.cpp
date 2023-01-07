#include<iostream>
#include<stack>
using namespace std;
struct node
{
	int coeff;
	int pwr;
	node* next;
};

struct polyLinkedList
{
	node* head;
	node* nnode;
	node* temp;

	bool isempty()
	{
		if (head != NULL)
		{
			return false;
		}
		return true;
	}

	// Insert  new Polynomial and order it based on power value.
	void insertInOrder(int c, int p)
	{
		nnode = new node();
		nnode->coeff = c;
		nnode->pwr = p;

		// Validating if the power of the new node less than the current head power
		if (isempty() || head->pwr < nnode->pwr)
		{
			nnode->next = head;
			head = nnode;
			return;
		}

		temp = head;
		while (temp->next != NULL && temp->next->pwr > nnode->pwr)
		{
			temp = temp->next;
		}
		if (temp->pwr != nnode->pwr)
		{
			nnode->next = temp->next;
			temp->next = nnode;
		}
		else
		{
			cout << nnode->pwr << "Value not allowed, Already entered earlier!" << endl;
		}

	}

	// To print the Poly in the format (CoefX^Power) + (CoefX^Power)
	void printPoly()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->coeff << "X^" << temp->pwr;

			if (temp->next != NULL)
			{
				if (temp->next->coeff > 0)
				{
					cout << " + ";
				}
			}
			temp = temp->next;
		}
		cout << endl;
	}

	// Add new node to the head of linked list if power is the biggest
	//Otherwise add the node normally based on order.
	void insertFront(int c, int p)
	{
		node* nnode;
		nnode = new node();
		nnode->coeff = c;
		nnode->pwr = p;

		if (isempty() || head->pwr < nnode->pwr)
		{
			nnode->next = head;
			head = nnode;
		}
		else if (head->pwr == nnode->pwr)
		{
			cout << "Not Allowed! " << nnode->coeff << "X^" << nnode->pwr << " Already Added! " << endl;
		}
		else
		{
			insertInOrder(c, p);
		}
	}

	// Add new node to the end of linked list
	void insertTail(int c, int p)
	{
		//node* nnode;
		nnode = new node();
		nnode->coeff = c;
		nnode->pwr = p;

		if (isempty())
		{
			nnode->next = NULL;
			head = nnode;
		}

		/*node* temp = head;*/
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		if (temp->pwr > nnode->pwr)
		{
			nnode->next = NULL;
			temp->next = nnode;
		}
		else if (temp->pwr == nnode->pwr)
		{
			cout << "Not Allowed! " << nnode->coeff << "X^" << nnode->pwr << " Already Added! " << endl;
		}
	}

	// Return the size of linked list
	int getSize()
	{
		int counter = 0;
		node* temp = head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}

	// Calculate the polynomial value entered by user
	double polyValue(int x)
	{
		node* temp = head;
		double base = x;
		int c, p;
		double result = 0;

		while (temp != NULL)
		{
			p = temp->pwr;
			c = temp->coeff;
			result += c * (pow(base, p));
			temp = temp->next;
		}
		return result;
	}

	// Function overload validating if two polynomials equals
	friend bool operator ==(polyLinkedList& l1, polyLinkedList& l2)
	{
		node* temp1 = l1.head;
		node* temp2 = l2.head;

		if (l1.getSize() != l2.getSize())
		{
			return false;
		}
		while (temp1 != NULL)
		{
			if (temp1->pwr != temp2->pwr || temp1->coeff != temp2->coeff)
			{
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return true;
	}

	// Add two polynomials together 
	void addTwoPoly(polyLinkedList l1, polyLinkedList l2)
	{
		node* temp1 = l1.head;
		node* temp2 = l2.head;
		node* temp3 = head;
		int c, p;

		bool flag = false;

		while (temp1 != NULL)
		{
			while (temp2 != NULL)
			{
				if (temp1->pwr == temp2->pwr)
				{
					p = temp1->pwr;
					c = temp1->coeff + temp2->coeff;
					insertInOrder(c, p);
					flag = true;
					break;
				}
				temp2 = temp2->next;
			}
			if (!flag)
			{
				insertInOrder(temp1->coeff, temp1->pwr);
			}
			temp1 = temp1->next;
			temp2 = l2.head;
			flag = false;
		}

		bool flag1 = false;
		temp2 = l2.head;
		while (temp2 != NULL)
		{
			while (temp3 != NULL)
			{
				if (temp3->pwr == temp2->pwr)
				{
					flag1 = true;
					break;
				}
				temp3 = temp3->next;
			}
			if (!flag1)
			{
				insertInOrder(temp2->coeff, temp2->pwr);
			}
			flag1 = false;
			temp3 = head;
			temp2 = temp2->next;
		}
	}
	void LLclear() {
		node* p;
		while (head != NULL) {
			p = head;
			head = head->next;
			delete p;
		}
	}
	friend ostream& operator<<(ostream& out, polyLinkedList poly)
	{
		stack <polyLinkedList> pls;
		while (!pls.empty())
		{
			out << pls.top();
			pls.pop();
		}
		return out;
	}
	void printStack(stack<polyLinkedList> polyS)
	{
		stack<polyLinkedList> polyS2;
		polyS2 = polyS;
		polyLinkedList lst2;

		while (!polyS2.empty())
		{
			lst2 = polyS2.top();
			nnode = head;

			while (nnode != NULL)
			{
				// To print the Poly in the format (CoefX^Power) + (CoefX^Power)
				cout << nnode->coeff << "X^" << nnode->pwr << endl;
				if (nnode->next != NULL)
				{
					if (nnode->next->coeff > 0)
					{
						cout << " + ";
					}
				}
				nnode = nnode->next;
			}
			polyS2.pop();
			cout << endl;
		}
	}

}lst1, lst2,polyAddition;

void printMenu()
{
	cout << "*************Main Menu*************" << endl;
	cout << "1. Add Polynomials" << endl;
	cout << "2. Print all polynomials to console" << endl;
	cout << "3. Test == Polynomials" << endl;
	cout << "4. Print polynomials Terms" << endl;
	cout << "5. Values of all polynomials" << endl;
	cout << "6. Print the addition of 2 polynomials" << endl;
	cout << "7. Test with InsertFront " << endl;
	cout << "8. Test with InsertTail" << endl;
	cout << "9. Exit" << endl;
}

int main()
{
	// Create new polynomials in memory
	stack <polyLinkedList*> polyStack;
	polyLinkedList* poly[50];
	for (int i = 0; i < 10; i++)
	{
		poly[i] = new polyLinkedList();
	}

	// Define variables
	int ch;
	bool flag = true;
	int polyNum = 0;
	int termsCount = 0;
	int c, p;
	int base;
	

	while (flag)
	{

		cout << "Select from Menu!" << endl; 
		cout<< endl;
		printMenu();

		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "1. Add Polynomials \n" << endl;
			cout << "Enter Number of Polynomial" << endl;
			cin >> polyNum;
			for (int i = 0; i < polyNum; i++)
			{
				polyLinkedList* polylist = poly[i];
				polylist->head = NULL;

				cout << "Enter number of terms for poly: " <<i+1<< endl;
				cin >> termsCount;

				for (int j = 0; j < termsCount; j++)
				{
					cout << "Enter Coeff for: " <<j+1<< endl;
					cin >> c;
					cout << "Enter Power: " << j+1<<endl;
					cin >> p;

					polylist->insertInOrder(c, p);
				}

				polyStack.push(polylist);
			}
			break;

		case 2:
			cout << "2. Print all polynomials to console \n" << endl;
			for (int i = 0; i < polyNum; i++)
			{
				polyStack.top();
				poly[i]->printPoly();
				polyStack.pop();
			}
			break;

		case 3:
			cout << "3. Test == Polynomials\n" << endl;
			lst1.head = NULL;
			lst2.head = NULL;
			cout << "First Polynomial !" << endl;
			cout << "Select Polynomial terms !" << endl;
			cin >> termsCount;
			for (int i = 0; i < termsCount ; i++)
			{
				cout << "Enter Coeff for " << i+1<<endl;
				cin >> c;
				cout << "Enter Power for" <<i+1<< endl;
				cin >> p;
				lst1.insertInOrder(c, p);
			}
			lst1.printPoly();

			cout << "Second Polynomial!" << endl;
			cout << "Select Polynomial Terms!" << endl;
			cin >> termsCount;
			for (int j = 0; j < termsCount; j++)
			{
				cout << "Enter Coeff: " <<j+1<< endl;
				cin >> c;
				cout << "Enter Power: " << j+1<<endl;
				cin >> p;
				lst2.insertInOrder(c, p);
			}
			lst2.printPoly();

			if (lst1 == lst2)
			{
				cout << "Polynomials Identical! " << endl;
			}
			else
			{
				cout << "Polynomials Bot Identical! " << endl;

			}
			break;

		case 4:
			cout << "4. Print polynomials Terms\n" << endl;
			if (polyStack.empty())
			{
				cout << "Poly stack is Empty!" << endl;
			}
			else
			{
				for (int i = 0; i < polyNum; i++)
				{
					polyStack.top();
					cout << "Number of Terms for polynomial: [" << i << "]" << " are :" << poly[i]->getSize()<< endl;
					polyStack.pop();
				}
				break;
			}
		case 5:
			cout << "5. Values of all polynomials\n" << endl;
			if (polyStack.empty())
			{
				cout << "Stack is empty!" << endl;
			}
			else
			{
				cout << "Enter Value of base - X:" << endl;
				cin >> base;
				for (int i = 0; i < polyNum; i++)
				{
					polyStack.top();
					cout << "Value of Polynomial is: " << poly[i]->polyValue(base) << endl;
					polyStack.pop();
				}
			}
			break;
		case 6:
			cout << "6. Print the addition of 2 polynomials\n" << endl;

			lst1.head = NULL;
			lst2.head = NULL;

			cout << "First Polynomial!" << endl;
			cout << "Select Polynomial terms!" << endl;
			cin >> termsCount;
			for (int i = 0; i < termsCount; i++)
			{
				cout << "Enter Coeff!" <<i+1<< endl;
				cin >> c;
				cout << "Enter Power!" << i+1<<endl;
				cin >> p;
				lst1.insertInOrder(c, p);
			}
			lst1.printPoly();

			cout << "Second Polynomial!" << endl;
			cout << "Select Polynomial Terms!" << endl;
			cin >> termsCount;
			for (int j = 0; j < termsCount; j++)
			{
				cout << "Enter Coeff: " <<j+1<< endl;
				cin >> c;
				cout << "Enter Power: " <<j+1<< endl;
				cin >> p;
				lst2.insertInOrder(c, p);
			}
			lst2.printPoly();
			
			cout << "Result of Summation is: " << endl;
			polyAddition.addTwoPoly(lst1, lst2);
			polyAddition.printPoly();
			break;

		case 7:
			lst1.head = NULL;
			cout << "7. Test with InsertFront\n " << endl;
			cout << "Enter number of terms!" << endl;
			cin >> termsCount;
			for (int i = 0; i < termsCount; i++)
			{
				cout << "Enter Coeff!" <<i+1<< endl;
				cin >> c;
				cout << "Enter power! " << i + 1 << endl;
				cin >> p;
				lst1.insertFront(c, p);
			}
			lst1.printPoly();
			break;
		case 8:
			lst2.head = NULL;
			cout << "8. Test with InsertTail\n" << endl;
			cout << "Enter number of terms!" << endl;
			cin >> termsCount;
			for (int i = 0; i < termsCount; i++)
			{
				cout << "Enter Coeff!" << i + 1 << endl;
				cin >> c;
				cout << "Enter power! " << i + 1 << endl;
				cin >> p;
				lst2.insertTail(c, p);
			}
			lst2.printPoly();
			break;

		case 9:
			cout << "9. Exit\n" << endl;
			cout << "Are you sure want to exit! (Y: Yes, N: NO) " << endl;
			string c;
			cin >> c;
			if (c == "Y")
			{
				flag = false;
				break;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}