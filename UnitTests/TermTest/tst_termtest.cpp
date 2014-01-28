#include <QString>
#include <QtTest>

#include <memory>
#include "../../terms.h"

using namespace std;

class TermTest : public QObject
{
    Q_OBJECT

public:
    TermTest();

private Q_SLOTS:
    void testPlus();
    void testPlus_data();
    void benchPlus();
    void testMinus();
    void testMinus_data();
    void benchMinus();
    void testMultiply();
    void testMultiply_data();
    void benchMultiply();
    void testDevide();
    void testDevide_data();
    void benchDevide();
    void testPower();
    void testPower_data();
    void benchPower();
    void testExp();
    void testExp_data();
    void benchExp();
    void testLog10();
    void testLog10_data();
    void benchLog10();
    void testSin();
    void testSin_data();
    void benchSin();

};

TermTest::TermTest()
{
}

void TermTest::testPlus()
{
    QFETCH(double, lhs);
    QFETCH(double, rhs);
    QFETCH(double, wish);
    double localStack[2];
    localStack[0] = rhs;
    localStack[1] = lhs;
    AbstractTerm *term = new Plus;
    QCOMPARE(term->calc(localStack, term->valency()), wish);
    delete term;
}

void TermTest::testPlus_data()
{
    QTest::addColumn<double>("lhs");
    QTest::addColumn<double>("rhs");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.0 << 0.0 << 0.0 + 0.0;
    QTest::newRow("1") << 0.0 << 1.0 << 0.0 + 1.0;
    QTest::newRow("2") << 1.0 << 0.0 << 1.0 + 0.0;
    QTest::newRow("3") << 1.0 << -1.0 << 1.0 + -1.0;
    QTest::newRow("4") << 100.0 << 0.001 << 100.0 + 0.001;
    QTest::newRow("5") << 1.0 << 1.0 << 1.0 + 1.0;
    QTest::newRow("6") << 3.1 << -1.0 << 3.1 + -1.0;
    QTest::newRow("7") << 0.5 << 0.5 << 0.5 + 0.5;
    QTest::newRow("8") << 0.01 << 0.01 << 0.01 + 0.01;
    QTest::newRow("9") << 1e-10 << 1e-10 << 1e-10 + 1e-10;
}

void TermTest::benchPlus()
{
    double localStack[2];
    localStack[0] = 1.0;
    localStack[1] = 1.5;
    AbstractTerm *term = new Plus;
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    delete term;
    Q_UNUSED(result);
}

void TermTest::testMinus()
{
    QFETCH(double, lhs);
    QFETCH(double, rhs);
    QFETCH(double, wish);
    double localStack[2];
    localStack[0] = rhs;
    localStack[1] = lhs;
    AbstractTerm *term = new Minus;
    QCOMPARE(term->calc(localStack, term->valency()), wish);
    delete term;
}

void TermTest::testMinus_data()
{
    QTest::addColumn<double>("lhs");
    QTest::addColumn<double>("rhs");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.0 << 0.0 << 0.0 - 0.0;
    QTest::newRow("1") << 0.0 << 1.0 << 0.0 - 1.0;
    QTest::newRow("2") << 1.0 << 0.0 << 1.0 - 0.0;
    QTest::newRow("3") << 1.0 << -1.0 << 1.0 - -1.0;
    QTest::newRow("4") << 100.0 << 0.001 << 100.0 - 0.001;
    QTest::newRow("5") << 1.0 << 1.0 << 1.0 - 1.0;
    QTest::newRow("6") << 3.1 << -1.0 << 3.1 - -1.0;
    QTest::newRow("7") << 0.5 << 0.5 << 0.5 - 0.5;
    QTest::newRow("8") << 0.01 << 0.01 << 0.01 - 0.01;
    QTest::newRow("9") << 1e-10 << 1e-10 << 1e-10 - 1e-10;
}

void TermTest::benchMinus()
{
    double localStack[2];
    localStack[0] = 1.0;
    localStack[1] = 1.5;
    AbstractTerm *term = new Minus;
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    delete term;
    Q_UNUSED(result);
}

void TermTest::testMultiply()
{
    QFETCH(double, lhs);
    QFETCH(double, rhs);
    QFETCH(double, wish);
    double localStack[2];
    localStack[0] = rhs;
    localStack[1] = lhs;
    AbstractTerm *term = new Multiply;
    QCOMPARE(term->calc(localStack, term->valency()), wish);
    delete term;
}

