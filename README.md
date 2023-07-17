# ft_containers

# C++ Vector Container

This repository contains an implementation of the `vector` container in C++, along with necessary files and features such as `std::iterator_traits`, `std::reverse_iterator`, `std::enable_if`, `std::is_integral`, and `std::equal` or `std::lexicographical_compare`. The implementation follows the C++98 standard.

## Usage

To use the `vector` container, follow the steps below:

1. Clone this repository to your local machine:

   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```

2. Compile the code and generate the executable using the provided Makefile:

   ```bash
   make
   ```

3. Run the executable:

   ```bash
   ./ft_containers
   ```

   This will execute the sample code using the `vector` container and demonstrate the implemented features.

4. Explore and modify the code as needed. You can refer to the `<container>.hpp` files for the implementation details of the `vector` container and other required features.

## Contents

The repository includes the following files:

- `vector.hpp`: Implementation of the `vector` container.
- `<container>.hpp`: Additional files implementing `std::iterator_traits`, `std::reverse_iterator`, `std::enable_if`, `std::is_integral`, and `std::equal` or `std::lexicographical_compare` features.
- `Makefile`: Used for compiling the code and generating the executable.
- `main.cpp`: Sample code demonstrating the usage of the `vector` container and other implemented features.

## Notes

- The implementation of the `vector` container in this repository does not include the specialization for `vector<bool>`.

- The features like `std::iterator_traits`, `std::reverse_iterator`, `std::enable_if`, `std::is_integral`, and `std::equal` or `std::lexicographical_compare` are implemented to demonstrate SFINAE (Substitution Failure Is Not An Error) and can be studied as examples.

- The code in this repository is designed to work with C++98 standard and may not include features from later C++ standards.

## Doc

Containers template --> Norme ISO 1998 c++
			- Vector (page 484 of the book, page 510 of the pdf)


What is an allocator? https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed

Writing my custom iterator - https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp


Exception safety - https://www.stroustrup.com/except.pdf
