#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*fptrSet)(void*, int);
typedef int (*fptrGet)(void*);
typedef void (*fptrDisplay)();

typedef struct _functions{
	fptrSet setX;
	fptrGet getX;
	fptrSet setY;
	fptrGet getY;
	fptrDisplay display;
} vFunctions;

typedef struct _shape{
	vFunctions functions;
	int x;
	int y;
} Shape;

typedef struct _rectangle{
	Shape base;
	int width;
	int height;
} Rectangle;

// Function with shape
void shapeDisplay(Shape *shape){printf("Shape\n");}
void shapeSetX(Shape *shape, int x){ shape->x = x;}
void shapeSetY(Shape *shape, int y){ shape->y = y;}
int shapeGetX(Shape *shape){return shape->x;}
int shapeGetY(Shape *shape){return shape->y;}

// Function with rectangle
void rectangleSetX(Rectangle *rectangle, int x){ rectangle->base.x =x;}
void rectangleSetY(Rectangle *rectangle, int y){ rectangle->base.y =y;}
int rectangleGetX(Rectangle *rectangle){return rectangle->base.x;}
int rectangleGetY(Rectangle *rectangle){return rectangle->base.y;}
void rectangleDisplay(){printf("Rectangle\n");}


Shape* getShapeInstance(){
	Shape *shape = (Shape *)malloc(sizeof(Shape));
	shape->functions.display = shapeDisplay;
	shape->functions.setX = (fptrSet)shapeSetX;
	shape->functions.getX = (fptrGet)shapeGetX;
	shape->functions.setY = (fptrSet)shapeSetY;
	shape->functions.getY = (fptrGet)shapeGetY;
	shape->x = 100;
	shape->y = 100;
	return shape;
}

Rectangle* getRectangleInstance(){
	Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
	rectangle->base.functions.display = rectangleDisplay;
	rectangle->base.functions.setX = (fptrSet)rectangleSetX;
	rectangle->base.functions.getX = (fptrGet)rectangleGetX;
	rectangle->base.functions.setY = (fptrSet)rectangleSetY;
	rectangle->base.functions.getY = (fptrGet)rectangleGetY;
	rectangle->base.x = 200;
	rectangle->base.y = 200;
	rectangle->height = 300;
	rectangle->width = 500;
	return rectangle;
}

int main()
{
	Shape *sptr = getShapeInstance();
	sptr->functions.setX(sptr, 35);
	sptr->functions.display();
	printf("%d\n", sptr->functions.getX(sptr));

	Rectangle *rptr = getRectangleInstance();
	rptr->base.functions.setX(rptr,35);
	rptr->base.functions.display();
	printf("%d\n", rptr->base.functions.getX(rptr));
	
	Shape *shapes[3];
	shapes[0] = getShapeInstance();
	shapes[0]->functions.setX(shapes[0], 35);
	shapes[1] = (Shape*)getRectangleInstance();
	shapes[1]->functions.setX(shapes[1], 45);
	shapes[2] = getShapeInstance();
	shapes[2]->functions.setX(shapes[2], 55);

	for(int i =0; i<3; i++){
		shapes[i]->functions.display();
		printf("%d\n", shapes[i]->functions.getX(shapes[i]));
	}

	printf("%d\n", ((Rectangle*)shapes[1])->width);
	printf("%d\n", ((Rectangle*)shapes[1])->height);
	
	return 0;
}
