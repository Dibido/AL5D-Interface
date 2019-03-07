; Auto-generated. Do not edit!


(cl:in-package robotarminterface-msg)


;//! \htmlinclude armPosition.msg.html

(cl:defclass <armPosition> (roslisp-msg-protocol:ros-message)
  ((positionName
    :reader positionName
    :initarg :positionName
    :type cl:string
    :initform "")
   (time
    :reader time
    :initarg :time
    :type cl:integer
    :initform 0))
)

(cl:defclass armPosition (<armPosition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <armPosition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'armPosition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotarminterface-msg:<armPosition> is deprecated: use robotarminterface-msg:armPosition instead.")))

(cl:ensure-generic-function 'positionName-val :lambda-list '(m))
(cl:defmethod positionName-val ((m <armPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:positionName-val is deprecated.  Use robotarminterface-msg:positionName instead.")
  (positionName m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <armPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotarminterface-msg:time-val is deprecated.  Use robotarminterface-msg:time instead.")
  (time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <armPosition>) ostream)
  "Serializes a message object of type '<armPosition>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'positionName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'positionName))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'time)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <armPosition>) istream)
  "Deserializes a message object of type '<armPosition>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'positionName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'positionName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'time)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<armPosition>)))
  "Returns string type for a message object of type '<armPosition>"
  "robotarminterface/armPosition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'armPosition)))
  "Returns string type for a message object of type 'armPosition"
  "robotarminterface/armPosition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<armPosition>)))
  "Returns md5sum for a message object of type '<armPosition>"
  "59ae392b882bffe08a45dc4e0a602b92")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'armPosition)))
  "Returns md5sum for a message object of type 'armPosition"
  "59ae392b882bffe08a45dc4e0a602b92")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<armPosition>)))
  "Returns full string definition for message of type '<armPosition>"
  (cl:format cl:nil "string positionName~%uint32 time~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'armPosition)))
  "Returns full string definition for message of type 'armPosition"
  (cl:format cl:nil "string positionName~%uint32 time~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <armPosition>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'positionName))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <armPosition>))
  "Converts a ROS message object to a list"
  (cl:list 'armPosition
    (cl:cons ':positionName (positionName msg))
    (cl:cons ':time (time msg))
))
