// 変数宣言
// ========================

fn main() {
    let name = "Taro";
    let mut age: u32 = 26;
    age += 5;
    println!("{} is {} years old.", name, age);
}

// type
// ========================

fn main() {
    // i64
    // i32
    // i16
    // i8

    // u64
    // u32
    // u16
    // u8

    // f32
    // f64

    println!("{}", 60.5 as i64);
    println!("{}", 60.5 as u64);
    println!("{}", 605i64);
}

fn main() {
    // 2種類の文字列型

    // &str
    // - 固定長
    // - immutable
    // - 実態はutf-8のバイト列への参照
    // - ""で括った文字列リテラルの宣言は&str型になる
    // - .to_string()でString型にキャスト
    //     - この操作で、新たにヒープ上にメモリが確保される
    // - 最初に選択するのはこっち
    let string_slice = "hello"; // &strになる

    // String(heap-allocated string)
    // - ヒープメモリ上に配置
    // - utf-8の文字列であることが保証される
    // - 変更可
    // - .as_str()メソッドによって&str方にキャスト
    //     - この操作は参照を取得するだけなので新たなメモリは確保されない
    // - String変数の先頭に`&`を付けても&str型になる
    //   - &をつけるよことによって、変数の参照を取得できる
    // - 文字列の変更操作が必要に慣ればこっち
    let heep_string = "world".to_string(); // Stringになる

    println!("{},{}", string_slice, heep_string)
}

fn main() {
    // // 文字列連結
    // // `+`はStringに対して、&strを付加する場合のみ可能
    // let hello = "Hello".to_string();
    // let result = hello + "World";
    // println!("{}", result);
    //
    // // `concat!`を使う
    // // リテラル値にしか使用できない
    // let result2 = concat!("true ", true, " num ", 12);
    // println!("{}", result2);

    // `format!`を使う
    let hello = "Hello";
    let world = "World";

    let result3 = format!("{} {}", hello, world);
    println!("{}", result3)
}

fn main() {
    // 文字列の長さ
    // rustは文字列をUTF-8 encodingとして扱う
    let hello = "Hello";
    let nihongo = "日本語";

    // lenを使う
    // len()は文字列のバイト帳を返す
    println!("{} is {} bytes long", hello, hello.len()); // 5 bytes
    println!("{} is {} bytes long", nihongo, nihongo.len()); // 9 bytes

    // chars()とcount()を使う
    // chars()はUnicode1文字ごとのイテレータを返す
    // count()はそのイテレータに対して実行することで、文字数を取得
    println!("{} is {} unicode chars long", hello, hello.chars().count()); // 5 bytes
    println!(
        "{} is {} unicode chars long",
        nihongo,
        nihongo.chars().count()
    ); // 9 bytes

    // rustでは、文字を全てutf-8で扱うので絵文字を使うことができる
    let eggs = ["🐣", "🐣", "🐣"];
    println!("{}", eggs.join("🥓"))
}


// タプル
// ========================

fn make_tuple() -> (u32, String){
    (70, "hello".to_string())
}
fn main() {
    // タプル
    let basic_tuple = (70, "hello");
    println!("{:?}", basic_tuple.0);
    println!("{:?}", basic_tuple.1);

    let (number, word) = make_tuple();
    println!("{:?}", number);
    println!("{:?}", word);
}



// 構造体
// ========================

#[derive(Debug)] // `{:?}`を使用するためには`Debug`が必要
struct Drink {
    name: String,
    price_in_yen: u32,
}

#[derive(Debug)]
struct VendingMachine {
    drinks: Vec<Drink>, // Vecは可変のリストを表すStruct
    cash_balance: u64,
}

fn main() {
    let drink = Drink {
        name: "Dr.Pepper".to_string(),
        price_in_yen: 120,
    };

    println!("{:?}", drink); // debug print
    println!("{:#?}", drink); // pretty debug print. 構造化されたオブジェクトを改行とインデントを伴って出力

    let mut machine = VendingMachine {
        drinks: Vec::new(), // `Vec::new()`で空のベクターを作製
        cash_balance: 0,
    };

    machine.drinks.push(drink);

    println!("{:?}", drink); // compiler error
    println!("{:?}", machine); // debug print
    println!("{:#?}", machine); // pretty debug print. 構造化されたオブジェクトを改行とインデントを伴って出力
}

// 修正版
#[derive(Debug)] // `{:?}`を使用するためには`Debug`が必要
struct Drink {
    name: String,
    price_in_yen: u32,
}

impl Drink {
    fn new(name: &str, price_in_yen: u32) -> Drink{
        Drink {
            name: name.to_string(),
            price_in_yen:price_in_yen
        }
    }
}

#[derive(Debug)]
struct VendingMachine {
    drinks: Vec<Drink>, // Vecは可変のリストを表すStruct
    cash_balance: u64,
}

// 実態を追加するために`impl`をStructに対し付加する
impl VendingMachine {
    fn new() -> VendingMachine { // VendingMachineのインスタンスを返す
        VendingMachine {
            drinks: Vec::new(), // `Vec::new()`で空のベクターを作製
            cash_balance: 0
        }
    }

    // メソッドがstructに対して、何らかの変更を加えるものである場合は、自己参照(self)の前に`mut`を付ける必要があるので、
    // その表記は`&mut self`といった感じになる
    fn add_drink(&mut self, drink: Drink){
        self.drinks.push(drink);

    }
}

fn main() {
    let drink = Drink::new("Dr.Pepper", 120);
    println!("{:?}", drink); // debug print
    println!("{:#?}", drink); // pretty debug print. 構造化されたオブジェクトを改行とインデントを伴って出力

    let mut machine = VendingMachine::new();

    // machine.drinks.push(drink);
    machine.add_drink(drink);

    // println!("{:?}", drink); // compiler error
    println!("{:?}", machine); // debug print
    println!("{:#?}", machine); // pretty debug print. 構造化されたオブジェクトを改行とインデントを伴って出力
}
