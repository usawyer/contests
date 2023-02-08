#include <iostream>

int main() {
  int num, places;
  std::cin >> num >> places;

  bool parity = places % 2 == 0 ? 1 : 0;
  int first_position = parity ? places / 2 : (places + 1) / 2;

  int counter = 0;
  int tmp_places = places;
  bool up = parity;

  while (num != 0) {
    int position = up ? first_position + counter : first_position - counter;
    std::cout << position << std::endl;

    if (up != parity || counter == 0) counter++;
    if (position != first_position) up = !up;

    num--;
    tmp_places--;

    if (tmp_places == 0) {
      tmp_places = places;
      counter = 0;
      up = parity;
    }
  }
}
