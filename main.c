#include <stdio.h>
#include <math.h>
#include <string.h>

#define CIRCLE_COUNT 2
#define CONST_PI 3.141592

typedef struct circle_s
{
	float x, y;
	float radius;
} circle_t;

typedef enum intersection_cases_e
{
	NO_INTR_PT = 0,
	CRL_INSIDE, /* one of circles inside */
	INTR_PTS, /* 1 or 2 intersection points (generic case) */
	TWO_INTR_PT, 
	ONE_INTR_PT,
	CRL_COINCIDE
} intersection_cases_t;

circle_t circles[CIRCLE_COUNT] = {0};

float circle_area (unsigned int idx)
{
	return (float) (circles[idx].radius * circles[idx].radius * CONST_PI);
}

float calc_cartesian_distance (float x1, float y1, float x2, float y2)
{
	return  sqrt( ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2) ));
}

intersection_cases_t check_circles_intersections (unsigned int idx1, unsigned int idx2)
{
	int dstc = -1;
	
	/* Set idxs from user vision to real one */
	idx1--;
	idx2--;
	
	float x1 = circles[idx1].x,
		y1 = circles[idx1].y,
		x2 = circles[idx2].x,
		y2 = circles[idx2].y,
		r1 = circles[idx1].radius,
		r2 = circles[idx2].radius;
	//printf ("\ndbg::: %f %f %f %f\n", x1, x2, y1, y2);
	if (idx1 == idx2)
		return CRL_COINCIDE;
	
	dstc = calc_cartesian_distance (x1, y1, x2, y2);
	//printf ("\ndbg::: %d\n", dstc);
	if ( (dstc == 0) && ( (int)r1 == (int)r2 ) )
		return CRL_COINCIDE;
	else if (dstc > (int)(r1 + r2))
		return NO_INTR_PT;
	else if (dstc < abs(r1 - r2) )
		return CRL_INSIDE;
	
	/* Here calculates intersection points... */
	return INTR_PTS;

}

void proc_cmd_2 ()
{
	unsigned int idx1, idx2;
	
	if (circles[0].radius == 0) /* no circles */
	{
		printf ("No circles exist\n");
		return;
	}
	
	printf ("Enter circles indexes to check intersection\n>> ");
	scanf ("%u %u", &idx1, &idx2);
	
	if (idx1 >= CIRCLE_COUNT && idx2 >= CIRCLE_COUNT )
	{
		printf ("Invalid idx\n");
		return;
	}
	
	printf ("\nResult: circles %u and %u ", idx1, idx2);
	switch ( check_circles_intersections (idx1, idx2) )
	{
		case CRL_COINCIDE:
			printf ("coincide\n");
			break;
		case NO_INTR_PT:
		case CRL_INSIDE:
			printf ("have no intersection points\n");
			break;
		case INTR_PTS:
			printf ("have 1 or 2 intersection points\n");
			break;
		
		default:
			printf ("N/A\n");
	}

}

void proc_cmd_1 ()
{
	printf ("Setting circles (%d)\n", CIRCLE_COUNT +1);
	for (int i = 0; i < CIRCLE_COUNT; i++)
	{
		circle_t tmp;

		printf ("#%d.x << ", i+1);
		scanf ("%f", &tmp.x);

		printf ("#%d.y << ", i+1);
		scanf ("%f", &tmp.y);

		printf ("#%d.radius << ", i+1);
		scanf ("%f", &tmp.radius);

		if (tmp.radius <= 0)
		{
			printf ("Invalid #%d.radius. Abort", i+1);
			memset (circles, 0, sizeof(circle_t) * CIRCLE_COUNT);
			return;
		}

		circles[i] = tmp;
	}
}

int proc_cmd (char cmd)
{
	switch (cmd)
	{
		case '1':
			proc_cmd_1 ();
			break;
		case '2':
			proc_cmd_2 ();
			break;
		default:
			return 1;
	}
	return 0;
}

void print_circle (unsigned int idx)
{
	if (idx >= CIRCLE_COUNT)
	{
		printf ("Invalid idx\n");
		return;	
	}

	printf ("circle #%d:\n"
			"\tX      = %f\n"
			"\tY      = %f\n"
			"\tRadius = %f\n"
			"\tArea   = %f\n",
			idx+1, circles[idx].x,
			circles[idx].y, circles[idx].radius,
			circle_area (idx)
	);
}

int main()
{
    char cmd = '\0';
    char cmds[8] = {0};
	
	printf ("Lab#1: geometry\nDaria Lenshina (IP-112 group)\n\n");
	
	while (1)
	{
		if (circles[0].radius != 0) /* if circles exists*/
		{
			for (int idx = 0; idx < CIRCLE_COUNT; idx++)
				print_circle (idx);
		}

		printf ("Please choose action:\n"
				"(0) Exit\n"
				"(1) Set circles (available %d)\n" /* proc_cmd_1 */
				"(2) Check circles's intersection\n>> ", /* proc_cmd_2 */
				CIRCLE_COUNT
		);

		scanf ("%s", cmds);
		sscanf (cmds, "%c", &cmd);
		
		if (cmd != '0')
			printf ("%s\n", proc_cmd (cmd) ? "Unavailable action\n\n" : "\n\n");
		else 
			break;
	}
	return 0;
}
