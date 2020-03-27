static double g_gravity (9.8); // restrict direct access to this file only

double getGravity() // this function can be exported to other files to access the global outside of this file
{
    // We could add logic here if needed later
    return g_gravity;
}

// This function can calculate the instant velocity for any gravity value (more useful)
// pass in the return value from getGravity() for parameter gravity if you want to use the global gravity
double instantVelocity(int time, double gravity)
{
    return gravity * time;
}
