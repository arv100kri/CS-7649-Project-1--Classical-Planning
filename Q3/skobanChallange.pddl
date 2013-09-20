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
		(LOCATION locationT)

		(isLeft locationA locationB)
		(isLeft locationC locationD)
		(isLeft locationD locationE)
		(isLeft locationF locationG)
		(isLeft locationG locationH)
		(isLeft locationH locationI)
		(isLeft locationI locationJ)
		(isLeft locationK locationL)
		(isLeft locationL locationM)
		(isLeft locationM locationN)
		(isLeft locationN locationO)
		(isLeft locationP locationQ)
		(isLeft locationQ locationR)
		(isLeft locationS locationT)

		(isRight locationB locationA)
		(isRight locationD locationC)
		(isRight locationE locationD)
		(isRight locationG locationF)
		(isRight locationH locationG)
		(isRight locationI locationH)
		(isRight locationJ locationI)
		(isRight locationL locationK)
		(isRight locationM locationL)
		(isRight locationN locationM)
		(isRight locationO locationN)
		(isRight locationQ locationP)
		(isRight locationR locationQ)
		(isRight locationT locationS)

		(isUp locationA locationC)
		(isUp locationB locationD)
		(isUp locationC locationH)
		(isUp locationD locationI)
		(isUp locationF locationK)
		(isUp locationG locationL)
		(isUp locationH locationM)
		(isUp locationI locationN)
		(isUp locationJ locationO)
		(isUp locationL locationP)
		(isUp locationM locationQ)
		(isUp locationN locationR)
		(isUp locationP locationS)
		(isUp locationQ locationT)

		(isDown locationC locationA)
		(isDown locationD locationB)
		(isDown locationH locationC)
		(isDown locationI locationD)
		(isDown locationK locationF)
		(isDown locationL locationG)
		(isDown locationM locationH)
		(isDown locationN locationI)
		(isDown locationO locationJ)
		(isDown locationP locationL)
		(isDown locationQ locationM)
		(isDown locationR locationN)
		(isDown locationS locationP)
		(isDown locationT locationQ)

		(in locationJ)
		(boxAt locationC)
		(boxAt locationG)
		(boxAt locationP)
	)
	(:goal (and
		(boxAt locationL)
		(boxAt locationM)
		(boxAt locationN)
	))

)