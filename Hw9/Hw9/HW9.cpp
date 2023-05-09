//Hw9

#include <iostream>
#include <algorithm>
using namespace std;

class Term {
public:
    Term(int c, int p): coeff(c), power(p){}
    int coeff;
    int power;
};

class Node {
public:
    Term term;
    Node* next;
    Node(Term t): term(t), next(nullptr) {}
};

class Polynomial {
private:
    Node* first;
public:
    Polynomial(): first(nullptr) {}
    Polynomial(Term t): first(new Node(t)) {}
    
    void add(Term t) {
        Node* newNode = new Node(t);
        if (first == nullptr or t.power > first->term.power)
        {
            newNode->next = first;
            first = newNode;
        }
        else {
            Node* cur = first;
            while((cur->next != nullptr) and (t.power < cur->next->term.power)) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
    Polynomial addition(Polynomial poly) {
        Polynomial sum;
        Node* p1 = first;
        Node* p2 = poly.first;
        while ((p1 != nullptr) and (p2 != nullptr)) {
            if (p1->term.power == p2->term.power) {
                double coeff = p1->term.coeff + p2->term.coeff;
                if(coeff!=0) {
                    sum.add(Term(coeff,p1->term.power));
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->term.power > p2->term.power) {
                sum.add(p1->term);
                p1 = p1->next;
            }
            else{
                sum.add(p2->term);
                p2 = p2->next;
            }
        }
        while (p1!=nullptr){
            sum.add(p1->term);
            p1 = p1->next;
        }
        while(p2!=nullptr) {
            sum.add(p2->term);
            p2 = p2->next;
        }
        return sum;
    }
    void print() {
        if (first == nullptr) {
            cout << "0" << endl;
        }
        Node* cur = first;
        while(cur!= nullptr) {
            if((cur->term.coeff > 0) and (cur != first)) {
                cout << "+";
            }
            if(cur->term.coeff == -1) {
                cout << "-";
            }
            else if (cur->term.coeff != 1 and cur->term.power > 0) {
                cout << cur->term.coeff;
            }
            if (cur->term.power == 0){
                cout << cur->term.coeff;
            }
            else if (cur->term.power == 1) {
                cout << "x";
            }
            else {
                cout << "x^" << cur->term.power;
            }
            cur = cur->next;
        }
        cout << endl;
    }
    
};

int main() {
    Polynomial p(Term(-2, 0));//p=-2
    p.add(Term(1, 1));//p=x-2
    p.add(Term(2, 2));//p=2*x^2+x-2
    Polynomial q(Term(2, 0));//q=2
    q.add(Term(-1, 1));//q=-x+2
    q.add(Term(1, 3));//q=x^3-x+2
    Polynomial h=p.addition(p);
    h.print();
    h=p.addition(q);
    h.print();
    cout<< "3/9/2023 " << "David Reynoso" << endl;
}
