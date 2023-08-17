#include <iostream>

using namespace std;

// Made by Mewily. An attempt to make a kind of logic using multiple booleans
/*

1 : true.
0 : false.

11 : this is true
10 : I don't care
01 : this is false
00 : I don't know

111 : I   know,   that this is true 
110 : I ignore,   that this is true 
101 : I   know,   that I don't care 
100 : I ignore,   that I don't care 
011 : I   know,   that this is false
010 : I ignore,   that this is false
001 : I   know,   that I don't know
000 : I ignore,   that I don't know

1111 : I   know,   that I   know,   that this is true
1110 : I ignore,   that I   know,   that this is true
1101 : I   know,   that I ignore,   that this is true
1100 : I ignore,   that I ignore,   that this is true
1011 : I   know,   that I   know,   that I don't care
1010 : I ignore,   that I   know,   that I don't care
1001 : I   know,   that I ignore,   that I don't care
1000 : I ignore,   that I ignore,   that I don't care
0111 : I   know,   that I   know,   that this is false
0110 : I ignore,   that I   know,   that this is false
0101 : I   know,   that I ignore,   that this is false
0100 : I ignore,   that I ignore,   that this is false
0011 : I   know,   that I   know,   that I don't know
0010 : I ignore,   that I   know,   that I don't know
0001 : I   know,   that I ignore,   that I don't know
0000 : I ignore,   that I ignore,   that I don't know

*/
// Thank to https://gist.github.com/toch/7ed3a1786d0ed464fd94 for the fibonacci example

#define unused(x)(void)(x)

template <int level> class b {
    public:
        union {
            class b<level-1> cond;
            class b<level-1> do_I_care;
            class b<level-1> care;
        };

    union {
        bool do_I_know = true;
        bool know;
    };

    b<level> (b<level-1> cond, bool know) {
        this -> cond = cond;
        this -> know = know;
    }

    b<level> (bool know) {
        this -> cond = b<level-1> (know);
        this -> know = know;
    }

    bool operator == (b<level> b) {
        return this -> cond == b.cond && this -> do_I_know == b.do_I_know;
    }
    bool operator != (b<level> b) {
        return !(this == b);
    }

    ostream & print_bool(ostream & os) {
        cond.print_bool(os);
        os << know;
        return os;
    }

    ostream & print_string(ostream & os, bool is_value = true) 
    {
        if constexpr(level == 1) {
            if (is_value) {
                os << (know ? "true" : "false");
                cond.print_string(os, know);
            } else {
                os << "because " << (know ? "I'm unaware" : "I don't care");
            }
        } else if constexpr(level == 2) {
            // let the compiler do the hardwork : changing this mess of if/else
            if(know)
            {
                if(cond.know)
                {
                    os << "this is true";
                }else
                {
                    os << "this is false";
                }
            }else
            {
                if(care.know)
                {
                    os << "I don't care";
                }else
                {
                    os << "I don't know";
                }
            }
        } else {
            if (know) {
                os << "I   know,   that ";
            } else {
                os << "I ignore,   that ";
            }
            cond.print_string(os, is_value&know);
        }
        return os;
    }

    friend ostream & operator << (ostream & os, b<level> b) {
        b.print_bool(os);
        os << " : ";
        b.print_string(os);
        return os;
    }

    /*
    struct b<level> operator& (b<level> b) 
    { 
      return value &  b.value;
    }

    struct b<level> operator| (struct b<level> b) { return value |  b.value; }
    bool operator^ (struct b<level> b) { return value ^  b.value; }*/
};

template <> class b<0> {
    public: b <0> () {}
    b <0> (bool b) {
        unused(b);
    }

    bool operator == (b <0> b) {
        unused(b);
        return true;
    }
    bool operator != (b <0> b) {
        unused(b);
        return false;
    }

    friend ostream & operator << (ostream & os, b<0> b) {
        unused(b);
        return os;
    }
    ostream & print_bool(ostream & os) {
        return os;
    }
    ostream & print_string(ostream & os, bool is_value = true) {
        unused(is_value);
        os << ".";
        return os;
    }
};

//'if constexpr' only available with '-std=c++17' or '-std=gnu++17'

template <int X, int Z>
ostream& print_all_possibilities_tmp(ostream& os, b<X> cur) {
    if constexpr (X < Z) {
        print_all_possibilities_tmp<X + 1, Z>(os, b<X+1>(cur, true));
        print_all_possibilities_tmp<X + 1, Z>(os, b<X+1>(cur, false));
    } else
    {
      os << cur << endl;
    }
    return os;
}

template <int X = 0, int Z>
ostream& print_all_possibilities(ostream& os, b<X> cur)
{
    print_all_possibilities_tmp<X,Z>(os, cur);
    os << endl;
    return os;
}

int main() {

    print_all_possibilities<0,1>(cout, b<0>());
    print_all_possibilities<0,2>(cout, b<0>());
    print_all_possibilities<0,3>(cout, b<0>());
    print_all_possibilities<0,4>(cout, b<0>());

    return 0;
}