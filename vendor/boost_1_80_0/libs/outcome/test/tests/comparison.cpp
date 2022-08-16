/* Unit testing for outcomes
(C) 2013-2022 Niall Douglas <http://www.nedproductions.biz/> (6 commits)


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifdef _MSC_VER
#pragma warning(disable : 4127)  // conditional expression is constant
#pragma warning(disable : 4244)  // conversion from int to short
#endif

#include <boost/outcome.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_monitor.hpp>

BOOST_OUTCOME_AUTO_TEST_CASE(works_outcome_comparison, "Tests that the outcome can compare to compatible outcomes")
{
#if !defined(__APPLE__) || defined(__cpp_exceptions)
  using namespace BOOST_OUTCOME_V2_NAMESPACE;
  auto p = boost::copy_exception(std::runtime_error("hi"));
  // value comparison
  {
    outcome<int> a(1), b(2), c(2);
    BOOST_CHECK(a == a);
    BOOST_CHECK(b == b);
    BOOST_CHECK(c == c);
    BOOST_CHECK(a != b);
    BOOST_CHECK(b == c);
  }
  // homogeneous outcome comparison
  {
    outcome<int> a(1), b(2), c(boost::system::errc::invalid_argument), d(p);
    BOOST_CHECK(a == a);
    BOOST_CHECK(a != b);
    BOOST_CHECK(a != c);
    BOOST_CHECK(a != d);
    BOOST_CHECK(b == b);
    BOOST_CHECK(b != c);
    BOOST_CHECK(b != d);
    BOOST_CHECK(c == c);
    BOOST_CHECK(c != d);
    BOOST_CHECK(d == d);
    outcome<int> e(boost::system::errc::invalid_argument), f(p);
    BOOST_CHECK(c == e);
    BOOST_CHECK(d == f);
  }
  // heterogeneous outcome comparison, so outcome<int> to outcome<double> etc
  {
    outcome<int> a(1);
    outcome<double> b(1);
    outcome<unsigned short> c(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == a);
    BOOST_CHECK(b == c);
    BOOST_CHECK(c == a);
    BOOST_CHECK(c == b);
    // outcome<void> e(in_place_type<void>);
    outcome<unsigned short> f(boost::system::errc::invalid_argument);
    outcome<double> g(p);
    // BOOST_CHECK(a != e);
    BOOST_CHECK(a != f);
    BOOST_CHECK(a != g);
    // BOOST_CHECK(e != f);
    BOOST_CHECK(f != g);
  }
  // upconverting outcome comparison, so outcome<int>==result<int> etc
  {
    outcome<int> a(1);
    result<int> b(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(b == a);
    // result<void> e(in_place_type<void>), f(boost::system::errc::invalid_argument);
    // BOOST_CHECK(a != e);
    // BOOST_CHECK(a != f);
  }
  // Should I do outcome<int>(5) == 5? Unsure if it's wise
#endif
}
