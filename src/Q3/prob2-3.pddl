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
		locationT
		locationU
		locationV
		locationW
		locationX
		locationY
		locationZ
		locationA1)

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
		(LOCATION locationU)
		(LOCATION locationV)
		(LOCATION locationW)
		(LOCATION locationX)
		(LOCATION locationY)
		(LOCATION locationZ)
		(LOCATION locationA1)

		(isLeft locationA locationB)
		(isLeft locationB locationC)
		(isLeft locationH locationI)
		(isLeft locationI locationJ)
		(isLeft locationJ locationK)
		(isLeft locationK locationL)
		(isLeft locationL locationM)
		(isLeft locationM locationN)
		(isLeft locationN locationO)
		(isLeft locationO locationP)
		(isLeft locationU locationV)
		(isLeft locationV locationW)
		(isLeft locationW locationX)
		(isLeft locationX locationY)
		(isLeft locationY locationZ)
		(isLeft locationZ locationA1)

		(isRight locationB locationA)
		(isRight locationC locationB)
		(isRight locationI locationH)
		(isRight locationJ locationI)
		(isRight locationK locationJ)
		(isRight locationL locationK)
		(isRight locationM locationL)
		(isRight locationN locationM)
		(isRight locationO locationN)
		(isRight locationP locationO)
		(isRight locationV locationU)
		(isRight locationW locationV)
		(isRight locationX locationW)
		(isRight locationY locationX)
		(isRight locationZ locationY)
		(isRight locationA1 locationZ)

		(isUp locationA locationD)
		(isUp locationC locationE)
		(isUp locationD locationF)
		(isUp locationE locationG)
		(isUp locationF locationN)
		(isUp locationG locationP)
		(isUp locationH locationQ)
		(isUp locationI locationR)
		(isUp locationL locationS)
		(isUp locationN locationT)
		(isUp locationQ locationU)
		(isUp locationR locationW)
		(isUp locationS locationY)
		(isUp locationT locationA1)
		
		(isDown locationD locationA)
		(isDown locationE locationC)
		(isDown locationF locationD)
		(isDown locationG locationE)
		(isDown locationN locationF)
		(isDown locationP locationG)
		(isDown locationQ locationH)
		(isDown locationR locationI)
		(isDown locationS locationL)
		(isDown locationT locationN)
		(isDown locationU locationQ)
		(isDown locationW locationR)
		(isDown locationY locationS)
		(isDown locationA1 locationT)

		(in locationI)
		(boxAt locationK)
		(boxAt locationM)
		(boxAt locationO)
	)
	(:goal (and
		(boxAt locationA)
		(boxAt locationD)
		(boxAt locationF)
	))

)