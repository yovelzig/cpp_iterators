// #include <iostream>
// #include <vector>
// #include <cmath>

// namespace ariel
// {

//     class MagicalContainer
//     {
//     private:
//         std::vector<int> elements;
//         std::vector<bool> isPrimeFlags;
//         std::vector<int *> nextPrimePtrs;

//         bool isPrime(int number) const
//         {
//             if (number < 2)
//                 return false;

//             for (int i = 2; i <= std::sqrt(number); ++i)
//             {
//                 if (number % i == 0)
//                     return false;
//             }

//             return true;
//         }

//     public:
//         void addElement(int element)
//         {
//             elements.push_back(element);
//             isPrimeFlags.push_back(isPrime(element));

//             if (isPrimeFlags.back())
//             {
//                 if (!nextPrimePtrs.empty())
//                 {
//                     nextPrimePtrs.back() = &(elements.back());
//                 }
//                 nextPrimePtrs.push_back(&(elements.back()));
//             }
//         }
//         void removeElement(int element)
// {
//     for (auto it = elements.begin(); it != elements.end(); ++it)
//     {
//         if (*it == element)
//         {
//             elements.erase(it);
//             isPrimeFlags.erase(isPrimeFlags.begin() + std::distance(elements.begin(), it));
//             break;
//         }
//     }

//     nextPrimePtrs.clear();
//     for (size_t i = 0; i < elements.size(); ++i)
//     {
//         if (isPrimeFlags[i])
//         {
//             if (!nextPrimePtrs.empty())
//             {
//                 nextPrimePtrs.back() = &(elements[i]);
//             }
//             nextPrimePtrs.push_back(&(elements[i]));
//         }
//     }
// }

//         // void removeElement(int element)
//         // {
//         //     for (auto it = elements.begin(); it != elements.end(); ++it)
//         //     {
//         //         if (*it == element)
//         //         {
//         //             elements.erase(it);
//         //             isPrimeFlags.erase(isPrimeFlags.begin() + std::distance(elements.begin(), it));
//         //             break;
//         //         }
//         //     }
//         //     nextPrimePtrs.clear();
//         //     for (size_t i = 0; i < elements.size(); ++i)
//         //     {
//         //         if (isPrimeFlags[i])
//         //         {
//         //             if (!nextPrimePtrs.empty())
//         //             {
//         //                 nextPrimePtrs.back() = &(elements[i]);
//         //             }
//         //             nextPrimePtrs.push_back(&(elements[i]));
//         //         }
//         //     }
//         // }

//         int size() const
//         {
//             return elements.size();
//         }

//         class AscendingIterator
//         {
//         private:
//             MagicalContainer &container;
//             std::vector<int>::iterator current;

//         public:
//             AscendingIterator(MagicalContainer &cont) : container(cont), current(container.elements.begin()) {}
//             AscendingIterator(const AscendingIterator &other) : container(other.container), current(other.current) {}

//             AscendingIterator &operator=(const AscendingIterator &other)
//             {
//                 if (this != &other)
//                 {
//                     container = other.container;
//                     current = other.current;
//                 }
//                 return *this;
//             }

//             bool operator==(const AscendingIterator &other) const
//             {
//                 return current == other.current;
//             }

//             bool operator!=(const AscendingIterator &other) const
//             {
//                 return !(*this == other);
//             }

//             int operator*() const
//             {
//                 return *current;
//             }

//             AscendingIterator &operator++()
//             {
//                 ++current;
//                 return *this;
//             }
//             AscendingIterator begin()
//             {
//                 return *this;
//             }

//             AscendingIterator end()
//             {
//                 AscendingIterator iter(container);
//                 iter.current = container.elements.end();
//                 return iter;
//             }
//             // AscendingIterator begin() {
//             //     current = container.elements.begin();
//             //     return *this;
//             // }

//             // AscendingIterator end() {
//             //     current = container.elements.end();
//             //     return *this;
//             // }
//         };

//         class SideCrossIterator
//         {
//         private:
//             MagicalContainer &container;
//             std::vector<int>::iterator forward;
//             std::vector<int>::reverse_iterator reverse;

//         public:
//             SideCrossIterator(MagicalContainer &cont) : container(cont), forward(container.elements.begin()), reverse(container.elements.rbegin()) {}

//             SideCrossIterator(const SideCrossIterator &other) : container(other.container), forward(other.forward), reverse(other.reverse) {}

//             SideCrossIterator &operator=(const SideCrossIterator &other)
//             {
//                 if (this != &other)
//                 {
//                     container = other.container;
//                     forward = other.forward;
//                     reverse = other.reverse;
//                 }
//                 return *this;
//             }

