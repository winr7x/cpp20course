
#include <coroutine>
#include <iostream>

struct CoroType {
  struct promise_type {
    CoroType get_return_object() { return CoroType(this); } // UNCOMMENT_TO_SEE comment and you get error: no member named 'get_return_object' in 'CoroType::promise_type'
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() noexcept
    {
      std::rethrow_exception(std::current_exception());
    }
    void return_void() {};
  };
  CoroType(promise_type* p)
      : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}

  ~CoroType() {
    std::cout << "Handle destroyed..." << std::endl;
    m_handle.destroy();
  }

  std::coroutine_handle<promise_type> m_handle;
};

CoroType do_work() { // with some random return type you will get error: unable to find the promise type for this coroutine
  std::cout << "Doing first thing..." << std::endl;
  co_await std::suspend_always{};
  std::cout << "Doing second thing..." << std::endl;
  co_await std::suspend_always{};
  std::cout << "Doing third thing..." << std::endl;
}

int main() {
  auto task = do_work();
  
  // Resume
  task.m_handle();

  // Resume for second time
  task.m_handle.resume(); // alternative for task.m_handle()

  // Resume for third time
  task.m_handle.resume(); // alternative for task.m_handle()


  std::cout << std::boolalpha;
  std::cout << "coro done : " << task.m_handle.done() << std::endl; // NEW_FOR_ME Check coroutine is done 

  // Resuming after coroutine has run to completion. BAD!
  // task.m_handle.resume(); // UNCOMMENT_TO_SEE When uncomment you will not see "Done!"

  std::cout << "Done!" << std::endl; 

  return 0;
}