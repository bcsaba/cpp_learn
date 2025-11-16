#include <format>
#include <iostream>
#include <ios>
#include <iterator>
#include <vector>

void assignments_and_simple_io() {
    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    constexpr int x {10};
    std::cout << "&x:\t" << &x << std::endl;
    const int *ptr = &x;
    std::cout << "ptr:\t" << ptr << std::endl;
    std::cout << "*ptr:\t" << *ptr << std::endl;

    // ptr = nullptr;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    char a2[8] = {'a', 'b', 'c'};
    char a3[8] {"abs"};
    char a4[8] = "abs";
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
    std::cout << a4 << std::endl;

}

constexpr double square(double x) { return x*x; }

// double square(double x)    // square a double precision floating-point number
// {
//     return x*x;
// }

void print_square(double x){
     std::cout << "the square of " << x << " is " << square(x) << "\n";
}

void cont_constexpr_examples() {
    const int dmv = 17;                         // dmv is a named constant
    int var = 17;                               // var is not a constant
    constexpr double max1 = 1.4 * square(dmv);    // OK if square(17) is a constant expression
    // constexpr double max2 = 1.4 * square(var);    // error: var is not a constant expression
    // double max1 = 1.4 * square(dmv);    // OK if square(17) is a constant expression
    // double max2 = 1.4 * square(var);    // error: var is not a constant expression
    const double max3 = 1.4 * square(var);        // OK, may be evaluated at run time
    double sum(const std::vector<double>&);          // sum will not modify its argument (§2.2.5)
    std::vector<double> v {1.2, 3.4, 4.5};           // v is not a constant
    // double s1 = sum(v);                   // OK: evaluated at run time
    // constexpr double s2 = sum(v);
}

bool accept() {
    std::cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    std::cin >> answer;

    if (answer == 'y') return true;
    return false;
}

bool accept2() {
    std::cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    std::cin >> answer;

    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "I'll take that for a no.\n";
            return false;
    }
}

bool accept3() {
    int tries = 1;
    while (tries < 4) {

        std::cout << "Do you want to proceed (y or n)?\n";
        char answer = 0;
        std::cin >> answer;

        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cout << "Sorry, I don't understand that.\n";
                tries++;
        }
    }

    std::cout << "I'll take that for a no.\n";
    return false;
}

void copy_fct() {
    std::cout << "copy_fct method " << std::endl;
    int v1[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];

    for (auto i = 0; i < 10; i++) {
        v2[i] = v1[i];
    }

    std::cout << "v2: " << v2[0] << " " << v2[1] << " " << v2[2] << " " << v2[3] << " " << v2[4] << " " << v2[5] << " " << v2[6] << " " << v2[7] << " " << v2[8] << " " << v2[9] << "\n";

    for (const auto x : {10, 21, 32, 43, 54, 65}) {
        std::cout << x << " ";
    }

    std::cout << std::endl << std::endl;
}

void increment() {
    std::cout << "Increment method " << std::endl;
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto& x: v) {
        ++x;
        std::cout << x << " ";
    }
    std::cout << std::endl << std::endl;
}

void count_x(char* p, char x) {
    std::cout << "count_x method " << std::endl;

    if (p == nullptr) return;

    int count = 0;
    for (; *p != 0; ++p) {
        if (*p == x)
            count++;
    }

    std::cout << "count of " << x << ": " << count << std::endl;

    std::cout << std::endl << std::endl;
}

struct Entry {
  std::string name;
  int number;
};

std::ostream& operator<<(std::ostream &os, const Entry &e) {
  std::cout << "The given entry is:" << std::endl;
  return os << "{\"" << e.name << "\", " << e.number << "}" << std::endl;
}

std::istream& operator>>(std::istream &is, Entry &e) {
  char c, c2;

  std::cout << "Add a new entry in the form { \"<name>\", <number> }" << std::endl;
  if(is >> c && c == '{' && is >> c2 && c2 == '"') {
    std::string name;
    while(is.get(c) && c != '"') {
      name += c;
    }

    if(is >> c && c == ',') {
      int number = 0;
      if(is >> number >> c && c == '}') {
	e = {name, number};
	return is;
      }
    }
  }

  is.setstate(std::ios_base::failbit);
  return is;
}

void cin_cout_override_example()
{
    Entry phone_entry;

    std::cin >> phone_entry;
    std::cout << phone_entry;
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    ;
    // assignments_and_simple_io();
    // cont_constexpr_examples();

    // Conditionals
    // std::cout << "Accept result: " << accept() << std::endl << std::endl;
    // std::cout << "Accept2 result: " << accept2() << std::endl << std::endl;
    // std::cout << "Accept3 result: " << accept3() << std::endl << std::endl;

    // For loops
    copy_fct();

    increment();

    count_x("Hello world", 'l');

    cin_cout_override_example();
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
