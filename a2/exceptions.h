#include <exception>

using namespace std;

class illegalParameterValue : public exception 
{
   public:
      illegalParameterValue(string theMessage = "Illegal parameter value");
      void outputMessage();
        virtual ~illegalParameterValue() throw();
         private:
      string message;
};

class illegalIndex  : public exception
{
   public:
      illegalIndex(string theMessage = "Illegal index") ;
      void outputMessage() ;
        virtual ~illegalIndex() throw();
   private:
      string message;
};

illegalParameterValue::illegalParameterValue(string theMessage)
{
        message = theMessage;
}

void illegalParameterValue::outputMessage() 
{
cout << message << endl;
}

illegalParameterValue::~illegalParameterValue() throw() 
{
//Error- declaration of `virtual APIEx::~APIEx()' throws different exceptions
}

illegalIndex::illegalIndex(string theMessage)
{ message = theMessage;
}

void illegalIndex::outputMessage() {cout << message << endl;
}

illegalIndex::~illegalIndex() throw() 
{
//Error- declaration of `virtual APIEx::~APIEx()' throws different exceptions
}
