#include<string.h>
#include<math.h>
struct distance
{
    int x;
    int y;
} p1, p2, p3;
int main()
{
    float d, dis;
    printf("Enter the coordinates of first point");
    scanf("%d%d",&p1.x,&p1.y);
    printf("Enter the coordinates of second point");
    scanf("%d%d",&p2.x,&p2.y);
//d=√((y2-y1)^2+(x2-x1)^2)
    p3.x=p2.x-p1.x;
    p3.y=p2.y-p1.y;
    printf("points %d %d",p3.x,p3.y);
    dis=(pow(p3.y,2)+pow(p3.x,2));
    d=sqrt(dis);
    printf("\nDistance is %f ",d);
}