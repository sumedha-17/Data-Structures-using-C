#include <stdio.h> 
#include <string.h> 
#define MAX 256   // ASCII range 
void buildBadMatchTable(char pattern[], int badChar[], int m) { 
int i; 
for (i = 0; i < MAX; i++) badChar[i] = m; 
printf("Step-by-step Bad Match Table Construction:\n"); 
printf("Initially, all characters set to %d\n\n", m); 
for (i = 0; i < m - 1; i++) { 
int shift = m - i - 1; 
badChar[(unsigned char)pattern[i]] = shift; 
printf("Pattern[%d] = '%c' → bad match value = max(1, %d - %d - 1) = %d\n", 
i, pattern[i], m, i, shift); 
} 
badChar[(unsigned char)pattern[m - 1]] = m; 
printf("Pattern[%d] = '%c' (last character) → bad match value = %d (special rule)\n\n", 
m - 1, pattern[m - 1], m); 
printf("Final Bad Match Table (unique pattern chars shown):\n"); 
int printed[256] = {0}; 
for (i = 0; i < m; i++) { 
unsigned char c = pattern[i]; 
if (!printed[c]) { 
printf("  '%c' : %d\n", c, badChar[c]); 
printed[c] = 1; 
} 
} 
printf("  '*' (all other chars) : %d\n\n", m); 
} 
void boyerMooreSearch(char text[], char pattern[]) { 
int n = strlen(text); 
int m = strlen(pattern); 
int badChar[MAX]; 
buildBadMatchTable(pattern, badChar, m); 
printf("=== Pattern Matching Process (showing each comparison) ===\n\n"); 
int startIndex = 0; 
while (startIndex <= n - m) { 
int j = m - 1; 
printf("Starting index for the comparison is %d:\n", startIndex); 
printf("Text   : %s\n", text); 
printf("Pattern: "); 
for (int s = 0; s < startIndex; s++) putchar(' '); 
printf("%s\n\n", pattern); 
// Compare right to left 
while (j >= 0) { 
char pc = pattern[j]; 
char tc = text[startIndex + j]; 
if (pc == tc) { 
printf("Compare pattern[%d] = '%c' with text[%d] = '%c' → Match\n", 
j, pc, startIndex + j, tc); 
j--; 
} else { 
printf("Compare pattern[%d] = '%c' with text[%d] = '%c' → Mismatch\n", 
j, pc, startIndex + j, tc); 
int badValue = badChar[(unsigned char)tc]; 
if (badValue < 1) badValue = 1; 
printf("Bad match value for text character '%c' = %d\n", tc, badValue); 
int newStart = startIndex + badValue; 
if (newStart > n - m) 
newStart = n - m + 1; // prevent overflow 
printf("→ New starting index for the comparison is %d\n\n", newStart); 
startIndex = newStart; 
break; 
} 
} 
if (j < 0) { 
printf("\n✅ Full pattern match found at starting index %d (0-based)\n", startIndex); 
return; 
} 
} 
printf("\n✅ Pattern not found in text.\n"); 
} 
int main() { 
char text[] = "welcometeammast"; 
char pattern[] = "teammast"; 
printf("Text    : %s\n", text); 
printf("Pattern : %s\n\n", pattern); 
boyerMooreSearch(text, pattern); 
return 0; 
} 
