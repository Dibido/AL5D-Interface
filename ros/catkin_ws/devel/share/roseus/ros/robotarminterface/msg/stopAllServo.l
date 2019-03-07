;; Auto-generated. Do not edit!


(when (boundp 'robotarminterface::stopAllServo)
  (if (not (find-package "ROBOTARMINTERFACE"))
    (make-package "ROBOTARMINTERFACE"))
  (shadow 'stopAllServo (find-package "ROBOTARMINTERFACE")))
(unless (find-package "ROBOTARMINTERFACE::STOPALLSERVO")
  (make-package "ROBOTARMINTERFACE::STOPALLSERVO"))

(in-package "ROS")
;;//! \htmlinclude stopAllServo.msg.html


(defclass robotarminterface::stopAllServo
  :super ros::object
  :slots (_Servo0 _Servo1 _Servo2 _Servo3 _Servo4 _Servo5 ))

(defmethod robotarminterface::stopAllServo
  (:init
   (&key
    ((:Servo0 __Servo0) (instance robotarminterface::servoPosition :init))
    ((:Servo1 __Servo1) (instance robotarminterface::servoPosition :init))
    ((:Servo2 __Servo2) (instance robotarminterface::servoPosition :init))
    ((:Servo3 __Servo3) (instance robotarminterface::servoPosition :init))
    ((:Servo4 __Servo4) (instance robotarminterface::servoPosition :init))
    ((:Servo5 __Servo5) (instance robotarminterface::servoPosition :init))
    )
   (send-super :init)
   (setq _Servo0 __Servo0)
   (setq _Servo1 __Servo1)
   (setq _Servo2 __Servo2)
   (setq _Servo3 __Servo3)
   (setq _Servo4 __Servo4)
   (setq _Servo5 __Servo5)
   self)
  (:Servo0
   (&rest __Servo0)
   (if (keywordp (car __Servo0))
       (send* _Servo0 __Servo0)
     (progn
       (if __Servo0 (setq _Servo0 (car __Servo0)))
       _Servo0)))
  (:Servo1
   (&rest __Servo1)
   (if (keywordp (car __Servo1))
       (send* _Servo1 __Servo1)
     (progn
       (if __Servo1 (setq _Servo1 (car __Servo1)))
       _Servo1)))
  (:Servo2
   (&rest __Servo2)
   (if (keywordp (car __Servo2))
       (send* _Servo2 __Servo2)
     (progn
       (if __Servo2 (setq _Servo2 (car __Servo2)))
       _Servo2)))
  (:Servo3
   (&rest __Servo3)
   (if (keywordp (car __Servo3))
       (send* _Servo3 __Servo3)
     (progn
       (if __Servo3 (setq _Servo3 (car __Servo3)))
       _Servo3)))
  (:Servo4
   (&rest __Servo4)
   (if (keywordp (car __Servo4))
       (send* _Servo4 __Servo4)
     (progn
       (if __Servo4 (setq _Servo4 (car __Servo4)))
       _Servo4)))
  (:Servo5
   (&rest __Servo5)
   (if (keywordp (car __Servo5))
       (send* _Servo5 __Servo5)
     (progn
       (if __Servo5 (setq _Servo5 (car __Servo5)))
       _Servo5)))
  (:serialization-length
   ()
   (+
    ;; robotarminterface/servoPosition _Servo0
    (send _Servo0 :serialization-length)
    ;; robotarminterface/servoPosition _Servo1
    (send _Servo1 :serialization-length)
    ;; robotarminterface/servoPosition _Servo2
    (send _Servo2 :serialization-length)
    ;; robotarminterface/servoPosition _Servo3
    (send _Servo3 :serialization-length)
    ;; robotarminterface/servoPosition _Servo4
    (send _Servo4 :serialization-length)
    ;; robotarminterface/servoPosition _Servo5
    (send _Servo5 :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; robotarminterface/servoPosition _Servo0
       (send _Servo0 :serialize s)
     ;; robotarminterface/servoPosition _Servo1
       (send _Servo1 :serialize s)
     ;; robotarminterface/servoPosition _Servo2
       (send _Servo2 :serialize s)
     ;; robotarminterface/servoPosition _Servo3
       (send _Servo3 :serialize s)
     ;; robotarminterface/servoPosition _Servo4
       (send _Servo4 :serialize s)
     ;; robotarminterface/servoPosition _Servo5
       (send _Servo5 :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; robotarminterface/servoPosition _Servo0
     (send _Servo0 :deserialize buf ptr-) (incf ptr- (send _Servo0 :serialization-length))
   ;; robotarminterface/servoPosition _Servo1
     (send _Servo1 :deserialize buf ptr-) (incf ptr- (send _Servo1 :serialization-length))
   ;; robotarminterface/servoPosition _Servo2
     (send _Servo2 :deserialize buf ptr-) (incf ptr- (send _Servo2 :serialization-length))
   ;; robotarminterface/servoPosition _Servo3
     (send _Servo3 :deserialize buf ptr-) (incf ptr- (send _Servo3 :serialization-length))
   ;; robotarminterface/servoPosition _Servo4
     (send _Servo4 :deserialize buf ptr-) (incf ptr- (send _Servo4 :serialization-length))
   ;; robotarminterface/servoPosition _Servo5
     (send _Servo5 :deserialize buf ptr-) (incf ptr- (send _Servo5 :serialization-length))
   ;;
   self)
  )

(setf (get robotarminterface::stopAllServo :md5sum-) "5ca42d423bd577b7c5ea57f8316de0e6")
(setf (get robotarminterface::stopAllServo :datatype-) "robotarminterface/stopAllServo")
(setf (get robotarminterface::stopAllServo :definition-)
      "servoPosition Servo0
servoPosition Servo1
servoPosition Servo2
servoPosition Servo3
servoPosition Servo4
servoPosition Servo5
================================================================================
MSG: robotarminterface/servoPosition
uint32 servoId
uint32 position
")



(provide :robotarminterface/stopAllServo "5ca42d423bd577b7c5ea57f8316de0e6")


