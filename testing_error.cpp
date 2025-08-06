#include <iostream>
#include <sstream>
#include <fstream>

void print_state(const std::ios& stream)
{
    std::cout << " good()=" << stream.good();
    std::cout << " eof()=" << stream.eof();
    std::cout << " fail()=" << stream.fail();
    std::cout << " bad()=" << stream.bad();
    std::cout << " rdstate()=" << stream.rdstate(); // returns the internal state of the stream
}

int main()
{
    std::stringstream stream;

    // Clear all flags and set goodbit
    stream.clear(std::ios::goodbit);
    std::cout << "goodbit:";
    print_state(stream);
    std::cout << '\n';

    // Clear all flags and set eofbit
    stream.clear(std::ios::eofbit);
    std::cout << " eofbit:";
    print_state(stream);
    std::cout << '\n';

    // Clear all flags and set failbit
    stream.clear(std::ios::failbit);
    std::cout << "failbit:";
    print_state(stream);
    std::cout << '\n';

    // Clear all flags and set badbit
    stream.clear(std::ios::badbit);
    std::cout << " badbit:";
    print_state(stream);
    std::cout << '\n';

    // Demonstrating file stream error states
    std::fstream st; // Creating object of fstream class

    // Open file for writing
    st.open("harendra.txt", std::ios::out);
    if (st.is_open())
    {
        st << 35;
        st.close();
        std::cout << '\n';
        print_state(st); // After close, the stream is no longer good
    }
    else
    {
        std::cerr << "Error opening file for writing\n";
    }

    // Open file for reading
    st.open("harendra.txt", std::ios::in);
    if (st.is_open())
    {
        int x;
        st >> x; // First read (should succeed)
        std::cout << "\nRead value: " << x << '\n';
        print_state(st); // Check state after successful read
        std::cout << '\n';

        st >> x; // Second read (likely fails if file has only one int)
        std::cout << "Attempt second read\n";
        print_state(st); // Check state after failed read (likely eofbit or failbit set)
        std::cout << '\n';

        st.close();
    }
    else
    {
        std::cerr << "Error opening file for reading\n";
    }

    return 0;
}
