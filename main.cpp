#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " [CHARSET] [MAX-LENGTH]" << endl;
    return 0;
  }

  int length = 0;
  cerr << "What is the max length: ";
  cin >> length;

  int pos[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  bool done = false;

  int y = 0;
  while (true) {
    for (int x = 0; x < strlen(argv[1]); x++) {
      pos[0] += 1;
      for (int i = 0; i < 10; i++) {
        if (pos[i] == -1) {
          break;
        }

        if (pos[i] == strlen(argv[1])) {
          if (i == length-1) {
            done = true;
          }
          pos[i+1] += 1;
          pos[i] = 0;
        }
        cout << argv[1][pos[i]];
      }

      cout << endl;
      if (done) {
        break;
      }
    }

    if (done) {
      break;
    }
  }


  return 0;
}
