/*
 * Definitions for the big 'ol settings struct. Here be sergals
 */

// Initialize to white
typedef struct {
  char r = 255;
  char g = 255;
  char b = 255;
} RGB;

typedef struct {
  RGB leftCheek;
  RGB rightCheek;
  bool operationInProgress = false; 
} Cheeks;

struct Settings {
  Cheeks cheeks;
};
