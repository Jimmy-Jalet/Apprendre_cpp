#include <iostream>
#include "trajectoire.h"
#include "segment.h"
#include "element.h"

using namespace std;

int main()
{
    Trajectoire uneTrajectoire(1,1,3);
    uneTrajectoire.Afficher();
    Segment segment1(9,0.2,4,7);
    segment1.Afficher();
    Segment segment2(5,0.27295,2,1);
    segment2.Afficher();

    return 0;
}
