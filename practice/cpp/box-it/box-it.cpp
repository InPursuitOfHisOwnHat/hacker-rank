#include<bits/stdc++.h>

using namespace std;

//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {

    private:

        long l, b, h;

    public:

        Box() {
            this->l = this->b = this->h = 0;
        }

        Box(int length, int breadth, int height) {
            this->l = length;
            this->b = breadth;
            this->h = height;
        }

        Box(const Box& b) {

            this->l = b.l;
            this->b = b.b;
            this->h = b.h;
            
        }

        int getLength() {
            return this->l;
        }

        int getBreadth() {
            return this->b;
        }

        int getHeight() {
            return this->h;
        }

        long long CalculateVolume() {

            return this->l * this->b * this->h;
        }

        bool operator<(Box& b) {

            if (this->l < b.l) {
                return true;
            }
            else if (this->b < b.b && this->l == b.l) {
                return true;
            }
            else if (this->h < b.h && this->b == b.b && this->l == b.l) {
                return true;
            }
            else {
                return false;
            }

        }

        friend ostream& operator<<(ostream& out, const Box B) {
            out << B.l << " " << B.b << " " << B.h;
            return out;
        }

};

