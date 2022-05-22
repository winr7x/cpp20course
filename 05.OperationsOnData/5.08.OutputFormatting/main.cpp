// https://youtu.be/8jLOx1hD3_o?t=21371

#include <iomanip>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // std::flush : flushes the output buffer to its final destination: device (terminal)
  std::cout << "This is a nice message...." << std::endl
            << std::flush;
  // After this std::flush, we're sure that at this line, the message has been sent
  // to the stream. This may be important in some applications.

  //==============================================================
  std::cout << std::endl;

  // std::setw() : Adjust the field width for the item about to be printed.
  // The setw() manipulator only affects the next value to be printed.

  std::cout << "Unformatted table : " << std::endl;
  std::cout << "Daniel : "
            << " "
            << "Gray"
            << " 25" << std::endl;
  std::cout << "Stanley : "
            << " "
            << "Woods"
            << " 33" << std::endl;
  std::cout << "Jordan : "
            << " "
            << "Parker"
            << " 45" << std::endl;
  std::cout << "Joe : "
            << " "
            << "Ball"
            << " 21" << std::endl;
  std::cout << "Josh : "
            << " "
            << "Carr"
            << " 27" << std::endl;
  std::cout << "Izaiah : "
            << " "
            << "Robinson"
            << " 29" << std::endl;

  std::cout << std::endl;
  std::cout << "Formatted table : " << std::endl;

  int col_width{14};

  std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << " Age" << std::endl;
  std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << " 25" << std::endl;
  std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) << "Woods" << std::setw(col_width) << " 33" << std::endl;
  std::cout << std::setw(col_width) << "Jordan" << std::setw(col_width) << "Parker" << std::setw(col_width) << " 45" << std::endl;
  std::cout << std::setw(col_width) << "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width) << " 21" << std::endl;
  std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width) << " 27" << std::endl;
  std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width) << " 29" << std::endl;

  // Justify : Values can be justified in their fields. There are three manipulators
  //           for adjusting the justification: left, right, and internal

  std::cout << std::endl;
  std::cout << "Right justified table(default) :  " << std::endl;
  col_width = 20;

  std::cout << std::right; // NEW_FOR_ME Right value alignment inside width. By default. '      value'
  std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << " Age" << std::endl;
  std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << " 25" << std::endl;
  std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) << "Woods" << std::setw(col_width) << " 33" << std::endl;
  std::cout << std::setw(col_width) << "Jordan" << std::setw(col_width) << "Parker" << std::setw(col_width) << " 45" << std::endl;
  std::cout << std::setw(col_width) << "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width) << " 21" << std::endl;
  std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width) << " 27" << std::endl;
  std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width) << " 29" << std::endl;

  std::cout << std::endl;
  std::cout << "Left justified table :  " << std::endl;

  std::cout << std::left; // NEW_FOR_ME Left value alignment inside width. 'value      '
  std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << " Age" << std::endl;
  std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << " 25" << std::endl;
  std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) << "Woods" << std::setw(col_width) << " 33" << std::endl;
  std::cout << std::setw(col_width) << "Jordan" << std::setw(col_width) << "Parker" << std::setw(col_width) << " 45" << std::endl;
  std::cout << std::setw(col_width) << "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width) << " 21" << std::endl;
  std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width) << " 27" << std::endl;
  std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width) << " 29" << std::endl;

  std::cout << std::endl;
  std::cout << "Internal justified :  " << std::endl;
  std::cout << std::right;
  std::cout << std::setw(10) << -123.45 << std::endl;
  std::cout << std::internal; // NEW_FOR_ME Align sign of number left and number itself right. '-    123.45'
  std::cout << std::setw(10) << -123.45 << std::endl;
  std::cout << std::left;
  std::cout << std::setw(10) << -123.45 << std::endl;

  std::cout << std::endl;

  std::cout << "Table with fill characters :  " << std::endl;

  std::cout << std::right;
  std::cout << std::setfill('.'); // The fill character
  std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << "Age" << std::endl;
  std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "25" << std::endl;
  std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) << "Woods" << std::setw(col_width) << "33" << std::endl;
  std::cout << std::setw(col_width) << "Jordan" << std::setw(col_width) << "Parker" << std::setw(col_width) << "45" << std::endl;
  std::cout << std::setw(col_width) << "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width) << "21" << std::endl;
  std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width) << "27" << std::endl;
  std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width) << "29" << std::endl;

  std::cout << std::endl;

  // showpos and noshowpos : show or hide the +  sign for positive numbers

  int pos_num{34};
  int neg_num{-45};

  std::cout << "pos_num : " << pos_num << std::endl;
  std::cout << "neg_num : " << neg_num << std::endl;

  std::cout << std::endl;
  std::cout << std::showpos;
  std::cout << "pos_num : " << pos_num << std::endl;
  std::cout << "neg_num : " << neg_num << std::endl;

  std::cout << std::endl;
  std::cout << std::noshowpos;
  std::cout << "pos_num : " << pos_num << std::endl;
  std::cout << "neg_num : " << neg_num << std::endl;

  std::cout << std::endl;

  // different number systems : std::dec, std::hex, std::oct // NEW_FOR_ME It only make sense for integral types, not for fractional

  int pos_int{717171};
  int neg_int{-47347};
  double double_var{498.32};

  std::cout << std::endl;
  std::cout << "default base format : " << std::endl;
  std::cout << "pos_int : " << pos_int << std::endl;
  std::cout << "neg_int : " << neg_int << std::endl;
  std::cout << "double_var : " << double_var << std::endl;

  std::cout << std::endl;
  std::cout << "pos_int in different bases : " << std::endl;
  std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
  std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl; // 0xaF173
  std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl; // 02570563

  std::cout << std::endl;
  std::cout << "neg_int in different bases : " << std::endl;
  std::cout << "neg_int (dec) : " << std::dec << neg_int << std::endl;
  std::cout << "neg_int (hex) : " << std::hex << neg_int << std::endl; // 0xffff470d
  std::cout << "neg_int (oct) : " << std::oct << neg_int << std::endl; // 7777643415

  std::cout << std::endl;
  std::cout << "double_var in different bases : " << std::endl;
  std::cout << "double_var (dec) : " << std::dec << double_var << std::endl; // 498.32
  std::cout << "double_var (hex) : " << std::hex << double_var << std::endl; // 498.32
  std::cout << "double_var (oct) : " << std::oct << double_var << std::endl; // 498.32

  std::cout << std::endl;

  // uppercase and nouppercase

  pos_int = 717171;

  std::cout << std::endl;
  std::cout << "pos_int (uppercase) : " << std::endl;
  std::cout << std::uppercase;
  std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
  std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
  std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
  std::cout << std::nouppercase;

  std::cout << std::endl;

  // fixed and scientific : for floating point values

  double a{3.1415926535897932384626433832795};
  double b{2006.0};
  double c{1.34e-10};

  std::cout << std::endl;
  std::cout << "double values (default : use scientific where necessary) : " << std::endl; // NEW_FOR_ME Use scientific where necessary only
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;

  std::cout << std::endl;
  std::cout << "double values (fixed) : " << std::endl;
  std::cout << std::fixed;
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;

  std::cout << std::endl;
  std::cout << "double values (scientific) : " << std::endl;
  std::cout << std::scientific;
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;

  std::cout << std::endl;
  std::cout << "double values (back to defaults) : " << std::endl;
  std::cout.unsetf(std::ios::scientific | std::ios::fixed); // Hack NEW_FOR_ME Reset to default behavior
  std::cout << "a : " << a << std::endl;
  std::cout << "b : " << b << std::endl;
  std::cout << "c : " << c << std::endl;

  std::cout << std::endl;

  // showpoint and noshowpoint : show trailing zeros if necessary
  // Force output of the decimal point

  double d{34.1};
  double e{101.99};
  double f{12.0};
  int g{45};

  std::cout << std::endl;
  std::cout << "noshowpoint (default) : " << std::endl;
  std::cout << "d : " << d << std::endl;
  std::cout << "e : " << e << std::endl;
  std::cout << "f : " << f << std::endl; // 12
  std::cout << "g : " << g << std::endl;

  std::cout << std::endl;
  std::cout << "std::showpoint: " << std::endl;
  std::cout << std::showpoint;
  std::cout << "d : " << d << std::endl;
  std::cout << "e : " << e << std::endl;
  std::cout << "f : " << f << std::endl; // 12.0
  std::cout << "g : " << g << std::endl;

  std::cout << std::endl;
  std::cout << "force std::noshowpoint: " << std::endl;
  std::cout << std::noshowpoint;
  std::cout << "d : " << d << std::endl;
  std::cout << "e : " << e << std::endl;
  std::cout << "f : " << f << std::endl; // 12.0
  std::cout << "g : " << g << std::endl;

  return 0;
}
