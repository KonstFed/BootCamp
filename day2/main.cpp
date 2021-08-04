#include <iostream>
#include <chrono>
using namespace std;
class Timer
        {
        private:
            // Псевдонимы типов используются для удобного доступа к вложенным типам
            using clock_t = std::chrono::high_resolution_clock;
            using second_t = std::chrono::duration<double, std::ratio<1> >;

            std::chrono::time_point<clock_t> m_beg;

        public:
            Timer() : m_beg(clock_t::now())
            {
            }

            void reset()
            {
                m_beg = clock_t::now();
            }

            double elapsed() const
            {
                return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
            }
        };
int fib(int n)
{
    if (n == 1 or n == 2)
    {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin>>n;
    Timer t;
    if (n == 1 or n == 2)
    {
        cout<<1;
    }
    int a,b,c;
    a = 1;
    b = 1;
    for (int i = 2; i<n; i++ )
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout<<c<<" Iterative Time "<<t.elapsed()<<"\n";
    Timer s;
    cout<<"Recursion "<<fib(n)<<" Time "<<s.elapsed();
    return 0;
    // Input: 1000; iterative 4.77026; recursive
}