//             bool operator==(const SideCrossIterator &other) const
//             {
//                 return forward == other.forward && reverse == other.reverse;
//             }

//             bool operator!=(const SideCrossIterator &other) const
//             {
//                 return !(*this == other);
//             }

//             int operator*() const
//             {
//                 if (forward < container.elements.end())
//                     return *forward;
//                 return *reverse;
//             }

//             SideCrossIterator &operator++()
//             {
//                 ++forward;
//                 ++reverse;
//                 return *this;
//             }
//             SideCrossIterator begin()
//             {
//                 return *this;
//             }

//             SideCrossIterator end()
//             {
//                 SideCrossIterator iter(container);
//                 iter.forward = container.elements.end();
//                 iter.reverse = container.elements.rend();
//                 return iter;
//             }

//             // SideCrossIterator begin() {
//             //     forward = container.elements.begin();
//             //     reverse = container.elements.rbegin();
//             //     return *this;
//             // }

//             // SideCrossIterator end() {
//             //     forward = container.elements.end();
//             //     reverse = container.elements.rend();
//             //     return *this;
//             // }
//         };

//         class PrimeIterator
//         {
//         private:
//             MagicalContainer &container;
//             std::vector<int *>::iterator current;

//         public:
//             PrimeIterator(MagicalContainer &cont) : container(cont), current(container.nextPrimePtrs.begin()) {}

//             PrimeIterator(const PrimeIterator &other) : container(other.container), current(other.current) {}

//             PrimeIterator &operator=(const PrimeIterator &other)
//             {
//                 if (this != &other)
//                 {
//                     container = other.container;
//                     current = other.current;
//                 }
//                 return *this;
//             }

//             bool operator==(const PrimeIterator &other) const
//             {
//                 return current == other.current;
//             }

//             bool operator!=(const PrimeIterator &other) const
//             {
//                 return !(*this == other);
//             }

//             int operator*() const
//             {
//                 return **current;
//             }

//             PrimeIterator &operator++()
//             {
//                 ++current;
//                 return *this;
//             }
//             PrimeIterator begin()
//             {
//                 return *this;
//             }

//             PrimeIterator end()
//             {
//                 PrimeIterator iter(container);
//                 iter.current = container.nextPrimePtrs.end();
//                 return iter;
//             }
//             // PrimeIterator begin()
//             // {
//             //     current = container.nextPrimePtrs.begin();
//             //     return *this;
//             // }

//             // PrimeIterator end()
//             // {
//             //     current = container.nextPrimePtrs.end();
//             //     return *this;
//             // }
//         };
//     };
// }

// // int main() {
// //     ariel::MagicalContainer container;
// //     container.addElement(17);
// //     container.addElement(2);
// //     container.addElement(25);
// //     container.addElement(9);
// //     container.addElement(3);

// //     std::cout << "Size of container: " << container.size() << std::endl;

// //     std::cout << "Elements in ascending order:\n";
// //     ariel::MagicalContainer::AscendingIterator ascIter(container);
// //     for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
// //         std::cout << *it << ' ';
// //     }
// //     std::cout << std::endl;

// //     std::cout << "Elements in cross order:\n";
// //     ariel::MagicalContainer::SideCrossIterator crossIter(container);
// //     for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
// //         std::cout << *it << ' ';
// //     }
// //     std::cout << std::endl;

// //     std::cout << "Prime numbers:\n";
// //     ariel::MagicalContainer::PrimeIterator primeIter(container);
// //     for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
// //         std::cout << *it << ' ';
// //     }
// //     std::cout << std::endl;

// //     container.removeElement(9);
// //     std::cout << "Size of container after removing an element: " << container.size() << std::endl;

