# Models

# Table of contents
* [Core Models](#coremodels)
    * [User](#user)
    * [Roles](#roles)
    * [Organization](#org)
    * [Team](#team)
* [Activity Models](#activity)


## Core Models <a name="coremodels"></a>
### User: <a name="user"></a>
```json
{
    email: "",
    firstName: "",
    lastName: "",
    password: "",
}
```
### Roles: <a name="roles"></a>
```json
{
    user: "",
    role: "",
    context: "Organization|Team",
    context_id: "org_a|team_a", 
}
```

### Organisation: <a name="org"></a>
```json
{
    id: "",
    name: ""
}
```
### Team: <a name="team"></a>
```json
{
    id: "",
    name: "",
    org_id: ""
}
```

## Activity Models <a name="activity"></a>
### Activity log:
```json
{
    logId : "",
    timestamp : "",
    user : "",
}

```
### Activity data log:
```json
{
    logId : "",
    activityId : "",
    title: "",
    activityType : "process | website | screenhot |sysInteraction ",
    timespent: "",
    reference: "process.exe | screenshot_url | website urls",
}
```
###
