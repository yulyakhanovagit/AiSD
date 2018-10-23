#include "lisp_func.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

lisp head (const lisp s){// PreCondition: not null (s)
    if (s != NULL)
        if (!isAtom(s)) return s->node.pair.hd;
        else { std::cerr << "Error: Head(atom) \n"; exit(1); }
    else { 
        std::cerr << "Error: Head(nil) \n";
        exit(1);
    }
}
//.......................................
bool isAtom (const lisp s){ 
    if(s == NULL) return false;
    else return (s -> tag);
}
//.......................................
bool isNull (const lisp s){ 
    return s==NULL;
}
//.......................................
lisp tail (const lisp s){// PreCondition: not null (s)
    if (s != NULL) 
        if (!isAtom(s)) return s->node.pair.tl;
        else { std::cerr << "Error: Tail(atom) \n"; exit(1); }
    else { 
        std::cerr << "Error: Tail(nil) \n";
        exit(1);
    }
}
//.......................................
lisp cons (const lisp h, const lisp t) {
    lisp p;
    if (isAtom(t)) { 
        std::cerr << "Error: Cons(*, atom)\n"; 
        exit(1);
    }
    else {
        p = new s_expr;
        p->tag = false;
        p->node.pair.hd = h;
        p->node.pair.tl = t;
        return p;
    }
}
//...........................
lisp make_atom (const base x) { 
    lisp s;
    s = new s_expr;
    s -> tag = true;
    s->node.atom = x;
    return s;
}
//...........................
void destroy (lisp s) {
    if (!s)
        return; 
    if (!isAtom(s)) {
        destroy (head (s));
        destroy (tail(s));
    }
    delete s;
}
//...........................
base getAtom (const lisp s) {
    if (!isAtom(s)) { 
        std::cerr << "Error: getAtom(s) for !isAtom(s) \n"; 
        exit(1);
    }
    else return (s->node.atom);
}

void read_lisp ( lisp& y, std::istream &list){
        char x;
        do {
            list >> x;
        } while (x == ' ');
        read_s_expr ( x, y, list);
}

void read_s_expr (char prev, lisp& y, std::istream &list){
        if ( prev == ')' ) {
            std::cout << "Closed bracket before opened bracket! " << std::endl;
            exit(1);
        }
        else if ( prev != '(' )
            y = make_atom (prev);
        else
            read_seq (y, list);
}



void read_seq ( lisp& y, std::istream &list){
        char x;
        lisp p1, p2;
        if (!(list >> x)) {
            std::cout << "Not enough symbols!" << std::endl;
            exit(1);
        }
        else {
            while ( x == ' ' ){
                list >> x;
            }

            if ( x == ')' )
                y = NULL;
            else {
                read_s_expr ( x, p1, list);
                read_seq ( p2, list);
                y = cons (p1, p2);
            }
        }
}
//...........................
// Процедура вывода списка с обрамляющими его скобками － write_lisp,
// а без обрамляющих скобок － write_seq
void write_lisp (const lisp x){
    //пустой список выводится как ()
    if (isNull(x)) 
        std::cout << " ()";
    else if (isAtom(x)) 
        std::cout << ' ' << x->node.atom;
    else { //непустой список}
        std::cout << " (" ;
        write_seq(x);
        std::cout << " )";
    }
} // end write_lisp
//...........................
void write_seq (const lisp x) {
//выводит последовательность элементов списка без обрамляющих его скобок
    if (!isNull(x)) {
        write_lisp(head (x));
        write_seq(tail (x));
    }
}


