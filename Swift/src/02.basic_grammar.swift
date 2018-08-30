let // 定数
var // 変数

// 型
// ======================

// 整数
Int

// 浮動小数点
Float
Double

// 文字列
String

// 論理値
Bool

// Optional
let s: Optional<String> = nil
let s: String? = nil

if s != nil {
  print(s!) // Optional型から値を取り出すことをunwrapすると言う
}

// Optional Binding
// sがnilじゃなかったら表示
if let value = s {
  print(value)
}

// print文に値の埋め込み
var y = 10
y += 10

print("y is \(y)")


/*
あるやつ
- if
- 条件演算子(三項演算子のようなもの)
- switch文
- while文
- repeat/while文 (do-while文のようなもの)
- for文

*/

// 配列,タプル,集合,辞書
// ================================

// 配列
var scores: [Int] = [50, 40]

var names = [String]() // 空配列の宣言
names.append("taguchi")
names.append("fkoji")

// タプル
var items = ("apple", 5)
print(items.0)

// 集合
var winners: Set<Int> = [3,5,8,8]
print(winners) // [3,5,8]
winners.insert(10)
winners.remove(5)
print(winners.count) // 4

// 辞書
var sales: Dictionary<String, Int> = ["taguchi": 200, "fkoji": 300]
