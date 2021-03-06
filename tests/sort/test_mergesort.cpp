#define BOOST_TEST_MODULE test_mergesort
#define BOOST_TEST_DYN_LINK

#include <stdlib.h>

#include "test_sort.hpp"
extern "C" {
#include "sort/mergesort.h"
}

BOOST_AUTO_TEST_CASE(empty_0) {
    void *xs = NULL;

    mergesort0(xs, 0, 0, compare_int);

    BOOST_TEST(0 == 0);
}

BOOST_AUTO_TEST_CASE(single_0) {
    int *xs = (int *) malloc(sizeof(int));

    *xs = 42;

    mergesort0(xs, 1, sizeof(int), compare_int);

    BOOST_TEST(*xs == 42);
}


using bdata::make;


BOOST_DATA_TEST_CASE(
    inc_two_elements_0,
    make({41, 42}) * make({41, 42}),
    a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    mergesort0(xs.data(), xs.size(), sizeof(int), compare_int);
    std::sort(ys.begin(), ys.end(), std::less<>{});

    BOOST_TEST(xs.size() == 2);
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

// BOOST_DATA_TEST_CASE(
//     dec_two_elements_0,
//     make(dec_sorts) * make({41, 42}) * make({41, 42}),
//     sort, a, b
// ) {
//     vi xs = {a, b};
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::greater<>{});
//     std::sort(ys.begin(), ys.end(), std::greater<>{});

//     BOOST_TEST(xs.size() == 2);
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

BOOST_DATA_TEST_CASE(
    inc_two_elements_1,
    make(
        create_vector(10, 1)
    ) * make(
        create_vector(10, 2)
    ),
    a, b
) {
    vi xs = {a, b};
    vi ys = xs;

    mergesort0(xs.data(), xs.size(), sizeof(int), compare_int);
    std::sort(ys.begin(), ys.end(), std::less<>{});

    BOOST_TEST(xs.size() == 2);
    // for (auto x: xs) std::cerr << x << " "; std::cerr << std::endl;
    // for (auto y: ys) std::cerr << y << " "; std::cerr << std::endl;
    BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
}

// BOOST_DATA_TEST_CASE(
//     dec_two_elements_1,
//     make(
//         dec_sorts
//     ) * make(
//         create_vector(10, 1)
//     ) * make(
//         create_vector(10, 2)
//     ),
//     sort, a, b
// ) {
//     vi xs = {a, b};
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::greater<>{});
//     std::sort(ys.begin(), ys.end(), std::greater<>{});

//     BOOST_TEST(xs.size() == 2);
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

// BOOST_DATA_TEST_CASE(
//     inc_three_elements_0,
//     make(
//         inc_sorts
//     ) * make(
//         create_vector(10, 1)
//     ) * make(
//         create_vector(10, 2)
//     ) * make(
//         create_vector(10, 3)
//     ),
//     sort, a, b, c
// ) {
//     vi xs = {a, b, c};
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::less<>{});
//     std::sort(ys.begin(), ys.end(), std::less<>{});

//     BOOST_TEST(xs.size() == 3);
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

// BOOST_DATA_TEST_CASE(
//     dec_three_elements_0,
//     make(
//         dec_sorts
//     ) * make(
//         create_vector(10, 1)
//     ) * make(
//         create_vector(10, 2)
//     ) * make(
//         create_vector(10, 3)
//     ),
//     sort, a, b, c
// ) {
//     vi xs = {a, b, c};
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::greater<>{});
//     std::sort(ys.begin(), ys.end(), std::greater<>{});

//     BOOST_TEST(xs.size() == 3);
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

// BOOST_DATA_TEST_CASE(
//     inc_random_mergesort_0,
//     make(inc_sorts) * bdata::xrange(1, 256) * bdata::xrange(20),
//     sort, n, s
// ) {
//     vi xs = create_vector(n, s);
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::less<>{});
//     std::sort(ys.begin(), ys.end(), std::less<>{});

//     BOOST_TEST(xs.size() == ys.size());
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

// BOOST_DATA_TEST_CASE(
//     dec_random_mergesort_0,
//     make(dec_sorts) * bdata::xrange(1, 256) * bdata::xrange(20),
//     sort, n, s
// ) {
//     vi xs = create_vector(n, s);
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::greater<>{});
//     std::sort(ys.begin(), ys.end(), std::greater<>{});

//     BOOST_TEST(xs.size() == ys.size());
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

// BOOST_DATA_TEST_CASE(
//     inc_random_mergesort_stress_0,
//     make(inc_sorts) * bdata::make(1e4) * bdata::xrange(10),
//     sort, n, s
// ) {
//     vi xs = create_vector(n, s);
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::less<>{});
//     std::sort(ys.begin(), ys.end(), std::less<>{});

//     BOOST_TEST(xs.size() == ys.size());
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }

// BOOST_DATA_TEST_CASE(
//     dec_random_mergesort_stress_0,
//     make(dec_sorts) * bdata::make(1e4) * bdata::xrange(10),
//     sort, n, s
// ) {
//     vi xs = create_vector(n, s);
//     vi ys = xs;

//     sort(xs.begin(), xs.end(), std::greater<>{});
//     std::sort(ys.begin(), ys.end(), std::greater<>{});

//     BOOST_TEST(xs.size() == ys.size());
//     BOOST_TEST(std::equal(xs.begin(), xs.end(), ys.begin()) == true);
// }
