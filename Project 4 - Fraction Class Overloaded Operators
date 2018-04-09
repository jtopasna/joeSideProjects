/*
 Class Invariant:
 Fraction objects will always be stored in the lowest terms OR with the
 default constructor values (0/1).
 
 If two arguments, they are assumed to be the numerator and denominator,
 just one is assumed to be a whole number, and zero arguments creates a zero
 Fraction. the denominator cannot be 0 and Fraction uses assert() to enforce
 this.
 
 Fraction objects have the private members int numrtr, int denmtr, and the
 simplify() function.
 */

#include "Fraction.h"
#include <iostream>
#include <cassert>

namespace cs_Fraction {

    Fraction::Fraction(int inNumrtr, int inDenmtr)
    
    {
        
        assert(inDenmtr != 0);
        
        numrtr = inNumrtr;
        
        denmtr = inDenmtr;
        
        simplify();
        
    }
    
    
    /*
     simplify() is a private member function that is called on Fraction objects
     whenever the Fraction object private data members may be changed to terms where
     they are not in the lowest terms. simplify() is not called for default-value
     Fraction objects.
     
     Pre: Fraction object does not have values in lowest terms; Fraction values are
     are non-negative ints
     Post: Fraction object private data members are reduced to lowest terms if not
     already
     */
    void Fraction::simplify()
    
    {
        
        if(denmtr < 0) {
            
            denmtr *= -1;
            
            numrtr *= -1;
            
        }
        
        if(numrtr == 0) {
            
            denmtr = 1;
            
        } else if(numrtr == denmtr) {
            
            numrtr = 1;
            
            denmtr = 1;
            
        } else {
        
            int temp = 1;
            
            if (numrtr < 0) {
                
                temp = -1;
                
                numrtr *= temp;
                
            }
            
                for (int count = numrtr; count > 1; count--) {
                
                    if(((numrtr % count == 0) && (denmtr % count == 0))) {
                    
                        numrtr = (numrtr/count);
                        
                        denmtr = (denmtr/count);
                        
                    }
                    
                }
            
            numrtr *= temp;
                
            }
        }
        



    
    
    
    
    
    
    
    std::ostream& operator<<(std::ostream& out, const Fraction& right)
    
    {
        
        if(right.denmtr == 1) {
            
            out << right.numrtr;
            
        } else if (abs(right.numrtr) > right.denmtr) {
            
        
            out << right.numrtr / right.denmtr;
            
            out << "+" << abs((right.numrtr % right.denmtr)) << "/" << right.denmtr;
        
        }
            
            
         else {
        
            out << right.numrtr << "/" << right.denmtr;
            
        }
        
        return out;
    }


    
    
    
    
    
    
    std::istream& operator>>(std::istream& in, Fraction& right)
    {
        
        int temp;
        
        in >> temp;
        
        if (in.peek() == '+'){
            
            in.ignore();
            
            in >> right.numrtr;
            
            in.ignore();
            
            in >> right.denmtr;
            
            if(temp < 0) {
                right.numrtr += abs((temp * right.denmtr));
                right.numrtr*=-1;
            } else {
                right.numrtr += temp * right.denmtr;
            }
            
            
        } else if (in.peek() == '/'){
            
            right.numrtr = temp;
            
            in.ignore();
            
            in >> right.denmtr;
            
        } else {

            right.numrtr = temp;
            
            right.denmtr = 1;
            
        }
        
        right.simplify();
        
        return in;
        
    }
    





    bool operator<(const Fraction& left, const Fraction& right)
    
    {
        
        return (left.numrtr * right.denmtr) < (right.numrtr * left.denmtr);
        
    }






    bool operator<=(const Fraction& left, const Fraction& right)
    
    {
        
        return ((left.numrtr * right.denmtr) <= (right.numrtr * left.denmtr));
        
    }






    bool operator>(const Fraction& left, const Fraction& right)
    
    {
        
        return (left.numrtr * right.denmtr) > (right.numrtr * left.denmtr);
        
    }






    bool operator>=(const Fraction& left, const Fraction& right)
    
    {
        
        return (left.numrtr * right.denmtr) >= (right.numrtr * left.denmtr);
        
    }






    bool operator==(const Fraction& left, const Fraction& right)
    
    {
        
        return (left.numrtr * right.denmtr) == (right.numrtr * left.denmtr);
        
    }






    bool operator!=(const Fraction& left, const Fraction& right)
    
    {
        
        return (left.numrtr * right.denmtr) != (right.numrtr * left.denmtr);
        
    }






    Fraction operator+(const Fraction& left, const Fraction& right)
    
    {
        
        Fraction temp;
        
        temp.denmtr = left.denmtr * right.denmtr;
        
        temp.numrtr = (left.numrtr * right.denmtr) + (right.numrtr * left.denmtr);
        
        temp.simplify();
        
        return temp;
        
    }


    
    
    
    
    
    

    Fraction operator-(const Fraction& left, const Fraction& right)
    
    {
        
        Fraction temp;
        
        temp.denmtr = left.denmtr * right.denmtr;
        
        temp.numrtr = (left.numrtr * right.denmtr) - (right.numrtr * left.denmtr);
        
        temp.simplify();
        
        return temp;
        
    }






    Fraction operator*(const Fraction& left, const Fraction& right)
    
    {
        
        Fraction temp;
        
        temp.denmtr = left.denmtr * right.denmtr;
        
        temp.numrtr = left.numrtr * right.numrtr;
        
        temp.simplify();
        
        return temp;
        
    }






    Fraction operator/(const Fraction& left, const Fraction& right)
    
    {
        
        Fraction temp;
        
        temp.numrtr = left.numrtr * right.denmtr;
        
        temp.denmtr = left.denmtr * right.numrtr;
        
        temp.simplify();
        
        return temp;
        
    }






    Fraction Fraction::operator+=(const Fraction& right)
    
    {
        
        *this = *this + right;
        
        return *this;
        
    }
    






    Fraction Fraction::operator-=(const Fraction& right)
    
    {
        
        *this = *this - right;
        
        return *this;
        
    }






    Fraction Fraction::operator*=(const Fraction& right)
    
    {
        
        *this = *this * right;
        
        return *this;
        
    }
    






    Fraction Fraction::operator/=(const Fraction& right)
    
    {
        
        *this = *this / right;
        
        return *this;
        
    }
    






    Fraction Fraction::operator++()
    
    {
        
        *this += 1;
        
        return *this;
        
    }






    Fraction Fraction::operator++(int)
    
    {
        
        Fraction temp = *this;
        
        
        *this += 1;
        
        return temp;
        
    }
    







    Fraction Fraction::operator--()
    
    {
        
        *this -= 1;
        
        return *this;
        
    }
    






    Fraction Fraction::operator--(int)
    
    {
        Fraction temp = *this;
        
        *this -= 1;
        
        temp.simplify();
        
        return temp;
        
    }
    
    
}
