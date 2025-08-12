#ifndef __EXCEPT__HPP
#define __EXCEPT__HPP

#include "__macros__.hpp"
#include "_phc.hpp"

#define STRINGIFY(x) #x
#define TOSTRING(x)  STRINGIFY(x)

#define ABORT(msg)                                                         \
  do                                                                       \
  {                                                                        \
    throw std::logic_error(RED_COLOR "ABORT: " + string(msg) + RESET_COLOR \
            + " in " __FILE__ ":" TOSTRING(__LINE__));                     \
  } while (0)

#define ASSERT(condition)                                                  \
  do                                                                       \
  {                                                                        \
    if (!(condition))                                                      \
    {                                                                      \
      throw std::logic_error(RED_COLOR "ASSERTION FAILED" RESET_COLOR ": " \
                                       "Condition: " #condition " — "    \
              + string(" at " __FILE__ ":" TOSTRING(__LINE__)));           \
    }                                                                      \
  } while (0)

#define ASSERT_NOT_NUL(ptr) ASSERT(ptr != NUL)

#endif
