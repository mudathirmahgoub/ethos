(declare-sort Int 0)
(declare-sort Real 0)

(program a.typeunion ()
    (Type Type) Type
    (
      ((a.typeunion Int Int) Int)
      ((a.typeunion Int Real) Real)
      ((a.typeunion Real Int) Real)
      ((a.typeunion Real Real) Real)
    )
)

(declare-const + (-> (! Type :var T :implicit) 
                     (! Type :var U :implicit) 
                     T U (a.typeunion T U)))


(declare-const = (-> (! Type :var T :implicit) T T Bool))


(declare-consts <numeral> Int)
(declare-consts <decimal> Real)


(assume a1 (= (+ 1.0 1) (+ 2.0 2)))
