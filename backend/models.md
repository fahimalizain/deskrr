# Models

# Table of contents
* [Core Models](#coremodels)
    * [User](#user)
    * [Roles](#roles)
    * [Organization](#org)
    * [Team](#team)
- [Activity Models](#activity-models)
    - [Activity](#activity)
    - [Activity Log](#activity-log)
    - [Activity Log Data](#activity-log-data)


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

## Activity Models
### Activity Type
An entity that user is linked with at any point of time. Eg: Idle, Google Chrome etc.

```js
{
    activityId: "12d13rc",
    title: "Google Chrome",
    type: "Process", // Process | Website | Idle
    reference: "chrome.exe", // exe, website_url
}
```

### Activity log:
```js
{
    logId : "",
    timestamp : "",
    user : "",
    activityId: "",
    timespent: "" // seconds
}

```
