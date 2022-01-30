#include <coroutine>
#include <memory>
#include <iostream>
#include <random>

struct transaction{

  enum myenum{credit = 0, debit = 1};
  
  long post_date;
  std::string src_accountid;
  std::string dest_accountid;
  myenum trantype;
  double ammount;

  transaction(): post_date(0), src_accountid(""),
		 dest_accountid(""), trantype(static_cast<myenum>(0)),
		 ammount(0){}
  
  transaction(const long pst_date, const std::string* src_id,
	      const std::string* dest_id, const int transactionType,
	      const double amt):
    post_date(pst_date),
    src_accountid(*src_id),
    dest_accountid(*dest_id),
    trantype(myenum(static_cast<myenum>(transactionType))),
    ammount(amt){}
};

struct Generator {

  struct promise_type;
  using handle_type = std::coroutine_handle<promise_type>;
  Generator(handle_type h): coro(h) {}
  handle_type coro;
  ~Generator() {
    if ( coro ) coro.destroy();
  }

  Generator(const Generator&) = delete;
  Generator& operator = (const Generator&) = delete;
  Generator(Generator&& oth): coro(oth.coro) {
    oth.coro = nullptr;
  }

  Generator& operator = (Generator&& oth) {
    coro = oth.coro;
    oth.coro = nullptr;
    return *this;
  }

  struct transaction getNextValue() {
    coro.resume();
    return coro.promise().current_value;
  }
  struct promise_type {
    promise_type() {}
    ~promise_type() {}
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }

    auto get_return_object() { return Generator{handle_type::from_promise(*this)}; }

    std::suspend_always yield_value(struct transaction value) {
      current_value = value;
      return {};
    }
    
    void return_void() {}
    void unhandled_exception() {
      std::exit(1);
    }
    struct transaction current_value;
  };
};

Generator getNext(int start = 10, int step = 10) {
  struct transaction tran;
  while(true){
    tran.post_date = rand() % 1000;
    tran.src_accountid = std::to_string(rand() % 10000000);
    tran.dest_accountid = std::to_string(rand() % 10000000);
    tran.trantype = static_cast<transaction::myenum>(rand() % 2);
    tran.ammount = rand() % 10000000 + 1;
    
    co_yield std::move(tran);
  }
}

int main() {
  auto gen = getNext();
  for (int i = 0; i <= 2; ++i) {
    auto val = gen.getNextValue();
    std::cout << "Transaction " << i
	      << "\n\tTransaction post date: " << val.post_date
	      << "\n\tTransaction src id " << val.src_accountid
	      << "\n\tTransaction dest id " << val.dest_accountid
	      << "\n\tTransaction type " << val.trantype
	      << "\n\tTransaction ammount: " << val.ammount << "\n\n";
  }
}
