// 継承ver
package main

import "fmt"

// =======================
// 具象クラス Subject
// =======================
// こっちも抽象化できるが(?)冗長になるので省略
// やるなら例えば、SMS以外に、電話とかにして、台詞を全く変えるなど

type Subject struct {
	name      string
	observers []Observer
}

func newSubject(name string) *Subject {
	return &Subject{name: name, observers: []Observer{}}
}

// method
func (s *Subject) addObserver(o Observer) {
	s.observers = append(s.observers, o)
}

func (s Subject) notifyObservers() {
	for _, observer := range s.observers {
		observer.notify()
	}
}

// =======================
// 抽象クラス Observer
// =======================

type Observer interface {
	notify()
}

type Child struct {
	name string
}

func newObserver(name string) *Child {
	return &Child{name: name}
}

// =======================
// 具象クラス GirlFriend,Mum  extends Observer
// =======================
// nameを設定したい
// 要件:　クラスごとに通知内容を全く別物にしたい

type Mom struct {
	*Child
}

func newMom() *Mom {
	return &Mom{newObserver("mom")}
}

func (g Mom) notify() {
	fmt.Printf("%vは,今帰ったでえ！！\n", g.name)
}

type GirlFriend struct {
	*Child
}

func newGirlFriend() *GirlFriend {
	return &GirlFriend{newObserver("Hanako")}
	// 以下を使っても同じ
	// return &GirlFriend{Child: newObserver("Hanako")}
	// return &GirlFriend{&Child{name: "Hanako"}}
}

// ここポインタ型レシーバだとみする！！！！！
// func (g *GirlFriend) notify() {
func (g GirlFriend) notify() {
	fmt.Printf("%vは,今帰ったよ\n", g.name)
}

// =======================
// main
// =======================

func main() {

	sms := newSubject("sms")
	mom := newMom()
	gf := newGirlFriend()

	sms.addObserver(*mom)
	sms.addObserver(*gf)

	sms.notifyObservers()

}
