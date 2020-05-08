#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
#include <sys/types.h>

struct word new_word(char * data) {
    struct word w;
    w.data = data;
    return w;
}

struct sentence new_sentence(struct word* data, int word_count) {
    struct sentence s;
    s.data = data;
    s.word_count = word_count;
    return s;
};

struct paragraph new_paragraph(struct sentence* data, int sentence_count) {
    struct paragraph p;
    p.data = data;
    p.sentence_count = sentence_count;
    return p;
}

struct document new_document(struct paragraph* data, int paragraph_count) {
    struct document d;
    d.data = data;
    d.paragraph_count = paragraph_count;
    return d;
};

ssize_t add_word_to_list(struct word** wlist, const ssize_t size, const struct word* w) {

    if (size == 0) {
        *wlist = malloc(sizeof(*w));
        (*wlist)[0] = *w;
        return 1;
    }
    else {
        int new_size = size+1;
        *wlist = realloc(*wlist, new_size*sizeof(*w));
        (*wlist)[size] = *w;
        return new_size;
    }
}

ssize_t add_sentence_to_list(struct sentence** slist, const ssize_t size, const struct sentence* s) {

    if (size == 0) {
        *slist = malloc(sizeof(*s));
        (*slist)[0] = *s;
        return 1;
    }
    else {
        int new_size = size+1;
        *slist = realloc(*slist, new_size*sizeof(*s));
        (*slist)[size] = *s;
        return new_size;
    }
}

ssize_t add_paragraph_to_list(struct paragraph** plist, const ssize_t size, const struct paragraph* p) {

    if (size == 0) {
        *plist = malloc(sizeof(*p));
        (*plist)[0] = *p;
        return 1;
    }
    else {
        int new_size = size+1;
        *plist = realloc(*plist, new_size*sizeof(*p));
        (*plist)[size] = *p;
        return new_size;
    }
}

ssize_t initialise_words(struct word** wlist, const char *text) {

    ssize_t wlist_size = 0;

    int text_cursor = 0;
    int word_start = 0;
    int word_len = 0;

    while(text[text_cursor++] != '\0') {
        if (text[text_cursor]==' ' || text[text_cursor] == '\0') {
            //cakelog("initialise_words: Found end-of-word at position [%d]", text_cursor);
            word_len = (text_cursor-word_start) + 1;
            //cakelog("initialise_words: Word length is [%d]", word_len);
            char* str = malloc(word_len+1*sizeof(char));
            snprintf(str, word_len, "%s", text+word_start);
            //cakelog("Got textract [%s], building word", str);
            struct word w = new_word(str);
            //cakelog("Built word, adding to list");
            wlist_size = add_word_to_list((&(*wlist)), wlist_size, &w);
            word_start = text_cursor+1;
        }
    }

    return wlist_size;
}

ssize_t initialise_sentences(struct sentence** slist, const char *text) {
    
    ssize_t slist_size = 0;

    int text_cursor = 0;
    int sentence_start = 0;
    int sentence_len =0;

    struct word* wlist;
    int word_count = 0;

    while(text[text_cursor++] != '\0') {
        if (text[text_cursor]=='.' || text[text_cursor] == '\n') {
            //cakelog("initialise_sentences: Found end-of-sentence at position [%d]", text_cursor);
            sentence_len = (text_cursor-sentence_start)+1;
            //cakelog("initialise_sentences: Sentence length is [%d]", sentence_len);
            char* str = malloc(sentence_len+1*sizeof(char));
            snprintf(str, sentence_len, "%s", text+sentence_start);
            //cakelog("Pulled sentence [%s]", str);
            word_count = initialise_words(&wlist, str);
            struct sentence s = new_sentence(wlist, word_count);
            //cakelog("Built sentence");
            slist_size = add_sentence_to_list((&(*slist)), slist_size, &s);
            sentence_start += text_cursor+1;
        }
    }

    return slist_size;
}

ssize_t initialise_paragraphs(struct paragraph** plist, const char* text) {

    ssize_t plist_size = 0;

    int text_cursor = 0;
    int p_start = 0;
    int p_len =0;

    struct sentence* slist;
    int s_count = 0;

    while(text[text_cursor++] != '\0') {
        if (text[text_cursor]=='\n' || text[text_cursor] == '\0') {
            //cakelog("initialise_paragraphs: Found end-of-paragraph at position [%d]", text_cursor);
            p_len = (text_cursor-p_start) + 1;
            //cakelog("initialise_paragraphs: Paragraph length is [%d]", p_len);
            char* str = malloc(p_len+1*sizeof(char));
            snprintf(str, p_len, "%s", text+p_start);
            //cakelog("initialise_paragraphs: Pulled paragraph [%s]", str);
            s_count = initialise_sentences(&slist, str);
            struct paragraph p = new_paragraph(slist, s_count);
            //cakelog("initialise_paragraphs: Built paragraph with [%d] sentences", s_count);
            plist_size = add_paragraph_to_list((&(*plist)), plist_size, &p);
            p_start += text_cursor+1;
        }
    }

    return plist_size;
}

struct document Doc;

void initialise_document(char * text) {

    struct paragraph* plist = NULL;
    ssize_t plist_count = 0;

    plist_count = initialise_paragraphs(&plist, text);
    Doc = new_document(plist, plist_count);

}


struct document get_document(char* text) {
    struct paragraph* plist = NULL;
    ssize_t plist_count = 0;

    plist_count = initialise_paragraphs(&plist, text);
    Doc = new_document(plist, plist_count);
    return Doc;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc,int k, int m) {
    return Doc.data[m-1].data[k-1];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc,int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}



void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}