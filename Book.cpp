#include "Book.hpp"

    // write and document all methods in this file.
    // Default constructor for Book class
Book::Book()
{
    // Initialize member variables or perform any necessary setup
    title_ = "";
    author_ = "";
    ISBN_ = 0;
    icon_ = nullptr;
    price_ = 0.0f;
    blurb_ = "";
}

// Destructor for Book class
Book::~Book()
{
    // Clean up dynamically allocated resources, if any
    delete[] icon_;
}

// Copy constructor for Book class
Book::Book(const Book& rhs)
{
    // Perform deep copy of member variables from rhs
    title_ = rhs.title_;
    author_ = rhs.author_;
    ISBN_ = rhs.ISBN_;
    // Deep copy icon
    if (rhs.icon_ != nullptr) {
        icon_ = new int[80];
        std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
    } else {
        icon_ = nullptr;
    }
    price_ = rhs.price_;
    keywords_ = rhs.keywords_;
    blurb_ = rhs.blurb_;
}

// Copy assignment operator for Book class
Book& Book::operator=(const Book& rhs)
{
    if (this != &rhs) {
        // Check for self-assignment
        // Perform deep copy of member variables from rhs
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        // Deep copy icon
        delete[] icon_; // Deallocate existing icon array
        if (rhs.icon_ != nullptr) {
            icon_ = new int[80];
            std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
        } else {
            icon_ = nullptr;
        }
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }
    return *this;
}

// Move constructor for Book class
Book::Book(Book&& rhs)
{
    // Move member variables from rhs
    title_ = std::move(rhs.title_);
    author_ = std::move(rhs.author_);
    ISBN_ = rhs.ISBN_;
    icon_ = rhs.icon_;
    rhs.icon_ = nullptr; // Reset the icon pointer in the source object
    price_ = rhs.price_;
    keywords_ = std::move(rhs.keywords_);
    blurb_ = std::move(rhs.blurb_);
}

// Move assignment operator for Book class
Book& Book::operator=(Book&& rhs)
{
    if (this != &rhs) {
        // Check for self-assignment
        // Move member variables from rhs
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = rhs.ISBN_;
        delete[] icon_; // Deallocate existing icon array
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr; // Reset the icon pointer in the source object
        price_ = rhs.price_;
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }
    return *this;
}

// Getter method for title
const std::string& Book::getTitle() const
{
    return title_;
}

// Setter method for title
void Book::setTitle(const std::string& title)
{
    this->title_ = title;
}

// Getter method for author
const std::string& Book::getAuthor() const
{
    return author_;
}

// Setter method for author
void Book::setAuthor(const std::string& author)
{
    this->author_ = author;
}

// Getter method for ISBN
long long int Book::getISBN() const
{
    return ISBN_;
}

// Setter method for ISBN
void Book::setISBN(long long int ISBN)
{
    this->ISBN_ = ISBN;
}

// Getter method for icon
const int* Book::getIcon() const
{
    return icon_;
}

// Setter method for icon
void Book::setIcon(int* icon)
{
    this->icon_ = icon;
}

// Getter method for price
float Book::getPrice() const
{
    return price_;
}

// Setter method for price
void Book::setPrice(float price)
{
    this->price_ = price;
}

// Getter method for keywords
const std::vector<std::string>& Book::getKeywords() const
{
    return keywords_;
}

// Setter method for keywords
void Book::setKeywords(const std::vector<std::string>& keywords)
{
    this->keywords_ = keywords;
}

// Getter method for blurb
const std::string& Book::getBlurb() const
{
    return blurb_;
}

// Setter method for blurb
void Book::setBlurb(const std::string& blurb)
{
    this->blurb_ = blurb;
}

// Print method for Book class
void Book::print() const {
    std::cout << "Title: " << title_ << std::endl;
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "ISBN: " << ISBN_ << std::endl;
    // Print icon information if available
    std::cout << "Icon: ";
    for (int i = 0; i < 80; ++i) {
        std::cout << icon_[i] << " ";
    }
    // Print Price
    std::cout << "\nPrice: $" << std::fixed << std::setprecision(2) << price_ << std::endl;

    // Print Keywords
    std::cout << "Keywords: ";
    if (!keywords_.empty()) {
        std::cout << keywords_[0];
        for (size_t i = 1; i < keywords_.size(); ++i) {
            std::cout << ", " << keywords_[i];
        }
    }
    std::cout << std::endl;
    // Print blurb
    std::cout << "Blurb: " << blurb_ << std::endl;
}

