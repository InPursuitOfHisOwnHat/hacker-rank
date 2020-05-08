#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
#include <sys/types.h>


ssize_t add_word_to_sentence(char*** s, ssize_t s_len, char* w) {
    // Need to add one to len of s but also to s[y][x]
    //cakelog("ssize_t add_word_to_sentence(char*** s, ssize_t s_len, char* w)");
    if (s_len == 0) {
        //cakelog("\tNew sentence (s_len = [%d]), allocating new char* at end of s of size [%d]", s_len, sizeof(char*));
        *s = malloc(sizeof(char*));
        //cakelog("\tAllocating new string of length [%d] at *s[0]", strlen(w)+1);
        (*s)[0] = malloc(strlen(w)+1);
        //cakelog("\tAssigning [%s] to *s[0]", w);
        (*s)[0] = w;
        return 1;
    }
    else {
        int new_len = s_len + 1;
        //cakelog("\tSentence length is curently [%d], allocating new char* at end of s of size [%ld] bytes", s_len, new_len*sizeof(char*));
        *s = realloc(*s, new_len*sizeof(char*));
        //cakelog("\tAllocating new string of length [%d] at *s[%d]", strlen(w)+1, s_len);
        (*s)[s_len] = malloc(strlen(w)+1);
        //cakelog("\tAssigning word [%s] to s[%d]", w, s_len);
        (*s)[s_len] = w;
        return new_len;
    }
}
 
void test_add_word_to_sentence() {

    //cakelog("test_add_word_to_sentence()");

    char* first = "First";
    char* second = "Second";
    char* third = "Third";
    char* fourth = "Fourth";

    char** s;
    ssize_t s_len = 0;

    //cakelog("Adding [%s] to sentence.", first);

    s_len = add_word_to_sentence(&s, s_len, first);

   // cakelog("Adding [%s] to sentence.", second);

    s_len = add_word_to_sentence(&s, s_len, second);

    //cakelog("Adding [%s] to sentence.", third);

    s_len = add_word_to_sentence(&s, s_len, third);

    //cakelog("Adding [%s] to sentence.", fourth);

    s_len = add_word_to_sentence(&s, s_len, fourth);

    //cakelog("Printing sentence:");

    for(int i=0; i<s_len; i++) {
        //cakelog("\t[%d]:[%s]", i, s[i]);
    }

}


ssize_t add_sentence_to_paragraph(char**** p, ssize_t p_len, char** s) {
    if (p_len == 0) {
        *p = malloc(sizeof(char*));
        (*p)[0] = malloc(sizeof(char*));
        (*p)[0] = s;
        return 1;
    }
    else {
        int new_len = p_len +1;
        *p = realloc(*p, new_len*sizeof(char*));
        (*p)[p_len] = malloc(sizeof(char*));
        (*p)[p_len] = s;
        return new_len;
    }
}

void test_add_sentence_to_paragraph() {
    //cakelog("test_add_word_to_sentence()");

    char* first = "First";
    char* second = "Second";
    char* third = "Third";
    char* fourth = "Fourth";

    char** s;
    ssize_t s1_len = 0;

    s1_len = add_word_to_sentence(&s, s1_len, first);
    s1_len = add_word_to_sentence(&s, s1_len, second);
    s1_len = add_word_to_sentence(&s, s1_len, third);
    s1_len = add_word_to_sentence(&s, s1_len, fourth);

    char* fifth = "Fifth";
    char* sixth = "Sixth";
    char* seventh = "Seventh";
    char* eighth = "Eight";

    char** s2;
    ssize_t s2_len = 0;

    s2_len = add_word_to_sentence(&s2, s2_len, fifth);
    s2_len = add_word_to_sentence(&s2, s2_len, sixth);
    s2_len = add_word_to_sentence(&s2, s2_len, seventh);
    s2_len = add_word_to_sentence(&s2, s2_len, eighth);

    char *** p;
    ssize_t p_len = 0;

    p_len = add_sentence_to_paragraph(&p, p_len, s);

    //cakelog("[%s]", p[0][0]);

    p_len = add_sentence_to_paragraph(&p, p_len, s2);

    //cakelog("[%s]", p[1][2]);

}


ssize_t add_paragraph_to_document(char***** d, ssize_t d_len, char*** p) {
    if (d_len == 0) {
        *d = malloc(sizeof(char*));
        (*d)[0] = malloc(sizeof(char*));
        (*d)[0] = p;
        return 1;
    }
    else {
        int new_len = d_len +1;
        *d = realloc(*d, new_len*sizeof(char*));
        (*d)[d_len] = malloc(sizeof(char*));
        (*d)[d_len] = p;
        return new_len;
    }
}

