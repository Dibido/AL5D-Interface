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

class ServoFeedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pulsewidth = null;
    }
    else {
      if (initObj.hasOwnProperty('pulsewidth')) {
        this.pulsewidth = initObj.pulsewidth
      }
      else {
        this.pulsewidth = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ServoFeedback
    // Serialize message field [pulsewidth]
    bufferOffset = _serializer.uint16(obj.pulsewidth, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ServoFeedback
    let len;
    let data = new ServoFeedback(null);
    // Deserialize message field [pulsewidth]
    data.pulsewidth = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robotarminterface/ServoFeedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1930e8bfd98a1ac05b9f850d8f71dbbc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    #feedback
    uint16 pulsewidth
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ServoFeedback(null);
    if (msg.pulsewidth !== undefined) {
      resolved.pulsewidth = msg.pulsewidth;
    }
    else {
      resolved.pulsewidth = 0
    }

    return resolved;
    }
};

module.exports = ServoFeedback;
