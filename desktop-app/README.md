# Desktop App
To monitor and send activity logs to the backend.

Targets: Windows (7+), MacOS, Linux

Electron app with std communication with a c++ project targeted at all platforms seperately.

Node Dependencies
* child_process [node-system-module](http://nodejs.org/api/child_process.html) to launch the C++ program as a child process.  [S1](https://stackoverflow.com/questions/5775088/how-to-execute-an-external-program-from-within-node-js)
* node-ipc [npm](https://www.npmjs.com/package/node-ipc) to handle inter process communications
    * [Unix Sockets Eg](https://stackoverflow.com/questions/39841942/communicating-between-nodejs-and-c-using-node-ipc-and-unix-sockets)