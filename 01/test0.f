C     test0
c     declaration is not necessary
c      INTEGER I, J, K
      INTEGER TEST
      I = 3
      J = 2
      K = TEST(I, J)
      IF ( K - 5 ) 100, 200, 200  ! Arithmetic IF , IF (a) { a < 0 }, { a == 0 }, { a> 0 }
 100  PRINT *, '>5'
      GOTO 300
 200  PRINT *, '<=5'
c     IF ( K > 5 ) THEN
c         PRINT *, '>5'
c      ELSE
c         PRINT *, '<=5'
c      END IF
 300  END

      INTEGER FUNCTION TEST(I, J)
      INTEGER I, J, K
      K = I * J
      RETURN
      END
