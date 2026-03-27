#ifndef POST_H
#define POST_H

typedef struct {
    int id;
    char title[128];
    char content[512];
} Post;

void init_posts();
Post* create_post(const char* title, const char* content);
Post* get_post(int id);
int update_post(int id, const char* title, const char* content);
int delete_post(int id);
char* get_all_posts_json();

#endif
