; Auto-generated. Do not edit!


(cl:in-package robotarminterface-msg)


;//! \htmlinclude stopAllServo.msg.html

(cl:defclass <stopAllServo> (roslisp-msg-protocol:ros-message)
  ((Servo0
    :reader Servo0
    :initarg :Servo0
    :type robotarminterface-msg:servoPosition
    :initform (cl:make-instance 'robotarminterface-msg:servoPosition))
   (Servo1
    :reader Servo1
    :initarg :Servo1
    :type robotarminterface-msg:servoPosition
    :initform (cl:make-instance 'robotarminterface-msg:servoPosition))
   (Servo2
    :reader Servo2
    :initarg :Servo2
    :type robotarminterface-msg:servoPosition
    :initform (cl:make-instance 'robotarminterface-msg:servoPosition))
   (Servo3
    :reader Servo3
    :initarg :Servo3
    :type robotarminterface-msg:servoPosition
    :initform (cl:make-instance 'robotarminterface-msg:servoPosition))
   (Servo4
    :reader Servo4
    :initarg :Servo4
    :type robotarminterface-msg:servoPosition
    :initform (cl:make-instance 'robotarminterface-msg:servoPosition))
   (Servo5
    :reader Servo5
    :initarg :Servo5
    :type robotarminterface-msg:servoPosition
    :initform (cl:make-instance 'robotarminterface-msg:servoPosition)))
)

(cl:defclass stopAllServo (<stopAllServo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <stopAllServo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'stopAllServo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotarminterface-msg:<stopAllServo> is deprecated: use robotarminterface-msg:stopAllServo instead.")))

(cl:ensure-generic-function 'Servo0-val :lambda-list '(m))
(cl:defmethod Servo0-val ((m <stopAllServo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:Servo0-val is deprecated.  Use robotarminterface-msg:Servo0 instead.")
  (Servo0 m))

(cl:ensure-generic-function 'Servo1-val :lambda-list '(m))
(cl:defmethod Servo1-val ((m <stopAllServo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:Servo1-val is deprecated.  Use robotarminterface-msg:Servo1 instead.")
  (Servo1 m))

(cl:ensure-generic-function 'Servo2-val :lambda-list '(m))
(cl:defmethod Servo2-val ((m <stopAllServo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:Servo2-val is deprecated.  Use robotarminterface-msg:Servo2 instead.")
  (Servo2 m))

(cl:ensure-generic-function 'Servo3-val :lambda-list '(m))
(cl:defmethod Servo3-val ((m <stopAllServo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:Servo3-val is deprecated.  Use robotarminterface-msg:Servo3 instead.")
  (Servo3 m))

(cl:ensure-generic-function 'Servo4-val :lambda-list '(m))
(cl:defmethod Servo4-val ((m <stopAllServo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:Servo4-val is deprecated.  Use robotarminterface-msg:Servo4 instead.")
  (Servo4 m))

(cl:ensure-generic-function 'Servo5-val :lambda-list '(m))
(cl:defmethod Servo5-val ((m <stopAllServo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:Servo5-val is deprecated.  Use robotarminterface-msg:Servo5 instead.")
  (Servo5 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <stopAllServo>) ostream)
  "Serializes a message object of type '<stopAllServo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Servo0) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Servo1) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Servo2) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Servo3) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Servo4) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Servo5) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <stopAllServo>) istream)
  "Deserializes a message object of type '<stopAllServo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Servo0) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Servo1) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Servo2) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Servo3) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Servo4) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Servo5) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<stopAllServo>)))
  "Returns string type for a message object of type '<stopAllServo>"
  "robotarminterface/stopAllServo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stopAllServo)))
  "Returns string type for a message object of type 'stopAllServo"
  "robotarminterface/stopAllServo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<stopAllServo>)))
  "Returns md5sum for a message object of type '<stopAllServo>"
  "5ca42d423bd577b7c5ea57f8316de0e6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'stopAllServo)))
  "Returns md5sum for a message object of type 'stopAllServo"
  "5ca42d423bd577b7c5ea57f8316de0e6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<stopAllServo>)))
  "Returns full string definition for message of type '<stopAllServo>"
  (cl:format cl:nil "servoPosition Servo0~%servoPosition Servo1~%servoPosition Servo2~%servoPosition Servo3~%servoPosition Servo4~%servoPosition Servo5~%================================================================================~%MSG: robotarminterface/servoPosition~%uint32 servoId~%uint32 position~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'stopAllServo)))
  "Returns full string definition for message of type 'stopAllServo"
  (cl:format cl:nil "servoPosition Servo0~%servoPosition Servo1~%servoPosition Servo2~%servoPosition Servo3~%servoPosition Servo4~%servoPosition Servo5~%================================================================================~%MSG: robotarminterface/servoPosition~%uint32 servoId~%uint32 position~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <stopAllServo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Servo0))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Servo1))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Servo2))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Servo3))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Servo4))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Servo5))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <stopAllServo>))
  "Converts a ROS message object to a list"
  (cl:list 'stopAllServo
    (cl:cons ':Servo0 (Servo0 msg))
    (cl:cons ':Servo1 (Servo1 msg))
    (cl:cons ':Servo2 (Servo2 msg))
    (cl:cons ':Servo3 (Servo3 msg))
    (cl:cons ':Servo4 (Servo4 msg))
    (cl:cons ':Servo5 (Servo5 msg))
))
