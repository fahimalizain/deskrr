# Algo Overview
Tries to describe the behaviour of codes across the project
- [Activity](#activity)

## Activity
Fetching activity optimally is a hard thing. We need to find a way to cache computations for reuse in reports. This document tries to describe the way adopted to save user-activities, hopefully in an efficient manner for reporting.

### Activity Logging
All newly found activities makes the server to store them. Suppose, a user posts interaction of 10min with an application, xchrome.exe that we do not know about, the server logs this appication in `Activity Type` model for the manager/user to modify its properties.

The desktop-monitor app posts activity in fixed interval decided from the server, which is customizable for each organization. 