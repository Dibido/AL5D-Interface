; Auto-generated. Do not edit!


(cl:in-package robotarminterface-msg)


;//! \htmlinclude ServoResult.msg.html

(cl:defclass <ServoResult> (roslisp-msg-protocol:ros-message)
  ((pulsewidth
    :reader pulsewidth
    :initarg :pulsewidth
    :type cl:fixnum
    :initform 0))
)

(cl:defclass ServoResult (<ServoResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServoResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServoResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotarminterface-msg:<ServoResult> is deprecated: use robotarminterface-msg:ServoResult instead.")))

(cl:ensure-generic-function 'pulsewidth-val :lambda-list '(m))
(cl:defmethod pulsewidth-val ((m <ServoResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:pulsewidth-val is deprecated.  Use robotarminterface-msg:pulsewidth instead.")
  (pulsewidth m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServoResult>) ostream)
  "Serializes a message object of type '<ServoResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pulsewidth)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pulsewidth)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServoResult>) istream)
  "Deserializes a message object of type '<ServoResult>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pulsewidth)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pulsewidth)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServoResult>)))
  "Returns string type for a message object of type '<ServoResult>"
  "robotarminterface/ServoResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoResult)))
  "Returns string type for a message object of type 'ServoResult"
  "robotarminterface/ServoResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServoResult>)))
  "Returns md5sum for a message object of type '<ServoResult>"
  "1930e8bfd98a1ac05b9f850d8f71dbbc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServoResult)))
  "Returns md5sum for a message object of type 'ServoResult"
  "1930e8bfd98a1ac05b9f850d8f71dbbc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServoResult>)))
  "Returns full string definition for message of type '<ServoResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%uint16 pulsewidth~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServoResult)))
  "Returns full string definition for message of type 'ServoResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%uint16 pulsewidth~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServoResult>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServoResult>))
  "Converts a ROS message object to a list"
  (cl:list 'ServoResult
    (cl:cons ':pulsewidth (pulsewidth msg))
))
