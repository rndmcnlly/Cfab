
#include "stdio.h"

struct gameobject
{
    void (*display)(struct gameobject *);
};

void gameobject_display(struct gameobject *gameobject)
{
    printf("\n");
}

struct gameobject make_gameobject()
{
    struct gameobject gameobject = {};
    gameobject.display = gameobject_display;
    return gameobject;
}

struct rect
{
    struct gameobject gameobject;
    int x, y, w, h;
};

void rect_display(struct gameobject *gameobject)
{
    gameobject_display(gameobject);
    struct rect *rect = (struct rect *)gameobject;
    printf("rect x,y,w,h: %d,%d,%d,%d\n", rect->x, rect->y, rect->w, rect->h);
}

struct rect make_rect()
{
    struct rect rect = {};
    rect.gameobject = make_gameobject();
    ((struct gameobject *)&rect)->display = rect_display;
    return rect;
}

struct guy
{
    struct rect rect;
    int health;
};

void guy_display(struct gameobject *gameobject)
{
    rect_display(gameobject);
    struct guy *guy = (struct guy *)gameobject;
    printf("guy health: %d\n", guy->health);
}

struct guy make_guy()
{
    struct guy guy = {};
    guy.rect = make_rect();
    ((struct gameobject *)&guy)->display = guy_display;
    return guy;
}

void custom_guy_display(struct gameobject * gameobject)
{
    guy_display(gameobject);
    printf("I'm the special guy!\n");
}

void display(void *ptr)
{
    ((struct gameobject *)ptr)->display(ptr);
}

int main()
{

    struct rect rect1 = make_rect();
    rect1.x = 1;

    struct guy healthy_guy_template = make_guy();
    healthy_guy_template.health = 100;

    struct guy guy1 = healthy_guy_template;
    guy1.rect.x = 2;

    struct guy guy2 = healthy_guy_template;
    guy2.rect.x = 3;

    struct guy guy3 = make_guy();
    guy3.health = 12;
    guy3.rect.x = 4;

    ((struct gameobject*)&guy3)->display = custom_guy_display;
    

    display(&rect1);
    display(&guy1);
    display(&guy2);
    display(&guy3);
}