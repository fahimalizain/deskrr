const datastore = require("@google-cloud/datastore")({
    projectId: "deskrr"
})
const bcrypt = require('bcrypt');
const saltRounds = 8;

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
                    firstName: req.body.firstName
                }
            });
        }).then(() => {
            res.send("OK");
        }).catch((e) => {
            res.status(400).send(e || "Failed saving data");
        })
}

exports.login = (req,res) =>{
    if (!req.body || !req.body.email || !req.body.password){
        res.sendStatus(400);
        return;
    }

    const query = datastore.createQuery('User').filter('email', req.body.email);
    datastore.runQuery(query)
        .then((data) => {
            if (data && data.length > 0 && data[0].length > 0){
                return data[0][0];
            }
            else
                return Promise.reject('User not Present');
        }).then((user) => {
            if(bcrypt.compareSync(req.body.password, user.password)) {
                return;
            } else {
                return Promise.reject("Wrong credentials");
            }            
        }).then(() => {
            res.send("OK");
        }).catch((e) => {
            res.status(400).send(e || "Failed login");
        })
}