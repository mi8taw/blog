#include "post.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_POSTS 100

static Post posts[MAX_POSTS];
static int count = 0;
static int next_id = 1;

void init_posts() {
    count = 0;
    next_id = 1;
}

Post* create_post(const char* title, const char* content) {
    if (count >= MAX_POSTS) return NULL;

    Post* p = &posts[count++];
    p->id = next_id++;
    strncpy(p->title, title, sizeof(p->title));
    strncpy(p->content, content, sizeof(p->content));
    return p;
}

Post* get_post(int id) {
    for (int i = 0; i < count; i++)
        if (posts[i].id == id) return &posts[i];
    return NULL;
}

int update_post(int id, const char* title, const char* content) {
    Post* p = get_post(id);
    if (!p) return 0;

    strncpy(p->title, title, sizeof(p->title));
    strncpy(p->content, content, sizeof(p->content));
    return 1;
}

int delete_post(int id) {
    for (int i = 0; i < count; i++) {
        if (posts[i].id == id) {
            for (int j = i; j < count - 1; j++)
                posts[j] = posts[j + 1];
            count--;
            return 1;
        }
    }
    return 0;
}

char* get_all_posts_json() {
    char* buffer = malloc(4096);
    strcpy(buffer, "[");

    for (int i = 0; i < count; i++) {
        char temp[700];
        sprintf(temp,
            "{\"id\":%d,\"title\":\"%s\",\"content\":\"%s\"}%s",
            posts[i].id,
            posts[i].title,
            posts[i].content,
            (i < count - 1) ? "," : ""
        );
        strcat(buffer, temp);
    }

    strcat(buffer, "]");
    return buffer;
}
