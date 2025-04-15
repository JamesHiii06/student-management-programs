#include "students.h"

int averageScore(profile *s, int ID)
{
    s[ID].aver = (s[ID].math + s[ID].lit + s[ID].eng) / 3.0;
    return s[ID].aver;
}

