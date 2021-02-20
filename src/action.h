#ifndef ACTION_H
#define ACTION_H
typedef struct Action{
	double (*action_do)(struct Action *);
}Action;

#endif // ACTION_H
