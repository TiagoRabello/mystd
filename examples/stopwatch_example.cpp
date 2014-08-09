#include <mystd/chrono.h> // For mystd::chrono::high_resolution_stopwatch

#include <iostream> // For std::cout
#include <thread> // For std::this_thread::sleep_for

int main()
{
  mystd::chrono::high_resolution_stopwatch sw;

  using namespace mystd::chrono::output; // For printing durations.

  // Simple start and stop example.
  std::cout << "Sleeping..." << std::endl;

  sw.start();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  sw.stop();

  std::cout << "This thread slept for a total of "
            << std::chrono::duration_cast<std::chrono::seconds>(sw.elapsed())
            << "." << std::endl;

  // Any time wasted here won't affect measurement.
  std::cout << "Sleeping without measuring..." << std::endl;

  std::this_thread::sleep_for(std::chrono::seconds(2));

  std::cout << "This thread slept for a total of "
            << std::chrono::duration_cast<std::chrono::seconds>(sw.elapsed())
            << "." << std::endl;

  // Now resume measurement.
  std::cout << "Sleeping with measuring..." << std::endl;

  sw.start();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  sw.stop();

  std::cout << "This thread slept for a total of "
            << std::chrono::duration_cast<std::chrono::seconds>(sw.elapsed())
            << "." << std::endl;

  // We can also reset the stopwatch and start all over again.
  std::cout << "Sleeping after reset..." << std::endl;

  sw.reset();
  sw.start();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  sw.stop();

  std::cout << "This thread slept for a total of "
            << std::chrono::duration_cast<std::chrono::seconds>(sw.elapsed())
            << "." << std::endl;

  // What about real-time feedback ?
  sw.reset();
  sw.start();
  for (int i = 0; i < 20; ++i)
  {
    std::cout << "Elapsed time inside loop: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(sw.elapsed())
              << "." << std::endl;
  }
  sw.stop();

  std::cout << "Total loop time: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(sw.elapsed())
            << "." << std::endl;

  // Sometimes we may want to reset without stopping the stopwatch though.
  sw.reset();
  sw.start();
  for (int i = 0; i < 20; ++i)
  {
    if (i == 10) { sw.reset(); }
    std::cout << "Elapsed time inside loop with reset: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(sw.elapsed())
              << "." << std::endl;
  }
  sw.stop();

  return 0;
}