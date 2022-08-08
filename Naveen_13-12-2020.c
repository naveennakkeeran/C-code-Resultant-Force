/* to calculate the resultant force, magnitude and direction */
#include <stdio.h>
#include <math.h>

float square(float a);

int main (void)
{
    float FNmag,FEmag,FSmag,FWmag;
    float FVmag,FHmag;
    float Fmag,Fdir,Fbear;
    
    printf("This program will calculate the resultant force\n");
    printf("Please enter the magnitude of the force (N) in the North direction: ");
    scanf("%f",&FNmag);
    printf("Please enter the magnitude of the force (N) in the East direction: ");
    scanf("%f",&FEmag);
    printf("Please enter the magnitude of the force (N) in the South direction: ");
    scanf("%f",&FSmag);
    printf("Please enter the magnitude of the force (N) in the West direction: ");
    scanf("%f",&FWmag);
    
    FVmag = FNmag-FSmag;
    FHmag = FEmag-FWmag;
    
    Fmag = sqrt(square(FVmag)+square(FHmag));
    Fdir = atan((FVmag)/(FHmag))*(180/M_PI);
    
    if(FVmag > 0 && FHmag > 0)
    {
        Fbear = 90 - Fdir;
    }
    if(FVmag > 0 && FHmag < 0)
    {
        Fbear = 270 + (-Fdir);
        Fdir += 180;
    }
    if(FVmag < 0 && FHmag < 0)
    {
        Fbear = 270 - Fdir;
        Fdir += 180;
    }
    if(FVmag < 0 && FHmag > 0)
    {
        Fbear = 90 + (-Fdir);
        Fdir += 360;
    }
    
    printf("\nMagnitude of force is %.2f N\n",Fmag);
    printf("Direction of force is %.2f degrees\n",Fdir);
    if(Fbear < 100)
    {
        printf("Bearing of force is 0%.0f\n",Fbear);
    }
    else
    {
        printf("Bearing of force is %.0f\n",Fbear);
    }
    
    return 0;
}

float square(float a)
{
    return a*a;
}
