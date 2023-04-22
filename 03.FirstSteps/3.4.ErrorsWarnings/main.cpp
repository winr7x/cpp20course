#include <iostream>

int main(){
   
   //Compile time errors
   //Warning errors
   //Run time error:
   std::cout << "before" << std::endl;
#if 0 // UNCOMMENT_TO_SEE compilation warning and runtime error
   int value = 7/0;
   // NEW_FOR_ME We will not see this in output and $LASTEXITCODE will be -1073741676:
   std::cout << "value : " << value << std::endl;
#endif
    return 0;
}