void TermTest::testMultiply_data()
{
    QTest::addColumn<double>("lhs");
    QTest::addColumn<double>("rhs");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.0 << 0.0 << 0.0 * 0.0;
    QTest::newRow("1") << 0.0 << 1.0 << 0.0 * 1.0;
    QTest::newRow("2") << 1.0 << 0.0 << 1.0 * 0.0;
    QTest::newRow("3") << 1.0 << -1.0 << 1.0 * -1.0;
    QTest::newRow("4") << 100.0 << 0.001 << 100.0 * 0.001;
    QTest::newRow("5") << 1.0 << 1.0 << 1.0 * 1.0;
    QTest::newRow("6") << 3.1 << -1.0 << 3.1 * -1.0;
    QTest::newRow("7") << 0.5 << 0.5 << 0.5 * 0.5;
    QTest::newRow("8") << 0.01 << 0.01 << 0.01 * 0.01;
    QTest::newRow("9") << 1e-10 << 1e-10 << 1e-10 * 1e-10;
}

void TermTest::benchMultiply()
{
    double localStack[2];
    localStack[0] = 1.0;
    localStack[1] = 1.5;
    AbstractTerm *term = new Multiply;
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    delete term;
    Q_UNUSED(result);
}

void TermTest::testDevide()
{
    QFETCH(double, lhs);
    QFETCH(double, rhs);
    QFETCH(double, wish);
    double localStack[2];
    localStack[0] = rhs;
    localStack[1] = lhs;
    AbstractTerm *term = new Devide;
    QCOMPARE(term->calc(localStack, term->valency()), wish);
    delete term;
}

void TermTest::testDevide_data()
{
    QTest::addColumn<double>("lhs");
    QTest::addColumn<double>("rhs");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.01 << 0.1 << 0.01 / 0.1;
    QTest::newRow("1") << 0.0 << 1.0 << 0.0 / 1.0;
    QTest::newRow("2") << 1.0 << 0.1 << 1.0 / 0.1;
    QTest::newRow("3") << 1.0 << -1.0 << 1.0 / -1.0;
    QTest::newRow("4") << 100.0 << 0.001 << 100.0 / 0.001;
    QTest::newRow("5") << 1.0 << 1.0 << 1.0 / 1.0;
    QTest::newRow("6") << 3.1 << -1.0 << 3.1 / -1.0;
    QTest::newRow("7") << 0.5 << 0.5 << 0.5 / 0.5;
    QTest::newRow("8") << 0.01 << 0.01 << 0.01 / 0.01;
    QTest::newRow("9") << 1e-10 << 1e-10 << 1e-10 / 1e-10;
}

void TermTest::benchDevide()
{
    double localStack[2];
    localStack[0] = 1.0;
    localStack[1] = 1.5;
    AbstractTerm *term = new Devide;
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    delete term;
    Q_UNUSED(result);
}

void TermTest::testPower()
{
    QFETCH(double, lhs);
    QFETCH(double, rhs);
    QFETCH(double, wish);
    double localStack[2];
    localStack[0] = rhs;
    localStack[1] = lhs;
    AbstractTerm *term = new Power;
    QCOMPARE(term->calc(localStack, term->valency()), wish);
    delete term;
}

void TermTest::testPower_data()
{
    QTest::addColumn<double>("lhs");
    QTest::addColumn<double>("rhs");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.0 << 0.0 << pow(0.0, 0.0);
    QTest::newRow("1") << 0.0 << 1.0 << pow(0.0, 1.0);
    QTest::newRow("2") << 1.0 << 0.0 << pow(1.0, 0.0);
    QTest::newRow("3") << 1.0 << -1.0 << pow(1.0, -1.0);
    QTest::newRow("4") << 100.0 << 0.001 << pow(100.0, 0.001);
    QTest::newRow("5") << 1.0 << 1.0 << pow(1.0, 1.0);
    QTest::newRow("6") << 3.1 << -1.0 << pow(3.1, -1.0);
    QTest::newRow("7") << 0.5 << 0.5 << pow(0.5, 0.5);
    QTest::newRow("8") << 0.01 << 0.01 << pow(0.01, 0.01);
    QTest::newRow("9") << 1e-10 << 1e-10 << pow(1e-10, 1e-10);
}

