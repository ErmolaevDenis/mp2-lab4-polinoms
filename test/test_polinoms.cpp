#include"gtest.h"
#include"polinoms.h"

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_get_polinom)
{
	Polinom p;
	ASSERT_NO_THROW(p.getPolinom());
}

TEST(Polinom, can_set_polinom)
{
	Polinom p;
	cout << endl << endl;
	ASSERT_NO_THROW(p.Set());
}

TEST(Polinom, polinom_ordered_correctly)
{
	Polinom p;
	Monom m1(111, 2);
	Monom m2(222, 1);
	p.getPolinom().sortInsert(m1);
	p.getPolinom().sortInsert(m2);
	EXPECT_EQ(p.getPolinom().getFirst()->data.getCoef(), 1);
	EXPECT_EQ(p.getPolinom().getFirst()->data.getDeg(), 222);
	EXPECT_EQ(p.getPolinom().getFirst()->next->data.getCoef(), 2);
	EXPECT_EQ(p.getPolinom().getFirst()->next->data.getDeg(), 111);
}

TEST(Polinom, can_multiply_polinom_by_const)
{
	Polinom p;
	Monom m1(111, 2);
	Monom m2(222, 1);
	p.getPolinom().sortInsert(m1);
	p.getPolinom().sortInsert(m2);
	Polinom res = p * 2;
	EXPECT_EQ(res.getPolinom().getFirst()->data.getCoef(), 2);
	EXPECT_EQ(res.getPolinom().getFirst()->data.getDeg(), 222);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getCoef(), 4);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getDeg(), 111);
}

TEST(Polinom, can_add_polinoms)
{
	Polinom p1;
	Monom m1(111, 2);
	Monom m2(222, 1);
	p1.getPolinom().sortInsert(m1);
	p1.getPolinom().sortInsert(m2);
	Polinom p2;
	Monom m3(000, 3);
	Monom m4(222, 2);
	p2.getPolinom().sortInsert(m3);
	p2.getPolinom().sortInsert(m4);
	Polinom res = p1 + p2;
	EXPECT_EQ(res.getPolinom().getFirst()->data.getCoef(), 3);
	EXPECT_EQ(res.getPolinom().getFirst()->data.getDeg(), 222);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getCoef(), 2);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getDeg(), 111);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->data.getCoef(), 3);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->data.getDeg(), 000);
}

TEST(Polinom, can_sub_polinoms)
{
	Polinom p1;
	Monom m1(111, 2);
	Monom m2(222, 1);
	p1.getPolinom().sortInsert(m1);
	p1.getPolinom().sortInsert(m2);
	Polinom p2;
	Monom m3(000, 3);
	Monom m4(222, 2);
	p2.getPolinom().sortInsert(m3);
	p2.getPolinom().sortInsert(m4);
	Polinom res = p1 - p2;
	EXPECT_EQ(res.getPolinom().getFirst()->data.getCoef(), -1);
	EXPECT_EQ(res.getPolinom().getFirst()->data.getDeg(), 222);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getCoef(), 2);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getDeg(), 111);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->data.getCoef(), -3);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->data.getDeg(), 000);
}

TEST(Polinom, can_mul_polinoms)
{
	Polinom p1;
	Monom m1(111, 2);
	Monom m2(222, 1);
	p1.getPolinom().sortInsert(m1);
	p1.getPolinom().sortInsert(m2);
	Polinom p2;
	Monom m3(000, 3);
	Monom m4(222, 2);
	p2.getPolinom().sortInsert(m3);
	p2.getPolinom().sortInsert(m4);
	Polinom res = p1 * p2;
	EXPECT_EQ(res.getPolinom().getFirst()->data.getCoef(), 2);
	EXPECT_EQ(res.getPolinom().getFirst()->data.getDeg(), 444);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getCoef(), 4);
	EXPECT_EQ(res.getPolinom().getFirst()->next->data.getDeg(), 333);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->data.getCoef(), 3);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->data.getDeg(), 222);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->next->data.getCoef(), 6);
	EXPECT_EQ(res.getPolinom().getFirst()->next->next->next->data.getDeg(), 111);
}