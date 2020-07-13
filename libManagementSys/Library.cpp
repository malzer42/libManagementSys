/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Library.cpp
 * Author: pamulamba
 * 
 * Created on 29 juin 2020, 22 h 21
 */

#include "Library.h"

/**
 * Default constructor
 */
Library::Library() : subs_(nullptr), nSubs_(0), books_(nullptr), nBooks_(0), borrows_(nullptr), nBorrows_(0)
{
    subs_ = new Subscriber*[MAX_SUB];
    for(unsigned short i = 0; i < MAX_SUB; i++){
        subs_[i] = nullptr;
    }
    
    books_ = new Book*[MAX_BOOK];
    for(unsigned short i = 0; i < MAX_BOOK; i++){
        books_[i] = nullptr;
    }
    
    borrows_ = new Borrow*[MAX_BORROW];
    for(unsigned short i = 0; i < MAX_BORROW; i++){
        borrows_[i] = nullptr;
    }
}

/**
 * Copy constructor
 * @param orig
 */
Library::Library(const Library& orig) : subs_(orig.subs_), nSubs_(orig.nSubs_), 
        books_(orig.books_), nBooks_(orig.nBooks_),
        borrows_(orig.borrows_), nBorrows_(orig.nBorrows_)
{
}

/**
 * Move constructor
 * @param orig
 * @return 
 */
Library::Library(Library&& orig) noexcept : subs_(nullptr), nSubs_(0), 
        books_(nullptr), nBooks_(0), borrows_(nullptr), nBorrows_(0)
{
    subs_ = orig.subs_;
    nSubs_ = orig.nSubs_;
    
    books_ = orig.books_;
    nBooks_ = orig.nBooks_;
    
    borrows_ = orig.borrows_;
    nBorrows_ = orig.nBorrows_;
    
    orig.subs_ = nullptr;
    orig.nSubs_ = 0;
    
    orig.books_ = nullptr;
    orig.nBooks_ = 0;
    
    orig.borrows_ = nullptr;
    orig.nBorrows_ = 0;
}


/**
 * Copy assignment operator
 * @param orig
 * @return *this
 */
Library& Library::operator=(const Library &orig){
    if(this != &orig){
        subs_ = orig.subs_;
        nSubs_ = orig.nSubs_;
        books_ = orig.books_;
        nBooks_ = orig.nBooks_;
        borrows_ = orig.borrows_;
        nBorrows_ = orig.nBorrows_;
    }
    return *this;    
}

/**
 * Move assignment operator
 * @param orig
 * @return 
 */
Library& Library::operator=(Library&& orig)noexcept{
    if(this != &orig){
        
        subs_ = nullptr;
        nSubs_ = 0;
        books_ = nullptr;
        nBooks_ = 0;
        borrows_ = nullptr;
        nBorrows_ = 0;
        
        subs_ = orig.subs_;
        nSubs_ = orig.nSubs_;
        books_ = orig.books_;
        nBooks_ = orig.nBooks_;
        borrows_ = orig.borrows_;
        nBorrows_ = orig.nBorrows_;
        
        orig.subs_ = nullptr;
        orig.nSubs_ = 0;
        orig.books_ = nullptr;
        orig.nBooks_ = 0;
        orig.borrows_ = nullptr;
        orig.nBorrows_ = 0;
    }
    return *this;   
}

Library::~Library() {
    delete[] subs_;
    subs_ = nullptr;
    delete[] books_;
    books_ = nullptr;
    delete[] borrows_;
    borrows_ = nullptr;
}

// Processing subscribers in the library

/**
 * Adding an instance of Subscriber to the list of subs_
 * @param subscriber
 */
void Library::addSubscriber(Subscriber& subscriber){
    if(nSubs_ < MAX_SUB){
        subs_[nSubs_++] = &subscriber;
    }
}

/**
 * Remove an instance of Subscriber to the list of subs_
 * @param id
 */
