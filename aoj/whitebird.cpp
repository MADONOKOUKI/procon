#include <algorithm>
#include <cstdio>
#include <cmath>
#define rep( i, a ) for( int i = 0; i != (a); ++i )
 
const double g = 9.8, EPS = 1e-10;
 
int N, V, X, Y;
int L[50], B[50], R[50], T[50];
 
double calc( double vy, double t )
{
    return vy * t - g * t * t / 2;
}
 
int cmp( double lb, double ub, double a )
{
    return a < lb + EPS ? -1 : a > ub - EPS ? 1 : 0;
}
 
bool check( double qx, double qy )
{
    double a = g * g / 4, b = g * qy - V * V, c = qx * qx + qy * qy;
    double D = b * b - 4 * a * c;
    if( D < 0 && D > -EPS )
        D = 0;
    if( D < 0 )
        return false;
 
    for( int d = -1; d != 1; d += 2 )
    {
        double t2 = ( -b + d * sqrt( D ) ) / ( 2 * a );
        if( t2 <= 0 )
            continue;
        double t = sqrt( t2 );
        double vx = qx / t, vy = ( qy + g * t * t / 2 ) / t;
 double yt = calc( vy, X / vx );
        if( yt < Y - EPS )
            continue;
 
        bool fl = true;
        rep( i, N )
        {
            if( L[i] >= X )
                continue;
            if( R[i] == X && Y <= T[i] && B[i] <= yt )
                fl = false;
            int yL = cmp( B[i], T[i], calc( vy, L[i] / vx ) );
            int yR = cmp( B[i], T[i], calc( vy, R[i] / vx ) );
            int xH = cmp( L[i], R[i], vx * ( vy / g ) );
            int yH = cmp( B[i], T[i], calc( vy, vy / g ) );
            if( xH == 0 && yH >= 0 && yL < 0 )
                fl = false;
            if( yL * yR <= 0 )
                fl = false;
        }
 
        if( fl )
            return true;
    }
 
    return false;
}

int main()
{
    scanf( "%d %d %d %d", &N, &V, &X, &Y );
    rep( i, N )
    {
        scanf( "%d %d %d %d", L + i, B + i, R + i, T + i );
        R[i] = std::min( R[i], X );
    }
 
    bool fl = check( X, Y );
    rep( i, N )
    {
        fl |= check( L[i], T[i] );
        fl |= check( R[i], T[i] );
    }
 
    puts( fl ? "Yes" : "No" );
 
    return 0;
}