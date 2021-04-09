#!/usr/bin/node

// prints all characters of a Star Wars movie
const request = require("request");
const ID = process.argv.slice(2, 3);
const URL = `https://swapi-api.hbtn.io/api/films/${ID}`;
const config = {
  url: URL,
  method: "GET",
};

request(config, async function (err, res, body) {
  if (err) {
    return console.log(err);
  }
  const result = JSON.parse(body).characters;
  for (const i in result) {
    await new Promise((resolve, reject) => {
      request(result[i], (err, res, body) => {
        if (err) {
          return console.log(err);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