void Library::removeSubscriber(const std::string& id){
    for(unsigned short i = 0; i < nSubs_; i++){
        if(subs_[i]->getIdNumber().compare(id) == 0){
            subs_[i] = subs_[nSubs_ - 1];
            nSubs_--;
            break;
        }        
    }
}

//void sortSubscriber(unsigned int option);
//void swapSubscriber(Subscriber &sub1, Subscriber &sub2);

// Processing books in the library

/**
 * Adding an instance of Book to the Library
 * @param book
 */
void Library::addBook(std::unique_ptr<Book>& book){
    if(nBooks_ < MAX_BOOK){
        books_[nBooks_++] = &*book;
    }
}

/**
 * Removing a book instance from the Library
 * @param quote
 */
void Library::removeBook(const std::string& quote){
    for(unsigned short i = 0; i < nBooks_; i++){
        if(books_[i]->getQuote().compare(quote) == 0){
            books_[i] = books_[nBooks_ -1];
            nBooks_--;
            break;
        }
    }
}

// Processing borrowers in the library
/**
 * Adding a Borrow instance in the Library
 * @param borrow
 */
void Library::addBorrow(Borrow& borrow){
    if(nBorrows_ < MAX_BORROW){
        borrows_[nBorrows_++] = &borrow;
    }
}

/**
 * Removing a Borrow instance in the Library
 * @param idNumber
 * @param quote
 */
void Library::removeBorrow(Borrow* borrow){
    for(unsigned short i = 0; i < nBorrows_; i++){
        if(borrows_[i]->getSubscriber()->getIdNumber() == borrow->getSubscriber()->getIdNumber() && 
                borrows_[i]->getBook()->getQuote() == borrow->getBook()->getQuote() ){
            borrows_[i] = borrows_[nBorrows_ -1];
            nBorrows_--;
            //borrows_[i]->getBook()->setNAvailables(borrows_[i]->getBook()->getNAvailables() + 1);
            break;
        }
    }    
}


// void sortBook(unsigned int option);
// void swapBook(Book &book1, Book &book2);

// Searching, borrowing, returning, displaying methods

/**
 * Searching instances of Book by title
 * @param title
 */
void Library::searchTitle(const std::string &title){
    bool isPresent = false;
    for(unsigned short i = 0; i < nBooks_; i++){
        if (books_[i]->getTitle().find(title) != std::string::npos){
            books_[i]->print();
            isPresent = true;
        }
    }
    if(!isPresent){
        std::cout << "!!! No book with the Title: " << title << " found in the library!!!\n";
    }
}


/**
 * Searching instances of Book by quote
 * @param book_quote
 */
void Library::searchQuote(const std::string &quote){
    std::cout << "Searching by quote...: " << quote << '\n';
    if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
        std::logic_error description("Range_Error-- Could Not run the searchQuote");
        throw;
    }
    else {
        std::regex pattern(quote);
        bool isFound = false;
        for (unsigned short i = 0; i < nBooks_; i++) {
            if (std::regex_search(books_[i]->getQuote(), pattern)) {
                std::cout << "nBooks_:" << nBooks_ <<". i: " << i <<'\n';
                isFound = true;
                books_[i]->print();
            }
        }
        if (!isFound) {
            std::cout << "!!! Could not find a book with Quote: " << quote << "!!!\n";
        }
    }    
    std::cout << "Leaving the search of quote\n";
}


/**
 * Borrowing a book based on some conditions 
 * Check if is possible for a Subscriber to borrow a specific book
 * If yes, then a new borrow instance is added to the list of borrowers
 * The following conditions are to be met for a Subscriber to borrow a book:
 * 1. The book is available
 * 2. The subscriber meets the age criterial -- the subscriber age >= book min reader age
 * 3. The subscriber did not already borrow the book
 * 4. The subscriber did exceed the maximum number of books allowed to borrow -- 2 by subscriber
 * The method return a Boolean value to indicate a successful or failure of a book
 * @param idNumber
 * @param quote
 * @param returnDate
 * @return 
 */
