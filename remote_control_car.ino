//L293Dの1,2ENに繋げたピンの番号を入れる定数
const int L293D_En12=7;
 
//L293Dの1Aに繋げたピンの番号を入れる定数
const int L293D_1A=6;
 
//L293Dの2Aに繋げたピンの番号を入れる定数
const int L293D_2A=5;

//x軸方向の値
int x_value;

// ジョイスティックの基準値
const int x_offset = 500;

void setup() {
  //L293Dに繋げたピンを出力ピンに設定し、使用できる状態にする
  pinMode(L293D_En12,OUTPUT);
  pinMode(L293D_1A,OUTPUT);
  pinMode(L293D_2A,OUTPUT);
}

void loop() {

  //1,2ENの入出力を有効にする
  digitalWrite(L293D_En12,HIGH);

  // X軸値を取得
  x_value=analogRead(A0);

  if (x_value<x_offset-300) {
    // 前進
    digitalWrite(L293D_1A,LOW);
    digitalWrite(L293D_2A,HIGH);
  }
  else if (x_value<x_offset+100) {
    // ニュートラル
    digitalWrite(L293D_1A,LOW);
    digitalWrite(L293D_2A,LOW);
  }
  else {
    // 後退
    digitalWrite(L293D_1A,HIGH);
    digitalWrite(L293D_2A,LOW);
  }
}
