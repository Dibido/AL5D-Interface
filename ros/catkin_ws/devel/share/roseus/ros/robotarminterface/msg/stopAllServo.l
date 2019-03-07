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
    ((:Servo0 __Servo0) 0)
    ((:Servo1 __Servo1) 0)
    ((:Servo2 __Servo2) 0)
    ((:Servo3 __Servo3) 0)
    ((:Servo4 __Servo4) 0)
    ((:Servo5 __Servo5) 0)
    )
   (send-super :init)
   (setq _Servo0 (round __Servo0))
   (setq _Servo1 (round __Servo1))
   (setq _Servo2 (round __Servo2))
   (setq _Servo3 (round __Servo3))
   (setq _Servo4 (round __Servo4))
   (setq _Servo5 (round __Servo5))
   self)
  (:Servo0
   (&optional __Servo0)
   (if __Servo0 (setq _Servo0 __Servo0)) _Servo0)
  (:Servo1
   (&optional __Servo1)
   (if __Servo1 (setq _Servo1 __Servo1)) _Servo1)
  (:Servo2
   (&optional __Servo2)
   (if __Servo2 (setq _Servo2 __Servo2)) _Servo2)
  (:Servo3
   (&optional __Servo3)
   (if __Servo3 (setq _Servo3 __Servo3)) _Servo3)
  (:Servo4
   (&optional __Servo4)
   (if __Servo4 (setq _Servo4 __Servo4)) _Servo4)
  (:Servo5
   (&optional __Servo5)
   (if __Servo5 (setq _Servo5 __Servo5)) _Servo5)
  (:serialization-length
   ()
   (+
    ;; uint32 _Servo0
    4
    ;; uint32 _Servo1
    4
    ;; uint32 _Servo2
    4
    ;; uint32 _Servo3
    4
    ;; uint32 _Servo4
    4
    ;; uint32 _Servo5
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _Servo0
       (write-long _Servo0 s)
     ;; uint32 _Servo1
       (write-long _Servo1 s)
     ;; uint32 _Servo2
       (write-long _Servo2 s)
     ;; uint32 _Servo3
       (write-long _Servo3 s)
     ;; uint32 _Servo4
       (write-long _Servo4 s)
     ;; uint32 _Servo5
       (write-long _Servo5 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _Servo0
     (setq _Servo0 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _Servo1
     (setq _Servo1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _Servo2
     (setq _Servo2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _Servo3
     (setq _Servo3 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _Servo4
     (setq _Servo4 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _Servo5
     (setq _Servo5 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get robotarminterface::stopAllServo :md5sum-) "a380ddba3e52984021c096a32dd95ec0")
(setf (get robotarminterface::stopAllServo :datatype-) "robotarminterface/stopAllServo")
(setf (get robotarminterface::stopAllServo :definition-)
      "uint32 Servo0
uint32 Servo1
uint32 Servo2
uint32 Servo3
uint32 Servo4
uint32 Servo5
")



(provide :robotarminterface/stopAllServo "a380ddba3e52984021c096a32dd95ec0")


