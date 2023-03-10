
#include <coroutine>
#include <iostream>

struct CoroType {
  struct promise_type {
    int m_value;
    CoroType get_return_object() { return CoroType(this); } // UNCOMMENT_FOR_ERROR comment and you get error: no member named 'get_return_object' in 'CoroType::promise_type'
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() noexcept
    {
      std::rethrow_exception(std::current_exception());
    }
    std::suspend_always yield_value(int val) { // NEW_FOR_ME This is called when co_yield is called
      m_value = val;
      return {};
    }
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
  std::cout << "Starting the coroutine..." << std::endl;
  co_yield 1;
  co_yield 2;
  co_yield 3;
  // co_return; // co_return is called implicitly
}

int main() {
  auto task = do_work();

  std::cout << std::endl;

  task.m_handle(); // This resumes the coroutine. When next suspension point is hit it pauses
  std::cout << "Value: " << task.m_handle.promise().m_value << std::endl; // NEW_FOR_ME Way to get yielded value
  
  std::cout << std::endl;

  task.m_handle(); // This resumes the coroutine. When next suspension point is hit it pauses
  std::cout << "Value: " << task.m_handle.promise().m_value << std::endl;

  std::cout << std::endl;

  task.m_handle(); // This resumes the coroutine. When next suspension point is hit it pauses
  std::cout << "Value: " << task.m_handle.promise().m_value << std::endl;

  std::cout << std::boolalpha;
  std::cout << "coro done : " << task.m_handle.done() << std::endl;

  std::cout << "--------" << std::endl;
  task.m_handle.resume();

  std::cout << "coro done : " << task.m_handle.done() << std::endl;

  std::cout << "Done!" << std::endl; 

  return 0;
}