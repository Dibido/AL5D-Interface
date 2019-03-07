;; Auto-generated. Do not edit!


(when (boundp 'robotarminterface::armPosition)
  (if (not (find-package "ROBOTARMINTERFACE"))
    (make-package "ROBOTARMINTERFACE"))
  (shadow 'armPosition (find-package "ROBOTARMINTERFACE")))
(unless (find-package "ROBOTARMINTERFACE::ARMPOSITION")
  (make-package "ROBOTARMINTERFACE::ARMPOSITION"))

(in-package "ROS")
;;//! \htmlinclude armPosition.msg.html


(defclass robotarminterface::armPosition
  :super ros::object
  :slots (_positionName _time ))

(defmethod robotarminterface::armPosition
  (:init
   (&key
    ((:positionName __positionName) "")
    ((:time __time) 0)
    )
   (send-super :init)
   (setq _positionName (string __positionName))
   (setq _time (round __time))
   self)
  (:positionName
   (&optional __positionName)
   (if __positionName (setq _positionName __positionName)) _positionName)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:serialization-length
   ()
   (+
    ;; string _positionName
    4 (length _positionName)
    ;; uint32 _time
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _positionName
       (write-long (length _positionName) s) (princ _positionName s)
     ;; uint32 _time
       (write-long _time s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _positionName
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _positionName (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint32 _time
     (setq _time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get robotarminterface::armPosition :md5sum-) "59ae392b882bffe08a45dc4e0a602b92")
(setf (get robotarminterface::armPosition :datatype-) "robotarminterface/armPosition")
(setf (get robotarminterface::armPosition :definition-)
      "string positionName
uint32 time
")



(provide :robotarminterface/armPosition "59ae392b882bffe08a45dc4e0a602b92")


