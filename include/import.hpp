/* import.hpp
Convenience macros for importing local namespace binds
(C) 2014 Niall Douglas http://www.nedprod.com/
File Created: Aug 2014


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

#ifndef BOOST_LOCAL_BIND_IMPORT_HPP
#define BOOST_LOCAL_BIND_IMPORT_HPP

#if defined(_MSC_VER) && _MSC_VER < 1900 // < VS14
#define BOOST_LOCAL_BIND_DISABLE_NAMESPACE_MODIFIERS
#endif

/* 2014-10-9 ned: I lost today figuring out the below. I really hate the C preprocessor now.
 * 
 * Anyway, infinity = 8. It's easy to expand below if needed.
 */

#define BOOST_LOCAL_BIND_GLUE(x, y) x y

#define BOOST_LOCAL_BIND_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define BOOST_LOCAL_BIND_EXPAND_ARGS(args) BOOST_LOCAL_BIND_RETURN_ARG_COUNT args
#define BOOST_LOCAL_BIND_COUNT_ARGS_MAX8(...) BOOST_LOCAL_BIND_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define BOOST_LOCAL_BIND_OVERLOAD_MACRO2(name, count) name##count
#define BOOST_LOCAL_BIND_OVERLOAD_MACRO1(name, count) BOOST_LOCAL_BIND_OVERLOAD_MACRO2(name, count)
#define BOOST_LOCAL_BIND_OVERLOAD_MACRO(name, count) BOOST_LOCAL_BIND_OVERLOAD_MACRO1(name, count)

#define BOOST_LOCAL_BIND_CALL_OVERLOAD(name, ...) BOOST_LOCAL_BIND_GLUE(BOOST_LOCAL_BIND_OVERLOAD_MACRO(name, BOOST_LOCAL_BIND_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))

#define BOOST_LOCAL_BIND_GLUE_(x, y) x y

#define BOOST_LOCAL_BIND_RETURN_ARG_COUNT_(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define BOOST_LOCAL_BIND_EXPAND_ARGS_(args) BOOST_LOCAL_BIND_RETURN_ARG_COUNT_ args
#define BOOST_LOCAL_BIND_COUNT_ARGS_MAX8_(...) BOOST_LOCAL_BIND_EXPAND_ARGS_((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define BOOST_LOCAL_BIND_OVERLOAD_MACRO2_(name, count) name##count
#define BOOST_LOCAL_BIND_OVERLOAD_MACRO1_(name, count) BOOST_LOCAL_BIND_OVERLOAD_MACRO2_(name, count)
#define BOOST_LOCAL_BIND_OVERLOAD_MACRO_(name, count) BOOST_LOCAL_BIND_OVERLOAD_MACRO1_(name, count)

#define BOOST_LOCAL_BIND_CALL_OVERLOAD_(name, ...) BOOST_LOCAL_BIND_GLUE_(BOOST_LOCAL_BIND_OVERLOAD_MACRO_(name, BOOST_LOCAL_BIND_COUNT_ARGS_MAX8_(__VA_ARGS__)), (__VA_ARGS__))

#define BOOST_LOCAL_BIND_STRINGIZE(a) #a
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION8(a, b, c, d, e, f, g, h) a ## _ ## b ## _ ## c ## _ ## d ## _ ## e ## _ ## f ## _ ## g ## _ ## h
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION7(a, b, c, d, e, f, g) a ## _ ## b ## _ ## c ## _ ## d ## _ ## e ## _ ## f ## _ ## g
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION6(a, b, c, d, e, f) a ## _ ## b ## _ ## c ## _ ## d ## _ ## e ## _ ## f
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION5(a, b, c, d, e) a ## _ ## b ## _ ## c ## _ ## d ## _ ## e
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION4(a, b, c, d) a ## _ ## b ## _ ## c ## _ ## d
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION3(a, b, c) a ## _ ## b ## _ ## c
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION2(a, b) a ## _ ## b
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION1(a) a
#define BOOST_LOCAL_BIND_NAMESPACE_VERSION(...) BOOST_LOCAL_BIND_CALL_OVERLOAD(BOOST_LOCAL_BIND_NAMESPACE_VERSION,__VA_ARGS__)

