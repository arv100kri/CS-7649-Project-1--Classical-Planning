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
		locationH
		locationI
		locationJ
		locationK
		locationL
		locationM)

	(:init
		(LOCATION locationA)
		(LOCATION locationB)
		(LOCATION locationC)
		(LOCATION locationD)
		(LOCATION locationE)
		(LOCATION locationF)
		(LOCATION locationG)
		(LOCATION locationH)
		(LOCATION locationI)
		(LOCATION locationJ)
		(LOCATION locationK)
		(LOCATION locationL)
		(LOCATION locationM)

		(isLeft locationA locationB)
		(isLeft locationD locationE)
		(isLeft locationE locationF)
		(isLeft locationF locationG)
		(isLeft locationH locationI)
		(isLeft locationI locationJ)
		(isLeft locationJ locationK)
		(isLeft locationL locationM)

		(isRight locationB locationA)
		(isRight locationE locationD)
		(isRight locationF locationE)
		(isRight locationG locationF)
		(isRight locationI locationH)
		(isRight locationJ locationI)
		(isRight locationK locationJ)
		(isRight locationM locationL)

		(isUp locationB locationC)
		(isUp locationC locationE)
		(isUp locationD locationH)
		(isUp locationE locationI)
		(isUp locationF locationJ)
		(isUp locationG locationK)
		(isUp locationH locationL)
		(isUp locationI locationM)

		(isDown locationC locationB)
		(isDown locationE locationC)
		(isDown locationH locationD)
		(isDown locationI locationE)
		(isDown locationJ locationF)
		(isDown locationK locationG)
		(isDown locationL locationH)
		(isDown locationM locationI)

		(in locationC)
		(boxAt locationJ)
	)
	(:goal (and
		(boxAt locationB)
	))

)