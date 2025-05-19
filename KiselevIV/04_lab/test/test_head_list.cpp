#include "head_list.h"
#include <gtest.h>

TEST(THeadList, can_create_empty_list)
{
    ASSERT_NO_THROW(THeadList<int> list);
}

TEST(THeadList, is_empty_on_creation)
{
    THeadList<int> list;
    EXPECT_TRUE(list.empty());
}

TEST(THeadList, can_push_front_node)
{
    THeadList<int> list;
    TNode<int>* node = new TNode<int>(5);
    ASSERT_NO_THROW(list.push_front(node));
    EXPECT_FALSE(list.empty());
}

TEST(THeadList, push_front_updates_pHead_next)
{
    //это чек что pHead->pNext ==pFirst
    THeadList<int> list;
    TNode<int>* node = new TNode<int>(10);
    list.push_front(node);
    EXPECT_EQ(list.get_first_key(), 10);
}

TEST(THeadList, can_pop_front_node)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(7));
    ASSERT_NO_THROW(list.pop_front());
}

TEST(THeadList, pop_front_updates_pHead_next)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(7));
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(THeadList, can_assign_head_list)
{
    THeadList<int> list1;
    list1.push_front(new TNode<int>(1));
    list1.push_front(new TNode<int>(2));

    THeadList<int> list2;
    ASSERT_NO_THROW(list2 = list1);
    EXPECT_FALSE(list2.empty());
    EXPECT_EQ(list2.get_first_key(), 2);
}

TEST(THeadList, assigned_lists_are_equal)
{
    THeadList<int> list1;
    list1.push_front(new TNode<int>(1));
    list1.push_front(new TNode<int>(2));

    THeadList<int> list2;
    list2 = list1;
    EXPECT_TRUE(list1 == list2);
}

TEST(THeadList, can_search_existing_key)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(3));
    EXPECT_NE(list.search(3), nullptr);
}

TEST(THeadList, search_returns_nullptr_for_nonexistent_key)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(3));
    EXPECT_EQ(list.search(100), nullptr);
}

TEST(THeadList, can_push_back_node)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(1));
    ASSERT_NO_THROW(list.push_back(new TNode<int>(5)));
    EXPECT_NE(list.search(5), nullptr);
}

TEST(THeadList, can_push_before_node)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(10));
    ASSERT_NO_THROW(list.push_before(new TNode<int>(7), 10));
    EXPECT_NE(list.search(7), nullptr);
}

TEST(THeadList, can_remove_node_by_key)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(10));
    ASSERT_NO_THROW(list.remove(10));
    EXPECT_EQ(list.search(10), nullptr);
}

TEST(THeadList, empty_returns_true_for_empty_list)
{
    THeadList<int> list;
    EXPECT_TRUE(list.empty());
}

TEST(THeadList, size_returns_correct_count)
{
    THeadList<int> list;
    list.push_front(new TNode<int>(1));
    list.push_front(new TNode<int>(2));
    EXPECT_EQ(list.size(), 2);
}
