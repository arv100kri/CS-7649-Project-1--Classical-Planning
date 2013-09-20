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
		locationM
		locationn
		locationO
		locationP
		locationQ)

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
		(LOCATION locationn)
		(LOCATION locationO)
		(LOCATION locationP)
		(LOCATION locationQ)

		(isLeft locationA locationB)
		(isLeft locationB locationC)
		(isLeft locationD locationE)
		(isLeft locationE locationF)
		(isLeft locationF locationG)
		(isLeft locationK locationL)
		(isLeft locationL locationm)
		(isLeft locationO locationM)

		(isRight locationB locationA)
		(isRight locationC locationB)
		(isRight locationE locationD)
		(isRight locationF locationE)
		(isRight locationG locationF)
		(isRight locationL locationK)
		(isRight locationm locationL)
		(isRight locationM locationO)

		(isUp locationA locationD)
		(isUp locationB locationE)
		(isUp locationC locationF)
		(isUp locationE locationK)
		(isUp locationF locationL)
		(isUp locationG locationM)
		(isUp locationL locationN)
		(isUp locationM locationO)
		(isUp locationO locationP)
		(isUp locationP locationQ)

		(isDown locationD locationA)
		(isDown locationE locationB)
		(isDown locationF locationC)
		(isDown locationK locationE)
		(isDown locationL locationF)
		(isDown locationM locationG)
		(isDown locationN locationL)
		(isDown locationO locationM)
		(isDown locationP locationO)
		(isDown locationQ locationP)

		(in locationD)
		(boxAt locationE)
		(boxAt locationF)
	)
	(:goal (and
		(boxAt locationA)
		(boxAt locationQ)
	))

)