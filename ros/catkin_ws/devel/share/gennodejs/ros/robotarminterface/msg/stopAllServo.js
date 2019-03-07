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

class stopAllServo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Servo0 = null;
      this.Servo1 = null;
      this.Servo2 = null;
      this.Servo3 = null;
      this.Servo4 = null;
      this.Servo5 = null;
    }
    else {
      if (initObj.hasOwnProperty('Servo0')) {
        this.Servo0 = initObj.Servo0
      }
      else {
        this.Servo0 = 0;
      }
      if (initObj.hasOwnProperty('Servo1')) {
        this.Servo1 = initObj.Servo1
      }
      else {
        this.Servo1 = 0;
      }
      if (initObj.hasOwnProperty('Servo2')) {
        this.Servo2 = initObj.Servo2
      }
      else {
        this.Servo2 = 0;
      }
      if (initObj.hasOwnProperty('Servo3')) {
        this.Servo3 = initObj.Servo3
      }
      else {
        this.Servo3 = 0;
      }
      if (initObj.hasOwnProperty('Servo4')) {
        this.Servo4 = initObj.Servo4
      }
      else {
        this.Servo4 = 0;
      }
      if (initObj.hasOwnProperty('Servo5')) {
        this.Servo5 = initObj.Servo5
      }
      else {
        this.Servo5 = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type stopAllServo
    // Serialize message field [Servo0]
    bufferOffset = _serializer.uint32(obj.Servo0, buffer, bufferOffset);
    // Serialize message field [Servo1]
    bufferOffset = _serializer.uint32(obj.Servo1, buffer, bufferOffset);
    // Serialize message field [Servo2]
    bufferOffset = _serializer.uint32(obj.Servo2, buffer, bufferOffset);
    // Serialize message field [Servo3]
    bufferOffset = _serializer.uint32(obj.Servo3, buffer, bufferOffset);
    // Serialize message field [Servo4]
    bufferOffset = _serializer.uint32(obj.Servo4, buffer, bufferOffset);
    // Serialize message field [Servo5]
    bufferOffset = _serializer.uint32(obj.Servo5, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type stopAllServo
    let len;
    let data = new stopAllServo(null);
    // Deserialize message field [Servo0]
    data.Servo0 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Servo1]
    data.Servo1 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Servo2]
    data.Servo2 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Servo3]
    data.Servo3 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Servo4]
    data.Servo4 = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [Servo5]
    data.Servo5 = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robotarminterface/stopAllServo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a380ddba3e52984021c096a32dd95ec0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 Servo0
    uint32 Servo1
    uint32 Servo2
    uint32 Servo3
    uint32 Servo4
    uint32 Servo5
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new stopAllServo(null);
    if (msg.Servo0 !== undefined) {
      resolved.Servo0 = msg.Servo0;
    }
    else {
      resolved.Servo0 = 0
    }

    if (msg.Servo1 !== undefined) {
      resolved.Servo1 = msg.Servo1;
    }
    else {
      resolved.Servo1 = 0
    }

    if (msg.Servo2 !== undefined) {
      resolved.Servo2 = msg.Servo2;
    }
    else {
      resolved.Servo2 = 0
    }

    if (msg.Servo3 !== undefined) {
      resolved.Servo3 = msg.Servo3;
    }
    else {
      resolved.Servo3 = 0
    }

    if (msg.Servo4 !== undefined) {
      resolved.Servo4 = msg.Servo4;
    }
    else {
      resolved.Servo4 = 0
    }

    if (msg.Servo5 !== undefined) {
      resolved.Servo5 = msg.Servo5;
    }
    else {
      resolved.Servo5 = 0
    }

    return resolved;
    }
};

module.exports = stopAllServo;
