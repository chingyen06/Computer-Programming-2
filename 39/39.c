#include <stdio.h>
#include <string.h>
#include <math.h>
#define ShapeText(TYPE) char name[10]; \
double (*perimeter)(struct TYPE*); \
double (*area)(struct TYPE*);

typedef struct shape_s {
    ShapeText(shape_s);
} shape_t;

typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} circle_t;

typedef struct rectangle_s {
    ShapeText(rectangle_s);
    double length, width;
} rectangle_t;

typedef struct square_s {
    ShapeText(square_s);
    double edge;
} square_t;

typedef struct triangle_s {
    ShapeText(triangle_s);
    double edge[3];
} triangle_t;

double circle_perimeter(circle_t *c)
{
    return 2 * 3.14 * c->radius;
}

double circle_area(circle_t *c)
{
    return 3.14 * c->radius * c->radius;
}

double rectangle_perimeter(rectangle_t *r)
{
    return 2 * (r->length + r->width);
}

double rectangle_area(rectangle_t *r)
{
    return r->length * r->width;
}

double square_perimeter(square_t *s)
{
    return 4 * s->edge;
}

double square_area(square_t *s)
{
    return s->edge * s->edge;
}

double triangle_perimeter(triangle_t *t)
{
    return t->edge[0] + t->edge[1] + t->edge[2];
}

double triangle_area(triangle_t *t)
{
    int i;
    double s = (t->edge[0] + t->edge[1] + t->edge[2]) / 2.0;
    double ans = s;

    for (i=0;i<3;i++)
        ans *= s - t->edge[i];

    return sqrtf(ans);
}

int main()
{
    int i, n;
    double p, a, t_p = 0, t_a = 0;
    shape_t shape;
    circle_t circle;
    rectangle_t rectangle;
    square_t square;
    triangle_t triangle;

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf("%s", shape.name);

        if (strcmp(shape.name, "C") == 0) {
            strcpy(circle.name, shape.name);
            scanf("%lf", &circle.radius);

            circle.perimeter = circle_perimeter;
            circle.area = circle_area;

            p = circle.perimeter(&circle);
            a = circle.area(&circle);
        }
        else if (strcmp(shape.name, "R") == 0) {
            strcpy(rectangle.name, shape.name);
            scanf("%lf %lf", &rectangle.length, &rectangle.width);

            rectangle.perimeter = rectangle_perimeter;
            rectangle.area = rectangle_area;

            p = rectangle.perimeter(&rectangle);
            a = rectangle.area(&rectangle);
        }
        else if (strcmp(shape.name, "S") == 0) {
            strcpy(square.name, shape.name);
            scanf("%lf", &square.edge);

            square.perimeter = square_perimeter;
            square.area = square_area;

            p = square.perimeter(&square);
            a = square.area(&square);
        }
        else {
            strcpy(triangle.name, shape.name);
            scanf("%lf %lf %lf", &triangle.edge[0], &triangle.edge[1], &triangle.edge[2]);

            triangle.perimeter = triangle_perimeter;
            triangle.area = triangle_area;

            p = triangle.perimeter(&triangle);
            a = triangle.area(&triangle);
        }

        t_p += p;
        t_a += a;

        printf("%.2lf %.2lf\n", p, a);
    }

    printf("%.2lf %.2lf\n", t_p, t_a);

    return 0;
}
