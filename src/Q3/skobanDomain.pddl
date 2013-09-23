;;Skoban Domain
;;RIP Fall 2013
;;Team X

(define (domain skoban)
  (:requirements :strips)
	(:predicates  (LOCATION ?loc)
								(at ?loc)						;;true if there is a box at location
								(in ?loc)						;;true if robot is at location
								(boxAt ?loc)				;;true if no box at location
								(isLeft ?loc ?loc)	;;true if loc(1) is at left of loc(2)
								(isRight ?loc ?loc)	;;true if loc(1) is at right of loc(2)
								(isUp ?loc ?loc)		;;true if loc(1) is at up of loc(2)
								(isDown ?loc ?loc)	;;true if loc(1) is at down of loc(2)
	)
	;;---------------------
	;; PUSH ACTIONS
	;;---------------------
	(:action PUSH-LEFT
		:parameters
			(?box-loc
			 ?loc
			 ?loc-to)
		:precondition
			(and (in ?loc) (boxAt ?box-loc) (not (boxAt ?loc-to)) 
			 (isLeft ?box-loc ?loc) (isLeft ?loc-to ?box-loc))
		:effect
		  (and (not (in ?loc)) (not (boxAt ?box-loc)) (in ?box-loc) (boxAt ?loc-to))
	)

	(:action PUSH-RIGHT
		:parameters
			(?box-loc
			 ?loc
			 ?loc-to)
		:precondition
			(and (in ?loc) (boxAt ?box-loc) (not (boxAt ?loc-to)) 
			 (isRight ?box-loc ?loc) (isRight ?loc-to ?box-loc))
		:effect
		  (and (not (in ?loc)) (not (boxAt ?box-loc)) (in ?box-loc) (boxAt ?loc-to))
	)

	(:action PUSH-UP
		:parameters
			(?box-loc
			 ?loc
			 ?loc-to)
		:precondition
			(and (in ?loc) (boxAt ?box-loc) (not (boxAt ?loc-to)) 
			 (isUp ?box-loc ?loc) (isUp ?loc-to ?box-loc))
		:effect
		  (and (not (in ?loc)) (not (boxAt ?box-loc)) (in ?box-loc) (boxAt ?loc-to))
	)

	(:action PUSH-DOWN
		:parameters
			(?box-loc
			 ?loc
			 ?loc-to)
		:precondition
			(and (in ?loc) (boxAt ?box-loc) (not (boxAt ?loc-to)) 
			 (isDown ?box-loc ?loc) (isDown ?loc-to ?box-loc))
		:effect
		  (and (not (in ?loc)) (not (boxAt ?box-loc)) (in ?box-loc) (boxAt ?loc-to))
	)

	;;---------------------
	;; MOVE ACTIONS
	;;---------------------

	(:action MOVE-LEFT
		:parameters
			(?loc-to
			 ?loc-from)
		:precondition
			(and (in ?loc-from) (not (boxAt ?loc-to)) (isLeft ?loc-to ?loc-from))
		:effect
			(and (not (in ?loc-from)) (in ?loc-to))
	)

	(:action MOVE-RIGHT
		:parameters
			(?loc-to
			 ?loc-from)
		:precondition
			(and (in ?loc-from) (not (boxAt ?loc-to)) (isRight ?loc-to ?loc-from))
		:effect
			(and (not (in ?loc-from)) (in ?loc-to))
	)

	(:action MOVE-UP
		:parameters
			(?loc-to
			 ?loc-from)
		:precondition
			(and (in ?loc-from) (not (boxAt ?loc-to)) (isUp ?loc-to ?loc-from))
		:effect
			(and (not (in ?loc-from)) (in ?loc-to))
	)

	(:action MOVE-DOWN
		:parameters
			(?loc-to
			 ?loc-from)
		:precondition
			(and (in ?loc-from) (not (boxAt ?loc-to)) (isDown ?loc-to ?loc-from))
		:effect
			(and (not (in ?loc-from)) (in ?loc-to))
	)
)