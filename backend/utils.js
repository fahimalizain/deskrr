const jwt = require('jsonwebtoken');
const fs = require('fs');
const privateKEY  = fs.readFileSync('./private.key', 'utf8');

exports.getPrivateKey = () => { return privateKEY; }

exports.getTimestamp = (req,res) => {
    return Date.now() / 1000;
}

exports.checkAuth = (fn) => {
    return function (req, res) {
      if (!req.headers || !req.headers.authorization) {
        res.status(401).send('No authorization token found.');
        return;
      }
      // expect authorization header to be
      // Bearer xxx-token-xxx
      const parts = req.headers.authorization.split(' ');
      if (parts.length != 2) {
        res.status(401).send('Bad credential format.');
        return;
      }
      const scheme = parts[0];
      const credentials = parts[1];
  
      if (!/^Bearer$/i.test(scheme)) {
        res.status(401).send('Bad credential format.');
        return;
      }
  
      try {
        const data = jwt.verify(credentials,privateKEY);
        fn(req, res);
      } catch(e) {
        res.status(401).send('Invalid token');
      }
    }
  }