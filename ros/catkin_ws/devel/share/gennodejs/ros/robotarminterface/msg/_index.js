
"use strict";

let allServo = require('./allServo.js');
let stopSingleServo = require('./stopSingleServo.js');
let stopAllServo = require('./stopAllServo.js');
let singleServo = require('./singleServo.js');
let armPosition = require('./armPosition.js');
let servoPosition = require('./servoPosition.js');

module.exports = {
  allServo: allServo,
  stopSingleServo: stopSingleServo,
  stopAllServo: stopAllServo,
  singleServo: singleServo,
  armPosition: armPosition,
  servoPosition: servoPosition,
};
