# Polynomial-of-n-degree

Note: Please download the zip file for the complete code

Background:
As you know that polynomial of n degree is represented by an expression as below: A0Xn + A1Xn-1 + A2Xn-2 + ……………………………. + C = 0 Such polynomials may be stored in a linked list such that a node contains two integer data members that stores the coefficient and power of X. It would be helpful if the highest order term is stored as first node, successively followed by the lower order terms. Understand that constant term can be zero. Coefficients can be positive or negative. And some powers may be absent.

![image](https://user-images.githubusercontent.com/42114538/211150170-17e7742f-d3cf-4c0d-8099-627de1866f98.png)

Problem: In this problem your goal is to write struct called PolyNode, polyLinkedList, functions and a main function, whose partial definition is given to you below.

struct PolyNode{ int coefficient; int power; PolyNode * Next; }; struct PolyLinkedList{ PolyNode * HeadPtr; //Your code };

1. The function insertInOrder inserts nodes into PolyLinkedList such that nodes are inserted

from front to back in the order of decreasing power of X, with last node being the constant. Additional requirement is that two nodes with the same value of the power field are not allowed. void insertInOrder(int c, int pwr)// c is coefficient and pwr is power

2. The function insertFront adds the node with coefficient (c) and power (pwr) as the first significant node, only if sorted order of the linked list (descending order of power of X) is NOT disturbed, or Linked list has no nodes in it. If adding the node in front of the list is attempted and it disturbs the sorted order of the list, then node is NOT added and user is informed about it’s not being added. void insertFront(int c, int pwr)// c is coefficient, and pwr is power

3. The function insertTail adds the node with coefficient (c) and power (pwr) as the last significant node in the linked list, only if sorted order of the linked list (descending order of power of X) is NOT disturbed, or Linked list has no nodes in it. If adding the node as the last node in the list is attempted and it disturbs the sorted order of the list, then node is NOT added and user is informed about it’s not being added. void insertTail (int c, int pwr) // c is coefficient, and pwr is power

4. Write the function getSize, that would iterate through the linked list and get ONLY number of significant nodes in the linked list. For example, if linked list has not had any node, getSize will return 0. Otherwise it will return number of polynomial nodes in the linked list size_poly getSize( ) const 

5. Function getValue returns the integer number that results from substituting argument values for X in the linked list. 

6. Write the friend function operator == that returns true if both linked lists left and right are identical in content of all nodes, or returns false otherwise. 

7. Write the function addTwoPoly that adds two poynomial equations and store the result into third linkes list. Example: -2X4 + 3X3 – 5X2 + 2X + 10 -2X3 + 4X +5 The result: -2X4 + X3 – 5X2 + 6X + 15

![image](https://user-images.githubusercontent.com/42114538/211150189-2d34c496-a9e1-4efb-a6a0-daeec4f7b33e.png)

Main function:

• Declare a stack of PolyLinkedList before the loop. Assume that stack is called PolyStack

• It is required to make a menu list for some commands and keep it in infinite loop. The required commands are:

1. Add Polynomials to PolyStack from keyboard data entry. This menu item should allow user to add as many polynomials to the PolyStack as user desires. This menu item should first prepare a polynomial using insertInOrder function to add to the PolyStack. Make sure that two of the added polynomials are identical, so that we can test == operator.

2. Print all polynomials to the console.

3. Test == operator for those two polynomials in PolyStack, that are identical in content.

4. Print to console, the number of terms (using getSize function) for polynomials in PolyStack.

5. Print to console values of all polynomials when X = 2, X = 4, X = 5.

6. Print the addition of 2 polynomials

7. Repeat the test you did for testing function insertFront

8. Repeat the test you did for testing function insertTail

9. Exit
