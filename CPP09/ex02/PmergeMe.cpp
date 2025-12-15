#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isAllDigits(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}
void PmergeMe::parseInput(const std::string& input)
{
	std::stringstream ss(input);
	std::string token;
	while (ss >> token)
	{
		if (isAllDigits(token))
		{
			int number;
			std::stringstream ts(token);
			if (!(ts >> number))
				throw CustomException("Error: Invalid number format '" + token + "'.");

			if (number <= 0)
				throw CustomException("Error: Number must be a positive integer.");

			_vec.push_back(number);
			_deq.push_back(number);
		}
		else
			throw CustomException("Error: Invalid input '" + token + "'.");

	}
}

double PmergeMe::calculateTimeDiff(const timeval& start, const timeval& end) {
    double startTime = start.tv_sec * 1000000.0 + start.tv_usec;
    double endTime   = end.tv_sec   * 1000000.0 + end.tv_usec;
    return endTime - startTime;
}

// Jacobsthal numbers: J0=0, J1=1, Jn = Jn-1 + 2*Jn-2
// For Ford-Johnson insertion order (excluding pending[0]):
// indices (1-based): 1, 3,2, 5,4, 11,10,9,8,7,6, ...
std::vector<size_t> PmergeMe::jacobsthalInsertionOrder(size_t pendingSize) {
    std::vector<size_t> order;

    if (pendingSize <= 1)
        return order;

    size_t r = pendingSize - 1;
    std::vector<size_t> points;
    size_t jPrev = 1;
    size_t jCurr = 3;
    points.push_back(1);
    while (jCurr <= r) {
        points.push_back(jCurr);
        size_t jNext = jCurr + 2 * jPrev;
        jPrev = jCurr;
        jCurr = jNext;
    }

    size_t prevPoint = 0;
    for (size_t pi = 0; pi < points.size(); ++pi) {
        size_t p = points[pi];
        if (p > r) p = r;
        for (size_t k = p; k > prevPoint; --k) {
            order.push_back(k);
        }
        prevPoint = p;
        if (prevPoint == r) break;
    }
    for (size_t k = r; k > prevPoint; --k)
        order.push_back(k);

    return order;
}

void PmergeMe::sortAndDisplay() {
    // VECTOR
    std::vector<int> v = this->_vec;
    display(v, "Before");

    timeval sv, ev;
    gettimeofday(&sv, NULL);
    fordJohnsonSort(v);
    gettimeofday(&ev, NULL);

    display(v, "After");

    // DEQUE
    std::deque<int> d = this->_deq;
    display(d, "Before");

    timeval sd, ed;
    gettimeofday(&sd, NULL);
    fordJohnsonSort(d);
    gettimeofday(&ed, NULL);
    display(d, "After");


    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << this->_vec.size() << " elements with std::vector: " << calculateTimeDiff(sv, ev) << " us" << std::endl;
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << this->_deq.size() << " elements with std::deque: " << calculateTimeDiff(sd, ed) << " us" << std::endl;
}
