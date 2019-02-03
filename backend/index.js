const datastore = require("@google-cloud/datastore")({
    projectId: "deskrr"
})
const auth = require("./auth.js");
Object.assign(exports, auth);

exports.query = (req, res) => {
    const query = datastore.createQuery('User').filter('teams', '=', 'google');
    datastore.runQuery(query)
        .then((data) =>  {
            res.send(data[0]);
        })

}
