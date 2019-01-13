const datastore = require("@google-cloud/datastore")({
    projectId: "deskrr"
})

exports.signup = (req, res) => {
    datastore.save({
        key: datastore.key("User"),
        data: {
            email: req.body.email,
            password: req.body.password,
            lastName: req.body.lastName,
            firstName: req.body.firstName
        }
    }).then(() => {
        res.send("OK");
    }).catch(() => {
        res.status(400).send("Failed saving data");
    })
}