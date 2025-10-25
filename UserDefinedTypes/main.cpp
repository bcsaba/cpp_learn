#include <iostream>
#include "vector.h"
#include "complex.h"
#include <cmath>

#include "container.h"
#include "list_container.h"
#include "vector_container.h"

struct VectorStuct {
    int size;
    double* elements;

    ~VectorStuct() {
        delete[] elements;
    }
};

void vector_init(VectorStuct& v, int size) {
    v.elements = new double[size];
    v.size = size;
}

void read_from_consol_and_sum(int size, double* elements) {
    VectorStuct v{};
    vector_init(v, size);

    for (int i = 0; i != size; ++i) {
        std::cin >> v.elements[i];
    }

    double sum = 0;
    for (int i = 0; i != size; ++i) {
        sum += v.elements[i];
    }

    std::cout << "Sum: " << sum << std::endl;


    std::cout << std::endl << std::endl;
}

void vector_access(const VectorStuct v, const VectorStuct& rv, const VectorStuct* pv) {
    int i1 = v.size;    // access through name
    int i2 = rv.size;   //access through reference
    int i3 = pv->size;  //access through pointer
}

double sqrt_sum(mycode::Vector& v) {
    double sum = 0;
    for (int i = 0; i != v.size(); ++i) {
        sum += sqrt(v[i]);
    }
    return sum;
}

void use(mycode::Container& c) {
  std::cout << "---------- Use with type: " << typeid(c).name() << " ----------" << std::endl;
    const unsigned long sz = c.size();

    for (int i = 0; i != sz; ++i) {
        std::cout << c[i] << std::endl;
    }
}

void useVc() {
    mycode::Vector_container vc = mycode::Vector_container{11, 12, 13};
    use(vc);
}

void useLc() {
    mycode::List_Container lc = mycode::List_Container {14, 15, 16};
    use(lc);
}

int main() {
    // VectorStuct v;
    // read_from_consol_and_sum(10, v.elements);

    auto v = mycode::Vector(5);

    std::cout << sqrt_sum(v) << " :: " << v.size() << std::endl;

    auto v2 = mycode::Vector({3, 4, 5, 6, 7, 8});

    std::cout << sqrt_sum(v2) << " :: " << v2.size() << std::endl;

    v2.push_back(9);
    v2.push_back(10);

    std::cout << sqrt_sum(v2) << " :: " << v2.size() << std::endl;

    useVc();
    useLc();

    return mycode::main();
}
