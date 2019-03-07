// Auto-generated. Do not edit!

// (in-package robotarminterface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class stopSingleServo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.servoId = null;
      this.position = null;
    }
    else {
      if (initObj.hasOwnProperty('servoId')) {
        this.servoId = initObj.servoId
      }
      else {
        this.servoId = 0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type stopSingleServo
    // Serialize message field [servoId]
    bufferOffset = _serializer.uint32(obj.servoId, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = _serializer.uint32(obj.position, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type stopSingleServo
    let len;
    let data = new stopSingleServo(null);
    // Deserialize message field [servoId]
    data.servoId = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robotarminterface/stopSingleServo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a23dbe6129c6467805107efe6f32b9f1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 servoId
    uint32 position
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new stopSingleServo(null);
    if (msg.servoId !== undefined) {
      resolved.servoId = msg.servoId;
    }
    else {
      resolved.servoId = 0
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = 0
    }

    return resolved;
    }
};

module.exports = stopSingleServo;
