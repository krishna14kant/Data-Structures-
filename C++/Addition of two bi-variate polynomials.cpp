// Addition of two bi-variate polynomials using link list.

#include <bits/stdc++.h>
#define MAXSIZE 10

using namespace std;

class Node
{
public:
    int coeff, px, py;
    Node *next;
};

Node *push(Node *top, int coeff, int px, int py)
{
    Node *temp = new Node;
    if (top == NULL)
    {
        temp->coeff = coeff;
        temp->px = px;
        temp->py = py;
        temp->next = top;
        top = temp;
        return top;
    }

    if (top->next == NULL)
    {
        temp->coeff = coeff;
        temp->px = px;
        temp->py = py;
        if (top->px > px || (top->px == px && top->py > py))
        {
            top->next = temp;
            temp->next = NULL;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
        return top;
    }

    Node *ptr = top;
    while (ptr->next != NULL && (ptr->px > px || (ptr->px == px && ptr->py > py)))
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        temp->coeff = coeff;
        temp->px = px;
        temp->py = py;

        if (ptr->px > px || (ptr->px == px && ptr->py > py))
        {
            ptr->next = temp;
            temp->next = NULL;
        }
        else
        {
            Node *temp1 = top;
            while (temp1->next != ptr)
            {
                temp1 = temp1->next;
            }
            temp->next = ptr;
            temp1->next = temp;
        }
        return top;
    }

    if (ptr == top)
    {
        if (ptr->px <= px && ptr->py < py)
        {
            temp->coeff = coeff;
            temp->px = px;
            temp->py = py;
            temp->next = ptr;
            top = temp;
            return top;
        }
    }

    temp->coeff = coeff;
    temp->px = px;
    temp->py = py;
    Node *temp1 = top;
    while (temp1->next != NULL && temp1->next != ptr)
    {
        temp1 = temp1->next;
    }

    if (temp1->next == NULL)
    {
        temp->next = NULL;
        temp1->next = temp;
        return top;
    }
    temp->next = ptr;
    temp1->next = temp;
    return top;
}

int powOfX(Node *curr)
{
    return curr->px;
}

int powOfY(Node *curr)
{
    return curr->py;
}

int coeff(Node *curr)
{
    return curr->coeff;
}

int size = 0;

Node *polly_add(Node *m, Node *n)
{
    Node *rTop = NULL;
    Node *currM = m;
    Node *currN = n;
    while (currN != NULL)
    {
        int a2 = powOfX(currN), b2 = powOfY(currN), c2 = coeff(currN);
        while (currM != NULL)
        {
            int a1 = powOfX(currM), b1 = powOfY(currM);
            if (a1 == a2 && b1 == b2)
            {
                currM->coeff += c2;
                currM = m;
                break;
            }

            else if (currM->next == NULL)
            {
                m = push(m, c2, a2, b2);
                currM = m;
                break;
            }
            currM = currM->next;
        }
        currN = currN->next;
    }
    while (m != NULL)
    {
        if (m->coeff != 0)
        {
            rTop = push(rTop, m->coeff, m->px, m->py);
            size++;
        }
        m = m->next;
    }
    return rTop;
}

void display(Node *top)
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->coeff << " " << temp->px << " " << temp->py << "\n";
        temp = temp->next;
    }
}

int main()
{

    int m, n;
    cin >> m >> n;
    if (m > 10 || n > 10)
    {
        cout << "Number of terms exceed the MAXSIZE limit\n";
        exit(0);
    }

    int coeff, px, py;
    Node *mTop = NULL, *nTop = NULL;
    while (m--)
    {
        cin >> coeff >> px >> py;
        mTop = push(mTop, coeff, px, py);
    }
    while (n--)
    {
        cin >> coeff >> px >> py;
        nTop = push(nTop, coeff, px, py);
    }

    Node *ans = polly_add(mTop, nTop);
    cout << size << "\n";
    display(ans);

    return 0;
}