bool Library::borrowBookBySubscriber(const std::string &idNumber, const std::string &quote, const std::string& returnDate){
    std::cout << "\nProcessing borrowBook...: \n"
            << "nSubs_: " << nSubs_ << ", nBooks_ " << nBooks_ << ", nBorrows_: " << nBorrows_ << '\n';
    const unsigned short MAX_BORROW_ALLOWED = 2;
    bool isSuccessful = false;
    bool isBookAvailable = false;
    bool isSubOldToReadTheBook = false;
    bool condition_one_and_two = false;
    
    unsigned short iSub = 0;
    unsigned short iBook = 0;
    
    if(nBorrows_ == 0){
        std::cout << "Checking condition 1 (Book available). nBorrows_: " << nBorrows_ << '\n';
        // Check condition 1.
        for(unsigned short i = 0; i < nBooks_; i++){
            if(books_[i]->getQuote() == quote){
                std::cout << "Number of books available: " << books_[i]->getNAvailables() << '\n';
                isBookAvailable = ((books_[i]->getNAvailables() > 0) ? true : isBookAvailable);
                iBook = i;
                break;
            }
        }
        
        std::cout << "iBook " << iBook << ", isBookAvailable: " << isBookAvailable << '\n';
        
        // Check condition 2.
        std::cout << "Checking condition 2 (Age). nBorrows_: " << nBorrows_ << '\n';
        for(unsigned short j = 0; j < nSubs_; j++){
            if(subs_[j]->getIdNumber() == idNumber){
                std::cout << "Subscriber age: " << subs_[j]->getAge() << '\n';
                std::cout << "Book reader age: " << books_[iBook]->getMinReaderAge() << '\n';
                        
                isSubOldToReadTheBook = ((subs_[j]->getAge() >= books_[iBook]->getMinReaderAge()) ? true : false );
                iSub = j;
                break;
            }
        }
        
        std::cout << "iSub: " << iSub << ", isSubOldToReadTheBook: " << isSubOldToReadTheBook << '\n';
        
        // Condition 1 and 2  
        condition_one_and_two = isBookAvailable && isSubOldToReadTheBook;
        
        std::cout << "Conditions 1 (Book Available) and 2 (Age). condition_one_and_two : " << condition_one_and_two << '\n';
        
        /**
         * nBorrows_ == 0
         * We do not check condition 3
         * We do not check condition 4
         */
        if(condition_one_and_two){
            //Borrow borrow(subs_[iSub], books_[iBook], returnDate);
            //addBorrow(borrow);
            std::unique_ptr<Borrow> borrow = std::make_unique<Borrow>(subs_[iSub], books_[iBook], returnDate);
            
            borrows_[nBorrows_++] = &*borrow; //Borrow(subs_[iSub], books_[iBook], returnDate);
            borrows_[nBorrows_]->print();
            books_[iBook]->setNAvailables( books_[iBook]->getNAvailables() - 1 );
            isSuccessful = true;
        }
    }
    else if(nBorrows_ > 0 && nBorrows_< MAX_BORROW){
        std::cout << "Checking condition 3 (has already borrowed the Book). nBorrows_: " << nBorrows_ << '\n';
        unsigned short counterSub = 0;
        bool hasBorrowedTheBook = false;
        
        for(unsigned short k; k < nBorrows_; k++){
            if(borrows_[k]->getSubscriber()->getIdNumber()== idNumber){
                counterSub++;
                hasBorrowedTheBook = ( ( borrows_[k]->getBook()->getQuote() == quote ) ? true : false);
            }
        }
        
        std::cout << "counterSub: " << counterSub << ", hasBorrowedTheBook: " << hasBorrowedTheBook << '\n';
        
        // Check condition 1.
        for(unsigned short i = 0; i < nBooks_; i++){
            if(books_[i]->getQuote() == quote){
                isBookAvailable = ((books_[i]->getNAvailables() > 0) ? true : isBookAvailable);
                iBook = i;
                break;
            }
        }
        
        // Check condition 2.
        for(unsigned short j = 0; j < nSubs_; j++){
            if(subs_[j]->getIdNumber() == idNumber){
                isSubOldToReadTheBook = ((subs_[j]->getAge() >= books_[iBook]->getMinReaderAge()) ? true : false );
                iSub = j;
                break;
            }
        }
        
        // Condition 1 and 2  
        condition_one_and_two = isBookAvailable && isSubOldToReadTheBook;
        
        std::cout << "Conditions 1 (Book Available) and 2 (Age). condition_one_and_two : " << condition_one_and_two << '\n';
        
        if((!hasBorrowedTheBook && counterSub < MAX_BORROW_ALLOWED) && condition_one_and_two ){
            //Borrow borrow(subs_[iSub], books_[iBook], returnDate);
            //addBorrow(borrow);
            std::unique_ptr<Borrow> borrow = std::make_unique<Borrow>(subs_[iSub], books_[iBook], returnDate);
            borrows_[nBorrows_++] = &*borrow; //Borrow(subs_[iSub], books_[iBook], returnDate);
            books_[iBook]->setNAvailables( books_[iBook]->getNAvailables() - 1 );
            isSuccessful = true;
        }       
        
    }
    else{
        isSuccessful = false;        
    }
    return isSuccessful;
}

