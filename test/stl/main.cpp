#include <iostream>
#include "test_array.h"
#include "test_vector.h"
#include "test_list.h"
#include "test_forward_list.h"
#include "test_deque.h"
#include "test_multiset.h"
#include "test_multimap.h"
#include "test_unordered_multiset.h"
#include "test_unordered_multimap.h"
#include "test_set.h"
#include "test_map.h"
#include "test_unordered_set.h"
#include "test_unordered_map.h"
#include "test_stack.h"
#include "test_queue.h"

using namespace std;

int main() {
    bb01::test_array();
    bb02::test_vector();
    bb03::test_list();
    bb04::test_forward_list();
    bb05::test_deque();
    bb06::test_multiset();
    bb07::test_multimap();
    bb08::test_unordered_multiset();
    bb09::test_unordered_multimap();
    bb10::test_set();
    bb11::test_map();
    bb12::test_unordered_set();
    bb13::test_unordered_map();
    bb14::test_stack();
    bb15::test_queue();
}