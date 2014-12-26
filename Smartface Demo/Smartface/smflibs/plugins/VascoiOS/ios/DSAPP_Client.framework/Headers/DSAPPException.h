//////////////////////////////////////////////////////////////////////////////
//
//  Copyright  1999 - 2013 VASCO DATA SECURITY
//  All rights reserved. http://www.vasco.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef DSAPPEXCEPTIONS_H_
#define DSAPPEXCEPTIONS_H_

#include <exception>
#include <string>
using namespace std;

/**
 * Exception which can be thrown by the DSAPP library in case of error.
 */
class DSAPPException: public exception
{

public:

	/** Constructor */
	DSAPPException(int errorCode);

	/** Desturctor */
	virtual ~DSAPPException() throw ();

	/**
	 * Gets the error code
	 * @return The error code
	 */
	int getErrorCode();

	/**
	 * Gets a default error message associated with the error code
	 * @return The error message
	 */
	string getMessage();

	/**
	 * Generic method to get the default error message
	 */
	virtual const char * what() const throw ();

private:

	/** Error code */
	int errorCode;

	/** Message */
	string message;

};

#endif
