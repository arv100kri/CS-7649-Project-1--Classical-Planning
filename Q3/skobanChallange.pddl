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
		locationQ
		locationR
		locationS
		locationT)

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
		(LOCATION locationR)
		(LOCATION locationS)

		(isLeft locationA locationB)
		(isLeft locationC locationD)
		(isLeft locationE locationF)
		(isLeft locationF locationG)
		(isLeft locationG locationH)
		(isLeft locationH locationI)
		(isLeft locationJ locationK)
		(isLeft locationK locationL)
		(isLeft locationL locationM)
		(isLeft locationM locationN)
		(isLeft locationO locationP)
		(isLeft locationP locationQ)
		(isLeft locationR locationS)

		(isRight locationB locationA)
		(isRight locationD locationC)
		(isRight locationF locationE)
		(isRight locationG locationF)
		(isRight locationH locationG)
		(isRight locationI locationH)
		(isRight locationK locationJ)
		(isRight locationL locationK)
		(isRight locationM locationL)
		(isRight locationN locationM)
		(isRight locationP locationO)
		(isRight locationQ locationP)
		(isRight locationS locationR)

		(isUp locationA locationC)
		(isUp locationB locationD)
		(isUp locationC locationG)
		(isUp locationD locationH)
		(isUp locationE locationJ)
		(isUp locationF locationK)
		(isUp locationG locationL)
		(isUp locationH locationM)
		(isUp locationI locationN)
		(isUp locationK locationO)
		(isUp locationL locationP)
		(isUp locationM locationQ)
		(isUp locationO locationR)
		(isUp locationP locationS)

		(isDown locationC locationA)
		(isDown locationD locationB)
		(isDown locationG locationC)
		(isDown locationH locationD)
		(isDown locationJ locationE)
		(isDown locationK locationF)
		(isDown locationL locationG)
		(isDown locationM locationH)
		(isDown locationN locationI)
		(isDown locationO locationK)
		(isDown locationP locationL)
		(isDown locationQ locationM)
		(isDown locationR locationO)
		(isDown locationS locationP)

		(in locationI)
		(boxAt locationC)
		(boxAt locationF)
		(boxAt locationO)
	)
	(:goal (and
		(boxAt locationK)
		(boxAt locationL)
		(boxAt locationM)
	))

)