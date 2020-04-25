/*
 * IndexOutOfBoundException.h
 *
 *  Created on: Apr 20, 2020
 *      Author: vibhath
 */

#ifndef INDEXOUTOFBOUNDEXCEPTION_H_
#define INDEXOUTOFBOUNDEXCEPTION_H_

#include <exception>
#include <string>

class IndexOutOfBoundException: public std::exception
{
    public:
        IndexOutOfBoundException(unsigned int req_index, unsigned int length);

    private:
        unsigned int req_index;
        unsigned int length;

        virtual const char* what() const throw();
};



#endif /* INDEXOUTOFBOUNDEXCEPTION_H_ */
