#include <iostream>
#include <vector>
#include "console.h"

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

#define unused(x) (void)(x)

template <int level>
class b
{
public:
    union
    {
        b<level-1> cond;
        b<level-1> do_I_care;
        b<level-1> care;
    };

    union
    {
        bool do_I_know = true;
        bool know;
    };

    b<level>(b<level - 1> cond, bool know)
    {
        this->cond = cond;
        this->know = know;
    }

    b<level>(bool know)
    {
        if constexpr (level == 1)
        {
            this->know = know;
        }
        else
        {
            this->know = true;
        }
        this->cond = b<level - 1>(know);
    }

    static b<level> unknow()
    {
        return b<level>(b<level-1>(true), false);
    }

    static b<level> dont_care()
    {
        return b<level>(b<level-1>(false), false);
    }

    bool is_true()
    {
        if constexpr (level == 1)
        {
            return know;
        }else
        {
            return know ? cond.is_true() : false;
        }
    }

    bool is_false()
    {
        if constexpr (level == 1)
        {
            return know == false;
        }else
        {
            return know ? cond.is_false() : false;
        }
    }

    bool operator==(b<level> b)
    {
        return this->cond == b.cond && this->do_I_know == b.do_I_know;
    }
    bool operator!=(b<level> b)
    {
        return !(this == b);
    }

    ostream &print_bool(ostream &os)
    {
        cond.print_bool(os);
        os << know;
        return os;
    }

    ostream &print_string(ostream &os, bool is_value = true)
    {
        if constexpr (level == 1)
        {
            if (is_value)
            {
                os << (know ? COLOR_FOREGROUND_GREEN : COLOR_FOREGROUND_RED) << (know ? "true " : "false") << COLOR_RESET;
            }
            else
            {
                os << "because " << (know ? "I'm unaware" : "I don't care");
            }
        }
        else if constexpr (level == 2)
        {
            // let the compiler do the hardwork : changing this mess of if/else
            if (know)
            {
                if (cond.know)
                {
                    os << COLOR_FOREGROUND_GREEN << "this is true " << COLOR_RESET;
                }
                else
                {
                    os << COLOR_FOREGROUND_RED << "this is false" << COLOR_RESET;
                }
            }
            else
            {
                if (care.know)
                {
                    os << COLOR_FOREGROUND_MAGENTA << "I don't know " << COLOR_RESET;
                }
                else
                {
                    os << COLOR_FOREGROUND_YELLOW "I don't care " << COLOR_RESET;
                }
            }
        }
        else
        {
            if (know)
            {
                //os << COLOR_FOREGROUND_GREEN << "I   know, " << COLOR_RESET << "  that ";
                if (cond.know)
                {
                    os << COLOR_FOREGROUND_GREEN << "I  know, " << COLOR_RESET << "that ";
                }
                else
                {
                    os << COLOR_FOREGROUND_RED << "I  know," << COLOR_RESET << "!that ";
                }
            }
            else
            {
                if (care.know)
                {
                    os << COLOR_FOREGROUND_MAGENTA "I !know, " << COLOR_RESET << "that ";
                }
                else
                {
                    os << COLOR_FOREGROUND_YELLOW  "I !care, " << COLOR_RESET << "that ";
                }
            }
            cond.print_string(os, is_value & know);
        }
        return os;
    }

    friend ostream &operator<<(ostream &os, b<level> b)
    {
        b.print_bool(os);
        os << " : ";
        b.print_string(os);
        return os;
    }

    b<level> operator|(b<level> a)
    {
        if constexpr (level == 1)
        {
            return b<1>(know | a.know);
        }else
        {
            if (is_true() | a.is_true())
            {
                return true;
            }
            if (is_false() & a.is_false())
            {
                return false;
            }
            return b<level>::unknow();
        }
    }
    b<level> operator&(b<level> a)
    {
        if constexpr (level == 1)
        {
            return b<1>(know & a.know);
        }else
        {
            if (is_true() & a.is_true())
            {
                return true;
            }
            if (is_false() | a.is_false())
            {
                return false;
            }
            return b<level>::unknow();
        }
    }

    b<level> operator!()
    {
        if constexpr (level == 1)
        {
            return b<1>(!know);
        }else
        {
            return b<level>(!cond, know);
        }
    }
    /*
    struct b<level> operator& (b<level> b)
    {
      return value &  b.value;
    }

    struct b<level> operator| (struct b<level> b) { return value |  b.value; }
    bool operator^ (struct b<level> b) { return value ^  b.value; }*/
};

template <>
class b<0>
{
public:
    b<0>() {}
    b<0>(bool b)
    {
        unused(b);
    }

    bool operator==(b<0> b)
    {
        unused(b);
        return true;
    }
    bool operator!=(b<0> b)
    {
        unused(b);
        return false;
    }

