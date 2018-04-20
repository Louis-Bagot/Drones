#include "../tests/testsVecteurR3.h"


void testsVecteurR3::testAddition(void)
{
    vec1 = new VecteurR3(1,2,3);
    vec2 = new VecteurR3(3,2,1);
    VecteurR3 vecRes = vec1 + vec2;

    CPPUNIT_ASSERT(vecRes.getX()==4 && vecRes.getY()==4 && vecRes.getZ());
}

void testsVecteurR3::testMultiplication(void){

}
void testsVecteurR3::setUp(void)
{
    //Methode appel� d�s le debut, c'est ici qu'on est cens� cr�er les objets
}

void testsVecteurR3::tearDown(void)
{
    //C'est ici qu'on d�truit les objets
}
