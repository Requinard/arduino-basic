/*
 * Definitions for the big 'ol settings struct. Here be sergals
 */

// Initialize to white
typedef struct {
  unsigned char r = 255;
  unsigned char g = 255;
  unsigned char b = 255;
} RGB;

typedef struct {
  RGB target;
  RGB current;
  bool operationInProgress = false;
} Cheeks;

struct Settings {
  Cheeks cheeks;
};
