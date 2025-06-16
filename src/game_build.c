/** 
 * buildBlanks
 * 
 * Function to build a blank string from the given
 * length of a word.
 * 
 * INPUTS:
 *     char blanks[]: An array to hold the blanks
 *     int length: How many blanks should there be
 * 
 * OUTPUT:
 *     NO RETURN. Uses a reference to an array. 
*/

void buildBlanks(char blanks[], int length) {
    int i;

    for (i = 0; i < length; ++i) {
        blanks[i] = '_';
    }
}