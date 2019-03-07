
(cl:in-package :asdf)

(defsystem "robotarminterface-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "allServo" :depends-on ("_package_allServo"))
    (:file "_package_allServo" :depends-on ("_package"))
    (:file "armPosition" :depends-on ("_package_armPosition"))
    (:file "_package_armPosition" :depends-on ("_package"))
    (:file "servoPosition" :depends-on ("_package_servoPosition"))
    (:file "_package_servoPosition" :depends-on ("_package"))
    (:file "singleServo" :depends-on ("_package_singleServo"))
    (:file "_package_singleServo" :depends-on ("_package"))
    (:file "stopAllServo" :depends-on ("_package_stopAllServo"))
    (:file "_package_stopAllServo" :depends-on ("_package"))
    (:file "stopSingleServo" :depends-on ("_package_stopSingleServo"))
    (:file "_package_stopSingleServo" :depends-on ("_package"))
  ))