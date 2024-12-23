## 'Const' type qualifier
- ‘const’ type qualifier in ‘c’ used to enforce read only feature on variables
- This is only programmer safety feature , so that the programmer cannot not modify the variable
- Still the contents of the variable can be modified by using its address(pointer)
- All local const variables will be stored in RAM
- All Global const variables are stored in FLASH or ROM,Unless the linker script is modified
- Global const variables cannot be modified as it gets stored in Flash memory which is write-protected

## const syntax
- const uint8_t data =10;
- uint8_t const data =10;

## const syntax with pointers
- uint8_t const *pointerData =(uint8_t*) 0x40000000;  // This pointerData is a pointer pointing to the **read only** data ; Still the pointer (pointerdata) can be modified. 

## 'Volatile' type qualifier
- Volatile is a type qualifier in ‘C’ used with variables to instruct the compiler not to invoke any optimization on the variable operation

## volatile syntax
- uint8_t volatile data;  // volatile data
- volatile uint8_t data;  // volatile data

## Non volatile pointer to volatile data
- - uint8_t volatile *pointerData;  // pointerData is a non volatile pointer,pointing to volatile data of type uint8
## volatile pointer to non volatile data
- uint8_t *volatile pointerData;  // pointerData is a volatile pointer,pointing to non volatile data of type uint8
## volatile pointer to volatile data
- uint8_t volatile *volatile pointerData;  //pointerData is a volatile pointer,pointing to volatile data of type uint8


  