#ifdef BOOST_LOCAL_BIND_DISABLE_NAMESPACE_MODIFIERS
# define BOOST_LOCAL_BIND_NAMESPACE_SELECT_2(name, modifier)
# define BOOST_LOCAL_BIND_NAMESPACE_SELECT2(name, modifier)
#else
# define BOOST_LOCAL_BIND_NAMESPACE_SELECT_2(name, modifier) name
# define BOOST_LOCAL_BIND_NAMESPACE_SELECT2(name, modifier) :: name
#endif
#define BOOST_LOCAL_BIND_NAMESPACE_SELECT_1(name) name
#define BOOST_LOCAL_BIND_NAMESPACE_SELECT1(name) :: name
#define BOOST_LOCAL_BIND_NAMESPACE_SELECT_(...) BOOST_LOCAL_BIND_CALL_OVERLOAD_(BOOST_LOCAL_BIND_NAMESPACE_SELECT_,__VA_ARGS__)
#define BOOST_LOCAL_BIND_NAMESPACE_SELECT(...) BOOST_LOCAL_BIND_CALL_OVERLOAD_(BOOST_LOCAL_BIND_NAMESPACE_SELECT,__VA_ARGS__)
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND8(a, b, c, d, e, f, g, h) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b BOOST_LOCAL_BIND_NAMESPACE_SELECT c BOOST_LOCAL_BIND_NAMESPACE_SELECT d BOOST_LOCAL_BIND_NAMESPACE_SELECT e BOOST_LOCAL_BIND_NAMESPACE_SELECT f BOOST_LOCAL_BIND_NAMESPACE_SELECT g BOOST_LOCAL_BIND_NAMESPACE_SELECT h
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND7(a, b, c, d, e, f, g) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b BOOST_LOCAL_BIND_NAMESPACE_SELECT c BOOST_LOCAL_BIND_NAMESPACE_SELECT d BOOST_LOCAL_BIND_NAMESPACE_SELECT e BOOST_LOCAL_BIND_NAMESPACE_SELECT f BOOST_LOCAL_BIND_NAMESPACE_SELECT g
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND6(a, b, c, d, e, f) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b BOOST_LOCAL_BIND_NAMESPACE_SELECT c BOOST_LOCAL_BIND_NAMESPACE_SELECT d BOOST_LOCAL_BIND_NAMESPACE_SELECT e BOOST_LOCAL_BIND_NAMESPACE_SELECT f
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND5(a, b, c, d, e) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b BOOST_LOCAL_BIND_NAMESPACE_SELECT c BOOST_LOCAL_BIND_NAMESPACE_SELECT d BOOST_LOCAL_BIND_NAMESPACE_SELECT e
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND4(a, b, c, d) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b BOOST_LOCAL_BIND_NAMESPACE_SELECT c BOOST_LOCAL_BIND_NAMESPACE_SELECT d
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND3(a, b, c) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b BOOST_LOCAL_BIND_NAMESPACE_SELECT c
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND2(a, b) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a BOOST_LOCAL_BIND_NAMESPACE_SELECT b
#define BOOST_LOCAL_BIND_NAMESPACE_EXPAND1(a) BOOST_LOCAL_BIND_NAMESPACE_SELECT_ a
// Expands into a::b::c:: ...
#define BOOST_LOCAL_BIND_NAMESPACE(...) BOOST_LOCAL_BIND_CALL_OVERLOAD(BOOST_LOCAL_BIND_NAMESPACE_EXPAND,__VA_ARGS__)

#ifdef BOOST_LOCAL_BIND_DISABLE_NAMESPACE_MODIFIERS
# define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier)
#else
# define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier) modifier namespace name {
#endif
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT1(name) namespace name {
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT(...) BOOST_LOCAL_BIND_CALL_OVERLOAD_(BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT,__VA_ARGS__)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND7(a, b, c, d, e, f, g) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND6(b, c, d, e, f, g)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND6(a, b, c, d, e, f) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND5(b, c, d, e, f)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND5(a, b, c, d, e) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND4(b, c, d, e)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND4(a, b, c, d) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND3(b, c, d)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND3(a, b, c) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND2(b, c)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND2(a, b) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND1(b)
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND1(a) BOOST_LOCAL_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a

// Expands into namespace a { namespace b { namespace c ...
#define BOOST_LOCAL_BIND_NAMESPACE_BEGIN(...) BOOST_LOCAL_BIND_CALL_OVERLOAD(BOOST_LOCAL_BIND_NAMESPACE_BEGIN_EXPAND,__VA_ARGS__)

#ifdef BOOST_LOCAL_BIND_DISABLE_NAMESPACE_MODIFIERS
# define BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT2(name, modifier)
#else
# define BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT2(name, modifier) }
#endif
#define BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT1(name) }
#define BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT(...) BOOST_LOCAL_BIND_CALL_OVERLOAD_(BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT,__VA_ARGS__)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND8(a, b, c, d, e, f, g, h) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND7(b, c, d, e, f, g, h)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND7(a, b, c, d, e, f, g) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND6(b, c, d, e, f, g)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND6(a, b, c, d, e, f) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND5(b, c, d, e, f)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND5(a, b, c, d, e) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND4(b, c, d, e)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND4(a, b, c, d) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND3(b, c, d)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND3(a, b, c) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND2(b, c)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND2(a, b) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND1(b)
#define BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND1(a) BOOST_LOCAL_BIND_NAMESPACE_END_NAMESPACE_SELECT a

// Expands into } } ...
#define BOOST_LOCAL_BIND_NAMESPACE_END(...) BOOST_LOCAL_BIND_CALL_OVERLOAD(BOOST_LOCAL_BIND_NAMESPACE_END_EXPAND,__VA_ARGS__)

// Expands into "local-bind-cpp-library/bind/stl11/impl/library"
#define BOOST_LOCAL_BIND_INCLUDE_STL11(prefix, impl, lib) BOOST_LOCAL_BIND_STRINGIZE(prefix/bind/stl11/impl/lib)
#define BOOST_LOCAL_BIND_INCLUDE_STL1z(prefix, impl, lib) BOOST_LOCAL_BIND_STRINGIZE(prefix/bind/stl1z/impl/lib)

// Expands into
#define BOOST_LOCAL_BIND_DECLARE(decl) static const char *boost_bindlib_out[]={ #decl };

#endif
