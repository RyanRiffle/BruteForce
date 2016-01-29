#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " [CHARSET] [MAX-LENGTH]" << endl;
    return 0;
  }

  int length = atoi(argv[2]);
  cerr << "Generating " << pow(strlen(argv[1]), length) << endl;
  return 0;

  int *pos = new int[length];
  for (int i = 0; i < length; i++) {
	  pos[i] = -1;
  }
  bool done = false;

  int y = 0;
  while (true) {
    for (int x = 0; x < strlen(argv[1]); x++) {
      pos[0] += 1;
      for (int i = 0; i < length; i++) {
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

		if (!done) {
			cout << argv[1][pos[i]];
		}
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
  delete pos;

  return 0;
}
