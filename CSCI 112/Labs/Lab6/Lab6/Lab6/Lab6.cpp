
// Includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Term Class
class Term {
    public:
        // Declarations
        string term;
        int coef;
        int exp;
        Term();
        Term(string);
        string get_term();
        void set_term(string);
        int get_exp();
        int get_coef();
        void splitTerm();
        void printTerm();
};

// Function Definitions

// Default Constructor
Term::Term() {
    term = "none";
    coef = -1;
    exp = -1;
}

// Real Constructor
Term::Term(string termIn) {
    term = termIn;
    splitTerm();
}

// Gets Term
string Term::get_term() {
    return term;
}

// Sets Term
void Term::set_term(string termIn) {
    term = termIn;
    splitTerm();
}

// Gets exponent
int Term::get_exp() {
    return exp;
}

// gets coefficient
int Term::get_coef() {
    return coef;
}

// splits term into exp and coeff using if statements to pull numbers out of strings
void Term::splitTerm() {
    if (term.length() == 3) {
        coef = term.at(0) - '0';
        exp = term.at(2) - '0';
    }
    else if (term.length() == 2) {
        if (term.at(0) == 'x') {
            coef = 1;
            exp = term.at(1) - '0';
        } else {
            coef = term.at(0) - '0';
            exp = 1;
        }
    } else {
        coef = term.at(0) - '0';
        exp = 0;
    }
}

// Prints term
void Term::printTerm() {
    cout << term << " ";
}

// Vector Class
class Vector {
    // Declarations
    private:
        vector<Term> terms;
        string poly;
    public:
        vector<string> newTerms;
        Vector(vector<Term>);
        void calcPoly();
        void printPoly();
};

// Function Definitions
Vector::Vector(vector<Term> termsIn) {
    terms = termsIn;
    calcPoly();
}

// Calculates Polynomian and stores it in newTerms vector
void Vector::calcPoly() {
    vector<int> expList;
    vector<int> coefList;
    int coefSum = 0;

    // Adds coefficients of terms with the same exponent and stores it in a vector
    for (unsigned int i = 0; i < terms.size(); i++) {
        if (find(expList.begin(), expList.end(), terms[i].get_exp()) == expList.end()) {
            for (unsigned int j = i; j < terms.size(); j++) {
                if (terms[i].get_exp() == terms[j].get_exp()) {
                    coefSum += terms[j].get_coef();
                }
            }
            coefList.push_back(coefSum);
            expList.push_back(terms[i].get_exp());
            coefSum = 0;
        }
    }

    // creates vector of new terms from above calculation using expList vector and coefList vector
    for (unsigned int k = 0; k < expList.size(); k++) {
        if (coefList[k] == 1) {
            newTerms.push_back("x" + to_string(expList[k]));
        } else if (expList[k] == 0) {
            newTerms.push_back(to_string(coefList[k]));
        } else if (expList[k] == 1) {
            newTerms.push_back(to_string(coefList[k]) + "x");
        }
        else {
            newTerms.push_back(to_string(coefList[k]) + "x" + to_string(expList[k]));
        }
    }
}

// Prints Polynomial
void Vector::printPoly() {
    for (unsigned int i = 0; i < newTerms.size() - 1; i++) {
        cout << newTerms[i] << " + ";
    }
    cout << newTerms[newTerms.size() - 1] << endl;
}

// Compare function to sort newTerms vector
bool compare(Term t1, Term t2) {
    return (t1.get_exp() > t2.get_exp());
}

// Start of main
int main()
{
    // Declarations
    vector<string> equation;
    string temp;

    // Gets Equation from command line with for loop and tests for DONE to end
    cout << "Enter Equation to Simplify (MUST ADD ' DONE' AT THE END): ";
    for (unsigned int i = 0; i < 50; i++) {
        cin >> temp;
        equation.push_back(temp);
        cin >> temp;
        if (temp == "DONE") {
            break;
        }
    }

    // Gets length of equation vector to create vector of Terms
    int len = equation.size();
    vector<Term> terms(len, Term());

    // Prints out terms in equation and initializes each term from equation vector
    cout << "The terms in the equation are: ";
    
    for (unsigned int j = 0; j < equation.size(); j++) {
        terms[j].set_term(equation[j]);
        cout << terms[j].term << " ";
    }

    cout << endl << "Simplified: ";

    // Uses Vector class to perform calculation and print final result
    Vector poly (terms);

    sort(poly.newTerms.begin(), poly.newTerms.end(), compare);
    poly.printPoly();

    return 0;
}