/**
 * Return method
 * If the subscriber has borrowed the book, the borrow record is deleted 
 * from the list borrows_
 * Return a Boolean value for a successful or failed return
 * Return a borrowed book by the Subscriber in the Library
 * @param subscriber_id
 * @param book_quote
 * @return isBookReturned
 */
bool Library::returnBook(const std::string &idNumber, const std::string &quote){
    bool isBookReturned = false;
    for(unsigned short i = 0; i < nBorrows_; i++){
        if(borrows_[i]->getSubscriber()->getIdNumber() == idNumber && borrows_[i]->getBook()->getQuote() == quote ){
            removeBorrow(borrows_[i]);
            //borrows_[i] = borrows_[nBorrows_ -1];
            //nBorrows_--;
            //borrows_[i]->getBook()->setNAvailables(borrows_[i]->getBook()->getNAvailables() + 1);
            isBookReturned = true;
            break;
        }
    }
    
    for(unsigned short i = 0; i < nBooks_; i++){
        if (books_[i]->getQuote() == quote){
            books_[i]->setNAvailables(books_[i]->getNAvailables() + 1);
            break;
        }
    }
    
    return isBookReturned;
}

/**
 * InfoSubscriber method
 * @param subscriber_id
 */
void Library::infoSubscriber(const std::string &idNumber) const{
    for (unsigned short i = 0; i < nBorrows_; i++) {
        if (borrows_[i]->getSubscriber()->getIdNumber() == idNumber) {
            borrows_[i]->getSubscriber()->print();
            break;
        }
    }
    
    for (unsigned short i = 0; i < nBorrows_; i++) {
        if (borrows_[i]->getSubscriber()->getIdNumber() == idNumber) {
            borrows_[i]->print();
        }
    }
}

//void swapBorrow(Borrow &borrow1, Borrow &borrow2);

/**
 * Printing methods
 */
void Library::print()const{
    std::cout << "\n\tPrinting Subscribers ...\n";
    for (unsigned short i = 0; i < nSubs_; i++) {
        std::cout << " " << i+1 << ". ";
        subs_[i]->print();
    }
    
    std::cout << "\n\tPrinting Books ...\n";
    
    for (unsigned short i = 0; i < nBooks_; i++) {
      std::cout << " " << i+1 << ". ";
      books_[i]->print();
    }
    
    std::cout << "\n\tPrinting Borrowers ...\n";
    
    for (unsigned short i = 0; i < nBorrows_; i++) {
      std::cout << " " << i+1 << ". ";
      borrows_[i]->print();
    }
}
