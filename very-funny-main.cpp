#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
        Point(double x = 0, double y = 0) : x(x), y(y) {}

        double getX() const
        {
            return x;
        }

        double getY() const
        {
            return y;
        }

        void setX(double x)
        { 
            this->x = x; 
        }

        void setY(double y)
        { 
            this->y = y;
        }

        friend ostream& operator<<(ostream& os, const Point& p)
        {
            os << "(" << p.x << ", " << p.y << ")";
            return os;
        }

        friend double operator-(Point const& p1, Point const& p2)
        {
            return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
        }

        friend string operator/(Point const& p1, Point const& p2)
        {
            return "(" + to_string((p1.x + p2.x)/2) + ", " + to_string((p1.y + p2.y)/2) + ")";
        }

        friend string operator==(Point const& p1, Point const& p2)
        {
            if (((p1.x == p2.x) && (p1.y == p2.y)))
            {
                return " are ";
            } else {
                return "are not ";
            }
        }

        friend string operator!=(Point const& p1, Point const& p2)
        {
            if (((p1.x != p2.x) || (p1.y != p2.y)))
            {
                return " are not";
            } else {
                return "are ";
            }
        }

        friend string operator*(Point const& p, int toUse)
        {
            int newX = int (p.x * toUse);
            return "(" + to_string(newX) + ", " + to_string(p.y * toUse) + ")";
        }

    private:
        double x;
        double y;
};

int main() 
{
    double x1, y1, x2, y2;

    cout << "Please input the x and y coordinates of the first point.\n";
    cin >> x1 >> y1;
    cout << "Please input the x and y coordinates of the second point.\n";
    cin >> x2 >> y2;

    Point p1(x1, y1);
    Point p2(x2, y2);

    while (true)
    {
        string actionChar;
        cout << "\nPlease input an action:\n[D] - Prints the distance between the two points\n[E] - Checks if the two points are equal\n[I] - Checks if the two points are not equal\n[M] - Prints the midpoint of the two points\n[T] - Multiplies a point by a constant\n";

        while ((!(cin >> actionChar)) || ((actionChar != "D") && (actionChar != "E") && (actionChar != "I") && (actionChar != "M") && (actionChar != "T") && (actionChar != "d") && (actionChar != "e") && (actionChar != "i") && (actionChar != "m") && (actionChar != "t")))
        {
            cout << "ERROR: Invalid response. Please input an action.\n";
            cin.clear();
            cin.ignore(40, '\n');
        }

        if ((actionChar == "D") || (actionChar == "d"))
        {
            cout << "The distance is " << (p1 - p2) << endl;
        }

        if ((actionChar == "E") || (actionChar == "e"))
        {
            cout << "The two points " << (p1 == p2) << "equal.\n";
        }

        if ((actionChar == "I") || (actionChar == "i"))
        {
            cout << "The two points " << (p1 != p2) << "equal.\n";
        }

        if ((actionChar == "M") || (actionChar == "m"))
        {
            cout << "The midpoint is " << (p1 / p2) << endl;
        }

        if ((actionChar == "T") || (actionChar == "t"))
        {
            int input;
            cout << "Please enter the point to multiply.\n";
            while ((!(cin >> input)) || ((input != 1) && (input != 2)))
            {
                cout << "ERROR: Invalid response. Please select the point to multiply.\n";
                cin.clear();
                cin.ignore(40, '\n');
            }

            Point p;
            if (input == 1)
            {
                p = p1;
            } else {
                p = p2;
            }

            int multi;
            cout << "Please enter a number to multiply by.\n";
            while (!(cin >> multi))
            {
                cout << "ERROR: Invalid response. Please select a number to multiply by.\n";
                cin.clear();
                cin.ignore(40, '\n');
            }

            cout << "The result is " << (p * multi) << endl;
        }
    }
}