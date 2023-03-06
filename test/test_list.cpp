#include"gtest.h"
#include"MList.h"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}

TEST(List, can_insert_elements_in_an_orderly_manner)
{
	List<int> l;
	ASSERT_NO_THROW(l.sortInsert(7));
}

TEST(List, can_check_if_the_empty_list_is_empty)
{
	List<int> l;
	EXPECT_TRUE(l.isEmpty());
}

TEST(List, can_check_if_the_non_empty_list_is_empty)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	EXPECT_FALSE(l.isEmpty());
}

TEST(List, can_get_the_first_element)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	ASSERT_NO_THROW(l.getFirst());
}

TEST(List, can_insert_elements_in_an_orderly_manner_correctly)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	EXPECT_EQ(l.getFirst()->data, 3);
	EXPECT_EQ(l.getFirst()->next->data, 2);
	EXPECT_EQ(l.getFirst()->next->next->data, 1);
}

TEST(List, can_copy_list)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	ASSERT_NO_THROW(List<int>copy(l));
}

TEST(List, copied_list_is_equal_to_source_one)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	List<int>copy(l);
	EXPECT_EQ(l.getFirst()->data, copy.getFirst()->data);
	EXPECT_EQ(l.getFirst()->next->data, copy.getFirst()->next->data);
	EXPECT_EQ(l.getFirst()->next->next->data, copy.getFirst()->next->next->data);
}

TEST(List, can_assign_list)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	List<int>copy;
	ASSERT_NO_THROW(copy = l);
}

TEST(List, assigned_list_is_equal_to_source_one)
{
	List<int> l;
	l.sortInsert(2);
	l.sortInsert(3);
	l.sortInsert(1);
	List<int>copy;
	copy.sortInsert(4);
	copy.sortInsert(5);
	copy = l;
	EXPECT_EQ(l.getFirst()->data, copy.getFirst()->data);
	EXPECT_EQ(l.getFirst()->next->data, copy.getFirst()->next->data);
	EXPECT_EQ(l.getFirst()->next->next->data, copy.getFirst()->next->next->data);
}