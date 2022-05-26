//------------------------------
// General functions used in
// several files.
//------------------------------

//------Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/general.h"


//------Eval
void eval(CNF* formula, int x, bool v) {
    /*
    Evaluate the formula at x with value v. It modifies the input formula.
    
    Input :
        - formula : the CNF* formula ;
        - x       : the variable ;
        - v       : the value that should take the variable.
    
    Output :
        the formula, where all clause where there is `x` are removed, and where -`x` is removed from all clauses.
    */

    if (v == false) {
        return eval(formula, -x, true);
    }

    struct CNF_clause* f = formula->f;
    struct CNF_clause* f0 = f;

    int cc = formula->cc;
    int varc = formula->varc;

    while (f != NULL) {
        Clause c = f->c;
        Clause c0 = c;

        bool go_next = true;
        while (c != NULL) {
            if (c->l == x) {
                if (f == f0) {
                    f0 = f->next;
                }
                
                del_clause(&f);
                cc--;
                go_next = false;
                break;
            }

            if (c->l == -x) {
                c0 = del_literal(c0, -x);
                f->c = c0;
                break;
            }

            c = c->next;
        }

        if (go_next) {
            f = f->next;
        }
    }

    formula->f = f0;
    formula->varc = varc - 1;
    formula->cc = cc;

}