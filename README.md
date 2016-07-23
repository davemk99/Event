# Event
This tiny library is created for adding Event support for C++.
Here is an example of usage.
```
#include "Event.h"
class Person

{
private:
  int age;
public:
  Event AgeChanged;
  Person(int age):age(age){}
  void SetAge(int age){
    this->age=age;
    AgeChanged(this);
  }
};
```
The Event.h header file includes this headers:iostream,algorithm,string,functional and list.Standard namespace also used.
For more examples go to ../Samples
