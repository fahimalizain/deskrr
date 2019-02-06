const datastore = require("@google-cloud/datastore")({
  projectId: "deskrr"
})
const bcrypt = require('bcrypt');
const saltRounds = 8;
const utils = require('./utils');
const jwt = require('jsonwebtoken');
const fs = require('fs');
const privateKEY  = fs.readFileSync('./private.key', 'utf8');
const checkAuth = utils.checkAuth;

exports.signup = (req, res) => {

  // check for valid fields
  if (!req.body || !req.body.email || !req.body.password || !req.body.lastName || !req.body.firstName) {
    res.sendStatus(400);
    return;
  }

  // building queries
  const query = datastore.createQuery("User").filter('email', req.body.email);
  datastore.runQuery(query)
    .then((data) => {
      if (data && data.length > 0 && data[0].length > 0) {
        return Promise.reject("email-exists");
      }
    }).then(() => {
      const hash = bcrypt.hashSync(req.body.password, 8);
      return datastore.save({
        key: datastore.key("User"),
        data: {
          email: req.body.email,
          password: hash,
          lastName: req.body.lastName,
          firstName: req.body.firstName,
          teams: req.body.teams
        }
      });
    }).then(() => {
      res.send("OK");
    }).catch((e) => {
      res.status(400).send(e || "Failed saving data");
    })
}

exports.login = (req, res) => {
  if (!req.body || !req.body.email || !req.body.password) {
    res.sendStatus(400);
    return;
  }

  const query = datastore.createQuery('User').filter('email', req.body.email);
  datastore.runQuery(query)
    .then((data) => {
      // [[{},{},{}],{Query details}]
      if (data && data.length > 0 && data[0].length > 0) {
        return data[0][0];
      }
      else
        return Promise.reject('User not Present');
    }).then((user) => {
      if (bcrypt.compareSync(req.body.password, user.password)) {
        return user;
      } else {
        return Promise.reject("Wrong credentials");
      }
    }).then((user) => {
      var payload = {
        email: user.email,
        time: utils.getTimestamp()
      };
      var token = jwt.sign(payload, privateKEY);
      res.set('Token',token);
      res.send("OK");
    }).catch((e) => {
      res.status(400).send(e || "Failed login");
    })
}

exports.helloWorld = checkAuth((req, res) => {
  res.send("Hiii");
})