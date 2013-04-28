#include "polyterm.h"

polyterm::polyterm()
{
    exponent=0;
    coef=0;

}

polyterm::polyterm(int Coefficient, int Exponent)
{
    exponent = Exponent;
    coef = Coefficient;
}

polyterm::polyterm(const polyterm &a)
{
    exponent = a.exponent;
    coef = a.coef;
}

polyterm &polyterm::operator =(const polyterm &a)
{
    exponent = a.exponent;
    coef = a.coef;

    return *this;
}

bool operator >=(const polyterm &a, const polyterm &b)
{
    if(a.exponent>=b.exponent)
        return true;
    else
        return false;

}

bool operator <=(const polyterm &a, const polyterm &b)
{
    if(a.exponent<=b.exponent)
        return true;
    else
        return false;
}

bool operator >(const polyterm &a, const polyterm &b)
{
    if(a.exponent>b.exponent)
        return true;
    else
        return false;
}
bool operator <(const polyterm &a, const polyterm &b)
{
    if(a.exponent<b.exponent)
        return true;
    else
        return false;
}
bool operator ==(const polyterm &a, const polyterm &b)
{
    if(a.exponent==b.exponent)
        return true;
    else
        return false;
}

bool operator !=(const polyterm &a, const polyterm &b)
{
    if(a.exponent!=b.exponent)
        return true;
    else
        return false;
}

polyterm operator +(const polyterm &a, const polyterm &b)
{
    polyterm c;
    if(a.exponent == b.exponent)
    {
        c.exponent = a.exponent;
        c.coef = a.coef+b.coef;
    }

    return c;

}

polyterm operator -(const polyterm &a, const polyterm &b)
{
    polyterm c;
    if(a.exponent == b.exponent)
    {
        c.exponent = a.exponent;
        c.coef = a.coef-b.coef;
    }

    return c;
}

polyterm operator *(const polyterm &a, const polyterm &b)
{
    polyterm c;
    if(a.exponent == b.exponent)
    {
        c.exponent = a.exponent+b.exponent;
        c.coef = a.coef*b.coef;
    }

    return c;
}

ostream &operator <<(ostream& out, const polyterm& a)
{
//    out << a.coefficenticent<<"x^"<<a.exponent;

   if(a.coef==1 && (a.exponent!=0 || a.exponent!=1))
       out<<"x^"<<a.exponent;
   else if(a.coef==-1 && (a.exponent!=0 && a.exponent!=1))
       out <<" - x^"<<a.exponent;
   else if(a.coef==-1 && a.exponent==1)
       out <<" - x";
   else if(a.coef < 0 && a.exponent == 1)
       out << " - " << a.coef*-1<<"x";
   else if(a.coef < 0)
       out << " - " << a.coef*-1<<"x^" <<a.exponent;
   else if(a.exponent==1)
       out <<a.coef<<"x";
   else if(a.exponent==0)
       out<<a.coef;
   else
       out<<a.coef<<"x^"<<a.exponent;

   return out;
}

int polyterm::Coef()
{
    return coef;
}

int polyterm::Exp()
{
    return exponent;
}

polyterm operator -(const polyterm &a)
{
    polyterm p;

    p.coef = a.coef * -1;
    p.exponent = a.exponent;

    return p;
}
