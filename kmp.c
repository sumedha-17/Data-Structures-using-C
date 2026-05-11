#include <stdio.h> 
#include <string.h> 
void computeLPSArray(char* pat, int M, int* lps) { 
int len = 0;  // length of the previous longest prefix suffix 
int i = 1; 
lps[0] = 0;   // lps[0] is always 0 
printf("Constructing LPS array for pattern: %s\n", pat); 
printf("Index\tCharacter\tLPS\n"); 
printf("0\t%c\t\t%d\n", pat[0], lps[0]); 
while (i < M) { 
if (pat[i] == pat[len]) { 
len++; 
lps[i] = len; 
printf("%d\t%c\t\t%d  (match)\n", i, pat[i], lps[i]); 
i++; 
} else { 
if (len != 0) { 
len = lps[len - 1]; 
printf("%d\t%c\t\t--  (mismatch, update len to %d)\n", i, pat[i], len); 
} else { 
lps[i] = 0; 
printf("%d\t%c\t\t%d  (mismatch, len=0)\n", i, pat[i], lps[i]); 
i++; 
} 
} 
} 
printf("\n"); 
} 
void KMPSearch(char* pat, char* txt) { 
int M = strlen(pat); 
int N = strlen(txt); 
int lps[M]; 
computeLPSArray(pat, M, lps); 
int i = 0; // index for txt[] 
int j = 0; // index for pat[] 
printf("=== Starting KMP Search ===\n"); 
printf("Text   : %s\n", txt); 
printf("Pattern: %s\n\n", pat); 
while (i < N) { 
printf("Compare txt[%d] = '%c' and pat[%d] = '%c' → ", i, txt[i], j, pat[j]); 
if (pat[j] == txt[i]) { 
printf("Match\n"); 
i++; 
j++; 
} else { 
printf("Mismatch\n"); 
if (j != 0) { 
int old_j = j; 
j = lps[j - 1]; 
printf("→ Update j from %d to lps[%d] = %d\n", old_j, old_j - 1, j); 
} else { 
i++; 
} 
} 
if (j == M) { 
printf("✅ Pattern found at index %d\n", i - j); 
j = lps[j - 1]; 
} 
} 
} 
int main() { 
char txt[100], pat[100]; 
printf("Enter text: "); 
fgets(txt, sizeof(txt), stdin); 
txt[strcspn(txt, "\n")] = '\0';  // remove newline 
printf("Enter pattern: "); 
fgets(pat, sizeof(pat), stdin); 
pat[strcspn(pat, "\n")] = '\0';  // remove newline 
printf("\n"); 
KMPSearch(pat, txt); 
return 0; 
}