// //     return 0;
// // }
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;
        std::vector<bool> isPrimeFlags;
        std::vector<int *> nextPrimePtrs;

        bool isPrime(int number) const
        {
            if (number < 2)
                return false;
            for (int i = 2; i <= std::sqrt(number); ++i)
            {
                if (number % i == 0)
                    return false;
            }
            return true;
        }

    public:
        void addElement(int element)
        {
            if (std::find(elements.begin(), elements.end(), element) != elements.end())
            {
                // Element already exists, do nothing
                return;
            }
            elements.push_back(element);
            isPrimeFlags.push_back(isPrime(element));

            if (isPrimeFlags.back())
            {
                if (!nextPrimePtrs.empty())
                {
                    nextPrimePtrs.back() = &(elements.back());
                }
                nextPrimePtrs.push_back(&(elements.back()));
            }

            std::sort(elements.begin(), elements.end()); // Sort the elements vector
        }

        void removeElement(int element)
        {
            auto it = std::find(elements.begin(), elements.end(), element);
            if (it == elements.end())
            {
                throw std::runtime_error("Element not found");
            }
            if (it != elements.end())
            {
                elements.erase(it);
                isPrimeFlags.erase(isPrimeFlags.begin() + std::distance(elements.begin(), it));
            }

            nextPrimePtrs.clear();
            for (size_t i = 0; i < elements.size(); ++i)
            {
                if (isPrimeFlags[i])
                {
                    if (!nextPrimePtrs.empty())
                    {
                        nextPrimePtrs.back() = &(elements[i]);
                    }
                    nextPrimePtrs.push_back(&(elements[i]));
                }
            }
        }

        int size() const
        {
            return elements.size();
        }

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            std::vector<int>::iterator current;

        public:
            AscendingIterator(MagicalContainer &cont) : container(cont), current(container.elements.begin()) {}

            bool operator==(const AscendingIterator &other) const
            {
                return current == other.current;
            }

            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }
            bool operator>(const AscendingIterator &other) const
            {
                return *current > *other.current;
            }

            bool operator<(const AscendingIterator &other) const
            {
                return *current < *other.current;
            }

            int operator*() const
            {
                return *current;
            }

            AscendingIterator &operator++()
            {
                ++current;
                return *this;
            }

            AscendingIterator begin()
            {
                current = container.elements.begin();
                return *this;
            }

            AscendingIterator end()
            {
                current = container.elements.end();
                return *this;
            }
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container;
            std::vector<int>::iterator forward;
            std::vector<int>::reverse_iterator reverse;
            bool isForward;
            bool isEndReached;
            int iterationCount;

        public:
            SideCrossIterator(MagicalContainer &cont)
                : container(cont),
                  forward(container.elements.begin()),
                  reverse(container.elements.rbegin()),
                  isForward(true),
                  isEndReached(false),
                  iterationCount(0) {}

            bool operator==(const SideCrossIterator &other) const
            {
                return forward == other.forward && reverse == other.reverse;
            }

            bool operator!=(const SideCrossIterator &other) const
            {
                return !(*this == other);
            }
            bool operator>(const SideCrossIterator &other) const
            {
                return *forward > *other.forward || *reverse > *other.reverse;
            }

            bool operator<(const SideCrossIterator &other) const
            {
                return *forward < *other.forward || *reverse < *other.reverse;
            }

            int operator*() const
            {
                if (isForward && forward != container.elements.end())
                    return *forward;
                if (!isForward && reverse != container.elements.rend())
                    return *reverse;
                return -1; // Return a default value to handle invalid cases
            }
            SideCrossIterator &operator++()
            {
                if (isEndReached)
                {
                    return *this;
                }

                if (isForward)
                {
                    if (forward != container.elements.end())
                    {
                        ++forward;
                    }
                }
                else
                {
                    if (reverse != container.elements.rend())
                    {
                        ++reverse;
                    }
                }

                isForward = !isForward;

                // Check if the iteration count has reached the vector's size
                ++iterationCount;
                if (iterationCount == container.size())
                {
                    isEndReached = true;
                    forward = container.elements.end();
                    reverse = container.elements.rend();
                }

                return *this;
            }
            SideCrossIterator begin()
            {
                forward = container.elements.begin();
                reverse = container.elements.rbegin();
                isForward = true;
                isEndReached = false;
                // previousElement = -1;
                return *this;
            }

            SideCrossIterator end()
            {
                forward = container.elements.end();
                reverse = container.elements.rend();
                return *this;
            }

            bool isEnd() const
            {
                return isEndReached;
            }
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            std::vector<int *>::iterator current;

        public:
            PrimeIterator(MagicalContainer &cont) : container(cont), current(container.nextPrimePtrs.begin()) {}

            bool operator==(const PrimeIterator &other) const
            {
                return current == other.current;
            }

            bool operator!=(const PrimeIterator &other) const
            {
                return !(*this == other);
            }
            bool operator>(const PrimeIterator &other) const
            {
                return *current > *other.current;
            }

            bool operator<(const PrimeIterator &other) const
            {
                return *current < *other.current;
            }

            int operator*() const
            {
                return **current;
            }

            PrimeIterator &operator++()
            {
                ++current;
                return *this;
            }

            PrimeIterator begin()
            {
                current = container.nextPrimePtrs.begin();
                return *this;
            }

            PrimeIterator end()
            {
                current = container.nextPrimePtrs.end();
                return *this;
            }
        };
    };
}