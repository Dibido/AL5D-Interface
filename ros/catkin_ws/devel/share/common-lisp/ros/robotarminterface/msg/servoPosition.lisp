; Auto-generated. Do not edit!


(cl:in-package robotarminterface-msg)


;//! \htmlinclude servoPosition.msg.html

(cl:defclass <servoPosition> (roslisp-msg-protocol:ros-message)
  ((servoId
    :reader servoId
    :initarg :servoId
    :type cl:integer
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0))
)

(cl:defclass servoPosition (<servoPosition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servoPosition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servoPosition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotarminterface-msg:<servoPosition> is deprecated: use robotarminterface-msg:servoPosition instead.")))

(cl:ensure-generic-function 'servoId-val :lambda-list '(m))
(cl:defmethod servoId-val ((m <servoPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:servoId-val is deprecated.  Use robotarminterface-msg:servoId instead.")
  (servoId m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <servoPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:position-val is deprecated.  Use robotarminterface-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servoPosition>) ostream)
  "Serializes a message object of type '<servoPosition>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'servoId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'servoId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'servoId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'servoId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'position)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servoPosition>) istream)
  "Deserializes a message object of type '<servoPosition>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'servoId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'servoId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'servoId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'servoId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'position)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servoPosition>)))
  "Returns string type for a message object of type '<servoPosition>"
  "robotarminterface/servoPosition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servoPosition)))
  "Returns string type for a message object of type 'servoPosition"
  "robotarminterface/servoPosition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servoPosition>)))
  "Returns md5sum for a message object of type '<servoPosition>"
  "a23dbe6129c6467805107efe6f32b9f1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servoPosition)))
  "Returns md5sum for a message object of type 'servoPosition"
  "a23dbe6129c6467805107efe6f32b9f1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servoPosition>)))
  "Returns full string definition for message of type '<servoPosition>"
  (cl:format cl:nil "uint32 servoId~%uint32 position~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servoPosition)))
  "Returns full string definition for message of type 'servoPosition"
  (cl:format cl:nil "uint32 servoId~%uint32 position~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servoPosition>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servoPosition>))
  "Converts a ROS message object to a list"
  (cl:list 'servoPosition
    (cl:cons ':servoId (servoId msg))
    (cl:cons ':position (position msg))
))