void TermTest::benchPower()
{
    double localStack[2];
    localStack[0] = 1.0;
    localStack[1] = 1.5;
    AbstractTerm *term = new Power;
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    delete term;
    Q_UNUSED(result);
}

void TermTest::testExp()
{
    QFETCH(double, arg);
    QFETCH(double, wish);
    double localStack[1];
    localStack[0] = arg;
    AbstractTerm *term = new Exp;
    QCOMPARE(term->calc(localStack, term->valency()), wish);
    delete term;
}

void TermTest::testExp_data()
{
    QTest::addColumn<double>("arg");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.0 << exp(0.0);
    QTest::newRow("1") << 0.1 << exp(0.1);
    QTest::newRow("2") << 1.0 << exp(1.0);
    QTest::newRow("3") << -10.0 << exp(-10.0);
    QTest::newRow("4") << 1.1 << exp(1.1);
    QTest::newRow("5") << M_PI << exp(M_PI);
    QTest::newRow("6") << M_PI/2.0 << exp(M_PI/2.0);
    QTest::newRow("7") << -M_PI << exp(-M_PI);
    QTest::newRow("8") << 1e2 << exp(1e2);
    QTest::newRow("9") << -1e3 << exp(-1e3);
}

void TermTest::benchExp()
{
    double localStack[1];
    localStack[0] = 1.5;
    AbstractTerm *term = new Exp;
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    delete term;
    Q_UNUSED(result);
}

void TermTest::testLog10()
{
    QFETCH(double, arg);
    QFETCH(double, wish);
    double localStack[1];
    localStack[0] = arg;
    shared_ptr<AbstractTerm> term = make_shared<Log10>();
    QCOMPARE(term->calc(localStack, term->valency()), wish);
}

void TermTest::testLog10_data()
{
    QTest::addColumn<double>("arg");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.01 << log10(0.01);
    QTest::newRow("1") << 0.1 << log10(0.1);
    QTest::newRow("2") << 1.0 << log10(1.0);
    QTest::newRow("3") << 10.0 << log10(10.0);
    QTest::newRow("4") << 1.1 << log10(1.1);
    QTest::newRow("5") << M_PI << log10(M_PI);
    QTest::newRow("6") << M_PI/2.0 << log10(M_PI/2.0);
    QTest::newRow("7") << 1.0/M_PI << log10(1.0/M_PI);
    QTest::newRow("8") << 1e2 << log10(1e2);
    QTest::newRow("9") << 1e-3 << log10(1e-3);
}

void TermTest::benchLog10()
{
    double localStack[1];
    localStack[0] = 1.5;
    shared_ptr<AbstractTerm> term = make_shared<Log10>();
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    Q_UNUSED(result);
}

void TermTest::testSin()
{
    QFETCH(double, arg);
    QFETCH(double, wish);
    double localStack[1];
    localStack[0] = arg;
    shared_ptr<AbstractTerm> term = make_shared<Sin>();
    QCOMPARE(term->calc(localStack, term->valency()), wish);
}

void TermTest::testSin_data()
{
    QTest::addColumn<double>("arg");
    QTest::addColumn<double>("wish");
    QTest::newRow("0") << 0.0 << sin(0.0);
    QTest::newRow("1") << 0.1 << sin(0.1);
    QTest::newRow("2") << 1.0 << sin(1.0);
    QTest::newRow("3") << -10.0 << sin(-10.0);
    QTest::newRow("4") << 1.1 << sin(1.1);
    QTest::newRow("5") << M_PI << sin(M_PI);
    QTest::newRow("6") << M_PI/2.0 << sin(M_PI/2.0);
    QTest::newRow("7") << -M_PI << sin(-M_PI);
    QTest::newRow("8") << 1e2 << sin(1e2);
    QTest::newRow("9") << -1e3 << sin(-1e3);
}

void TermTest::benchSin()
{
    double localStack[1];
    localStack[0] = 1.5;
    shared_ptr<AbstractTerm> term = make_shared<Sin>();
    double result;
    QBENCHMARK
    {
        result = term->calc(localStack, term->valency());
    }
    Q_UNUSED(result);
}


QTEST_APPLESS_MAIN(TermTest)

#include "tst_termtest.moc"