void test_add_paragraph_to_document() {
    //cakelog("test_add_paragraph_to_document()");

    char* first = "First";
    char* second = "Second";
    char* third = "Third";
    char* fourth = "Fourth";

    char** s;
    ssize_t s1_len = 0;

    s1_len = add_word_to_sentence(&s, s1_len, first);
    s1_len = add_word_to_sentence(&s, s1_len, second);
    s1_len = add_word_to_sentence(&s, s1_len, third);
    s1_len = add_word_to_sentence(&s, s1_len, fourth);

    char* fifth = "Fifth";
    char* sixth = "Sixth";
    char* seventh = "Seventh";
    char* eighth = "Eight";

    char** s2;
    ssize_t s2_len = 0;

    s2_len = add_word_to_sentence(&s2, s2_len, fifth);
    s2_len = add_word_to_sentence(&s2, s2_len, sixth);
    s2_len = add_word_to_sentence(&s2, s2_len, seventh);
    s2_len = add_word_to_sentence(&s2, s2_len, eighth);

    char *** p;
    ssize_t p_len = 0;

    p_len = add_sentence_to_paragraph(&p, p_len, s);
    p_len = add_sentence_to_paragraph(&p, p_len, s2);

    char ****d;
    ssize_t d_len = 0;

    d_len = add_paragraph_to_document(&d, d_len, p);

    //First word of first paragraph
    //cakelog("[%s]", d[0][0][0]);

    d_len = add_paragraph_to_document(&d, d_len, p);

    //cakelog("[%s]", d[1][0][1]);

}


ssize_t extract_words_to_sentence(char*** s, const char *text) {

    int text_cursor = 0;
    int word_start = 0;
    int word_len = 0;
    int s_len = 0;

    while(text[text_cursor++] != '\0') {
        if (text[text_cursor]==' ' || text[text_cursor] == '\0') {
            //cakelog("initialise_words: Found end-of-word at position [%d]", text_cursor);
            word_len = (text_cursor-word_start) + 1;
            //cakelog("initialise_words: Word length is [%d]", word_len);
            char* str = malloc(word_len+1*sizeof(char));
            snprintf(str, word_len, "%s", text+word_start);
            //cakelog("Got textract [%s], building word", str);
            s_len = add_word_to_sentence(&(*s), s_len, str);
            //cakelog("Added word [%s] to sentence (length is now [%d]", str, s_len);
            word_start = text_cursor+1;
        }
    }
    return s_len;
}

ssize_t extract_sentences_to_paragraph(char**** p, const char *text) {
    
    int text_cursor = 0;
    int sentence_start = 0;
    int sentence_len =0;

    int p_len = 0;

    while(text[text_cursor++] != '\0') {
        if (text[text_cursor]=='.' || text[text_cursor] == '\n') {
            //cakelog("initialise_sentences: Found end-of-sentence at position [%d]", text_cursor);
            sentence_len = (text_cursor-sentence_start)+1;
            //cakelog("initialise_sentences: Sentence length is [%d]", sentence_len);
            char* str = malloc(sentence_len+1*sizeof(char));
            snprintf(str, sentence_len, "%s", text+sentence_start);
            //cakelog("initialise_sentences: Pulled sentence [%s]", str);
            char** sentence;
            extract_words_to_sentence(&sentence, str);
            p_len = add_sentence_to_paragraph(&(*p), p_len, sentence);
            sentence_start = text_cursor+1;
        }
    }

    return p_len;
}

ssize_t extract_paragraphs_to_document(char***** d, const char *text) {
    
    int text_cursor = 0;
    int p_start = 0;
    int p_len =0;

    int d_len = 0;

    while(text[text_cursor++] != '\0') {
        if (text[text_cursor]=='\n' || text[text_cursor] == '\0') {
            //cakelog("initialise_paragraphs: Found end-of-paragraph at position [%d]", text_cursor);
            p_len = (text_cursor-p_start) + 1;
            //cakelog("initialise_paragraphs: Paragraph length is [%d]", p_len);
            char* str = malloc(p_len+1*sizeof(char));
            snprintf(str, p_len, "%s", text+p_start);
            //cakelog("initialise_paragraphs: Pulled paragraph [%s]", str);
            char*** paragraph;
            extract_sentences_to_paragraph(&paragraph, str);
            d_len = add_paragraph_to_document(&(*d), d_len, paragraph);
            p_start = text_cursor+1;
        }
    }
    return d_len;
}


void test_extract_sentences_to_paragraph() {

    char* text = "This is a sentence.And so is this one.Okay.\n";
    char***p;
    int p_len = 0;
    p_len = extract_sentences_to_paragraph(&p, text);
    //cakelog("%s",p[0][0]);

}

void test_extract_words_to_a_sentence() {
    char* text = "This is a sentence";

    char** s;
    int s_len = 0;
    s_len = extract_words_to_sentence(&s,text);
}

void test_extract_paragraphs_to_document() {
    char* text = "Hello there.This is a sentence too.\nHere is another sentence on another paragraph.";
    char****d;
    int d_len = 0;
    d_len = extract_paragraphs_to_document(&d, text);
}

char**** get_document(char* text) {

    char****d;
    int d_len = 0;
    d_len = extract_paragraphs_to_document(&d, text);
    return d;

}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}