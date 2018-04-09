/*

 
 The class Fraction represents a fraction object that stores a user's fraction.
 The class Fraction includes private members int numrtr, denmtr and the
 private void function simplify(). simplify() is used to ensure a Fraction
 object is always stored in the lowest possible terms, whether created directly
 by the client program or read in by the client program from a user with the
 overloaded extraction operator.
 
 ==List of Protypes for Public Members, Friend Functions, Overloaded Operators==
 
 Fraction(int numrtr = 0, int denmtr = 1);
 
 If two arguments, they are assumed to be the numerator and denominator,
 just one is assumed to be a whole number, and zero arguments creates a zero
 Fraction. the denominator cannot be 0 and Fraction uses assert() to enforce
 this.
 
 Pre: client calls Fraction and new Fraction object created
 Post: new Fraction object created; constructor used to set default private
 member values of int numrtr = 0 and int denmtr = 1;  the
 Fraction object then has simplify() called which ensures Fraction object is
 always stored in lowest terms
 
 
Overloaded Insertion Operator
 
 pre: output stream takes fraction object
 post: if cout, output stream displays Fraction object's private members. For
 Whole numbers printed without a denominator (e.g. not 3/1 but just 3).
 Improper Fractions are printed as a mixed number with a + sign between the two
 parts. Negative Fractions are printed with a leading minus sign.
 
Overloaded Extraction Operator
 
 Pre: input stream takes fraction object
 Post: if cin, input stream stores ints in Fraction object. no spaces or
 formatting errors in the Fractions that you read. Can take in mixed number,
 negative number, whole numbers

 
 Overloaded +
 Pre: right fraction object and left fraction object;
 Post: right fraction object added to left and stored as mixed number in
 lowest terms
 
 Overloaded -
 Pre: right fraction object and left fraction object;
 Post: right fraction object subtracted from left and stored as mixed number in
 lowest terms
 
 Overloaded *
 Pre: right fraction object and left fraction object;
 Post: right fraction object multiplied by left and stored as mixed number in
 lowest terms
 
 Overloaded /
 Pre: right fraction object and left fraction object;
 Post: left fraction object divided by right and stored as mixed number in
 lowest terms
 
 Overloaded +=
 Pre: right fraction object and left fraction object;
 Post: left fraction object set equal to left fraction object plus right fraction
 
 Overloaded -=
 Pre: right fraction object and left fraction object;
 Post: left fraction object set equal to left fraction object minus right fraction
 
 Overloaded *=
 Pre: right fraction object and left fraction object;
 Post: left fraction object set equal to left fraction object times right fraction
 
 Overloaded /=
 Pre: right fraction object and left fraction object;
 Post: left fraction object set equal to left fraction object divided right fraction
 
 Overloaded PreIncrement
 
 Pre: fraction object value incremented
 Post: fraction object value determined
 
 Overloaded PostIncrement
 
 Pre: fraction object value determined
 Post: fraction object incremented by adding one to fraction object
 
 Overloaded PreDecrement
 
 Pre: fraction object value decremented by 1
 Post: fraction object value determined

 Overloaded PostDecrement
 
 Pre: fraction object value determined
 Post: fraction object value decremented
 
 
 friend bool operator<(const Fraction& left, const Fraction& right)
 
 Pre: left fraction compared to right fraction
 Post: bool value returned. true if left < right. false if otherwise. neither
 fraction object changed
 
 
 friend bool operator<=(const Fraction& left, const Fraction& right)
 
 Pre: left fraction compared to right fraction
 Post: bool value returned. true if left <= right. false if otherwise. neither
 fraction object changed
 
 friend bool operator>(const Fraction& left, const Fraction& right)
 
 Pre: left fraction compared to right fraction
 Post: bool value returned. true if left > right. false if otherwise. neither
 fraction object changed
 
 friend bool operator>=(const Fraction& left, const Fraction& right)
 
 Pre: left fraction compared to right fraction
 Post: bool value returned. true if left >= right. false if otherwise. neither
 fraction object changed
 
 friend bool operator==(const Fraction& left, const Fraction& right)
 
 Pre: left fraction compared to right fraction
 Post: bool value returned. true if left == right. false if otherwise. neither
 fraction object changed
 
 friend bool operator!=(const Fraction& left, const Fraction& right)
 
 Pre: left fraction compared to right fraction
 Post: bool value returned. true if left != right. false if otherwise. neither
 fraction object changed
 
 */


#ifndef Fraction_h
#define Fraction_h

#include <iostream>

namespace cs_Fraction {

class Fraction
    
{
    
private:
    
    int numrtr;
    
    int denmtr;
    
    void simplify();
    
public:
    
    Fraction(int inNumrtr = 0, int inDenmtr = 1);
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
    
    friend std::istream& operator>>(std::istream& in, Fraction& right);
    
    friend bool operator<(const Fraction& left, const Fraction& right);
    
    friend bool operator<=(const Fraction& left, const Fraction& right);
    
    friend bool operator>(const Fraction& left, const Fraction& right);
    
    friend bool operator>=(const Fraction& left, const Fraction& right);
    
    friend bool operator==(const Fraction& left, const Fraction& right);
    
    friend bool operator!=(const Fraction& left, const Fraction& right);
    
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    
    Fraction operator+=(const Fraction& right);
    
    Fraction operator-=(const Fraction& right);
    
    Fraction operator*=(const Fraction& right);
    
    Fraction operator/=(const Fraction& right);
    
    Fraction operator++();
    
    Fraction operator++(int);
    
    Fraction operator--();
    
    Fraction operator--(int);
    
};


}

#endif /* Fraction_h */

/*
 SAMPLE OUTPUT
 
 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0
 
 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6
 
 ----- Testing relational operators between Fractions
 Comparing 1/2 to 1/2
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 Comparing 1/2 to -1/2
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing -1/2 to 1/10
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing 1/10 to 0
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing 0 to 0
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 
 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing -3 to 1/4
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 
 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4
 
 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6
 
 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2
 
 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3
 
 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3

 
 
 */
