#include <iostream>
#include <vector>

double* get_from_jack(int* count)
{
    *count = 5;
    double* data = new double[*count];

    for(int i=0;i<*count;i++){
        data[i] = i * 2.5;
    }

    return data;
}

std::vector<double>* get_from_jill()
{
    std::vector<double>* data = new std::vector<double>;

    for(int i=0;i<5;i++){
        data->push_back(i * 4.5);
    }
    return data;
}

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    double* high = first;
    for(double *p=first; p!=last; ++p){
        if(*high < *p){
            high = p;
        }
    }
    return high;
}

void fct() {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    std::vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data, jack_data + jack_count);
    double* jill_high = high(&(*jill_data)[0], &(*jill_data)[0] + jill_data->size());

    std::cout << "Jill's max: " << *jill_high << '\n';
    std::cout << "Jack's max: " << *jack_high << '\n';

    delete[] jack_data;
    delete jill_data;
}



int main()
{
    fct();
    return 0;
}