    friend ostream &operator<<(ostream &os, b<0> b)
    {
        unused(b);
        return os;
    }
    ostream &print_bool(ostream &os)
    {
        return os;
    }
    ostream &print_string(ostream &os, bool is_value = true)
    {
        unused(is_value);
        return os;
    }

    b<0> operator|(b<0> b) { unused(b); return this; }
    b<0> operator&(b<0> b) { unused(b); return this; }
    b<0> operator!() { return this; }
};

//'if constexpr' only available with '-std=c++17' or '-std=gnu++17'

template <int X, int Z>
ostream &print_all_possibilities_tmp(ostream &os, b<X> cur)
{
    if constexpr (X < Z)
    {
        print_all_possibilities_tmp<X + 1, Z>(os, b<X + 1>(cur, true));
        print_all_possibilities_tmp<X + 1, Z>(os, b<X + 1>(cur, false));
    }
    else
    {
        os << cur << endl;
    }
    return os;
}

template <int X = 0, int Z>
ostream &print_all_possibilities(ostream &os, b<X> cur)
{
    print_all_possibilities_tmp<X, Z>(os, cur);
    os << endl;
    return os;
}

template <int X, int Z>
void get_all_possibilities(vector<b<Z>>& vals, b<X> cur)
{
    if constexpr (X < Z)
    {
        get_all_possibilities<X + 1, Z>(vals, b<X + 1>(cur, true));
        get_all_possibilities<X + 1, Z>(vals, b<X + 1>(cur, false));
    }
    else
    {
        vals.push_back(cur);
    }
    //return vals;
}

template<int X>
void print_operator()
{
    vector<b<X> > v = vector<b<X> >();
    get_all_possibilities<0,X>(v, b<0>()); 
    string sep = "   ";

    cout << "Bool of " << X << " orders :"  << endl;

    cout << "================= (!a) =========" << endl;

    for (auto &a : v)
    {
        cout << "(a)=(" << a << ")" << sep << "(!a)=(" << (!a) << ")" << endl;
    }
    cout << endl;

    cout << "================= (a & b) =========" << endl;
    for (auto &a : v)
    {
        for (auto &b : v)
        {
            cout << "(a)=(" << a << ")" << sep <<
                    "(b)=(" << b << ")" << sep << ":" << sep <<
                    "(a & b)=(" << (a & b)<< ")"  << endl;
        }
    }
    cout << endl;

    cout << "================= (a | b) =========" << endl;
    for (auto &a : v)
    {
        for (auto &b : v)
        {
            cout << "(a)=(" << a << ")" << sep <<
                    "(b)=(" << b << ")" << sep << ":" << sep <<
                    "(a | b)=(" << (a | b)<< ") "  << endl;
        }
    }
    cout << endl;

    cout << "================= (a => b) =========" << endl;
    for (auto &a : v)
    {
        for (auto &b : v)
        {
            cout << "(a)=(" << a << ")" << sep <<
                    "(b)=(" << b << ")" << sep << ":" << sep <<
                    "((a&b) | (!a) | b)=(" << ((a&b) | (!a) | b) << ") " << endl; /* sep <<
                    "((a&b) | (!a))=(" << ((a&b) | (!a)) << ") " << sep <<
                    "((a&b) | ((!a)&b) | ((!a)&(!b)))=(" << ((a&b) | ((!a)&b) | ((!a)&(!b))) << ") " << sep <<
                    "((!a) | b)=(" << ((!a) | b)<< ") " << endl;*/
        }
    }
    cout << endl;

}

int main()
{

    /*
    cout << b<0> () << endl << endl;

    cout << b<1> (true) << endl;
    cout << b<1> (false) << endl << endl;

    cout << b<2> (true , true ) << endl;
    cout << b<2> (false, true ) << endl;
    cout << b<2> (true , false) << endl;
    cout << b<2> (false, false) << endl << endl;

    cout << b<3> (b<2> (true , true ), true ) << endl;
    cout << b<3> (b<2> (false, true ), true ) << endl;

    cout << b<3> (b<2> (true, false ), true ) << endl;

    cout << b<3> (b<2> (false, false), false) << endl;
    cout << b<3> (b<2> (false, true ), false) << endl;
    */

    // print_all_possibilities<0,1>(cout, b<0>());
    // print_all_possibilities<0,2>(cout, b<0>());
    // print_all_possibilities<0,3>(cout, b<0>());
    // print_all_possibilities<0,4>(cout, b<0>());
    // print_all_possibilities<0,5>(cout, b<0>());
    // print_all_possibilities<0,6>(cout, b<0>());

    //print_all_possibilities

    //cout << (b<1>(true) & b<1>(true)) << endl;

    print_operator<0>();
    print_operator<1>();
    print_operator<2>();
    print_operator<3>();

    return 0;
}