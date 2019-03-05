
(cl:in-package :asdf)

(defsystem "robotarminterface-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "robotarm" :depends-on ("_package_robotarm"))
    (:file "_package_robotarm" :depends-on ("_package"))
  ))