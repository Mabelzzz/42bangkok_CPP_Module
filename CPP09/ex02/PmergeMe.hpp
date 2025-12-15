#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <sys/time.h>

#define RED    "\033[31m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

class PmergeMe {

	private:
		std::vector<int> _vec;
		std::deque<int>  _deq;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		class CustomException : public std::runtime_error {
			public:
				CustomException(const std::string& msg) : std::runtime_error(msg) {}
		};

		void parseInput(const std::string& input);
		void sortAndDisplay();
		double calculateTimeDiff(const timeval& start, const timeval& end);
		static bool isAllDigits(const std::string& s);

		template <typename Cont>
		void display(const Cont& c, const std::string& prefix) const {
			std::cout << prefix << ":";
			for (typename Cont::const_iterator it = c.begin(); it != c.end(); ++it)
				std::cout << " " << *it;
			std::cout << std::endl;
		}

		static std::vector<size_t> jacobsthalInsertionOrder(size_t pendingSize);

		// insert value into [begin, begin+limit) using lower_bound
		template <typename Cont>
		void insertWithBound(Cont& mainChain, int value, size_t limit) {
			if (limit > mainChain.size())
				limit = mainChain.size();
			typename Cont::iterator it =
				std::lower_bound(mainChain.begin(),
								mainChain.begin() + (std::ptrdiff_t)limit,
								value);
			mainChain.insert(it, value);
		}

		// find index of a value (partner big) in mainChain
		template <typename Cont>
		size_t findIndex(const Cont& c, int value) {
			for (size_t i = 0; i < c.size(); ++i) {
				if (c[i] == value)
					return i;
			}
			return c.size(); // not found
		}

		// ---- Ford-Johnson core (vector + deque) ----
		template <typename Cont>
		void fordJohnsonSort(Cont& a)
		{
			if (a.size() <= 1) return;

			// 1) make pairs (small, big)
			std::vector< std::pair<int,int> > pairs;
			pairs.reserve(a.size() / 2);

			bool hasStraggler = (a.size() % 2 != 0);
			int straggler = 0;

			for (size_t i = 0; i + 1 < a.size(); i += 2) {
				int x = a[i];
				int y = a[i + 1];
				if (x <= y) pairs.push_back(std::make_pair(x, y));
				else        pairs.push_back(std::make_pair(y, x));
			}
			if (hasStraggler) straggler = a.back();

			// 2) sort the "big" values recursively
			Cont mainChain;
			for (size_t i = 0; i < pairs.size(); ++i)
				mainChain.push_back(pairs[i].second);

			fordJohnsonSort(mainChain);

			// 3) reorder pairs by sorted bigs (stable)
			std::vector< std::pair<int,int> > orderedPairs;
			orderedPairs.reserve(pairs.size());
			std::vector<char> used(pairs.size(), 0);

			for (size_t i = 0; i < mainChain.size(); ++i) {
				int big = mainChain[i];
				for (size_t p = 0; p < pairs.size(); ++p) {
					if (!used[p] && pairs[p].second == big) {
						used[p] = 1;
						orderedPairs.push_back(pairs[p]);
						break;
					}
				}
			}

			// 4) pending = smalls aligned to orderedPairs
			std::vector<int> pending;
			pending.reserve(orderedPairs.size());
			for (size_t i = 0; i < orderedPairs.size(); ++i)
				pending.push_back(orderedPairs[i].first);

			// 5) insert pending[0] first (bounded before partner big)
			if (!pending.empty()) {
				size_t posBig0 = findIndex(mainChain, orderedPairs[0].second);
				insertWithBound(mainChain, pending[0], posBig0);
			}

			// 6) Jacobsthal insertion for the rest
			std::vector<size_t> order = PmergeMe::jacobsthalInsertionOrder(pending.size());
			for (size_t oi = 0; oi < order.size(); ++oi) {
				size_t pIdx = order[oi];
				if (pIdx >= pending.size())
					continue;

				int small = pending[pIdx];
				int partnerBig = orderedPairs[pIdx].second;

				size_t posBig = findIndex(mainChain, partnerBig);
				insertWithBound(mainChain, small, posBig);
			}

			// 7) insert straggler
			if (hasStraggler) {
				insertWithBound(mainChain, straggler, mainChain.size());
			}

			a = mainChain;
		}
};

#endif
