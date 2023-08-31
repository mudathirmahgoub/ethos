(program maybe_nil ((T Type) (t T))
    (T T) T
    (
      ((maybe_nil t t)       t)
      ((maybe_nil t alf.nil) t)
    )
)
(declare-const and (-> (! Type :var U :implicit) Bool U (maybe_nil Bool U)) :right-assoc-nil)
(declare-const = (-> (! Type :var T :implicit) T T Bool))

; nary.append cons c xs
; Appends `c` to the head of `xs`.
(program nary.append
    ((L Type) (cons (-> L L L)) (c L) (xs L :list))
    ((-> L L L) L L) L
    (
        ((nary.append cons c xs) (cons c xs))
    )
)

; AND_INTRO
; Since we don't have premise lists, we implement different variants of and_intro

; Appends F to the head of Fs where Fs is a null-terminated list.
; I.e. `F`, `(and F1 (and F2 .. (and Fn nil)..)` ==>
;    `(and F ( and F1 (and F2 .. (and Fn nil)..)`
(declare-rule and_intro_nary ((F Bool) (Fs Bool))
    :premises (F Fs)
    :conclusion (nary.append and F Fs)
)

; binary and introduction
(declare-rule and_intro ((F1 Bool) (F2 Bool))
    :premises (F1 F2)
    :conclusion (and F1 F2) ; Note: this creates `(and F1 (and F2 nil))`.
)


; TRANS
; Only binary trans supported
(declare-rule trans ((T Type) (t1 T) (t2 T) (t3 T))
    :premises ((= t1 t2) (= t2 t3))
    :args ()
    :conclusion (= t1 t3)
)
