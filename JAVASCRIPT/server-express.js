const express = require('express');

const app = express();

app.get('/', (req, res) => {
	res.send('Hello world!');
});

app.get('/about', (req, res) => {
	res.send('About!');
});

app.listen('8585', 'localhost', err => {
	console.log('Listening on localhost:8585');
});