;;Problem 2.1 Definition
;;RIP Fall 2013
;;Team X

(define (problem skoban-2-1)
	(:domain skoban)
	(:objects
		locationA
		locationB
		locationC
		locationD
		locationE
		locationF
		locationG
		locationH)

	(:init
		(LOCATION locationA)
		(LOCATION locationB)
		(LOCATION locationC)
		(LOCATION locationD)
		(LOCATION locationE)
		(LOCATION locationF)
		(LOCATION locationG)
		(LOCATION locationH)

		(isLeft locationA locationB)
		(isLeft locationB locationC)
		(isLeft locationC locationD)
		(isLeft locationE locationF)
		(isLeft locationF locationG)
		(isLeft locationG locationH)

		(isRight locationB locationA)
		(isRight locationC locationB)
		(isRight locationD locationC)
		(isRight locationF locationE)
		(isRight locationG locationF)
		(isRight locationH locationG)

		(isUp locationA locationE)
		(isUp locationB locationF)
		(isUp locationC locationG)
		(isUp locationD locationH)

		(isDown locationE locationA)
		(isDown locationF locationB)
		(isDown locationG locationC)
		(isDown locationH locationD)

		(in locationF)
		(boxAt locationG)
	)
	(:goal (and
		(in locationG)
	))

)