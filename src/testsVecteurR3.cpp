#include "../tests/testsVecteurR3.h"


void testsVecteurR3::testAddition(void)
{
    vec1 = new VecteurR3(1,2,3);
    vec2 = new VecteurR3(3,2,1);
    VecteurR3 vecRes = vec1 + vec2;

    CPPUNIT_ASSERT(vecRes.getX()==4 && vecRes.getY()==4 && vecRes.getZ()==4);
}

void testsVecteurR3::testSoustraction(void)
{
    vec1 = new VecteurR3(3,2,3);
    vec2 = new VecteurR3(-1,2,1);
    VecteurR3 vecRes = vec1 - vec2;

    CPPUNIT_ASSERT(vecRes.getX()==4 && vecRes.getY()==0 && vecRes.getZ()==2);
}

void testsVecteurR3::testAffectation(void)
{
    vec1 = new VecteurR3(1,1,1);
    VecteurR3 vecRes = vec1;

    CPPUNIT_ASSERT(vecRes.getX()==1 && vecRes.getY()==1 && vecRes.getZ()==1);
}

void testsVecteurR3::testMultiplication(void)
{
    vec1 = new VecteurR3(1,2,1);
    vec2 = new VecteurR3(2,1,2);
    float res = vec1*vec2;

    CPPUNIT_ASSERT(res==6);
}

void testsVecteurR3::testMultiplicationScalaire(void)
{
    vec1 = new VecteurR3(1,2,1);
    float scal = 2.0;
    VecteurR3 vecRes = scal*vec1;

    CPPUNIT_ASSERT(vecRes.getX()==2 && vecRes.getY()==4 && vecRes.getZ()==2);
}

void testsVecteurR3::testIncrementation(void)
{
    vec1 = new VecteurR3(1,1,1);
    vec1 += vec1;

    CPPUNIT_ASSERT(vec1.getX()==2 && vec1.getY()==2 && vec1.getZ()==2);
}

void testVecteurR3::testNorme22(void)
{
    vec1 = new VecteurR3(1,1,1);
    float res = vec1.norme22();

    CPPUNIT_ASSERT(res==3);
}

void testVecteurR3::testprodVec(void)
{
    vec1 = new VecteurR3(1,2,3);
    vec2 = new VecteurR3(3,2,1);
    VecteurR3 vecRes = vec1.prodVec(vec2);

    CPPUNIT_ASSERT(vec1.getX()==-4 && vec1.getY()==8 && vec1.getZ()==-4);
}


void testsVecteurR3::setUp(void)
{
    //Methode appel� d�s le debut, c'est ici qu'on est cens� cr�er les objets
}

void testsVecteurR3::tearDown(void)
{
    //C'est ici qu'on d�truit les objets
}
