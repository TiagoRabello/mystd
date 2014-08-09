#ifndef _MYSTD_CHRONO_STOPWATCH_H
#define _MYSTD_CHRONO_STOPWATCH_H

#include <chrono>

namespace mystd
{
  namespace chrono
  {
    ///////////////////////////////////////////////////////////////////////////
    /// Defines a basic lightweight template usefull for measuring
    /// time/performance.
    /// All timing is done using Clock template parameter.
    /// (Clock must model TrivialClock concept)
    ///////////////////////////////////////////////////////////////////////////
    template<typename Clock>
    struct basic_stopwatch
    {
      using clock = Clock; ///< Clock type used for all the measuring.

      using duration = typename clock::duration; ///< Duration type as defined
                                                 ///< by the clock.

      using rep = typename clock::rep; ///< Arithmetic type representing the
                                       ///< number of ticks in the stopwatch's
                                       ///< duration.

      using period = typename clock::period; ///< Type representing the tick
                                             ///< period of the stopwatch,
                                             ///< in seconds.

      /////////////////////////////////////////////////////////////////////////
      /// Start/resume measuring elapsed time. If called after
      /// basic_stopwatch::stop, measurement will be resumed.
      /////////////////////////////////////////////////////////////////////////
      void start()
      {
        running = true;
        curr_start = clock::now();
      }

      /////////////////////////////////////////////////////////////////////////
      /// Stop/pause measuring elapsed time. If basic_stopwatch::start is
      /// called afterwards, measurement will be resumed.
      /////////////////////////////////////////////////////////////////////////
      void stop()
      {
        auto end_time = clock::now();
        running = false;
        accumulated_time += end_time - curr_start;
      }

      /////////////////////////////////////////////////////////////////////////
      /// Get current accumulated elapsed time. If called while stopwatch is
      /// running, calculate elapsed time until this call. Else, get elapsed
      /// time until last call to basic_stopwatch::stop.
      /////////////////////////////////////////////////////////////////////////
      duration elapsed()
      {
        if (running)
        {
          auto end_time = clock::now();
          return end_time - curr_start;
        }
        return accumulated_time;
      }

      /////////////////////////////////////////////////////////////////////////
      /// Reset accumulated elapsed time and restart the measuring if called
      /// while stopwatch is running.
      /////////////////////////////////////////////////////////////////////////
      void reset()
      {
        accumulated_time = duration{ 0 };
        if (running)
        {
          curr_start = clock::now();
        }
      }

    private:
      using time_point = typename clock::time_point;

      bool running{ false };
      time_point curr_start;
      duration accumulated_time{ 0 };
    };

    ///////////////////////////////////////////////////////////////////////////
    /// stopwatch aliases for every clock on std.
    ///////////////////////////////////////////////////////////////////////////
    using high_resolution_stopwatch = basic_stopwatch<std::chrono::high_resolution_clock>;
    using steady_stopwatch = basic_stopwatch<std::chrono::steady_clock>;
    using system_stopwatch = basic_stopwatch<std::chrono::system_clock>;

  } // End of chrono namespace.
} // End of mystd namespace.

#endif
