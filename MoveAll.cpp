#include "MoveAll.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  // Iterate through the source vector
    for (auto it = source.begin(); it != source.end(); ) {
        // Check if the book has the specified keyword
        if (std::find(it->getKeywords().begin(), it->getKeywords().end(), keyword) != it->getKeywords().end()) {
            // Move the book to the dest vector
            dest.push_back(std::move(*it));
            it = source.erase(it); // Remove the book from the source vector
            ++books_moved;
        } else {
            ++it; // Move to the next book
        }
    }

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}

